/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:24 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/12 04:17:21 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags_stock5(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if ((s_flags->c & (1 << 4)))
	{
		var->k = s_flags->largeur - var->len_str_hexa -
			ft_stock_buf_base(var, s_flags, var->res_strcmp, var->len_str_hexa);
		ft_memset(&var->buf_tmp[0], ' ', var->k);
		var->i_buf_tmp = var->k;
		ft_stock_buf_base(var, s_flags, var->res_strcmp, var->len_str_hexa);
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, var->len_str_hexa);
		var->i_buf_tmp += var->len_str_hexa;
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp,
				var->i_buf_tmp + var->len_str_hexa);
		var->i_buf += s_flags->largeur;
	}
	else
		ft_flags_stock2_5(var, s_flags, str_hexa);
}

static void		ft_flags_stock4(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if ((s_flags->c & (1 << 2)))
	{
		var->i_stock_buf = ft_stock_buf_base(var, s_flags, var->res_strcmp,
											var->len_str_hexa);
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, var->len_str_hexa);
		var->i_buf_tmp += var->len_str_hexa;
		var->k = s_flags->largeur - s_flags->precision - var->len_str_hexa -
			var->i_stock_buf;
		if (var->k < 0)
			var->k = 0;
		if (var->type == TYPE_BITWISE)
			var->k = s_flags->largeur - var->len_str_hexa;
		ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', var->k);
		var->i_buf_tmp += var->k;
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp +
				var->len_str_hexa);
		var->i_buf += var->i_buf_tmp;
	}
	else if ((s_flags->c & (1 << 0)))
		ft_flags_stock2_4(var, s_flags, str_hexa);
	else
		ft_flags_stock5(var, s_flags, str_hexa);
}

static void		ft_flags_stock3(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if (s_flags->largeur < var->len_str_hexa)
	{
		var->i_plus = ft_stock_plus(var, s_flags, str_hexa);
		ft_stock_buf_base(var, s_flags, var->res_strcmp, var->len_str_hexa);
		if (!var->res_strcmp && var->len_str_hexa == 1 && s_flags->m == 0 &&
			s_flags->c <= 16)
		{
			if (var->type == TYPE_ADDRESS)
			{
				ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp);
				var->i_buf += var->i_buf_tmp;
			}
			if (s_flags->c == 8 && (var->type == TYPE_SHORT ||
									var->type == TYPE_INT))
				ft_memcpy(&var->buf[var->i_buf], " ", var->i_buf += 1);
			return ;
		}
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, var->i_buf_tmp +=
				var->len_str_hexa);
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp);
		var->i_buf += var->i_buf_tmp;
	}
	else if (s_flags->largeur >= s_flags->precision)
		ft_flags_stock4(var, s_flags, str_hexa);
}

static void		ft_flags_stock2(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if (s_flags->largeur > s_flags->precision && s_flags->precision >=
		var->len_str_hexa)
	{
		if ((s_flags->c & (1 << 2)))
			ft_flags_stock2_21(var, s_flags, str_hexa);
		else
			ft_flags_stock2_2(var, s_flags, str_hexa);
	}
	else
		ft_flags_stock3(var, s_flags, str_hexa);
}

void			ft_flags_stock(t_var *var, t_flags *s_flags, char *str_hexa)
{
	var->res_strcmp = ft_strcmp(str_hexa, "0");
	var->len_str_hexa = ft_strlen(str_hexa);
	var->i_buf_tmp = 0;
	var->i_moins = 0;
	if (s_flags->c == 8 && s_flags->m == 0 && !s_flags->largeur &&
		!s_flags->precision && (var->type == TYPE_SHORT ||
							var->type == TYPE_INT) && str_hexa[0] != '-')
		var->buf[var->i_buf++] = ' ';
	if (s_flags->precision >= s_flags->largeur && s_flags->precision >=
			var->len_str_hexa)
		ft_flags_stock2_1(var, s_flags, str_hexa);
	else
		ft_flags_stock2(var, s_flags, str_hexa);
	free(str_hexa);
}