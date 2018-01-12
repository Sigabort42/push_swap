/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_stock2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:22:39 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/12 05:21:24 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_flags_stock2_5(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if (var->type == TYPE_ADDRESS)
		var->k = s_flags->largeur - var->len_str_hexa - 2;
	else if (s_flags->precision < var->len_str_hexa && var->res_strcmp)
		var->k = s_flags->largeur - var->len_str_hexa;
	else if ((s_flags->largeur >= s_flags->precision + var->len_str_hexa &&
			var->res_strcmp && var->type != TYPE_BITWISE) ||
			s_flags->precision >= var->len_str_hexa)
		var->k = s_flags->largeur - s_flags->precision - var->len_str_hexa;
	else
		var->k = s_flags->largeur - s_flags->precision;
	(var->k < 0) ? var->k = 0 : 0;
	ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', var->i_buf_tmp += var->k);
	(var->type == TYPE_ADDRESS) ?
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0x", var->i_buf_tmp += 2) : 0;
	if (!(!var->res_strcmp && s_flags->m == 0))
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa,
				var->i_buf_tmp += var->len_str_hexa);
	else if (var->type == TYPE_ADDRESS && !var->res_strcmp)
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa,
				var->i_buf_tmp += var->len_str_hexa);
	(var->type == TYPE_ADDRESS) ?
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp,
				var->i_buf_tmp) : ft_memcpy(&var->buf[var->i_buf], var->buf_tmp,
											var->i_buf_tmp + var->len_str_hexa);
	var->i_buf += var->i_buf_tmp;
}

void	ft_flags_stock2_4(t_var *var, t_flags *s_flags, char *str_hexa)
{
	var->i_moins = ft_stock_moins(var, str_hexa);
	var->i_plus = ft_stock_plus(var, s_flags, str_hexa);
	if (s_flags->c & (1 << 3) && (var->type == TYPE_SHORT ||
								var->type == TYPE_INT))
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], " ", var->i_buf_tmp += 1);
	var->k = (var->len_str_hexa) ? s_flags->largeur - s_flags->precision -
	var->len_str_hexa - ft_stock_buf_base(var, s_flags, var->res_strcmp,
	var->len_str_hexa) - var->i_plus : s_flags->largeur - s_flags->precision;
	if (var->type == TYPE_BITWISE)
		var->k = s_flags->largeur - var->len_str_hexa;
	ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', var->k);
	var->i_buf_tmp += var->k;
	ft_memcpy(&var->buf_tmp[var->i_buf_tmp], &str_hexa[var->i_moins],
			var->len_str_hexa);
	var->i_buf_tmp += var->len_str_hexa;
	ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp +
			var->len_str_hexa);
	var->i_buf += s_flags->largeur;
}

void	ft_flags_stock2_2(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if (s_flags->largeur < var->len_str_hexa)
		var->i_moins = ft_stock_moins(var, str_hexa);
	if (str_hexa[0] == '-')
		var->i_moins = 1;
	var->i_plus = (s_flags->c & (1 << 1)) ? 1 : 0;
	var->k = ((var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) &&
			var->len_str_hexa) ? s_flags->largeur - s_flags->precision :
		s_flags->largeur - s_flags->precision - var->i_moins - var->i_plus;
	ft_memset(&var->buf_tmp[0], ' ', var->k);
	var->i_buf_tmp += var->k;
	if (!(s_flags->largeur < var->len_str_hexa))
		var->i_moins = ft_stock_moins(var, str_hexa);
	ft_stock_plus(var, s_flags, str_hexa);
	ft_stock_buf_base(var, s_flags, var->res_strcmp, var->len_str_hexa);
	var->k = s_flags->precision - var->len_str_hexa + var->i_moins;
	ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', var->k);
	var->i_buf_tmp += var->k;
	ft_memcpy(&var->buf_tmp[var->i_buf_tmp], &str_hexa[var->i_moins],
			var->len_str_hexa);
	var->i_buf_tmp += var->len_str_hexa;
	ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp +
			var->len_str_hexa);
	var->i_buf += s_flags->largeur;
	(!var->len_str_hexa && (var->type >= TYPE_OCTAL && var->type <=
		TYPE_HEXA_MAJ)) ? ft_memcpy(&var->buf[var->i_buf - 1], "0", 1) : 0;
}

void	ft_flags_stock2_21(t_var *var, t_flags *s_flags, char *str_hexa)
{
	var->i_plus = ft_stock_plus(var, s_flags, str_hexa);
	var->k = s_flags->precision - var->len_str_hexa;
	ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', var->k);
	var->i_buf_tmp += var->k;
	ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa,
			var->len_str_hexa);
	var->i_buf_tmp += var->len_str_hexa;
	var->k = ((var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) &&
			var->len_str_hexa) ? s_flags->largeur - s_flags->precision
		- 2 : s_flags->largeur - s_flags->precision;
	ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', var->k);
	var->i_buf_tmp += var->k;
	(!var->len_str_hexa && !s_flags->precision && (var->type >=
							TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ)) ?
		ft_memcpy(&var->buf[var->i_buf++], "0", 1) : 0;
	ft_memcpy(&var->buf[var->i_buf], var->buf_tmp,
			var->i_buf_tmp + var->len_str_hexa);
	var->i_buf = s_flags->largeur;
}

void	ft_flags_stock2_1(t_var *var, t_flags *s_flags, char *str_hexa)
{
	var->i_moins = ft_stock_moins(var, str_hexa);
	ft_stock_buf_base(var, s_flags, var->res_strcmp, var->len_str_hexa);
	var->k = s_flags->precision - var->len_str_hexa + var->i_moins;
	ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', var->k);
	var->i_buf_tmp += var->k;
	ft_memcpy(&var->buf_tmp[var->i_buf_tmp], &str_hexa[var->i_moins],
			var->len_str_hexa);
	ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp +
			var->len_str_hexa);
	var->i_buf += var->i_buf_tmp + var->len_str_hexa - var->i_moins;
	(!var->len_str_hexa && !s_flags->precision && (var->type >= TYPE_OCTAL
										&& var->type <= TYPE_HEXA_MAJ)) ?
		ft_memcpy(&var->buf[var->i_buf++], "0", 1) : 0;
}
