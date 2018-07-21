/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 23:35:20 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 23:35:46 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst			*ft_listnew(int nb)
{
	t_lst       *new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	new->nb = nb;
	new->next = 0;
	new->prev = 0;
	return (new);
}
