//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Accueil
//				   
//		But de cette fonction  :  Ouvre un fichier .txt contenant un dictionnaire.
//								  Renvoi 1 si le mot est présent dans le dictionnaire.
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
		

#include "boogle.h"

int dico(char Mot[20])
{
	FILE*fichier=NULL;
	char lignelu[200];
	char motTampon[200];
	int i;

	fichier=fopen("Dico.txt","r");									// Ouvre Dico.txt en mode lecture

	if(fichier != NULL)												// Si Dico.txt existe alors
	{																//
		while(fgets(lignelu, 200, fichier) !=NULL)					// Tant qu'il y a des lignes
		{															//
			i=0;													//
																	//
			while (lignelu[i] != EOF)								// Tant qu'on est pas arrivé a la fin de la ligne
			{														//
				motTampon[i]=lignelu[i];							// On copie caractere par caractere la ligne dans un tampon
				if (motTampon[i] == '\r')							// Si le caractere est \r (nouvelle ligne) 
				{													//
					motTampon[i]='\0';								// On le remplace par \0 (caractere de fin de ligne)
					if (strcmp(Mot,motTampon)==0)					// Si le Mot entré par l'utilisateur est identique au mot de la ligne
					{												//
						rewind(fichier);							// Replace le curseur en début de fichier
						fclose(fichier);							// Ferme le fichier ouvert
						return true;								// la fonction retourne true
					}												//
				}													//
				i++;												// caractere par caractere
			}														//
		}															//
	}																//

	

	else															// Si Dico.txt n'éxiste pas
	{																//
		erreur();													// Appel de la fonction erreur
	}																//

	rewind(fichier);												// Replace le curseur en début de fichier
	fclose(fichier);												// Ferme le fichier ouvert
	return false;
}