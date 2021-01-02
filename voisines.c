//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : calcul voisines             Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"

T_Tab_Case	case_voisine(int **nimber, int nlig, int ncol, int x, int y){
	T_Tab_Case voisins;
	int	j;

	voisins.tab = (T_Case*)malloc(sizeof(T_Case) * 4);
	voisins.n = 0;
	j = 0;
	if (x + 1 <= nlig && y <= ncol && nimber[x + 1][y] != -1 )
	{
		voisins.tab[j].abs = x + 1;
		voisins.tab[j].ord = y;
		j++;
		if (x + 2 <= nlig && y <= ncol && nimber[x + 2][y] != -1)
		{
			voisins.tab[j].abs = x + 2;
			voisins.tab[j].ord = y;/* condition */
			j++;
		}
	}
	if (x <= nlig && y + 1 <= ncol && nimber[x][y + 1] != -1 )
	{
		voisins.tab[j].abs = x;
		voisins.tab[j].ord = y + 1;
		j++;
		if (x <= nlig && y + 2 <= ncol && nimber[x][y + 2] != -1)
		{
			voisins.tab[j].abs = x;
			voisins.tab[j].ord = y + 2;
			j++;
		}
	}
	voisins.n = j;
	return (voisins);
}
