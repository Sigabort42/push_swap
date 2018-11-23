/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pile_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:25:25 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 02:26:37 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_init_pile_a(t_lst **pile_a, char **av)
{
	int			i;
	int			j;
	char		**tab_nb;
	long long	nb;

	i = 1;
	j = 0;
	*pile_a = 0;
	while (av[i])
	{
		if (!(tab_nb = ft_strsplit(av[i], ' ')))
			return (1);
		while (tab_nb[j] && ft_isdigit(tab_nb[j][0]))
		{
			nb = ft_altoi(tab_nb[j++]);
			if (nb < -2147483648 || nb > 2147483647 ||
			ft_listadd(pile_a, ft_listnew(nb)))
			{
				write(1, "Error\n", 6);
				ft_free_tab(tab_nb);
				return (1);
			}
		}
		if (ft_verif_list(*pile_a) || (tab_nb[j] && !ft_isdigit(tab_nb[j][0])))
		{
			write(1, "Error\n", 6);
			ft_free_tab(tab_nb);
			return (1);
		}
		j = 0;
		i++;
		ft_free_tab(tab_nb);
	}
	return (0);
}
