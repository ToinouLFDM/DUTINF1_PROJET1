void init_maps(Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
  int i=0, j=0;
    while (j<(H/lenght_Case))
  {
    while(i<(W/lenght_Case))
    {
      map1[i][j].exit=0;
      map2[i][j].exit=0;
      map1[i][j].wall=0;
      map2[i][j].wall=0;
      map1[i][j].own.key1=0;
      map2[i][j].own.key1=0;
      map1[i][j].own.key2=0;
      map2[i][j].own.key2=0;
      map1[i][j].own.key3=0;
      map2[i][j].own.key3=0;
      i++;
    }
    j++;
    i=0;
  }
}
void make_Maze(Case map1[][H_Map],Case map2[][H_Map],Player *player1,Player *player2)
{
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
  actualiser();
}

void game(Player *player1, Player *player2, Case map1[][H/lenght_Case], Case map2[][H/lenght_Case])
{
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
  actualiser();
}

void Is_pressed(Player *player1,Player *player2,Input in)
{

  if(in.key[SDLK_UP] )
    player2->up.pressed=1;
  else
    player2->up.pressed=0;
  if(in.key[SDLK_DOWN] )
    player2->down.pressed=1;
  else
    player2->down.pressed=0;
  if(in.key[SDLK_LEFT] )
    player2->left.pressed=1;
  else
    player2->left.pressed=0;
  if(in.key[SDLK_RIGHT] )
    player2->right.pressed=1;
  else
    player2->right.pressed=0;
 

  if(in.key[SDLK_z] )
    player1->up.pressed=1;
  else
    player1->up.pressed=0;
  if(in.key[SDLK_s] )
    player1->down.pressed=1;
  else
    player1->down.pressed=0;
  if(in.key[SDLK_q] )
    player1->left.pressed=1;
  else
    player1->left.pressed=0;
  if(in.key[SDLK_d] )
    player1->right.pressed=1;
  else
    player1->right.pressed=0;
}
void deplacement(Player *player1, Case map1[][H/lenght_Case])
{
  if(!player1->up.is_moving && !player1->down.is_moving && !player1->left.is_moving && !player1->right.is_moving)
  {
    if(player1->up.pressed && !(map1[player1->position.x][(player1->position.y)-1].wall) && (player1->position.y>0))
    {
      printf("player1 %d\n",player1->Victory);
     // player1->up.pressed=0;
      player1->down.pressed=0;
      //player1->right.pressed=0;
      //player1->left.pressed=0;
      player1->up.is_moving=1;
      player1->position.y-=1;
    }
    if(player1->down.pressed && !(map1[player1->position.x][(player1->position.y)+1].wall) && (player1->position.y<(H/lenght_Case)-1))
    { 
      player1->up.pressed=0;
      //player1->down.pressed=0;
      //player1->right.pressed=0;
      //player1->left.pressed=0;
      printf("player1 %d\n",player1->Victory);
      player1->down.is_moving=1;
      player1->position.y+=1;
    }

    if(player1->left.pressed && !(map1[player1->position.x-1][(player1->position.y)].wall) && (player1->position.x>0))
    { 
      //player1->up.pressed=0;
      //player1->down.pressed=0;
      player1->right.pressed=0;
      //player1->left.pressed=0;
      printf("player1 %d\n",player1->Victory);
      player1->left.pressed=0;
      player1->left.is_moving=1;
      player1->position.x-=1;
    }
    if(player1->right.pressed && !(map1[player1->position.x+1][(player1->position.y)].wall) && (player1->position.x<(W/lenght_Case-1)))
    {
      //player1->up.pressed=0;
      //player1->down.pressed=0;
      //player1->right.pressed=0;
      player1->left.pressed=0;
      printf("player1 %d\n",player1->Victory);
      player1->right.is_moving=1;
      player1->position.x+=1;
    }
	}
}
void move_player(Player *player)
{
  if(player->up.is_moving>lenght_Case)
    player->up.is_moving=0;
  if(player->down.is_moving>lenght_Case)
    player->down.is_moving=0;
  if(player->left.is_moving>lenght_Case)
    player->left.is_moving=0;
  if(player->right.is_moving>lenght_Case)
    player->right.is_moving=0;


  if(player->up.is_moving)
  {
    graphic_anim_erase(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
    player->pos_graphic.y-=1;
    graphic_anim(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
    player->up.is_moving+=1;
  }
  else if(player->down.is_moving)
  {
    graphic_anim_erase(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
    player->pos_graphic.y+=1;
    player->down.is_moving+=1;
    graphic_anim(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
  }
  else if(player->left.is_moving)
  {
    graphic_anim_erase(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
    player->pos_graphic.x-=1;

    player->left.is_moving+=1;
    graphic_anim(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
  }
  else if(player->right.is_moving)
  {
    graphic_anim_erase(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
    player->pos_graphic.x+=1;
    player->right.is_moving+=1;
    graphic_anim(player->pos_graphic.x,player->pos_graphic.y,(player->ID==1)?1:2);
  }
  else
  {
    graphic_player(player->position.x,player->position.y,(player->ID==1)?1:2);
  }
}
void Victory(Player *player1, Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
  if(player1->own.key1 && player1->own.key2 && player1->own.key3)
    player1->Victory=map1[player1->position.x][player1->position.y].exit;
  if(player2->own.key1 && player2->own.key2 && player2->own.key3)
    player2->Victory=map2[player2->position.x][player2->position.y].exit;  
  
}

void InitPlayer(Player *player1,int id)
{
  player1->own.key1=0;
  player1->own.key2=0;
  player1->own.key3=0;
  player1->Victory=0;
  player1->up.is_moving=0;
  player1->up.pressed=0;
  player1->down.is_moving=0;
  player1->down.pressed=0;
  player1->left.is_moving=0;
  player1->left.pressed=0;
  player1->right.is_moving=0;
  player1->right.pressed=0;
  player1->ID=id;
  graphic_player(player1->position.x,player1->position.y,1);

}
void game_IA(Player *player1, Player *player2, Case map1[][H/lenght_Case], Case map2[][H/lenght_Case])
{
  InitPlayer(player1,1);
  InitPlayer(player2,2);
  actualiser();
  Input in;
  // init SDL, chargement, tout ce que vous faites avant la boucle.
  memset(&in,0,sizeof(in));
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    attente(5);
    pick_Item(map1,player1);
    pick_Item(map2,player2);
    UpdateEvents(&in);
    move_player(player1);
    move_player(player2);
    deplacement(player1,map1);
    deplacement_IA(player2,map2);
    Is_pressed(player1,player2,in);
    reinitialiser_evenements();
    Victory(player1,player2,map1,map2);
    actualiser();
  }
  reinitialiser_evenements();
  screen_victory(player1,player2);
  traiter_evenements();
  actualiser();
}
//deplace l'ia en faisant appelle au fonction de deduction de chemin
void deplacement_IA(Player *player,Case map[][H_Map])
{
  Point tmp=player->position;
  int a=entier_aleatoire(difficulty);
  if(!player->up.is_moving && !player->down.is_moving && !player->right.is_moving && !player->left.is_moving && a==1)
    player->position=path_IA(player,map);
  switch(tmp.x-player->position.x)
  {
    case 1:
      player->left.is_moving=1;
      break;
    case -1:
      player->right.is_moving=1;
      break;
  }
  switch(tmp.y-player->position.y)
  {
    case 1:
      player->up.is_moving=1;
      break;
    case -1:
      player->down.is_moving=1;
  }

}

void pick_Item(Case map[][H_Map], Player *player)
{
  Point p={player->position.x,player->position.y};
  if(map[p.x][p.y].own.key1)
  {
    map[p.x][p.y].own.key1=0;
    player->own.key1=1;
  }
  if(map[p.x][p.y].own.key2)
  {
    player->own.key2=1;
    map[p.x][p.y].own.key1=0;
  }
  if(map[p.x][p.y].own.key3)
  {
    player->own.key3=1;
    map[p.x][p.y].own.key3=0;
  }
}
void make_Maze_multi(Case map1[][H_Map],Case map2[][H_Map],Player *player1,Player *player2)
{
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
  actualiser();
}




void game_multi(Player *player1, Player *player2, Case map1[][H/lenght_Case], Case map2[][H/lenght_Case])
{
  
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
  actualiser();
}

