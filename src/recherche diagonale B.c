//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Recherche
//				   
//		But de cette fonction  :  Fonction de recherche en diagonal de haut droit a bas gauche
//								  Fonction de recherche en diagonal de bas gauche a haut droit								  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//						  

#include "boogle.h"

// recherche en diagonal de haut droit a bas gauche
bool Diago1_a(char leTab[8][8],char * Mot,int i,int j,int lenght)
{
	int p=0;
	int temp=0;

	while(leTab[i][j]!='&')  
	{
		if (leTab[i][j]==Mot[p])
		{
			temp++;
		}
		j--;
		i++;
		p++;
	}

	// Si le mot est bien trouve
	//
	if(temp==lenght) return true;
	return false;
}

// recherche en diagonal de bas gauche a haut droit
bool Diago1_b(char leTab[8][8],char * Mot,int i,int j,int lenght)
{
	int p=0;
	int temp=0;
	
	while(leTab[i][j]!='&')  
	{
		if (leTab[i][j]==Mot[p])
		{
			temp++;
		}
		j++;
		i--;
		p++;
	}

	// Si le mot est bien trouve
	//
	if(temp==lenght) return true;
	return false;
}