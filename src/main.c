//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Programme principal
//				   
//		But de cette fonction  :  1) Appel de la fonction "accueil" --> choix dans le menu 
//								  2) Appel de la fonction voulu
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//

#include "boogle.h"

void main()
{
	int lechoix;												// variable pour la saisie du choix dans le menu accueil

	do															// Boucle tant que le joueur ne décide pas de quitter
	{															//
		accueil(&lechoix);										// Appel de la fonction accueil et demande du choix dans le menu
		SystemCLS();											// Efface l'écran pour afficher la fonction voulu
																//
		if(lechoix==1)											// Si le choix du joueur = 1
			regle();											// Appel de la fonction régle (affichage des régles)
																//
		if(lechoix==2)											// Si le choix du joueur = 2
			jouer();											// Appel de la fonction permettant de jouer
																//
		if(lechoix==3)											// Si le choix du joueur = 2
			statistiques();										// Appel de la fonction statistiques
																//
		if((lechoix <1 || lechoix >3) && lechoix!=4)			// Si le choix ne fait pas partie du menu
			erreur();											// Appel de la fonction erreur
																//																
	}while(lechoix != 4);										// Sortie de boucle si le choix du joueur = 4

	SystemCLS();												// Efface lécran
	exit(1);													// Quitte le programme
}