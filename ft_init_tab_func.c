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

void	ft_func(int *tab, int *tab2)
{
	ft_printf("%p %p\n", tab, tab2);
}

void	ft_init_tab_func(t_tab *tab)
{
	int	i;

	i = 0;
//	if (!(*tab = malloc(sizeof(t_tab) * 12)))
//		return ;
//	tab[11] = 0;
	tab[0].command = ft_strdup("sa");
	tab[0].f = &ft_func;
	tab[1].command = ft_strdup("sb");
	tab[1].f = &ft_func;
	tab[2].command = ft_strdup("ss");
	tab[2].f = &ft_func;
	tab[3].command = ft_strdup("pa");
	tab[3].f = &ft_func;
	tab[4].command = ft_strdup("pb");
	tab[4].f = &ft_func;
	tab[5].command = ft_strdup("ra");
	tab[5].f = &ft_func;
	tab[6].command = ft_strdup("rb");
	tab[6].f = &ft_func;
	tab[7].command = ft_strdup("rr");
	tab[7].f = &ft_func;
	tab[8].command = ft_strdup("rra");
	tab[8].f = &ft_func;
	tab[9].command = ft_strdup("rrb");
	tab[9].f = &ft_func;
	tab[10].command = ft_strdup("rrr");
	tab[10].f = &ft_func;
}
