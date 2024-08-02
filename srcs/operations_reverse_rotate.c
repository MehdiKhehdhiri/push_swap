#include "../push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last_node;

	if (ft_stack_lstsize(*stack) < 2)
		return (-1);
	node = *stack;
	last_node = ft_stack_lstlast(node);
	while (node)
	{
		if (node->next->next == NULL)
		{
			node->next = NULL;
			break ;
		}
		node = node->next;
	}
	last_node->next = *stack;
	*stack = last_node;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stack_lstsize(*stack_a) < 2) || (ft_stack_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
