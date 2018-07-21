/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pile_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:19:36 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/22 00:05:00 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_verif_list(t_lst *pile_a)
{
	t_lst		*tmp;
	t_lst		*tmp2;

	if (!pile_a)
		return (1);
	tmp = pile_a;
	tmp2 = pile_a->next;
	while (tmp->next)
	{
		while (tmp2)
		{
			if (tmp->nb == tmp2->nb)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	return (0);
}

static void		ft_free_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}

static int		ft_range_pile(t_lst **pile_a, char **tab_nb, int *j)
{
	long long	nb;

	while (tab_nb[*j] && ft_isdigit(tab_nb[*j][0]))
	{
		nb = ft_altoi(tab_nb[*j]);
		*j = *j + 1;
		if (nb < -2147483648 || nb > 2147483647 ||
			ft_listadd(pile_a, ft_listnew(nb)))
		{
			write(1, "Error\n", 6);
			ft_free_tab(tab_nb);
			return (1);
		}
	}
	return (0);
}

int				ft_init_pile_a(t_lst **pile_a, char **av)
{
	int			i;
	int			j;
	char		**tab_nb;

	i = 1;
	j = 0;
	*pile_a = 0;
	while (av[i])
	{
		if (!(tab_nb = ft_strsplit(av[i], ' ')))
			return (1);
		if (ft_range_pile(pile_a, tab_nb, &j))
			return (1);
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
