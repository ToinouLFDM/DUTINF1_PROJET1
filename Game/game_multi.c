void make_Maze_multi(Case map1[][H_Map],Case map2[][H_Map],Player *player1,Player *player2)
{/*
  int x=0,y;
  generator_Maze(map1);
  init_ecran(gray);
  int y_key1=entier_aleatoire(H_Map-  1)/2;
  int y_key2=entier_aleatoire(H_Map-1)/2+H_Map/2;
  int y_key3=entier_aleatoire(H_Map-1)/2+H_Map/2;
  int y_p=entier_aleatoire(H_Map-1)/2+1;
  int y_e=entier_aleatoire(H_Map-1)/2 +H_Map/2;
  int player_done=0,exit_done=0,key1_done=0,key2_done=0,key3_done=0;
  for(;x<W_Map;x++)
  {
    for(y=0;y<H_Map;y++)
    {
      if(map1[x][y].wall==1)
      {
	map2[x][y].wall=1;
	graphic_wall(x,y,1);
	graphic_wall(x,y,2);
      }
      if(y_p==y)
      {
	if(map1[x][y].wall!=1 && !player_done)
	{
	  player1->position.x=x;
	  player1->position.y=y;
	  player1->pos_graphic.x=x*lenght_Case;
	  player1->pos_graphic.y=y*lenght_Case;
	  player2->position.x=x;
	  player2->position.y=y;
	  player2->pos_graphic.x=x*lenght_Case;
	  player2->pos_graphic.y=y*lenght_Case;
	  graphic_player(x,y,1);
	  graphic_player(x,y,2);
	  player_done=1;
	}
      }
      if(y_e==y && x>W_Map/2)
      {
	if(map1[x][y].wall!=1 && !exit_done)
	{
	  map1[x][y].exit=1;
	  map2[x][y].exit=1;
	  graphic_exit(x,y,1);
	  graphic_exit(x,y,2);
	  exit_done=1;
	}
      }
      if(y_key1==y && x>W_Map/2)
      {
	if(map1[x][y].wall!=1 && !key1_done)
	{
	  map1[x][y].own.key1=1;
	  map2[x][y].own.key1=1;
	  key1_done=1;
	  graphic_key(x,y,1);
	  graphic_key(x,y,2);
	}
      }
      if(y_key2==y)
      {
	if(map1[x][y].wall!=1 && !key2_done)
	{
	  map1[x][y].own.key2=1;
	  map2[x][y].own.key2=1;
	  key2_done=1;
	  graphic_key(x,y,1);
	  graphic_key(x,y,2);
	}
      }
      if(y_key3==y)
      {
	if(map1[x][y].wall!=1 && !key3_done)
	{
	  map1[x][y].own.key3=1;
	  map2[x][y].own.key3=1;
	  key3_done=1;
	  graphic_key(x,y,1);
	  graphic_key(x,y,2);
	}
      }

    }
  }
  call_send_map(map2);
  actualiser();*/
}




void game_multi(Player *player1, Player *player2, Case map1[][H/lenght_Case], Case map2[][H/lenght_Case])
{
/*
  InitPlayer(player1,1);
  InitPlayer(player2,2);
  actualiser();
  Input in;
  // init SDL, chargement, tout ce que vous faites avant la boucle.
  memset(&in,0,sizeof(in));
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    attente(5);
    pick_Item(map1,player1);  //si un item est present sur le labyrinthe il est attribué au player 
    pick_Item(map2,player2); //idem pour le deuxieme joueur
    UpdateEvents(&in);
    move_player(player1);
    move_player(player2);
    deplacement(player1,map1);
    deplacement(player2,map2);
    Is_pressed(player1,player2,in);
    reinitialiser_evenements();
    Victory(player1,player2,map1,map2);
    actualiser();
  }
  reinitialiser_evenements();
  screen_victory(player1,player2);
  traiter_evenements();
  actualiser();*/
}
