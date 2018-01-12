/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:19:03 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/12 18:42:51 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_var	var;
	if (argc < 2)
	{
		write(1, "usage : ./checker $ARG [-cv]\n", 28);
		return (0);
	}
	var.buf = ft_strnew(10);
	while ((var.ret = read(0, var.buf, 10)))
	{
		ft_putstr(var.buf);
		ft_putstr("\n");
		ft_bzero(var.buf, 10);
	}
}
