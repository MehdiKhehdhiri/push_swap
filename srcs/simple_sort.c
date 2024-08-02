#include "../push_swap.h"

static int	get_min(t_stack **stack, int val)
{
	t_stack	*node;
	int		min;

	node = *stack;
	min = node->index;
	while (node->next)
	{
		node = node->next;
		if ((node->index < min) && node->index != val)
			min = node->index;
	}
	return (min);
}

static void	sort_3(t_stack **stack_a)
{
	t_stack	*node;
	int		min;
	int		next_min;

	node = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (node->index == min && node->next->index != next_min)
		sort_3_1(stack_a);
	else if (node->index == next_min)
	{
		if (node->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (node->next->index == min)
			ra(stack_a);
		else
			sort_3_2(stack_a);
	}
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_stack_lstsize(*stack_a) == 0
		|| ft_stack_lstsize(*stack_a) == 1)
		return ;
	size = ft_stack_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
