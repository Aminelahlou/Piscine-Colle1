int main(int argc, char **argv)
{
	if (argc != 10)
	{
		ft_putstr("Erreur");
	}
	else 
	{
		char **entree;
		//copier les données entrées dans le tableau entrée
		//verifier s'il y a des erreurs dans la variable entree avec la fonction ft_verif
		//completer le sudoku et lancer une fonction de vérification
		//si erreur revenir en arrière : notion de backtracking : https://openclassrooms.com/courses/le-backtracking-par-l-exemple-resoudre-un-sudoku
		//puis recompleter
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
