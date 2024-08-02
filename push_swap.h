#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;
/*
check_args.c
*/
void	ft_check_args(int argc, char **argv);

/*
indexing_nodes.c
*/
void	indexing_node(t_stack **stack);

/*
operations_push.c
*/
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

/*
operations_rotate.c
*/
int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

/*
operations_reverse_rotate.c*/
int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

/*
operations_swap.c
*/
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

/*
radix_sort.c
*/
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/*
simple_sort.c
*/
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

/*
simple_sort2.c"
*/
void	sort_3_1(t_stack **stack_a);
void	sort_3_2(t_stack **stack_a);

/*
t_list.c
*/
t_stack	*ft_stack_lstnew(int value);
void	ft_stack_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stack_lstlast(t_stack *head);
void	ft_stack_lstadd_back(t_stack **stack, t_stack *new);
int		ft_stack_lstsize(t_stack *head);

/*
utils.c
*/
int		is_sorted(t_stack **stack);
void	ft_error(char *msg);
int		get_distance(t_stack **stack, int index);
void	ft_free(char **str);
void	free_stack(t_stack **stack);

#endif
