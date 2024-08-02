#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	while (*lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = list;
	}
}
