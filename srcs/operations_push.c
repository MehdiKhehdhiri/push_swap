#include "../push_swap.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_stack_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		temp->next = head_to;
		*stack_to = temp;
	}
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
