/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_post_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekhedhi <mekhedhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:06:04 by mekhedhi         #+#    #+#             */
/*   Updated: 2024/10/19 23:11:37 by mekhedhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	post_sort_optimization(t_ps *data)
{
	if (!data->op_list)
		return ;
	eliminate_neutral_op(data->op_list);
	merge_op(data->op_list);
}

void	eliminate_neutral_op(t_list *op_list)
{
	t_list		*ref;
	t_list		*cmp;
	enum e_op	op_neutral;

	ref = op_list->next;
	while (ref && ref->next)
	{
		op_neutral = neutral_op(op_from(ref));
		if (op_neutral)
		{
			cmp = ref->next;
			while (!op_on_same_stack(op_from(ref), op_from(cmp))
				&& op_from(cmp) != op_neutral && cmp->next)
				cmp = cmp->next;
			if (ref->prev && op_from(cmp) == op_neutral)
			{
				ref = ref->prev;
				remove_op(ref->next);
				remove_op(cmp);
				continue ;
			}
		}
		ref = ref->next;
	}
}

void	merge_op(t_list *op_list)
{
	t_list		*reader;
	enum e_op	child;

	reader = op_list;
	while (reader && reader->next)
	{
		child = child_op(op_from(reader), op_from(reader->next));
		if (child)
		{
			remove_op(reader->next);
			reader->content = (void *)(uintptr_t)child;
		}
		reader = reader->next;
	}
}
