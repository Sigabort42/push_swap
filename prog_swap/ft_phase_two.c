#include "../push_swap.h"

static void	ft_exec(t_vari *var, char *name_cmd, int cmd)
{
	ft_putendl(name_cmd);
	var->tab_func[cmd].f(var);
	var->count++;
}

void		ft_phase_two(t_vari *var)
{
	t_lst	*tmp;

	if (var->last_a->nb > var->last_a->prev->nb)
		ft_exec(var, SA, SA_CMD);
	while (var->last_b)
	{
		tmp = var->last_a;
		while (var->last_a->nb < var->last_b->nb && tmp != var->first_a &&
		ft_count_pile(var->last_a) > 2)
			ft_exec(var, RA, RA_CMD);
		ft_exec(var, PA, PA_CMD);
		if (var->last_a->nb > var->first_a->nb)
			ft_exec(var, RA, RA_CMD);
		else if (var->last_a->nb > var->last_a->prev->nb)
			ft_exec(var, SA, SA_CMD);
/*		while (var->last_a != tmp)
		{
			var->count++;
			var->tab_func[RRA_CMD].f(var);
			ft_putendl(RRA);
		}
*/	}
}
