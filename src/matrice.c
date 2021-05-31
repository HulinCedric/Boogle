//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Matrice
//				   
//		But de cette fonction  :  Genére une grille de jeu avec un nombre de voyelles imposé
//								  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//

	
#include "boogle.h"

char matrice(char unTab[][8])
{
	int i,j;										// variables de comptage

	srand(time(NULL));								// Permet de remplir notre matrice avec des caracteres aléatoire

	for(i=0;i<8;i++)								// On parcour la grille/matrice
	{												//
		for(j=0;j<8;j++)							//
		{											//
			unTab[i][j]='&';						// On rempli notre grille avec le caractere '&' 
		}											//
	}												//

	for(i=1;i<7;i++)								// Pn parcour l'interieur de notre grille
	{												//
		for(j=1;j<7;j++)							//
		{											//
			unTab[i][j]=rand()%26+65;				// On rempli la grille avec des caractéres aléatoire
		}											//
	}												//

	verifVoyelles(unTab);

	return **unTab;									// On renvoi notre grille/matrice
}