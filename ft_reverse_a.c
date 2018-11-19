#include "push_swap.h"

void	ft_reverse_a(t_vari *var)
{
	t_lst	*tmp;

	if (!var->last_a || !var->last_a->prev)
		return ;
	tmp = var->first_a->next;
	tmp->prev = 0;
	var->first_a->prev = var->last_a;
	var->last_a->next = var->first_a;
	var->last_a = var->first_a;
	var->first_a = tmp;
	var->last_a->next = 0;
}
