/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:19:03 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 01:51:52 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_verif_arg(int ac)
{
	if (ac < 2)
	{
		write(1, "usage : ./checker $ARG [-cv]\n", 28);
		exit(EXIT_FAILURE);
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

int				main(int argc, char **argv)
{
	t_vari		var;
	t_lst		*pile_a;

	var.first_b = 0;
	var.last_b = 0;
	ft_verif_arg(argc);
	if (ft_init_tab_func(&var.tab_func) || ft_init_pile_a(&pile_a, argv))
		return (1);
	var.first_a = pile_a;
	var.last_a = ft_listlast(pile_a);
	ft_affiche(&var);
	while ((var.ret = get_next_line(0, &var.buf)))
	{
		ft_verif_command(var.buf, var.tab_func);
		ft_exec_command(&var, var.tab_func, var.buf);
		ft_bzero(var.buf, var.ret);
		ft_affiche(&var);
	}
	ft_verif_tri(&var);
	return (0);
}
