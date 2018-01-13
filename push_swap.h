/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:18:07 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/13 18:43:41 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"
#include <stdio.h>

# define SA "sa"//swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucu
# define SB "sb"//swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucu
# define SS "ss" //sa et sb en même temps
# define PA "pa"//push a - prend le premier élément au sommet de b et le met sur a. Ne fa rien si b est vide.
# define PB "pb"//push b - prend le premier élément au sommet de a et le met sur b. Ne fa rien si a est vide.
# define RA "ra"// rotate a - décale d’une position vers le haut tous les élements de la pile  Le premier élément devient le dernier.
# define RB "rb"// rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dern
# define RR "rr"// ra et rb en même temps
# define RRA "rra"//reverse rotate a - décale d’une position vers le bas tous les élements  la pile a. Le dernier élément devient le premie
# define RRB "rrb"//reverse rotate b - décale d’une position vers le bas tous les élements  la pile b. Le dernier élément devient le premie
# define RRR "rrr"// rra et rrb en même temps

typedef struct	s_vari
{
	int			ret;
	int			*pile_a;
	int			*pile_b;
	char		*buf;
}				t_vari;

typedef struct	s_tab
{
	char		*command;
	void		(*f)(int *, int *);
}				t_tab;

void	ft_init_tab_func(t_tab *tab);
void	ft_func(int *tab, int *tab2);

#endif
