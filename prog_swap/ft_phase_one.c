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
	float	n;
	float	m;
	float	m2;
	int	n_b;
	t_lst	*tmp;

	tmp = var->last_a;
	n_b = 0;
	n = (float)ft_count_node(var);
	if (n > 150)
		m = n / 14;
	else if (n > 50)
		m = n / 7;
	else
		m = n / 5;
	m2 = m;
	while (tmp->prev)
	{
		while (n_b < (int)m2 - 1)
		{
			if (tmp->nb <= (int)m2 && tmp->nb != n && ++n_b)
				ft_exec(var, PB, PB_CMD);
			else
				ft_exec(var, RA, RA_CMD);
			tmp = var->last_a;
		}
		m2 += m;
	}
}
