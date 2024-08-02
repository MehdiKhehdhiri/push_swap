#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!*lst)
		*lst = new;
	else
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
}
