//###########################################################
// Cr�e par : CADET Gauthier           le : 09/12/2019      #
// syst�me : Windows 10, codeblock                          #
//                                                          #
// Titre : lire un entier born�        Version : 5          #
// Derni�re modification le : 08/01/2019                    #
//###########################################################

#include "header.h"

int		lire_entier(int b_inf, int b_sup){
	int	n;

	do{
		scanf("%i", &n);
	}while (n < b_inf || n > b_sup);

	return (n);
}
