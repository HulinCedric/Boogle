//  JEU DU BOOGLE par FOUCO Charles, SOUQUET Leo, BOOS Gael et HULIN Cédric
//
//	PROJETS TUTEURES S1 : Nathalie FENEON 				Tuteur : Rosa LECAT
//
//	Sujet5 RL3		Groupe S1-RL3.4
//
//	Membres du groupe :
//				Charles  Fouco
//				Cédric   Hulin
//				Leo      Souquet
//				Gael     Boos
//
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define false 0
#define true 1
typedef int bool;


typedef struct
{
	char nom[20];
	char prenom[20];
	int points;
}joueur;



//PROTOTYPES

void main(); // PROGRAMME PRINCIPAL

void accueil(int *lechoix); // CHOIX DANS LE MENU

void jouer(); // JOUER AU BOOGLE

char matrice(char unTab[][8]); // PERMET DE GENERER UNE MATRICE 

void regle(); // AFFICHE LES REGLES DU JEU

void statistiques(); // AFFICHE LE NOM ET LE SCORE DE TOUS LES JOUEURS

bool dico(char Mot[20]); // RENVOI 1 SI LE MOT EST PRESENT DANS LE DICTIONNAIRE

void erreur(); // MESSAGE D'ERREUR ET REDIRECTION SI LE CHOIX/FICHIER N'EST PAS VALIDE

void verifVoyelles(char unTab[8][8]); // AJOUTE UN NOMBRE PREDEFINI DE VOYELLES DANS LA GRILLE DE JEU

int nbreVoyelles(char unTat[8][8]);	// RETOURNE LE NOMBRE DE VOYELLES PRESENTENT DANS LA GRILLE DE JEU



// FONCTIONS DE RECHERCHE

// RECHERCHE EN DIAGONAL DE HAUT GAUCHE A BAS DROIT ET BAS DROIT A HAUT GAUCHE
//
bool Diago1_a(char leTab[8][8],char * Mot,int i,int j,int lenght);
bool Diago1_b(char leTab[8][8],char * Mot,int i,int j,int lenght);

// RECHERCHE EN DIAGONAL DE HAUT DROIT A BAS GAUCHE ET BAS GAUCHE A HAUT DROIT
//
bool Diago2_a(char leTab[8][8],char * Mot,int i,int j,int lenght);
bool Diago2_b(char leTab[8][8],char * Mot,int i,int j,int lenght);

// RECHERCHE EN HORIZONTALE DE DROITE A GAUCHE ET DE GAUCHE A DROITE
//
bool horizontal_a(char leTab[8][8],char * Mot,int i,int j,int lenght);
bool horizontal_b(char leTab[8][8],char * Mot,int i,int j,int lenght);

// RECHERCHE EN HORIZONTALE DE HAUT A EN BAS ET DE BAS A EN HAUT
//
bool vertical_a(char leTab[8][8],char * Mot,int i,int j,int lenght);
bool vertical_b(char leTab[8][8],char * Mot,int i,int j,int lenght);

// portabilité Mac
void SystemCLS();
void SystemPause();
void strupr(char chaine[7]);



