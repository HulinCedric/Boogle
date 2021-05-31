//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction strupr
//
//		But de cette fonction  :  Portabilité Macintosh							  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//

#include "boogle.h"

void strupr(char chaine[7])
{
	int i;

	for(i=0; i<strlen(chaine);i++)
	{
		if (chaine[i]<='z' && chaine[i]>='a')
		{
			chaine[i]+='A'-'a';
		}
	}
}