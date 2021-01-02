//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : jeu a boucler               Version : 5          #
// Dernière modification le : 15/01/2019                    #
//###########################################################

#include "header.h"

int jeu(char **tableau, int nlig, int ncol, T_Tab_Case case_b, int niveau, int next){
    int indice_tour;
    int compt_tour = 1;
    int proba;
		int	**tab_strat;
	T_Case	pion;

	indice_tour = next;

	tab_strat = calcul_nimbers(ncol, nlig, case_b);
	pion.abs = 1;
	pion.ord = 1;
	tableau[pion.abs][pion.ord] = '0';

  affichage(tableau);
    // Boucle du jeu qui s'effectue tant que le pion n'est pas arrivé sur la case du puit
   while (pion.abs != ncol || pion.ord != nlig)
   {


      /* on génère un entier de manière aléatoire a chaque tour qui servira pour la probabilité du coup gagnant
      donc si il y 1/3 de chance que l'ordi joue aléatoirement ou gagnant selon la difficulté on vérifie si proba = 2 par exemple*/
      proba = rand() % 3;

      if (indice_tour == 2) {
        pion = coup_joueur(tableau, pion, case_b, nlig, ncol, tab_strat);
        indice_tour = 1;
      }
     	else if (indice_tour == 1){
          switch (niveau){
              case 1:// niveau débutant
                  pion = coup_ordi_hasard(tableau, pion, case_b, nlig, ncol, tab_strat);
                  break;
              case 2:// niveau intermédiaire
                  // =2 pour le 1/3 de coups gagnants
                  if (proba == 2)
                      pion = coup_ordi_gagnant(tableau, pion, case_b, nlig, ncol, tab_strat);
                  else
                      pion = coup_ordi_hasard(tableau, pion, case_b, nlig, ncol, tab_strat);
                  break;
              case 3:// niveau expert
                  // =2 pour le 1/3 de coups hasards
                  if (proba == 2)
                      pion = coup_ordi_hasard(tableau, pion, case_b, nlig, ncol, tab_strat);
                  else
                      pion = coup_ordi_gagnant(tableau, pion, case_b, nlig, ncol, tab_strat);
                  break;
              case 4:// niveau virtuose
                  pion = coup_ordi_gagnant(tableau, pion, case_b, nlig, ncol, tab_strat);
                  break;
          }
        indice_tour = 2;
      }

     affichage(tableau);
      compt_tour++;
   } //fin while

 		if (indice_tour == 1)
	     printf("\nLe joueur a gagne\n");
    else
      printf("\nL'IA a gagne\n");

   return (compt_tour);
}
