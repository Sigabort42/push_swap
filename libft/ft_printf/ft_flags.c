/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:47:50 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/12 05:54:48 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_verif_modificateur(char *mod, t_flags *s_flags)
{
	s_flags->m = 0;
	if (!ft_strcmp(mod, "hh"))
		s_flags->m = s_flags->m | (1 << 0);
	if (!ft_strcmp(mod, "h"))
		s_flags->m = s_flags->m | (1 << 1);
	if (!ft_strcmp(mod, "l"))
		s_flags->m = s_flags->m | (1 << 2);
	if (!ft_strcmp(mod, "ll"))
		s_flags->m = s_flags->m | (1 << 3);
	if (!ft_strcmp(mod, "j"))
		s_flags->m = s_flags->m | (1 << 4);
	if (!ft_strcmp(mod, "z"))
		s_flags->m = s_flags->m | (1 << 5);
}

static int			ft_verif_mod(char c)
{
	if (c == 'h')
		return (0);
	if (c == 'l')
		return (0);
	if (c == 'j')
		return (0);
	if (c == 'z')
		return (0);
	return (1);
}

static void			ft_flags2(char *flags, t_flags *s_flags, int *i)
{
	int				u;

	s_flags->largeur = ft_atoi(&flags[*i]);
	*i += (flags[*i] >= '0' && flags[*i] <= '9') ?
		ft_is_number(ft_atoi(&flags[*i])) : 0;
	s_flags->precision = (flags[*i] == '.') ? ft_atoi(&flags[*i + 1]) : 0;
	u = ft_is_number(ft_atoi(&flags[*i + 1]));
	*i += (flags[*i] == '.') ? u : 0;
	(flags[*i - u] == '.') ? ft_verif_modificateur(&flags[*i + 1], s_flags) :
		ft_verif_modificateur(&flags[*i], s_flags);
}

int					ft_flags(char *flags, t_flags *s_flags)
{
	int				i;

	i = 0;
	if (flags[0] == 0)
		return (0);
	s_flags->c = 0;
	while (flags[i] && (!(flags[i] >= '1' && flags[i] <= '9')) &&
	flags[i] != '.' && ft_verif_mod(flags[i]))
	{
		if (flags[i] == '0')
			s_flags->c = s_flags->c | (1 << 0);
		if (flags[i] == '+')
			s_flags->c = s_flags->c | (1 << 1);
		if (flags[i] == '-')
			s_flags->c = s_flags->c | (1 << 2);
		if (flags[i] == ' ')
			s_flags->c = s_flags->c | (1 << 3);
		if (flags[i] == '#')
			s_flags->c = s_flags->c | (1 << 4);
		i++;
	}
	ft_flags2(flags, s_flags, &i);
	return (1);
}
