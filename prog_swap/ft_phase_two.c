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

#include <stdio.h>

t_lst		*ft_verif_taille(t_lst *lst, int nb)
{
	t_lst	*tmp;
	t_lst	*n;

	tmp = lst;
	n = tmp;
	while (tmp)
	{
		if (tmp->nb > nb)
			return (0);
		else if (n->nb < tmp->nb)
			n = tmp;
		tmp = tmp->next;
	}
	return (n);
}

void		ft_push_taille(t_vari *var, t_lst *addr)
{
	t_lst *pile_a;

	pile_a = var->first_a;
	while (pile_a && pile_a != addr)
		pile_a = pile_a->next;
	ft_exec(var, PA, PA_CMD);
	ft_exec(var, SA, SA_CMD);
}

void		ft_phase_two2(t_vari *var, int *f)
{
	t_lst	*addr;
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
			if (!(addr = ft_verif_taille(var->first_a, var->last_b->nb)))
				ft_exec(var, RA, RA_CMD);
			else
				ft_push_taille(var, addr);
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
