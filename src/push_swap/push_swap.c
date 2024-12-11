/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekhedhi <mekhedhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:06:30 by mekhedhi         #+#    #+#             */
/*   Updated: 2024/10/19 23:11:37 by mekhedhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i])|| str[i] == ' '
			|| (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		else
			return (0);
	}
	return (1);
}

char	*get_args(int argc, char **argv)
{
	int		i;
	char	*args;
	char	*tmp;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 1)
			return ("Error");
	}
	args = ft_strdup("");
	i = 0;
	while (++i < argc)
	{
		tmp = args;
		args = ft_strjoin(args, argv[i]);
		free(tmp);
		tmp = args;
		if (i == argc - 1)
			args = ft_strjoin(args, "\0");
		else
			args = ft_strjoin(args, " ");
		free(tmp);
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_ps	data;
	char	**args;
	char	*joined_args;
	int		i;

	joined_args = get_args(argc, argv);
	if (ft_strcmp(joined_args, "Error") == 0)
	{
		ft_putendl_fd("Errords", 2);
		exit(EXIT_FAILURE);
	}
	args = ft_split(joined_args, ' ');
	free(joined_args);
	init_data(&data, argc, args, true);
	sort(&data);
	print_operations(data.op_list);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
