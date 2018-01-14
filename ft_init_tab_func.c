/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:41:16 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/13 18:44:41 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_func(t_vari *var)
{
      	ft_printf("{red}%p{eoc} %3.1p\n", var, var);
}

void	ft_init_tab_func(t_tab **tab_func)
{
	if (!(*tab_func = malloc(sizeof(t_tab) * 12)))
		exit(EXIT_FAILURE);
	(*tab_func)[0].command = ft_strdup("sa");
	(*tab_func)[0].f = &ft_swap_a;
	(*tab_func)[1].command = ft_strdup("sb");
	(*tab_func)[1].f = &ft_swap_b;
	(*tab_func)[2].command = ft_strdup("ss");
	(*tab_func)[2].f = &ft_swap_s;
	(*tab_func)[3].command = ft_strdup("pa");
	(*tab_func)[3].f = &ft_push_a;
	(*tab_func)[4].command = ft_strdup("pb");
	(*tab_func)[4].f = &ft_push_b;
	(*tab_func)[5].command = ft_strdup("ra");
	(*tab_func)[5].f = &ft_rotate_a;
	(*tab_func)[6].command = ft_strdup("rb");
	(*tab_func)[6].f = &ft_rotate_b;
	(*tab_func)[7].command = ft_strdup("rr");
	(*tab_func)[7].f = &ft_rotate_r;
	(*tab_func)[8].command = ft_strdup("rra");
	(*tab_func)[8].f = &ft_reverse_a;
	(*tab_func)[9].command = ft_strdup("rrb");
	(*tab_func)[9].f = &ft_reverse_b;
	(*tab_func)[10].command = ft_strdup("rrr");
	(*tab_func)[10].f = &ft_reverse_r;
	(*tab_func)[11].command = 0;
}
