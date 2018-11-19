#include "../push_swap.h"

static void     ft_exec(t_vari *var, char *name_cmd, int cmd)
{
        ft_putendl(name_cmd);
        var->tab_func[cmd].f(var);
        var->count++;
}

static void ft_first_one(t_vari *var)
{
	if (var->last_a->nb > var->last_b->nb)
		ft_exec(var, "pb", PB_CMD);
	else
	{
		ft_exec(var, "pb", PB_CMD);
		ft_exec(var, "sb", SB_CMD);
	}
}

void	ft_phase_one(t_vari *var)
{
	int	nb;

	nb = var->last_a->nb;
	if (!var->last_b)
		ft_exec(var, "pb", PB_CMD);
	ft_first_one(var);
	ft_first_one(var);
	while (var->last_a)
	{
//		printf("%d %d\n", var->last_a->nb, var->last_b->nb);
		if (var->last_a->nb < nb)
		{
			nb = var->last_a->nb;
			ft_exec(var, "pb", PB_CMD);
			ft_exec(var, "rb", RB_CMD);
		}
		if (var->last_a->nb > var->last_b->nb && var->last_a->nb > var->first_b->nb)
			ft_exec(var, "pb", PB_CMD);
		else //if (var->last_a->nb < var->last_b->nb)
			ft_exec(var, "rb", RB_CMD);
	}
	while (nb != var->first_b->nb)
		ft_exec(var, "rb", RB_CMD);
	while (var->last_b)
		ft_exec(var, "pa", PA_CMD);
}
