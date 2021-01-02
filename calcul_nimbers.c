//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : stratégie gagnante          Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"


int	**calcul_nimbers(int ncol, int nlig, T_Tab_Case case_ban)
{
	int	**nimber;
	int	i, c, j, sum;
	T_Tab_Case	caseun;

	nimber = (int**)malloc(sizeof(int*) * (nlig + 2));
	i = 0;
	while (i < nlig + 1)
	{
		c = 0;
		nimber[i] = (int*)malloc(sizeof(int) * (ncol + 2));
		while (c < ncol + 1)
		{
			nimber[i][c] = 0;
			c++;
		}
		i++;
	}
	i = 0;
	while (i < case_ban.n)
	{
		nimber[case_ban.tab[i].abs][case_ban.tab[i].ord] = -1;
		i++;
	}
	i = nlig;
	while (i > 0)
	{
		c = ncol;
		while (c > 0)
		{
			j = 0;
			sum = 0;
			caseun = case_voisine(nimber, nlig, ncol, i, c);
			while (j < caseun.n)
			{
				sum += nimber[caseun.tab[j].abs][caseun.tab[j].ord];
				j++;
			}
			if (nimber[i][c] != -1){
                if (sum == caseun.n)
                    nimber[i][c] = 0;
                else
                    nimber[i][c] = 1;
			}

			if (c == ncol && i == nlig)
				nimber[i][c] = 0;
			c--;
		}
		i--;
	}
	return (nimber);
}
