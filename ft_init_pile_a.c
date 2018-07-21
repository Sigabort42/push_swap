/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pile_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:19:36 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:19:37 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_list_pushback(t_lst **alst, t_lst *new)
{
	t_lst		*tmp;

	if (!(*alst))
	{
		if (!(*alst = (t_lst*)malloc(sizeof(t_lst))))
			return (1);
		*alst = new;
		return (0);
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (0);
}

static int		ft_listadd(t_lst **alst, t_lst *new)
{
	if (!new)
		return (1);
	if (!(*alst))
	{
		if (!(*alst = (t_lst*)malloc(sizeof(t_lst))))
		{
			free(new);
			return (1);
		}
		*alst = new;
		return (0);
	}
	(*alst)->prev = new;
	new->next = *alst;
	*alst = new;
	return (0);
}

t_lst			*ft_listnew(int nb)
{
	t_lst		*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	new->nb = nb;
	new->next = 0;
	new->prev = 0;
	return (new);
}

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

void		ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
}

int			ft_init_pile_a(t_lst **pile_a, char **av)
{
	int		i;
	int		j;
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
