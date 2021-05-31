//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Accueil
//				   
//		But de cette fonction  :  Gestion d'un choix non valide ou d'un fichier inexistant.
//							  
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
						  
#include "boogle.h"

void erreur()
{
	SystemCLS();		
	printf("\n\n\t     -- ERREUR LE CHOIX/FICHIER SELECTIONNE N'EXISTE PAS --\n\n\t\t  -- VOUS ALLEZ ETRE REDIRIGE VERS L'ACCUEIL --\n\n\t\t    ");
	SystemPause();
	SystemCLS();
	main();				
}