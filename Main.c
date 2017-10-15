#include "parametre.h"
#include "graphique.c"
#include "pathfinding.c"
#include "game.c"




int main(int argc, char *argv[])
{	
	// début de la session graphique
	ouvrir_fenetre(W*2+taille_Case,H);
	
	
	//initialision map
	Case map[W/taille_Case][H/taille_Case];
	Case map2[W/taille_Case][H/taille_Case];
	Point player,monster;
	player=init_damier(map);
	player=init_damier(map2);
	graphisme_damier(map,player,1);
	graphisme_damier(map2,player,2);
	
	 //Game
	 Game(map,map2, player, monster);
	 
	
	// fin de la session graphique
  attendre_clic();
  fermer_fenetre();
	return 0;
}



		



