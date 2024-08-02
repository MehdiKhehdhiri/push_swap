#include "../push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_distance(t_stack **stack, int min)
{
	t_stack	*node;
	int		distance;

	distance = 0;
	node = *stack;
	while (node)
	{
		if (node->index == min)
			break ;
		distance++;
		node = node->next;
	}
	return (distance);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}
