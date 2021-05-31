//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction SystemPause
//				   
//		But de cette fonction  :  Portabilite Macintosh						  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//

#include "boogle.h"

void SystemPause()
{
	fpurge(stdin);
	printf("\nTapez sur entrer ...\n\n");
	getchar();
}