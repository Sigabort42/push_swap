/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:22:43 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/24 06:07:27 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_exec(t_vari *var, int cmd, char *c_cmd)
{
	var->count++;
	var->tab_func[cmd].f(var);
	ft_putendl(c_cmd);
}

void	ft_phase_one2(t_vari *var)
{
	ft_exec(var, RRA_CMD, RRA);
	ft_exec(var, SA_CMD, SA);
	ft_exec(var, RA_CMD, RA);
	ft_exec(var, RA_CMD, RA);
}

void		ft_phase_one(t_vari *var)
{
	int		nb;
	int		div;

	div = (ft_count_pile(var->last_a) / 3);
	nb = var->first_a->nb;
	while (var->last_a && (ft_count_pile(var->last_a) > 2) && var->last_a->nb != nb)
	{
		if (var->last_a && var->last_a->nb > var->first_a->nb)
			ft_exec(var, RA_CMD, RA);
		if (var->last_a && var->last_a->nb < var->first_a->nb &&
		var->last_a->nb > var->first_a->next->nb)
			ft_phase_one2(var);
		else
			ft_exec(var, PB_CMD, PB);
	}
}
