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

typedef	struct s_tab	t_tab;

typedef struct		s_lst
{
	int		nb;
	struct	s_lst	*next;
	struct	s_lst	*prev;
}			t_lst;

typedef struct		s_vari
{
	struct s_lst	*first_a;
	struct s_lst	*last_a;
	struct s_lst	*first_b;
	struct s_lst	*last_b;
	int		ret;
	char		*buf;
	t_tab		*tab_func;
}			t_vari;

struct		s_tab
{
	char		*command;
	void		(*f)(t_vari *);
};

void			ft_init_tab_func(t_tab **tab);
void			ft_func(t_vari *var);
void			ft_verif_command(char *command, t_tab *tab_func);
void			ft_init_pile_a(t_lst **pile_a, char **av);
void			ft_list_pushback(t_lst **alst, t_lst *new);
t_lst			*ft_listnew(int nb);
t_lst			*ft_listlast(t_lst *lst);
void			ft_swap_a(t_vari *var);
void			ft_swap_b(t_vari *var);
void			ft_swap_s(t_vari *var);
void			ft_push_a(t_vari *var);
void			ft_push_b(t_vari *var);
void			ft_rotate_a(t_vari *var);
void			ft_rotate_b(t_vari *var);
void			ft_rotate_r(t_vari *var);
void			ft_reverse_a(t_vari *var);
void			ft_reverse_b(t_vari *var);
void			ft_reverse_r(t_vari *var);
void			ft_exec_command(t_vari *var, t_tab *tab_func, char *command);
void			ft_verif_tri(t_vari *var);
long long		ft_altoi(const char *str);

#endif
