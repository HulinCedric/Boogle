//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction statistique
//				   
//		But de cette fonction  :  Affichage du nom, du prénom et du score d'une partie
//								  							  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//

#include "boogle.h"

void statistiques()
{
	FILE*fichier;																// variable de type fichier pour le fichier contenant les statistiques
	char caracterelu;															// variable pour la lecture caractere par caractere
	int nombre_de_parties=0;													// variable contenant le nombre de joueurs

	fichier = fopen("enregitrement.txt","rt");									// Ouverture du fichier "enregistrement.txt" en mode lecture texte

	if(fichier != NULL)															// Si le fichier éxiste
	{																			//
		while( (caracterelu = fgetc(fichier)) != EOF)							// Tant qu'on arrive pas é la fin du fichier
		{																		//
			printf("%c",caracterelu);											// On affiche caractere par caractere le contenu du fichier
																				//
			if(caracterelu == '\n')												// Si le caractere lu est "\n" (retour é la ligne)																	//
				nombre_de_parties++;											// On incrémente le nombre de joueurs
		}																		//
		printf("\n\n\n\n \t\t\t\tNombre de parties jouees : %d\n\n\t\t\t      ",nombre_de_parties);
	}																			//

	else																		// Si le fichier n'éxiste pas
	{																			// 
		erreur();																// Appel de la fonction erreur
	}																			//

	fclose(fichier);															// On ferme le fichier ouvert

	SystemPause();
	SystemCLS();

}