/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:21:32 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:21:33 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_vari *var)
{
	int	d;

	if (!var->last_a || !var->last_a->prev)
		return ;
	d = var->last_a->nb;
	var->last_a->nb = var->last_a->prev->nb;
	var->last_a->prev->nb = d;
}
