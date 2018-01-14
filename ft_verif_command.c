/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:37:35 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/13 17:40:48 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_verif_command(char *command, t_tab *tab_func)
{
	int	i;

	i = 0;
	while (tab_func[i].command && ft_strcmp(command, tab_func[i].command))
		i++;
	if (!tab_func[i].command)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
