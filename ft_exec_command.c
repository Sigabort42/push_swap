/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:19:56 by elbenkri          #+#    #+#             */
/*   Updated: 2018/07/21 21:19:56 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_command(t_vari *var, t_tab *tab_func, char *command)
{
	int	i;

	i = 0;
	while (tab_func[i].command)
	{
		if (!ft_strcmp(command, tab_func[i].command))
		{
			tab_func[i].f(var);
			return ;
		}
		i++;
	}
}
