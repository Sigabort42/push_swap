
#include "push_swap.h"

t_lst	*ft_listlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
