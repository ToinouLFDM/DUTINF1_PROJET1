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
    afficher_key(player1,player2);
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

