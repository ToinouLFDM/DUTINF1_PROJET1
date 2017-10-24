void init_maps(Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
  int i=0, j=0;
  init_ecran();
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
  actualiser();
}

void game(Player *player1, Player *player2, Case map1[][H/lenght_Case], Case map2[][H/lenght_Case])
{
  while(!(player1->Victory) &&!(player2->Victory) )
  {
    attente(1);
    reinitialiser_evenements();
    traiter_evenements();
              
    printf("player1 %d,player2 %d\n",player1->Victory,player2->Victory);
    Victory(player1,player2,map1,map2);
  }

}

void Victory(Player *player1, Player *player2,Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
  player1->Victory=map1[player1->position.x][player1->position.y].exit;
  player2->Victory=map2[player2->position.x][player2->position.y].exit;  
}
