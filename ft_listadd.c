/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 23:38:22 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 23:39:00 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_listadd(t_lst **alst, t_lst *new)
{
	if (!new)
		return (1);
	if (!(*alst))
	{
		*alst = new;
		return (0);
	}
	(*alst)->prev = new;
	new->next = *alst;
	*alst = new;
	return (0);
}
