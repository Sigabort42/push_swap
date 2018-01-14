#include "push_swap.h"

void	ft_swap_a(t_vari *var)
{
	int	d;

	ft_putstr("\nswap_a\n");
	if (!var->last_a || !var->last_a->prev)
		return ;
	d = var->last_a->nb;
	var->last_a->nb = var->last_a->prev->nb;
	var->last_a->prev->nb = d;
}
