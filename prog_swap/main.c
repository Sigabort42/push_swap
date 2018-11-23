/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:19:03 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 02:23:58 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

static void		ft_verif_arg(int ac)
{
	if (ac < 2)
	{
		write(1, "usage : ./push_swap $ARG [-cv]\n", 28);
		exit(1);
	}
}

static void		ft_free_func(t_tab **tab)
{
	int			i;

	i = 0;
	while ((*tab)[i].command)
	{
		free((*tab)[i].command);
		i++;
	}
	free((void*)(*tab));
}

static void		ft_free_pile(t_lst **pile)
{
	while ((*pile)->next)
	{
		*pile = (*pile)->next;
		free((*pile)->prev);
	}
	free(*pile);
}

int				main(int argc, char **argv)
{
	t_vari		var;
	t_lst		*pile_a;

	var.first_b = 0;
	var.last_b = 0;
	ft_verif_arg(argc);
	if (ft_init_tab_func(&var.tab_func) || ft_init_pile_a(&pile_a, argv))
	{
		ft_free_func(&var.tab_func);
		ft_free_pile(&var.first_a);
		return (1);
	}
	var.first_a = pile_a;
	var.last_a = ft_listlast(pile_a);
	ft_phase_one(&var);
	ft_phase_two(&var);
	ft_free_func(&var.tab_func);
	ft_free_pile(&var.first_a);
	printf("number stroke = %d\n", var.count);
	return (0);
}
