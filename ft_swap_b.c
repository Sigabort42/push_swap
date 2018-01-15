#include "push_swap.h"

void	ft_swap_b(t_vari *var)
{
	int	d;

	ft_putstr("\nswap_b\n");
	if (!var->last_b || !var->last_b->prev)
	{
		ft_putstr("\nswap_b\n");
		return ;
	}
	d = var->last_b->nb;
	var->last_b->nb = var->last_b->prev->nb;
	var->last_b->prev->nb = d;
}
