#include "../push_swap.h"

t_stack	*ft_stack_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_stack_lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stack_lstlast(t_stack *node)
{
	t_stack	*tmp;

	tmp = node;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_stack_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ft_stack_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_stack_lstsize(t_stack *node)
{
	size_t	i;
	t_stack	*tmp;

	tmp = node;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
