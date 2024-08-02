#include "../push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*node;
	t_stack	*min;
	int		min_flag;

	min = NULL;
	min_flag = 0;
	node = *stack;
	if (node)
	{
		while (node)
		{
			if ((node->index == -1) && (!min_flag || node->value < min->value))
			{
				min = node;
				min_flag = 1;
			}
			node = node->next;
		}
	}
	return (min);
}

void	indexing_node(t_stack **stack)
{
	t_stack	*node;
	int		index;

	index = 0;
	node = get_next_min(stack);
	while (node)
	{
		node->index = index++;
		node = get_next_min(stack);
	}
}
