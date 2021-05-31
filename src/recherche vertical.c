//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Recherche
//				   
//		But de cette fonction  :  Fonction de recherche en vertical du bas vers le haut 
//								  Fonction de recherche en vertical du haut vers le bas								  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
				  


#include "boogle.h"

// recherche en vertical du bas vers le haut
bool vertical_a(char leTab[8][8],char * Mot,int i,int j,int lenght)
{
	int p=0;
	int temp=0;

	while(leTab[i][j]!='&')  
	{
		if (leTab[i][j]==Mot[p])
		{
			temp++;
		}
		i--;
		p++;
		
	}

	// Si le mot est bien trouve
	//
	if(temp==lenght) return true;
	return false;
}

// recherche en vertical du haut vers le bas
bool vertical_b(char leTab[8][8],char * Mot,int i,int j,int lenght)
{
	int p=0;
	int temp=0;

	while(leTab[i][j]!='&')  
	{
		if (leTab[i][j]==Mot[p])
		{
			temp++;
		}
		i++;
		p++;
		
	}

	// Si le mot est bien trouve
	//
	if(temp==lenght) return true;
	return false;
}