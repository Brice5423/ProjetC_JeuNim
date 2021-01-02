//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : coup joueur                 Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"


T_Case	coup_joueur(char **tableau, T_Case pion, T_Tab_Case case_b, int nlig, int ncol, int **nimber)
{
	int	j;
	int	choix;
	T_Tab_Case casedeux;

	j = 0;
	casedeux = case_voisine(nimber, nlig, ncol, pion.abs, pion.ord);

	printf("A toi de jouer !\nChoisir la destination ");
	while (j < casedeux.n)
	{
		printf("%i: (%i,%i) ",(j + 1) ,casedeux.tab[j].abs ,casedeux.tab[j].ord);
		j++;
	}
	printf("\n");
	choix = lire_entier(1, casedeux.n);

	tableau[pion.abs][pion.ord] = '.';

	tableau[casedeux.tab[choix - 1].abs][casedeux.tab[choix - 1].ord] = '0';

	pion.abs = casedeux.tab[choix - 1].abs;
	pion.ord = casedeux.tab[choix - 1].ord;

	return (pion);
}
