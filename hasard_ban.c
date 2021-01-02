//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : génération case bannies     Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"

bool case_valide(T_Tab_Case t_ban, int x, int y, int nlig, int ncol)
{
	int j;

	j = 0;
	while (j < t_ban.n)
	{
		if (x == 1)
			return (FALSE);
		else if (y == 1)
			return (FALSE);
		else if (x == nlig)
			return (FALSE);
		else if (y == ncol)
			return (FALSE);
		else if (t_ban.tab[j].abs == x + 1 && t_ban.tab[j].ord == y - 1) /* test pour la case en bas a gauche */
			return (FALSE);
		else if (t_ban.tab[j].abs == x - 1 && t_ban.tab[j].ord == y + 1) /* test pour la case en haut a droite*/
			return (FALSE);
		else if (t_ban.tab[j].abs == x && t_ban.tab[j].ord == y)
			return (FALSE);
		j++;
	}
	if (j == 0)
	{
		if (x == 1)
			return (FALSE);
		else if (y == 1)
			return (FALSE);
		else if (x == nlig)
			return (FALSE);
		else if (y == ncol)
			return (FALSE);
	}
	return (TRUE); /* Ne s'execute que si les cases cherchées n'ont pas été trouvées */
}

T_Tab_Case	hasard_ban(int nban, int nlig, int ncol)
{
	int		c;
	int		x;
	int		y;
	int		i;
	bool	test;
	T_Tab_Case	t_ban;

	c = 0;
	t_ban.tab = (T_Case*)malloc(sizeof(T_Case) * nban);	/*le malloc accorde de la mémoire pour nban fois T_Tab_Case*/
	t_ban.n = 0;
	while (c < nban)
	{
		test = FALSE;
		i = 0;
		while (!test && i != 100)		/* Sécurité pour éviter la boucle infinie s'il n'y a plus de cases banissables */
		{
			x = (rand() % nlig) + 1;		/*Fleche car tab est un pointeur*/
			y = (rand() % ncol) + 1;
			test = case_valide(t_ban, x, y, nlig, ncol);
			i++;
		}
		if (test)
		{
			t_ban.tab[c].abs = x;
			t_ban.tab[c].ord = y;
			t_ban.n += 1;
		}
		c++;
	}
	return (t_ban);
}
