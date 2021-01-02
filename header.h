//###########################################################
// Crée par : CADET Gauthier           le : 09/12/2019      #
// système : Windows 10, codeblock                          #
//                                                          #
// Titre : librairie pour toutes nos fonctions               #
// Dernière modification le : 08/01/2019                    #
//###########################################################


#ifndef HEADER_H
# define HEADER_H	/*Si non existant*/

# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define VMIN 5
# define VMAX 30


# define bool int
# define TRUE 1
# define FALSE 0

typedef	struct T_Case{
	int	abs;
	int	ord;
} T_Case;

typedef	struct T_Tab_Case{
	struct T_Case *tab;
	int	n;
}T_Tab_Case;

/*principales fonctions*/


int	lire_entier(int b_inf, int b_sup);

void parametres(int *nlig, int *ncol, int *niveau, int *next, int *nban);

int	max(int a, int b);

struct T_Tab_Case hasard_ban(int nban, int nlig, int ncol);

void affichage(char **grille);

int jeu(char **tableau, int nlig, int ncol, T_Tab_Case case_ban, int niveau, int next);

T_Tab_Case hasard_ban(int nban, int nlig, int ncol); /*type T_Tab_Case*/

void affichage(char **grille);

T_Tab_Case case_voisine(int **nimber, int nlig, int ncol, int x, int y);

int	**calcul_nimbers(int ncol, int nlig, T_Tab_Case case_ban);

T_Case coup_joueur(char **tableau, T_Case pion, T_Tab_Case case_b, int nlig, int ncol, int **nimber);

T_Case coup_ordi_hasard(char **tableau, T_Case pion, T_Tab_Case case_b, int nlig, int ncol, int **nimber);

T_Case coup_ordi_gagnant(char **tableau, T_Case pion, T_Tab_Case case_b, int nlig, int ncol, int **nimber);


#endif
