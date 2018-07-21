#include "../push_swap.h"

void	ft_phase_one(t_vari *var)
{
	while (var->last_a && ft_count_pile(var->last_a) > 2)
	{
		if (var->last_a && var->last_a->nb > var->first_a->nb)
		{
			var->count++;
			var->tab_func[RA_CMD].f(var);
			ft_putendl(RA);
		}
		else if (var->last_a && var->last_a->nb < var->first_a->nb &&
		var->last_a->nb > var->first_a->next->nb)
		{
			var->count++;
			var->tab_func[RRA_CMD].f(var);
			ft_putendl(RRA);
			var->count++;
			var->tab_func[SA_CMD].f(var);
			ft_putendl(SA);
			var->count++;
			var->tab_func[RA_CMD].f(var);
			ft_putendl(RA);
			var->count++;
			var->tab_func[RA_CMD].f(var);
			ft_putendl(RA);
		}
		else
		{
			var->count++;
			var->tab_func[PB_CMD].f(var);
			ft_putendl(PB);
		}
/*		while (var->last_b && var->last_b->nb < var->first_b->nb)
		{
			var->tab_func[RR_CMD].f(var);
			ft_putendl(RR);
			var->count++;
			if (var->last_b->prev && var->last_b->nb < var->last_b->prev->nb)
			{
				var->tab_func[SB_CMD].f(var);
				ft_putendl(SB);
				var->count++;
			}
		}
		if (var->last_b && var->last_b->prev && var->last_b->nb < var->last_b->prev->nb)
		{
			var->tab_func[SB_CMD].f(var);
			ft_putendl(SB);
			var->count++;
		}
*/	}
}
