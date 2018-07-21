/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:21:06 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:21:06 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_vari *var)
{
	t_lst	*tmp;

	if (!var->last_a || !var->last_a->prev)
		return ;
	tmp = var->last_a->prev;
	var->last_a->next = var->first_a;
	var->first_a->prev = var->last_a;
	var->first_a = var->last_a;
	var->first_a->prev = 0;
	var->last_a = tmp;
	tmp->next = 0;
}
