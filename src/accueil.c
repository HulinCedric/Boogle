//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Accueil
//				   
//		But de cette fonction  :  Affichage du menu puis l'utilisateur entre son choix.
//								  Ce choix est passé en parametre pour etre éxploité dans le "MAIN".
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
					  
#include "boogle.h"

void accueil(int *lechoix)
{
	printf("\n\t\tJEU DU BOOGLE par FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cedric\n\n\n");

	printf("1) Regles du jeu\n");
	printf("2) Jouer\n");
	printf("3) Statistiques\n");
	printf("4) Quitter\n\n");

	printf("Votre choix dans le menu : ");

	scanf("%d", lechoix);
	fpurge(stdin);

}