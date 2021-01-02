//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : renseigner paramètres       Version : 5          #
// Dernière modification le : 08/01/2019                    #
//###########################################################

#include "header.h"

void parametres(int *nlig, int *ncol, int *niveau, int *next, int *nban){

    // saisie du nombre de lignes
        printf("Veuillez saisir le nombre de lignes :\n");
        *nlig = lire_entier(VMIN, VMAX);

    // saisie du nombre de colonnes
        printf("Veuillez saisir le nombre de colonnes :\n");
        *ncol = lire_entier(VMIN, VMAX);

    // saisie du niveau de difficulté
         printf("Veuillez saisir le niveau (1 a 4) :\n");
         *niveau = lire_entier(1, 4);
    // saisie de l'ordre de jeu
         printf("Veuillez saisir qui commence (1 : ordinateur, 2 : joueur) :\n");
         *next = lire_entier(1, 2);

    //le nombre de cases bannies et un entier compris entre 0 et le maximum entre les lignes et les colonnes
        srand(time(NULL));
        *nban = (int) (rand() % max(*nlig, *ncol));
}
