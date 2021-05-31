//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction regle
//				   
//		But de cette fonction  :  Affichage des régles du jeu (fichier).
//								 						  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
			  

#include "boogle.h"

void regle()
{					
	char caracterelu;														// variable permettant la lecture caractere par caractere
	FILE*fichier;															// variable de type fichier pour ouvrir le fichier contenant les régles

	printf("\n\t\tJEU DU BOOGLE par FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cedric\n\n\n\n");
		
	fichier=fopen("regleboogle.txt","rt");									// On ouvre le fichier "regleboogle.txt" en mode lecture texte

	if(fichier != NULL)														// Si le fichier éxiste
	{																		//
		while((caracterelu=fgetc(fichier))!=EOF)							// Tant qu'on arrive pas a la fin du fichier
		{																	//
		printf("%c",caracterelu);											// On affiche caractere par caractere le conteu du fichier
		}																	//
	}																		//

	else																	// Si le fichier n'éxiste pas
	{																		//
		erreur();															// Appel de la fonction erreur
	}																		// 


	fclose(fichier);														// On ferme le fichier ouvert

	SystemPause();
	SystemCLS();
}