/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:43:35 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 01:43:36 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_vari *var)
{
	int	d;

	if (!var->last_b || !var->last_b->prev)
		return ;
	d = var->last_b->nb;
	var->last_b->nb = var->last_b->prev->nb;
	var->last_b->prev->nb = d;
}
