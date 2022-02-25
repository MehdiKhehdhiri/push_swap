/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:19:33 by mkhedhir          #+#    #+#             */
/*   Updated: 2022/02/25 20:01:58 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->content = (void *) content;
	list->next = 0;
	return (list);
}


int	main(int ac, char av)
{
	int	i;
	t_pile	*a;

	a = NULL
	i = 1;
	while (i <= ac)
	{
		if (ft_isnum(av[i]))
		{
			a = ft_lstnew(ft_atoi(av[i]));
		}	
	}
}
