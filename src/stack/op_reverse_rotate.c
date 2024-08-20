/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhehdir <mkhehdir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:07:04 by mkhehdir          #+#    #+#             */
/*   Updated: 2024/08/20 19:07:05 by mkhehdir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	r_rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bottom];
		stk->stack[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}

void	r_rotate_a(t_ps *data)
{
	r_rotate(&data->a);
	if (data->writing_mode)
		save_op(data, rra);
}

void	r_rotate_b(t_ps *data)
{
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrb);
}

void	r_rotate_ab(t_ps *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrr);
}
