#include "lib/libgraphique.h"
#include<stdio.h>
#include<math.h>

#define W 400 //taille graphique d'un labyrinthe
#define H 320	//taille graphique d'un labyrinthe
#define difficulty 6
#define lenght_Case 40




typedef struct ITEM{
	int key1;
	int key2;
	int key3;
}Item;



typedef struct PLAYER{
	Item own;
	Point position;
	}Player;


typedef struct CASE {
	
	int exit;
	int wall;
	Item own;
}Case;



//GAME.C
	//init qui va initiliser les 2 matrice de case et dessiner les mur et le fond d'ecran
	//une fct game qui gere la boucle du jeu
	//une fct qui gere le deplacement pour les deux joueurs en simultané
	
//graphique
	//fct fond d'ecran
	//fct dessine une case en fct de sa position matricielle et en fct du labyrinthe choisi
	//fct dessine un mur ..................................................................
	









