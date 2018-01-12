/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:18:07 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/12 18:45:45 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"
#include <stdio.h>

# define SA //swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucu
# define SB //swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucu
# define SS //sa et sb en même temps
# define PA //push a - prend le premier élément au sommet de b et le met sur a. Ne fa rien si b est vide.

typedef struct	s_var
{
	int			ret;
	int			*pile_a;
	int			*pile_b;
	char		*buf;
}				t_var;
#endif
