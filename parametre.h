#include "lib/libgraphique.h"
#include<stdio.h>
#include<math.h>

#define W 500 //taille graphique d'un labyrinthe
#define H 500//taille graphique d'un labyrinthe
#define difficulty 6
#define lenght_Case 20



typedef struct ITEM{
	int key1;
	int key2;
	int key3;
}Item;



typedef struct PLAYER{
	Item own;
	Point position;
	int Victory;
	}Player;


typedef struct CASE {
	
	int exit;
	int wall;
	Item own;
}Case;



//GAME.C
	//init qui va initiliser les 2 matrice de case et dessiner les mur et le fond d'ecran
	void init_maps(Case map1[][H/lenght_Case],Case map2[][H/lenght_Case]);
	//une fct game qui gere la boucle du jeu
	void game(Player *player1,Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case]);
	//une fct qui gere le deplacement pour les deux joueurs en simultané
	void Victory(Player *player1,Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case]);

//graphique
	//fct fond d'ecran
	void init_ecran();
	//fct dessine une case en fct de sa position matricielle et en fct du labyrinthe choisi
	void graphic_case(int , int ,int nb_map);
	//fct dessine un mur ..................................................................
	void graphic_wall(int , int , int nb_map);

	









