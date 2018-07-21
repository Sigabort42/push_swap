/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:20:48 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:20:49 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_b(t_vari *var)
{
	t_lst	*tmp;

	if (!var->last_b || !var->last_b->prev)
		return ;
	tmp = var->first_b->next;
	tmp->prev = 0;
	var->first_b->prev = var->last_b;
	var->last_b->next = var->first_b;
	var->last_b = var->first_b;
	var->first_b = tmp;
	var->last_b->next = 0;
}
