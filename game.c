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
      int a=(entier_aleatoire(5)==1)?1:0;
      map1[i][j].wall=a;
      map2[i][j].wall=a;
      if(map1[i][j].wall)
	graphic_wall(i, j, 1)	;
      if(map2[i][j].wall)
	graphic_wall(i, j, 2)	;


      i++;
    }
    j++;
    i=0;
  }
  map1[(W/lenght_Case)-1][(H/lenght_Case)-1].exit=1;
  map2[(W/lenght_Case)-1][(H/lenght_Case)-1].exit=1;
  graphic_exit((W/lenght_Case)-1,(H/lenght_Case)-1,1);
  graphic_exit((W/lenght_Case)-1,(H/lenght_Case)-1,2);
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
    attente(60);
    traiter_evenements();
    Is_pressed(player1,player2);
    deplacement(player1,map1);
    deplacement(player2,map1);
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
      player1->up.is_moving=0;
	graphic_case(player1->position.x, player1->position.y,player1->ID);
	player1->position.y-=1;
	graphic_player(player1->position.x, player1->position.y,player1->ID);
      }
 if(player1->down.pressed && !(map1[player1->position.x][(player1->position.y)+1].wall) && (player1->position.y<(H/lenght_Case)-1))
      {
	 printf("player1 %d\n",player1->Victory);
	player1->down.pressed=0;
	player1->down.is_moving=0;
	graphic_case(player1->position.x, player1->position.y,player1->ID);
	player1->position.y+=1;
	graphic_player(player1->position.x, player1->position.y,player1->ID);
      }

 if(player1->left.pressed && !(map1[player1->position.x-1][(player1->position.y)].wall) && (player1->position.x>0))
      {
	 printf("player1 %d\n",player1->Victory);
	player1->left.pressed=0;
	graphic_case(player1->position.x, player1->position.y,player1->ID);
	player1->position.x-=1;
	graphic_player(player1->position.x, player1->position.y,player1->ID);
      }
 if(player1->right.pressed && !(map1[player1->position.x+1][(player1->position.y)].wall) && (player1->position.x<(W/lenght_Case-1)))
      {
	 printf("player1 %d\n",player1->Victory);
	player1->right.pressed=0;
	graphic_case(player1->position.x, player1->position.y,player1->ID);
	player1->position.x+=1;
	graphic_player(player1->position.x, player1->position.y,player1->ID);
      }


}
void Victory(Player *player1, Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
  player1->Victory=map1[player1->position.x][player1->position.y].exit;
  player2->Victory=map2[player2->position.x][player2->position.y].exit;  
}

void InitPlayer(Player *player1,int id)
{
  player1->position.x=0;
  player1->position.y=0;
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
