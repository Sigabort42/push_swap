#include "push_swap.h"

void	ft_list_pushback(t_lst **alst, t_lst *new)
{
	t_lst	*tmp;

	if (!(*alst))
	{
		if (!(*alst = (t_lst*)malloc(sizeof(t_lst))))
			exit(EXIT_FAILURE);
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_lst	*ft_listnew(int nb)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void		ft_init_pile_a(t_lst **pile_a, char **av)
{
	int	i;
	int	j;
	char	**tab_nb;

	i = 1;
	j = 0;
	*pile_a = 0;
	while (av[i])
	{
		tab_nb = ft_strsplit(av[i], ' ');
		while (tab_nb[j] && ft_isdigit(tab_nb[j][0]))
			ft_list_pushback(pile_a, ft_listnew(ft_atoi(tab_nb[j++])));
		if (tab_nb[j] && !ft_isdigit(tab_nb[j][0]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j = 0;
		i++;
	}
}
