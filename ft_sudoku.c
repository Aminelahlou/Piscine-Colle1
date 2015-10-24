#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void affichage (int grille[9][9])
{
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            printf( ((j+1)%3) ? "%d " : "%d|", grille[i][j]); // attention pas le droit à printf
        }
        putchar('\n'); // remplacer putchar par ft_putchar ou write
        if (!((i+1)%3))
            puts("------------------");
    }
    puts("\n\n");
}

bool absentSurLigne (int k, int grille[9][9], int i)
{
    for (int j=0; j < 9; j++) //Attention faut chqnger le for par un while
        if (grille[i][j] == k)
            return false;
    return true;
}

bool absentSurColonne (int k, int grille[9][9], int j)
{
    for (int i=0; i < 9; i++) //chqnger le for par un while
        if (grille[i][j] == k)
            return false;
    return true;
}

bool absentSurBloc (int k, int grille[9][9], int i, int j) // k etant la valeur de grille[i][j] sur la grille[9][9]
{
    int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
    for (i=_i; i < _i+3; i++) // remplacer for par while
        for (j=_j; j < _j+3; j++) // remplacer for par while
            if (grille[i][j] == k)
                return false;
    return true;
}

	}
}

bool estValide (int grille[9][9], int position)
{
    // Si on est à la 82e case (on sort du tableau)
    if (position == 9*9)
        return true;

    // On récupère les coordonnées de la case
    int i = position/9, j = position%9;

    // Si la case n'est pas vide, on passe à la suivante (appel récursif)
    if (grille[i][j] != 0)
        return estValide(grille, position+1);

    // A implémenter : backtracking

// énumération des valeurs possibles
    for (int k=1; k <= 9; k++)
    {
        // Si la valeur est absente, donc autorisée
        if (absentSurLigne(k,grille,i) && absentSurColonne(k,grille,j) && absentSurBloc(k,grille,i,j))
        {
            // On enregistre k dans la grille
            grille[i][j] = k;
            // On appelle récursivement la fonction estValide(), pour voir si ce choix est bon par la suite
            if ( estValide (grille, position+1) )
                return true;  // Si le choix est bon, plus la peine de continuer, on renvoie true :)
        }
    }
    // Tous les chiffres ont été testés, aucun n'est bon, on réinitialise la case
    grille[i][j] = 0;
    // Puis on retourne false :(
    return false;
}
int main(int argc, char **argv)
{
	if (argc != 10)
	{
		printf("Erreur");
	}
	else 
	{
		char **grille;
		int i;
		int j;

		i = 0;
		j = 0;
		while (i < 9)
		{
			while (j < 9)
			{
				grille[i][j] = argv[i - 1][j - 1];
				j++;
			}
		i++;
		}		
		
		affichage(grille);
		estvalide(grille);
		affichage(grille);
		//copier les données entrées dans le tableau entrée
		//verifier s'il y a des erreurs dans la variable entree avec la fonction ft_verif
		//completer le sudoku et lancer une fonction de vérification
		//si erreur revenir en arrière : notion de backtracking : https://openclassrooms.com/courses/le-backtracking-par-l-exemple-resoudre-un-sudoku
		//puis recompleter
}
