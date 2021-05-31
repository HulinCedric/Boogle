//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Voyelles
//				   
//		But de cette fonction  :  Remplie la matrice avec des voyelles 
//								  								  
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//

#include "Boogle.h"


int nbreVoyelles(char unTab[8][8])
{
	int i,j,k,leNbreVoyelles=0;
	char leTabVoyelle[6]={'A','E','I','O','U','Y'};

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<6;k++)
			{
				if(unTab[i][j] == leTabVoyelle[k])
					leNbreVoyelles ++;
		
			}
		}
	}

	return leNbreVoyelles;
}



void verifVoyelles(char unTab[8][8])
{
	char leTabVoyelle[6]={'A','E','I','O','U','E'}; //sans le Y et avec plus de E
	char leTabConsonne[20]={'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z'};
	srand (time (NULL));


		while(nbreVoyelles(unTab) != 12) 
		//while(nbreVoyelles(uneMat) != nbreVoyelles(uneMat)) //ne modifie pas la matrice
		{

			if(nbreVoyelles(unTab) > 12)
				unTab[1+rand()%6][1+rand()%6] = leTabConsonne[rand()%20];
			else
				unTab[1+rand()%6][1+rand()%6] = leTabVoyelle[rand()%6];
		}
}