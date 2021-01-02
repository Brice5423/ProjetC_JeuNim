//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : Projet Algo C main          Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################


#include "header.h"
#include "affichage.c"
#include "coup_joueur.c"
#include "coup_ordi_hasard.c"
#include "hasard_ban.c"
#include "jeu.c"
#include "lire_entier.c"
#include "max.c"
#include "parametres.c"
#include "voisines.c"
#include "calcul_nimbers.c"
#include "coup_ordi_gagnant.c"
#include <time.h>

int	main(){
	int	nlig, ncol, niveau, next, nban;
	T_Tab_Case case_b;
	char **grille;
	int	i, j, compt_tour;
	int **nb_nimbers;

	srand((unsigned int) time(NULL));

    //On demande les paramètres de la partie au joueur
	parametres(&nlig, &ncol, &niveau, &next, &nban);

	switch(niveau){
	    case 1:printf("\nniveau choisi : Debutant\n");break;
	    case 2:printf("\nniveau choisi : Intermediaire\n");break;
	    case 3:printf("\nniveau choisi : Expert\n");break;
	    case 4:printf("\nniveau choisi : Virtuose\n");break;
	    default: printf("\nniveau non défini\n");
	}
	//On génère les cases bannies
 	case_b = hasard_ban(nban, nlig, ncol);
	i = 0;

	//On alloue la mémoire suffisante pour créer notre tableau
	grille = (char**)malloc(sizeof(char*) * (nlig + 2));
	while (i < nlig + 1){
		j = 0;
		grille[i] = (char*)malloc(sizeof(char) * (ncol + 2));
		while (j < ncol + 1)
		{
			grille[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < case_b.n)
	{
		grille[case_b.tab[i].abs][case_b.tab[i].ord] = 'x'; /*les cases bannies sont représentées par des x */
		i++;
	}

	printf("\nla partie peut commencer !\n");

	nb_nimbers = calcul_nimbers(ncol, nlig, case_b);

	compt_tour = jeu(grille, nlig, ncol, case_b, niveau, next);

	printf("\nPartie terminee en %i de tours !\n\n\n", compt_tour);

    return 0;
}
