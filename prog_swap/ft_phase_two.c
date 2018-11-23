/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:11:53 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 02:16:29 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ft_exec(t_vari *var, char *name_cmd, int cmd)
{
	ft_putendl(name_cmd);
	var->tab_func[cmd].f(var);
	var->count++;
}

void		ft_phase_two2(t_vari *var, int *f)
{
	while (var->last_b && var->last_b->nb > var->first_a->nb &&
	var->last_b->nb < var->last_a->nb)
	{
		ft_exec(var, PA, PA_CMD);
		ft_exec(var, RA, RA_CMD);
	}
	if (var->last_b && var->last_a->nb < var->last_b->nb)
	{
		while (var->last_b && var->last_a->nb < var->last_b->nb)
		{
			*f = 1;
			ft_exec(var, RA, RA_CMD);
		}
	}
	while (var->last_b && var->last_a->nb > var->last_b->nb &&
	var->first_a->nb < var->last_b->nb)
		ft_exec(var, PA, PA_CMD);
	ft_exec(var, RRA, RRA_CMD);
}

void		ft_phase_two(t_vari *var)
{
	int		tmp;
	int		f;

	f = 0;
	while (var->last_b)
	{
		tmp = var->last_a->nb;
		while (var->last_b->nb > var->first_a->nb)
		{
			ft_exec(var, PA, PA_CMD);
			ft_exec(var, RA, RA_CMD);
		}
		while (var->last_b && var->last_a->nb < var->last_b->nb)
		{
			f = 1;
			ft_exec(var, RA, RA_CMD);
		}
		if (!f)
			ft_exec(var, PA, PA_CMD);
		while (tmp != var->last_a->nb && f)
			ft_phase_two2(var, &f);
		f = 0;
	}
}
