/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_to_the_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhehdir <mkhehdir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:06:23 by mkhehdir          #+#    #+#             */
/*   Updated: 2024/08/20 19:06:24 by mkhehdir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_the_top(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&data->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&data->a) == to_sort->size)
		to_sort->loc = TOP_A;
}
