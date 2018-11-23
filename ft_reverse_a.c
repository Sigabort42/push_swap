/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:43:04 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 01:43:04 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_a(t_vari *var)
{
	t_lst	*tmp;

	if (!var->last_a || !var->last_a->prev)
		return ;
	tmp = var->first_a->next;
	tmp->prev = 0;
	var->first_a->prev = var->last_a;
	var->last_a->next = var->first_a;
	var->last_a = var->first_a;
	var->first_a = tmp;
	var->last_a->next = 0;
}
