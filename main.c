#include "parametre.h"
#include "Graphic/graphique.c"
#include "Graphic/menu.c"
#include "Game/game.c"
#include "Generator/generator_Maze_v2.c"
#include "IA/tree.c"
#include "IA/ia.c"
#include "network/sent_map.c"
#include "network/receive_map.c"

void main()
{	
	// début de la session graphique
	ouvrir_fenetre(W*2+lenght_Case,H+lenght_Case*H_Map/4);
	int type_partie=Menu();
	while(type_partie!=0)
	{
		Case map1[W/lenght_Case][H/lenght_Case],map2[W/lenght_Case][H/lenght_Case];
		init_maps(map1,map2);
		Player player1;
		Player player2;
	
		if(type_partie==1)
		{
			make_Maze(map1,map2,&player1,&player2);
			game(&player1,&player2,map1,map2);
		}
		if(type_partie==2)
		{
			game_IA(&player1,&player2,map1,map2);
			make_Maze(map1,map2,&player1,&player2);
		}
		if(type_partie==3)
		{
			make_Maze_multi(map1,map2,&player1,&player2);
			game_multi(&player1,&player2,map1,map2);
		}
		type_partie=Menu();
	}
	// fin de la session graphique
	fermer_fenetre();
	return ;
}
