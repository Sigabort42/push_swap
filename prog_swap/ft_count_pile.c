#include "../push_swap.h"

int	ft_count_pile(t_lst *pile)
{
	t_lst	*tmp;
	int	i;

	i = 0;
	tmp = pile;
	while (tmp)
	{
		i++;
		tmp = tmp->prev;
	}
	return (i);
}
