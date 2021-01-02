//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : coup ordi gagnant         Version : 5          #
// Dernière modification le : 11/01/2019                    #
//###########################################################

#include "header.h"



T_Case coup_ordi_gagnant(char **tableau, T_Case pion, T_Tab_Case case_b, int nlig, int ncol, int **nimber){

    T_Tab_Case voisins; // tous les voisins
    T_Tab_Case voisins_Nz; // vosins dont le nimber est 0

    int i;
    int a;
    i = 0;

    voisins_Nz.n = 0;

    voisins = case_voisine(nimber, nlig, ncol, pion.abs, pion.ord);
    voisins_Nz.tab = (T_Case*)malloc(sizeof(T_Case) * 2);

    while (i < voisins.n){
        if (nimber[voisins.tab[i].abs][voisins.tab[i].ord == 0]){
            voisins_Nz.tab[voisins.n] = voisins.tab[i];
            voisins.n++;
        }
        i++;
    }

    if (voisins.n != 0){
        a = rand() % voisins.n;
        tableau[pion.abs][pion.ord] = '.';
        pion.abs = voisins.tab[a].abs;
        pion.ord = voisins.tab[a].ord;
    }
    else {
        a = rand() % voisins.n;
        tableau[pion.abs][pion.ord] = '.';
        pion.abs = voisins_Nz.tab[a].abs;
        pion.ord = voisins_Nz.tab[a].ord;
    }

    printf("L'ordinateur deplace le pion en ");
    printf("(%i, %i)\n",pion.abs , pion.ord);
    tableau[pion.abs][pion.ord] = '0';
    return (pion);

}
