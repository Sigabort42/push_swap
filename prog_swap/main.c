/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:19:03 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/13 18:43:15 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		ft_verif_arg(int ac)
{
	if (ac < 2)
	{
		write(1, "usage : ./push_swap $ARG [-cv]\n", 28);
		exit(1);
	}
}

static void		ft_affiche(t_vari *var)
{
	t_lst		*tmp_a;
	t_lst		*tmp_b;
	tmp_a = var->first_a;
	ft_putstr("pile_a: ");
	while (tmp_a)
	{
		ft_printf("|%i ", tmp_a->nb);
		tmp_a = tmp_a->next;
	}
	tmp_b = var->first_b;
	ft_putstr("\n\n\npile_b:");
	while (tmp_b)
	{
		ft_printf("|%i ", tmp_b->nb);
		tmp_b = tmp_b->next;
	}
	ft_putstr("\n");	
}

int			main(int argc, char **argv)
{
	t_vari		var;
	t_lst		*pile_a;

	var.first_b = 0;
	var.last_b = 0;
	ft_verif_arg(argc);
	ft_init_tab_func(&var.tab_func);
	ft_init_pile_a(&pile_a, argv);
	var.first_a = pile_a;
	var.last_a = ft_listlast(pile_a);
//	ft_affiche(&var);
	ft_phase_one(&var);
//	ft_affiche(&var);
	printf("number stroke = %d\n", var.count);
	return (0);
}
