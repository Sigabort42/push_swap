/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:20:23 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:20:24 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_a(t_vari *var)
{
	t_lst	*new;

	if (!var->last_b)
	{
//		ft_putstr("lil\n");
		return ;
	}
	else if (var->first_b->next)
	{
		new = ft_listnew(var->last_b->nb);
		ft_list_pushback(&var->first_a, new);
		var->last_a = new;
		free(var->last_b);
		var->last_b = var->last_b->prev;
		var->last_b->next = 0;
//		ft_putstr("lil2\n");
	}
	else if (!var->first_b->next && !var->last_b->next)
	{
//		ft_putstr("lil2\n");
		new = ft_listnew(var->last_b->nb);
		ft_list_pushback(&var->first_a, new);
		var->last_a = new;
		free(var->last_b);
		var->last_b = 0;
		var->first_b = 0;
	}
//	ft_putstr("lil3\n");
}
