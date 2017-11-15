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
//place un point aleatoirement sur une case ou il n'y apas de murs dans la partie droite ou gauche de la map
Point put_in_square(Case map[][H_Map],int square_x,int square_y)//square_x->1 ou 2 square_y->1ou 2
{
  Point p_alea={0,0};
  while(map[p_alea.x][p_alea.y].wall)
  {
    if(square_x==1)
      p_alea.x=entier_aleatoire(W_Map/2);
    else
      p_alea.x=entier_aleatoire(W_Map/2)+W_Map/2;

    if(square_y==1)
      p_alea.y=entier_aleatoire(H_Map/2);
    else
      p_alea.y=entier_aleatoire(H_Map/2)+H_Map/2;
  }
  return p_alea;

}
void make_Maze(Case map1[][H_Map],Case map2[][H_Map],Player *player1,Player *player2)
{
  int x=0,y;
  generator_Maze(map1);
  init_ecran(gray);
  Point alea_key1=put_in_square(map1,2,1);
  attente(5);
  Point alea_key2=put_in_square(map1,1,2);
  attente(5);
  Point alea_key3=put_in_square(map1,2,2);
  attente(5);
  Point alea_p=put_in_square(map1,1,1);
  attente(5);
  Point alea_e=put_in_square(map1,2,2);
  printf("player->%d,%d  exit->%d,%d\n ",alea_p.x,alea_p.y,alea_e.x,alea_e.y);
  for(;x<W_Map;x++)
  {
    for(y=0;y<H_Map;y++)
    {
    	map2[x][y].fake_exit=0;
      if(map1[x][y].wall)
      {
	map2[x][y].wall=1;
	graphic_wall(x,y,1);
	graphic_wall(x,y,2);
      }
      if(alea_p.x==x && alea_p.y==y)
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
      }
      if(alea_e.x==x && alea_e.y==y)
      {
	map1[x][y].exit=1;
	map2[x][y].exit=1;
	graphic_exit(x,y,1);
	graphic_exit(x,y,2);
      }
      if(alea_key1.x==x && alea_key1.y==y)
      {
	map1[x][y].own.key1=1;
	map2[x][y].own.key1=1;
	graphic_key(x,y,1);
	graphic_key(x,y,2);
      }

      if(alea_key2.x==x && alea_key2.y==y)
      {
	map1[x][y].own.key2=1;
	map2[x][y].own.key2=1;
	graphic_key(x,y,1);
	graphic_key(x,y,2);
      }


      if(alea_key3.x==x && alea_key3.y==y)
      {
	map1[x][y].own.key3=1;
	map2[x][y].own.key3=1;
	graphic_key(x,y,1);
	graphic_key(x,y,2);
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
  int time_init=SDL_GetTicks();
  int delta_time=time_init;
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    attente(5);
    pick_Item(map1,player1);  //si un item est present sur le labyrinthe il est attribué au player 
    pick_Item(map2,player2); //idem pour le deuxieme joueur
    delta_time=SDL_GetTicks()-time_init;
    dessiner_timer((delta_time%3600000)/60000,(delta_time%60000)/1000,(delta_time%1000)/10);
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
  Input_file(delta_time/60000,(delta_time%60000)/1000,(delta_time%1000)/10);
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
    
  int i=0,j;
  for(;i<W_Map;i++)
  {
  	for(j=0;j<H_Map;j++)
  	{
  		if(map1[i][j].exit)
  		{
  			graphic_exit(i,j,1);
  			graphic_exit(i,j,2);
  		}
  	}
  }
  
 

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
  Point fake_exit_pos={0,0};
  int time_init=SDL_GetTicks();
  int delta_time=time_init;
  int fake_exit=entier_aleatoire(difficulty/5+1);
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    attente(5);
    dessiner_timer(0,0,0);
    pick_Item(map1,player1);
    pick_Item(map2,player2);
    delta_time=SDL_GetTicks()-time_init;
    dessiner_timer((delta_time%3600000)/60000,(delta_time%60000)/1000,(delta_time%1000)/10);
    UpdateEvents(&in);
    move_player(player1);
    move_player(player2);
    deplacement(player1,map1);
    deplacement_IA(player2,map2,&fake_exit,&fake_exit_pos);
    Is_pressed(player1,player2,in);
    reinitialiser_evenements();
    Victory(player1,player2,map1,map2);
    actualiser();
  }
  reinitialiser_evenements();
  screen_victory(player1,player2);
  if(player1->Victory)
	  Input_file(delta_time/60000,(delta_time%60000)/1000,(delta_time%1000)/10);
  traiter_evenements();
  actualiser();
}
//deplace l'ia en faisant appelle au fonction de deduction de chemin
void deplacement_IA(Player *player,Case map[][H_Map],int *fake_exit,Point *fake_exit_pos)
{
  Point tmp=player->position;
  int a=entier_aleatoire(difficulty);
  int b=entier_aleatoire(100000/difficulty);
  printf("fake_exit->%d,fake exit position->%d,%d\n",*fake_exit,fake_exit_pos->x,fake_exit_pos->y);
  printf("player position->%d,%d\n",player->position.x,player->position.y);
  if(map[player->position.x][player->position.y].own.key1 || map[player->position.x][player->position.y].own.key2 || map[player->position.x][player->position.y].own.key3)
  	*fake_exit=entier_aleatoire(difficulty/5+1);
  if((fake_exit_pos->x==0 && fake_exit_pos->y==0 )&& *fake_exit<=difficulty/5 && b==1)
  {


    *fake_exit_pos=put_in_square(map,entier_aleatoire(2),entier_aleatoire(2));
    map[fake_exit_pos->x][fake_exit_pos->y].fake_exit=1;
    *fake_exit+=1;
    
    

  }
  else if(fake_exit_pos->x!=0 && fake_exit_pos->y!=0 && *fake_exit<=difficulty/5)
  {
    if(!player->up.is_moving && !player->down.is_moving && !player->right.is_moving && !player->left.is_moving && a==1)
      player->position=path_IA(player,map,1);
    if(map[player->position.x][player->position.y].fake_exit)
    {
      fake_exit_pos->x=0;
      fake_exit_pos->y=0;
      map[player->position.x][player->position.y].fake_exit=0;
    }
  }
  else
  {
    if(!player->up.is_moving && !player->down.is_moving && !player->right.is_moving && !player->left.is_moving && a==1)
      player->position=path_IA(player,map,0);
  }
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
    map[p.x][p.y].own.key2=0;
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

