/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:22:08 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:22:09 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_verif_tri(t_vari *var)
{
	t_lst	*pile_a;

	pile_a = var->first_a;
	while (pile_a)
	{
		if (pile_a->next && !(pile_a->nb >= pile_a->next->nb))
		{
			write(1, "KO\n", 3);
			exit(EXIT_SUCCESS);
		}
		pile_a = pile_a->next;
	}
	if (var->first_b || var->last_b)
	{
		write(1, "KO\n", 3);
		exit(EXIT_SUCCESS);
	}
	write(1, "OK\n", 3);
}
