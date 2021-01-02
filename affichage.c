//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : affichage                   Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"

void affichage(char **grille)/* pointeur sur pointeur sur char */
{
	int		i;
	int		c;

	i = 1;
	while (grille[i]){
		c = 1;
		if (i == 1){
			printf("  ");
			while (grille[i][c]){
				printf(" %.2i ", c);
				c++;
			}
			printf("\n");
		}
		c = 1;
		printf("%.2i", i);
		while (grille[i][c]){
			printf("| %c ", grille[i][c]);
			c++;
		}
		i++;
		printf("|\n");
	}
}
