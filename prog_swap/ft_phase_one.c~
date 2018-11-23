#include "../push_swap.h"

int	ft_count_node(t_vari *var)
{
	int	i;
	t_lst	*tmp;
	
	i = 0;
	tmp = var->first_a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_phase_one(t_vari *var)
{
	int	n;
	int	m;
	int	m2;
	int	n_b;
	t_lst	*tmp;

	tmp = var->last_a;
	n_b = 0;
	n = ft_count_node(var);
	if (n > 150)
		m = n / 20;
	else if (n > 50)
		m = n / 10;
	else
		m = n / 4;
	m2 = m;
	while (tmp->prev)
	{
		while (n_b < m2 - 1)
		{
			if (tmp->nb <= m2 && tmp->nb != n && ++n_b)
				ft_exec(var, PB, PB_CMD);
			else
				ft_exec(var, RA, RA_CMD);
			tmp = var->last_a;
		}
		m2 += m;
	}
}

/*void	ft_phase_one(t_vari *var)
{
	int	nb;

	nb = var->first_a->nb;
	while (var->last_a && (ft_count_pile(var->last_a) > 2 && var->last_a->nb != nb))
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
		while (var->last_b && var->last_b->nb < var->first_b->nb)
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
	}
}
*/
