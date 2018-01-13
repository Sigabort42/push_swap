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

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_vari	var;
	t_tab	tab_func[12];

	if (argc < 2)
	{
		write(1, "usage : ./checker $ARG [-cv]\n", 28);
		return (0);
	}
	var.buf = ft_strnew(10);
	ft_init_tab_func(tab_func);
//	if (!tab_func)
//		return (1);
	while ((var.ret = read(0, var.buf, 10)))
	{
		ft_putstr(var.buf);
		ft_putstr("\n");
		ft_bzero(var.buf, 10);
	}
}
