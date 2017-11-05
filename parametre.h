#include "lib/libgraphique.h"
#include<stdio.h>
#include<math.h>

#define W 500 //taille graphique d'un labyrinthe
#define H 500//taille graphique d'un labyrinthe
#define difficulty 6
#define lenght_Case 20
#define W_Map W/lenght_Case
#define H_Map H/lenght_Case



typedef struct ITEM{
	int key1;
	int key2;
	int key3;
}Item;


typedef struct MOVE{
  int is_moving;
  int pressed;
}move;

typedef struct PLAYER{
	Item own;
	Point position;
	int Victory;
	move up;
	move left;
	move right;
	move down;
	int ID;
	}Player;


typedef struct CASE {
	
	int exit;
	int wall;
	Item own;
}Case;



//GAME.C
	//init qui va initiliser les 2 matrice de case et dessiner les mur et le fond d'ecran
	void init_maps(Case map1[][H/lenght_Case],Case map2[][H/lenght_Case]);
	void make_Maze(Case map1[][H_Map], Case map2[][H_Map],Player *player1, Player *player2);
	//une fct game qui gere la boucle du jeu
	void game(Player *player1,Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case]);
	//une fct qui gere le deplacement pour les deux joueurs en simultané
	void Is_pressed(Player *player1,Player *player2);
	void deplacement(Player *player1, Case map1[][H/lenght_Case]);
	void Victory(Player *player1,Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case]);
	void InitPlayer(Player *player1,int id);
//graphique
	//fct fond d'ecran
	void init_ecran(Couleur c);
	//fct dessine une case en fct de sa position matricielle et en fct du labyrinthe choisi
	void graphic_case(int , int ,int nb_map);
	void graphic_player(int , int ,int nb_map);
	void graphic_exit(int , int ,int nb_map);

	//fct dessine un mur ..................................................................
	void graphic_wall(int , int , int nb_map);
	void screen_victory(Player *player1, Player *player2);
//MAZE
  void generator(Case map[][H/lenght_Case]);
  int check_Map(Case map[][H/lenght_Case]);
  void check_Rec(int tab[][H/lenght_Case],Case map[][H/lenght_Case],int x,int y);
  int check_Close(Case map[][H/lenght_Case], int tab[][H/lenght_Case],int x,int y);
  void put_Wall(Case map[][H/lenght_Case], int *nb_loop, int *nb_Case);
  int check_Put_Wall(Case map[][H/lenght_Case],int *nb_Case, int rand_x,int rand_y);

//MAZE V2
  void generator_Maze(Case map[][H_Map]);
  void init_Lab(Case map[][H_Map], int tab[][H_Map]);
  int is_Perfect(int tab[][H_Map]);
  void break_Wall(Case map[][H_Map], int tab[][H_Map]);
  void set_Path(int tab[][H_Map], int x, int y);
  void set_Path_Rec(int tab[][H_Map], int x, int y,int from_x,int from_y);
  void debug_Print_Tab(int tab[][H_Map]);





