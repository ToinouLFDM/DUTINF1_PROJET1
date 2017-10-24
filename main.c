#include "parametre.h"
#include "graphique.c"
#include "game.c"

int main(int argc, char *argv[])
{	
	// début de la session graphique
	ouvrir_fenetre(W*2+lenght_Case,H);
	Case map1[][],map2[][];
	graphic_map(map1,map2);
	
	
	// fin de la session graphique
  attendre_clic();
  fermer_fenetre();
	return 0;
}
