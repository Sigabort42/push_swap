#include <stdlib.h>
#include <stdio.h>

void	ft_affiche(int *tab, int taille)
{
	int	i;

	i = 0;
	while (i <= taille)
		printf("la=>>>|%i|\n", tab[i++]);
}

int	*ft_concat(int tab, int *tab2, int taille2)
{
	int	*tab_f;
	int	i;
	int	j;

	i = 1;
	j = 0;
	tab_f[0] = tab;
	while (i < taille2)
		tab_f[i++] = tab2[j++];
	return (tab_f);
}

int	*ft_insert(int *tab, int nb, int taille, int i)
{
	int	*tab2;

	printf("ici=>>>\n");
	ft_affiche(tab, taille + 1);
	printf("\n");
	if (!taille)
	{
		printf("lol\n");
		tab[0] = nb;
		tab[1] = 0;
		return (tab);
	}
	else if (tab[0] >= nb)
	{
		printf("lol2\n");
		tab[taille + 1] = 0;
		while (taille >= 0)
		{
			tab[taille + 1] = tab2[taille];
			taille--;
		}
		tab[0] = nb;
		return (tab);
	}
	else
	{
		printf("lol3\n");
		return (ft_concat(tab[0], ft_insert(&tab[i], nb, taille - 1, i + 1), taille - 1));
	}
}

int	main()
{
	int	tab[5];

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab = ft_insert(tab, 2, 0, 0);
	ft_affiche(tab, 1);
	printf("\n");
	tab = ft_insert(tab, 1, 1, 0);
	ft_affiche(tab, 2);
	printf("\n");
	tab = ft_insert(tab, 3, 2, 0);
	ft_affiche(tab, 3);
	printf("\n");
/*	tab = ft_insert(tab, 8, 3);
	ft_affiche(tab, 4);
	printf("\n");
	tab = ft_insert(tab, 7, 4);
	ft_affiche(tab, 5);
	printf("\n");
*/	return (0);
}
