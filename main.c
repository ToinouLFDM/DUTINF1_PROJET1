#include "parametre.h"
#include "graphique.c"
#include "game.c"
#include "generator_maze.c"
#include "generator_Maze_v2.c"

int main(int argc, char *argv[])
{	
	// début de la session graphique
	ouvrir_fenetre(W*2+lenght_Case,H+lenght_Case);
	Point corner={W/2,0};
	Point size={W,H};
	afficher_image_resize("picture/Menu.bmp",corner,size);
	actualiser();
	attendre_clic();
	Case map1[W/lenght_Case][H/lenght_Case],map2[W/lenght_Case][H/lenght_Case];
	init_maps(map1,map2);
	Player player1;
	Player player2;
	make_Maze(map1,map2,&player1,&player2);
	game(&player1,&player2,map1,map2);
	// fin de la session graphique
  attendre_clic();
  fermer_fenetre();
	return 0;
}
