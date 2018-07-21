/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:20:33 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:20:33 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_b(t_vari *var)
{
	t_lst	*new;

	if (!var->last_a)
		return ;
	else if (var->last_a->prev)
	{
		new = ft_listnew(var->last_a->nb);
		if (ft_list_pushback(&var->first_b, new))
			return ;
		var->last_b = new;
		free(var->last_a);
		var->last_a = var->last_a->prev;
		var->last_a->next = 0;
	}
	else if (!var->last_a->prev && !var->last_a->next)
	{
		new = ft_listnew(var->last_a->nb);
		if (ft_list_pushback(&var->first_b, new))
			return ;
		var->last_b = new;
		free(var->last_a);
		var->last_a = 0;
		var->first_a = 0;
	}
}
