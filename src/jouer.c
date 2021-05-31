//
// IUT de Nice / Departement informatique / Projet tuteuré
// Annee 2008_2009 - 
//
// Projet Booble - Fonction Jouer
//				   
//		But de cette fonction  :  1) Enregistrement du joueur
//								  2) Demande de l'utilisation du dictionnaire
//								  3) Initialisation,remplissage et affichage de notre grille(matrice)
//								  4) Saisie du mot entré par l'utilisateur
//								  5) Recherche si le mot entré par l'utilisateur est présent dans la grille
//								  6) Comptage du nombre de mots trouvés
//
//
// Auteurs : FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//								   


#include "boogle.h"

void jouer()
{
	/*********************************************************************************************************************************/
	/*													DECLARATION DES VARIABLES													 */
	/*********************************************************************************************************************************/

	joueur unJoueur;								// variable de type "joueur" : Nom, Prenom, Score

	char leTab[8][8];								// Tableau pour notre grille/matrice
	char Mot[25];									// Tableau pour la saisie du mot 
	char leTabMot[60][25];							// Tableau de chaines de caracteres pour sauvegarder les mots entrés
	char laReponse;									// Voulez-vous entrer un nouveau mot ?
	char dictio;									// Voulez-vous jouer avec un dictionnaire ?
	const char quitter[2] = "Q";
	const char new_matrice[2] = "N";
	const char quitter_2[2] = "q";
	const char new_matrice_2[2] = "n";

	int i,j,k=0;									// variables de comptage
	int condition_dico;								// variable de sortie de boucle
	int condition_mot_deja_entre;					// variable de sortie de boucle
	int Longueur_chaine;							// variable contenant la longueur du mot
	int Compteur_Mot_Trouve=0;						// variable contenant le nombre de mots trouvés par le joueur
	int Compteur_Points=0;							// variable contenant le nombre de points du joueur
	int mot_faux=0;									// variable de sortie de boucle
	int quit=0;										// variable de boucle

	FILE*fichierEnreg;								// variable de type fichier pour "enregistrement.txt"

	/*********************************************************************************************************************************/
	/*							              PARTIE ENREGISTREMENT ET DEMANDE DE DICTIONNAIRE										 */
	/*********************************************************************************************************************************/

	printf("\n\t\tJEU DU BOOGLE par FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cedric\n\n\n\n");

	fichierEnreg = fopen("enregitrement.txt","a+");						// On va créer un fichier enregistrement.txt s'il n'éxiste pas 
																		// puis on vient écrire dans ce fichier 
	printf(" ENREGISTREMENT ");
	printf("\n\n Nom : ");
	scanf("%s",unJoueur.nom);	
	fpurge(stdin);
	printf(" Prenom : ");
	scanf("%s",unJoueur.prenom);
	fpurge(stdin);
	printf("\n\n Voulez-vous jouer avec un dictionnaire ? O/N ");
	dictio=getchar();
	fpurge(stdin);
	SystemCLS();


	/*********************************************************************************************************************************/
	/*							               INITIALISATION ET AFFICHAGE DE LA GRILLE DE JEU										 */
	/*********************************************************************************************************************************/
	
	matrice(leTab);									// Generation d'une grille de jeu

	do												// Boucle voulez-vous entrer un nouveau mot ?
	{

		printf("\n\t\tJEU DU BOOGLE par FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cedric\n\n\n\n");
		printf("\t\t\t\t     --- VOTRE GRILLE DE JEU ---\n\n\n");
		

		for(i=1;i<7;i++)							// 
		{											//
			printf("\t\t\t\t\t");					//
			for(j=1;j<7;j++)						//
			{										//	Affichage matrice
				printf("  %c",leTab[i][j]);			//
			}										//
			printf("\n\n");							//
		}											//
		printf("\n\n\n");


	/*********************************************************************************************************************************/
	/*												  SAISIE DU MOT + CONDITIONS SUR LA SAISIE										 */
	/*********************************************************************************************************************************/
		

		do																		// Boucle tant que la saisie n'est pas correct
		{
			condition_dico=0;													//
			condition_mot_deja_entre=0;											// Initialisations
			strcpy(Mot,"initialisation");										//
			mot_faux=0;															//

			printf("\n\n Tappez 'Q' pour quitter \n");
			printf(" Tappez 'N' pour jouer avec une nouvelle grille \n");
			printf("\n\n Veuillez entrer un mot : ");				
			scanf("%s",Mot);
			fpurge(stdin);
			strupr(Mot);														// Mise en majuscule du mot
			Longueur_chaine=strlen(Mot);										// Longueur_chaine contient la longueur du mot


			// Si le joueur veut quitter la partie
			//
			if(strcmp(quitter,Mot) == 0 || strcmp(quitter_2,Mot) == 0)										
			{			
				quit=1;
																		
			}
			
			if(quit==0)
			{
				// Si le joueur demande une nouvelle grille de jeu
				//
				if(strcmp(new_matrice,Mot) == 0 || strcmp(new_matrice_2,Mot) == 0)									
				{	
					// Generation d'une nouvelle grille de jeu
					//
					matrice(leTab); SystemCLS();
				
					// Mise a zero des points du joueur
					//
					Compteur_Points=0;
					Compteur_Mot_Trouve=0;
				
					// Affiche de la nouvelle grille
					//
					printf("\n\t\tJEU DU BOOGLE par FOUCO Charles, SOUQUET Leo, BOOS Gael et et HULIN Cedric\n\n\n\n");
					printf("\t\t\t\t     --- VOTRE GRILLE DE JEU ---\n\n\n");
				
					for(i=1;i<7;i++)							 
					{											
						printf("\t\t\t\t\t");					
						for(j=1;j<7;j++)						
						{										
							printf("  %c",leTab[i][j]);			
						}										
						printf("\n\n");							
					}											
					printf("\n\n\n");
				
					continue;
				}		
			
				// Si le mot entré est trop court
				//
				if(Longueur_chaine<3)												
				{																	
					printf("\n MOT TROP COURT, REESAYER \n\n");	
					mot_faux=1;
					sleep(1);
					continue;
				}
			
			
				// Si le mot entré est trop long
				//
				if(Longueur_chaine>6)												
				{																	
					printf("\n MOT TROP LONG, REESAYER \n\n");
					mot_faux=1;
					sleep(1);
					continue;
				}																	
			
				// Si le joueur utilise un dictionnaire
				//
				if(dictio=='O' || dictio=='o')										
				{	
					// Si le mot ne fait pas parti du dictionnaire
					//
					if(!dico(Mot))											
					{																
						condition_dico=1;
						mot_faux=1;
						printf("\n CE MOT N'EST PAS FRANCAIS, REESAYER \n\n");	
						sleep(1);
					}
				
					// Si le mot fait parti du dictionnaire
					//
					else															
					{		
						printf("\n MOT FRANCAIS : OUI \n");	
					}												
				}																	
			
				// On copie le mot entré dans le tableau de sauvegarde
				//
				strcpy(leTabMot[k],Mot);											
				k++;																
			
				// Traiter le cas d'un mot deja entre
				//
				for(i=0;i<k-1;i++)													
				{																						
					if(strcmp(leTabMot[i],Mot) == 0)								
					{																
						condition_mot_deja_entre=1;		
						mot_faux=1;
						printf("\n CE MOT A DEJA ETE ENTREE \n\n");	
						sleep(1);
						break;
					}																
				}
			}

		}while((Longueur_chaine<3 || Longueur_chaine>6 || condition_dico != 0 || condition_mot_deja_entre !=0) && mot_faux!=1 && quit!=1);


	/*********************************************************************************************************************************/
	/*													RECHERCHE DU MOT DANS LA GRILLE												 */
	/*********************************************************************************************************************************/	
		if(mot_faux==0 || quit==0)
		{
			for(i=1;i<7;i++)														// On parcours la grille																							
			{																		//
			for(j=1;j<7;j++)													//                 
			{																	//
				if(leTab[i][j]==Mot[0])											// Si la 1er lettre de la grille correspond ‡ celle du mot
				{	
					// DIAGONALE DESCENDANTE VERS LA DROITE
					if (leTab[i+1][j+1]==Mot[1])								// Si la 2e lettre de la grille correspond ‡ celle du mot 
					{															

						// Si la fonction renvoie vrai (le mot entré est dans la grille)
						if(Diago2_a(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve en diagonale desendante vers la droite\n\n"); 
							Compteur_Mot_Trouve++;								// On incrémente le nombre de mots trouvé
							Compteur_Points+=strlen(Mot);						// Le nombre de points = la longueur du mot 
						}								   			
					}	

					// DIAGONALE MONTANTE VERS LA DROITE
					if (leTab[i-1][j-1]==Mot[1])								
					{																						
						
						if(Diago2_b(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve en diagonale montante vers la gauche\n\n");  
							Compteur_Mot_Trouve++;								
							Compteur_Points+=strlen(Mot);						
						}
					}
					
					// CAS DIAGONALE DESCENDANTE VERS LA GAUCHE
					if (leTab[i+1][j-1]==Mot[1])
					{
						if(Diago1_a(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve en diagonale descandante vers la gauche\n\n");  
							Compteur_Mot_Trouve++;
							Compteur_Points+=strlen(Mot);
						}
					}

					// CAS DIAGONALE MONTANTE VERS LA DROITE
					if (leTab[i-1][j+1]==Mot[1])
					{
						if(Diago1_b(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve en diagonale montante vers la droite\n\n");  	
							Compteur_Mot_Trouve++;
							Compteur_Points+=strlen(Mot);
						}
					}	

					// CAS HORIZONTALE DROITE A GAUCHE
					if (leTab[i][j-1]==Mot[1])
					{
						if(horizontal_a(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve a l'horizontale de la droite vers la gauche\n\n"); 
							Compteur_Mot_Trouve++;
							Compteur_Points+=strlen(Mot);
						}
					}
	
					// CAS HORIZONTALE DE GAUCHE A DROITE
					if (leTab[i][j+1]==Mot[1])
					{
						if(horizontal_b(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve a l'horizontale de la gauche vers la droite\n\n"); 
							Compteur_Mot_Trouve++;
							Compteur_Points+=strlen(Mot);
						}
					}	

					// CAS VERTICALE DE BAS EN HAUT
					if (leTab[i-1][j]==Mot[1])
					{
						if(vertical_a(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve a la verticale du bas vers le haut\n\n");  
							Compteur_Mot_Trouve++;
							Compteur_Points+=strlen(Mot);
						}
					}

					// CAS VERTICALE DE HAUT EN BAS
					if (leTab[i+1][j]==Mot[1])
					{
						if(vertical_b(leTab, Mot, i, j, Longueur_chaine))
						{
							printf(" \ntrouve a la verticale du haut vers le bas\n\n");  
							Compteur_Mot_Trouve++;
							Compteur_Points+=strlen(Mot);
						}
					}
				}
			}
			}
		}
		
		// Si le joueur ne veux pas quitter la partie
		//
		if(quit==0)
		{
			// On lui afffiche ses scores
			//			
			printf("\t\t\t\t\t\t\t\t\tNombre de mots trouves : %d",Compteur_Mot_Trouve);
			sleep(1);
			printf("\n\t\t\t\t\t\t\t\t\tNombre de points : %d",Compteur_Points);
			sleep(1);
		}

		// Si le joueur a trouver un mot on lui demande s'il souhaite continuer
		//
		if (mot_faux==0 && quit==0)
		{
			printf("\n\n\t\t\t Voulez-vous entrer un nouveau mot ? O/N : ");
			laReponse=getchar();
		}

		// Si le joueur n'a pas trouver un mot juste
		//
		if (mot_faux==1)	laReponse='O';

		// Si le joueur demande a quitter
		//
		if (quit==1)	laReponse='N';

		// Si la reponse du joueur est de ne pas rentrer de nouveau mot
		//
		if (laReponse!='O' && laReponse!='o')
		{
			printf("\nScore Partie\t\t\t\t\t\t\tNombre de mots trouves : %d",Compteur_Mot_Trouve);
			sleep(1);
			printf("\nScore Partie\t\t\t\t\t\t\tNombre de points : %d",Compteur_Points);
			sleep(1);
			printf("\nA bientot %s\n\n",unJoueur.prenom);
			sleep(2);
		}
		fpurge(stdin);
		SystemCLS();

	}while(laReponse=='O' || laReponse=='o');							// On recommence tant que la réponse = 'O' ou 'o'
	
	unJoueur.points = Compteur_Points;
	fprintf(fichierEnreg, "\n  %s %s\t\t\tPoints : %d",unJoueur.nom,unJoueur.prenom,unJoueur.points);	// On écrit dans le fichier
	fclose(fichierEnreg);
	
	SystemCLS();				
}