//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : coup ordi aléatoire         Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"


T_Case	coup_ordi_hasard(char **tableau, T_Case pion, T_Tab_Case case_b, int nlig, int ncol, int **nimber)
{
	int	choix;
	srand((unsigned int) time(NULL));
	T_Tab_Case	casedeux;

	casedeux = case_voisine(nimber, nlig, ncol, pion.abs, pion.ord);

	printf("\nL'ordinateur deplace le pion en ");
	choix = rand()%casedeux.n;
	printf("(%i, %i)\n",casedeux.tab[choix].abs ,casedeux.tab[choix].ord);

	tableau[pion.abs][pion.ord] = '.';

	tableau[casedeux.tab[choix].abs][casedeux.tab[choix].ord] = '0';

	pion.abs = casedeux.tab[choix].abs;
	pion.ord = casedeux.tab[choix].ord;

	return (pion);
}
