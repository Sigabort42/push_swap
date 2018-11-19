#include "push_swap.h"

void		ft_push_a(t_vari *var)
{
	t_lst	*new;

	if (!var->last_b)
		return ;
	else if (var->first_b->next)
	{
		new = ft_listnew(var->last_b->nb);
		ft_list_pushback(&var->first_a, new);
		var->last_a = new;
		free(var->last_b);
		var->last_b = var->last_b->prev;
		var->last_b->next = 0;
	}
	else if (!var->first_b->next && !var->last_b->next)
	{
		new = ft_listnew(var->last_b->nb);
		ft_list_pushback(&var->first_a, new);
		var->last_a = new;
		free(var->last_b);
		var->last_b = 0;
		var->first_b = 0;
	}
}
