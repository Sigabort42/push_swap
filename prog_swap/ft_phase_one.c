/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:52:15 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 01:55:56 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			ft_count_node(t_vari *var)
{
	int		i;
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

int			ft_phase_one2(int n)
{
	if (n > 150)
		return (n / 20);
	else if (n > 50)
		return (n / 10);
	else
		return (n / 4);
}

void		ft_phase_one(t_vari *var)
{
	int		n;
	int		m;
	int		m2;
	int		n_b;
	t_lst	*tmp;

	tmp = var->last_a;
	n_b = 0;
	n = ft_count_node(var);
	m = ft_phase_one2(n);
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
