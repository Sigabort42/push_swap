#include "push_swap.h"

void	ft_rotate_b(t_vari *var)
{
	t_lst	*tmp;

	if (!var->last_b || !var->last_b->prev)
		return ;
	tmp = var->last_b->prev;
	var->last_b->next = var->first_b;
	var->first_b->prev = var->last_b;
	var->first_b = var->last_b;
	var->first_b->prev = 0;
	var->last_b = tmp;
	tmp->next = 0;
}