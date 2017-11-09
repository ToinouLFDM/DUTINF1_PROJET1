void init_maps(Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
  int i=0, j=0;
  init_ecran(gray);
  while (j<(H/lenght_Case))
  {
    while(i<(W/lenght_Case))
    {
      map1[i][j].exit=0;
      map2[i][j].exit=0;
      map1[i][j].wall=0;
      map2[i][j].wall=0;
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
  int y_p=entier_aleatoire(H_Map-1)/2+1;
  int y_e=entier_aleatoire(H_Map-1)/2 +H_Map/2;
  int a=0,b=0;
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
	if(map1[x][y].wall!=1 && !a)
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
	  a=1;
	}
      }
      if(y_e==y)
      {
	if(map1[x][y].wall!=1 && !b)
	{
	  map1[x][y].exit=1;
	  map2[x][y].exit=1;
	  graphic_exit(x,y,1);
	  graphic_exit(x,y,2);
	  b=1;
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
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    reinitialiser_evenements();
    attente(5);   
    traiter_evenements();
   
    move_player(player1);
    move_player(player2);
    deplacement(player1,map1);
    deplacement(player2,map2);
    Is_pressed(player1,player2);
    reinitialiser_evenements();
    Victory(player1,player2,map1,map2);
    actualiser();
  }
  reinitialiser_evenements();
  screen_victory(player1,player2);
  traiter_evenements();
  actualiser();
}

void Is_pressed(Player *player1,Player *player2)
{
  if(touche_a_ete_pressee(SDLK_UP) && !(player2->up.is_moving) && !(player2->left.is_moving)&& !(player2->right.is_moving) && !(player2->down.is_moving))
    player2->up.pressed=1;
  else if(touche_a_ete_pressee(SDLK_DOWN) && !(player2->up.is_moving) && !(player2->left.is_moving)&& !(player2->right.is_moving) && !(player2->down.is_moving))
    player2->down.pressed=1;
  else if(touche_a_ete_pressee(SDLK_LEFT) && !(player2->up.is_moving) && !(player2->left.is_moving)&& !(player2->right.is_moving) && !(player2->down.is_moving))
    player2->left.pressed=1;
  else if(touche_a_ete_pressee(SDLK_RIGHT) && !(player2->up.is_moving) && !(player2->left.is_moving)&& !(player2->right.is_moving) && !(player2->down.is_moving))
    player2->right.pressed=1;
  if(touche_a_ete_pressee(SDLK_z) && !(player1->up.is_moving) && !(player1->left.is_moving)&& !(player1->right.is_moving) && !(player1->down.is_moving))
    player1->up.pressed=1;
  else if(touche_a_ete_pressee(SDLK_s) && !(player1->up.is_moving) && !(player1->left.is_moving)&& !(player1->right.is_moving) && !(player1->down.is_moving))
    player1->down.pressed=1;
  else if(touche_a_ete_pressee(SDLK_q) && !(player1->up.is_moving) && !(player1->left.is_moving)&& !(player1->right.is_moving) && !(player1->down.is_moving))
    player1->left.pressed=1;
  else if(touche_a_ete_pressee(SDLK_d) && !(player1->up.is_moving) && !(player1->left.is_moving)&& !(player1->right.is_moving) && !(player1->down.is_moving))
    player1->right.pressed=1;

}
void deplacement(Player *player1, Case map1[][H/lenght_Case])
{
  if(player1->up.pressed && !(map1[player1->position.x][(player1->position.y)-1].wall) && (player1->position.y>0))
  {
      printf("player1 %d\n",player1->Victory);
      player1->up.pressed=0;
      player1->down.pressed=0;
      player1->right.pressed=0;
      player1->left.pressed=0;
      player1->up.is_moving=1;
      player1->position.y-=1;
  }
  if(player1->down.pressed && !(map1[player1->position.x][(player1->position.y)+1].wall) && (player1->position.y<(H/lenght_Case)-1))
  { 
    player1->up.pressed=0;
    player1->down.pressed=0;
    player1->right.pressed=0;
    player1->left.pressed=0;
    printf("player1 %d\n",player1->Victory);
    player1->down.is_moving=1;
    player1->position.y+=1;
  }

  if(player1->left.pressed && !(map1[player1->position.x-1][(player1->position.y)].wall) && (player1->position.x>0))
  { 
    player1->up.pressed=0;
    player1->down.pressed=0;
    player1->right.pressed=0;
    player1->left.pressed=0;
    printf("player1 %d\n",player1->Victory);
    player1->left.pressed=0;
    player1->left.is_moving=1;
    player1->position.x-=1;
  }
  if(player1->right.pressed && !(map1[player1->position.x+1][(player1->position.y)].wall) && (player1->position.x<(W/lenght_Case-1)))
  {
    player1->up.pressed=0;
    player1->down.pressed=0;
    player1->right.pressed=0;
    player1->left.pressed=0;
    printf("player1 %d\n",player1->Victory);
    player1->right.is_moving=1;
    player1->position.x+=1;
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
  player1->Victory=map1[player1->position.x][player1->position.y].exit;
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
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    reinitialiser_evenements();
    attente(5);   
    traiter_evenements();
   
    move_player(player1);
    move_player(player2);
    deplacement(player1,map1);
    deplacement_IA(player2,map2);
    Is_pressed(player1,player2);
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
  player->position=path_IA(player->position,map);
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

