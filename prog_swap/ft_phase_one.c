#include "../push_swap.h"

void	ft_phase_one(t_vari *var)
{
	while (var->last_a && ft_count_pile(var->last_a) > 2)
	{
		var->count++;
		var->tab_func[PB_CMD].f(var);
		ft_putendl(PB);
		while (var->last_b->nb < var->first_b->nb)
		{			
			var->tab_func[RB_CMD].f(var);
			ft_putendl(RB);
			var->count++;
			if (var->last_b->prev && var->last_b->nb < var->last_b->prev->nb)
			{
				var->tab_func[SB_CMD].f(var);
				ft_putendl(SB);
				var->count++;
			}
		}
		if (var->last_b->prev && var->last_b->nb < var->last_b->prev->nb)
		{
			var->tab_func[SB_CMD].f(var);
			ft_putendl(SB);
			var->count++;
		}
	}
}
