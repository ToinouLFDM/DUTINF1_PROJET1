void generator(Case map[][H/lenght_Case])
{
  int nb_Loop=0;
  int nb_Case=(((H/lenght_Case)*2)/3);
  while (check_Map(map)!=1)
  {
    printf("nb_loop -> %d\n",nb_Loop);
    if (nb_Loop>=100)
    {
      nb_Case--;
      nb_Loop=0;
    }
    nb_Loop++;
    put_Wall(map,&nb_Loop,&nb_Case);
  }
}



int check_Map(Case map[][H/lenght_Case])
{
  printf("\n");
  int x,y;
  int tab[W/lenght_Case][H/lenght_Case]={{0}};
  for(x=0;x<W/lenght_Case;x++)
  {
    for(y=0;y<H/lenght_Case;y++)
    {
      tab[x][y]=1;
    }
  }
    check_Rec(tab,map,0,0);
  int i = 0 , j = 0;
  int a = 0;
  for (;j<H/lenght_Case;j++)
  {
    i=0;
    for (;i<W/lenght_Case;i++)
      printf("%d. ",tab[i][j]);
    printf("\n");
  }
  i = 0 ; j = 0;
  for (;i<W/lenght_Case;i++)
  {
    j=0;
    for (;j<H/lenght_Case;j++)
      {
	if (tab[i][j]>1)
	  a = 1;
	if (tab[i][j] == -1)		    //tab[x][y] == 1  -> 1 case a chemin unique
	  return 2;			    //		== 0 -> 1 mur
      }					    //		==  2  -> 1 case a chemin non unique
					    //          == -1 -> 1 case fermé
  }	
  return (a)?0:1;
}

void check_Rec(int tab[][H/lenght_Case],Case map[][H/lenght_Case],int x,int y)

{   
  /*if(x-1>=0 && y-1>=0 && x+1<W/lenght_Case && y+1<=H/lenght_Case &&
      tab[x-1][y]==-1 && tab[x][y-1]==-1 && tab[x+1][y]==-1 && tab[x][y+1]==-1)
  {
    tab[x][y]=-1;
  }
    if (map[x][y].wall == 1)
  {
    tab[x][y] = -1;
  }
  if (tab[x][y] == 2 || tab[x][y] == -1)
    return;
  tab[x][y]++;
  if (x-1>=0)
    check_Rec(tab,map,x-1,y);
  if (x+1<W/lenght_Case)
    check_Rec(tab,map,x+1,y);
  if (y-1>=0)
    check_Rec(tab,map,x,y-1);
  if (y+1<=H/lenght_Case)
    check_Rec(tab,map,x,y+1);*/
  for(x=0;x<W/lenght_Case;x++)
  { 
    for(y=0;y<H/lenght_Case;y++)
    {
      if(map[x][y].wall)
	tab[x][y]=0;
    }
  }

  for(x=0;x<W/lenght_Case;x++)
  {
    for(y=0;y<H/lenght_Case;y++)
    {
      if(!(check_Close(map,tab,x,y)) )
	return;	
    }
  }
     

  
  
  for (x=0; x<W/lenght_Case;x++)
  {
    for(y=0;y<H/lenght_Case;y++)
    {
      if(tab[x][y]==1)
      {
	if (tab[x-1][y-1]>=1 || tab[x-1][y+1]>=1 || tab[x+1][y+1]>=1 || tab[x+1][y-1]>=1)
	{
	  tab[x][y]=2;
	  return;
	}
      }
    }
  }
}

int check_Close(Case map[][H/lenght_Case],int tab[][H/lenght_Case],int x, int y)
{
  int i=x,j=y,count=0;
  while(x<W/lenght_Case || tab[x+1][y]>0)
    x+=1;

  if (x<W/lenght_Case)
  {
    while(y<H/lenght_Case || tab[x+1][y]==0 || tab[x][y+1]>0 )
      y++;

    if(y<H/lenght_Case && tab[x+1][y]>0 )
      return 1;
  }
  else
    count+=1;

  if(y<H/lenght_Case)
  {
    while(x>=0 || tab[x][y+1]==0 || tab[x-1][y]>0)
      x--;

    if(x>=0 && tab[x][y+1]>0)
      return 1;
  }
  else
    count+=1;

  if(x>=0)
  {
    while(y>=0 || tab[x-1][y]==0 || tab[x][y-1]>0)
      y--;
    if(y>=0 && tab[x-1][y]>0)
      return 1;
  }
  else
    count+=1;
  if(y>=0)
  {
    while(x<W/lenght_Case || tab[x][y-1]==0 || tab[x+1][y]>0)
      x++;
    if(x<H/lenght_Case && tab[x][y-1]>0)
      return 1;
  }
  else
    count+=1;
  if(x<W/lenght_Case)
  {
    while(y<H/lenght_Case || tab[x+1][y]==0 || tab[x][y+1]>0)
      y++;
    if(y<H/lenght_Case && tab[x+1][y]>0)
      return 1;
  }
  else
    count+=1;
  if(count>=3)
    return 1;
  tab[i][j]=-1;
  return 0;
}



void put_Wall(Case map[][H/lenght_Case], int *nb_loop, int *nb_Case)
{
  int rand_x = entier_aleatoire(W/lenght_Case);
  int rand_y = entier_aleatoire(H/lenght_Case);
  int i = 0;
  int a = check_Put_Wall(map,nb_Case,rand_x,rand_y);
  if (a==0)
  {
    nb_loop+=1;
    printf("nb_case -> %d\n",*nb_Case);
  }
  else 
  {  
    if (a==1)
    {
     while (i<*nb_Case && (rand_x+i < W/lenght_Case))  
     {
       map[rand_x+i][rand_y].wall=1;
       graphic_wall(rand_x+i,rand_y,1);
       i++;
       nb_loop=0;
      
     }
    }
   
    else
    {
      while (i<*nb_Case && (rand_y+i < H/lenght_Case))
      {
        map[rand_x][rand_y+i].wall=1;
	graphic_wall(rand_x,rand_y+i,1);
        i++;
        nb_loop=0;
      }
    }
  }
  actualiser();
  attendre_clic();
}


int check_Put_Wall(Case map[][H/lenght_Case],int *nb_Case,int rand_x,int rand_y)
{
  int i = 0, x = 0 , y = 0;
  int arret = *nb_Case+1-(2*(*nb_Case)/3);
  Case tmp[W/lenght_Case][H/lenght_Case];
  for (;x<W/lenght_Case;x++)
  {
    y=0;
    for(;y<H/lenght_Case;y++)
    {
      int wall=map[x][y].wall;
      tmp[x][y].wall=wall;
    }
  }
  if (entier_aleatoire(2))
  {
    while (i<arret && (rand_x+i<W/lenght_Case))
    {
      tmp[rand_x+i][rand_y].wall=1;
      printf("i=%d arret=%d \n",i,arret);
      i++;
    }
    if (i != arret)
      return 0;
    i=0;
    int j=0 ;				//
    printf("new_tmp\n");		//
    for (;j<H/lenght_Case;j++)		//
    {					//
      i=0;				//
      for (;i<W/lenght_Case;i++)	//
	printf("%d. ",tmp[i][j].wall);	//
      printf("\n");			//
    }					//
    i = 0;
     printf("check map tmp -> %d\n",check_Map(tmp));
    return (check_Map(tmp)!=2)?1:0;
  }
  else 
  {
    while (i<arret && (rand_y+i<H/lenght_Case))
    {
      tmp[rand_x][rand_y+i].wall=1;
      printf("i=%d arret=%d \n",i,arret);
      i++;
    }
    if (i != arret)
      return 0;
    i=0;
    int j=0;
    printf("new_tmp\n");
    for (;j<H/lenght_Case;j++)
    {
      i=0;
      for (;i<W/lenght_Case;i++)
	printf("%d. ",tmp[i][j].wall);
      printf("\n");
    }
    i = 0;
    printf("check map tmp -> %d\n",check_Map(tmp));
    return (check_Map(tmp)!=2)?2:0;
  }
}
