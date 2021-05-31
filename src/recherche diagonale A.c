//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Recherche
//				   
//		But de cette fonction  :  Fonction de recherche en diagonal de haut gauche a bas droit
//								  Fonction de recherche en diagonal de as droit a haut gauche								  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
					  

#include "boogle.h"

// recherche en diagonal de Haut gauche a bas droit
bool Diago2_a(char leTab[8][8],char * Mot,int i,int j,int lenght)
{
	int p=0;
	int temp=0;

	while(leTab[i][j]!='&')									// Tant qu'on arrive pas au rebort de la grille
	{														//
		if (leTab[i][j]==Mot[p])							// Si la lettre de la grille correspond é celle du mot
		{													//
			temp++;											// On incrémente le temp
		}													//
		j++;												// On se déplace dans la grille
		i++;												// On se déplace dans la grille
		p++;												// On regarde le caractere suivant du mot
	}

	// Si le mot est bien trouve
	//
	if(temp==lenght) return true;
	return false;								
}

// recherche en diagonal de bas droit a haut gauche
bool Diago2_b(char leTab[8][8],char * Mot,int i,int j,int lenght)
{
	int p=0;
	int temp=0;

	while(leTab[i][j]!='&')									// Tant qu'on arrive pas au rebort de la grille  
	{														//
		if (leTab[i][j]==Mot[p])							// Si la lettre de la grille correspond é celle du mot
		{													//
			temp++;											// On incrémente le temp
		}													//
		j--;												// On se déplace dans la grille
		i--;												// On se déplace dans la grille
		p++;												// On regarde le caractere suivant du mot
	}

	// Si le mot est bien trouve
	//
	if(temp==lenght) return true;
	return false;													 
}



