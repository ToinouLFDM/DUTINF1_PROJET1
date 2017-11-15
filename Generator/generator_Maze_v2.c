void generator_Maze(Case map[][H_Map])
{
  int tab[W_Map][H_Map]={{0}};
  init_Lab(map,tab);
  int loop=0;
  while(!(is_Perfect(tab)))
  {
    break_Wall(map,tab);
    actualiser();
    loop+=1;
    if(loop%22==0)
    	printf("loop count -> %d %\n",loop/22);
    load_screen((loop/22));
  }
  while(loop/22<=102)
  {
    load_screen(loop/22);
    loop+=1;
    if(loop%22==0)
    	printf("loop count -> %d %\n",loop/22);
    attente(15);
  }
}

void init_Lab(Case map[][H_Map],int tab[][H_Map])
{
  int x=0,y=0,count=1;
  for(;x<W_Map;x++)
  {
    for(y=0;y<H_Map;y++)
    {
      if(!(y%2))
      {
	map[x][y].wall=1;
	tab[x][y]=0;
      }
      else
      {
	if(!(x%2))
	{
	  map[x][y].wall=1;
	  tab[x][y]=0;
	}
	else
	{
	  tab[x][y]=count;
	  count+=1;
	}
      }
      printf("%d ",tab[x][y]); //debug
    }
    printf("\n");  //debug
  }
}

int is_Perfect(int tab[][H_Map])
{
  int x=1,y=1,a=tab[1][1];
  for(;x<W_Map;x+=2)
  {
    for(y=1;y<H_Map;y+=2)
    {
      if(tab[x][y]!=a)
	return 0;
    }
  }
  return 1;
}

void break_Wall(Case map[][H_Map],int tab[][H_Map])
{
  int x=1, y=1;
  for(;y<H_Map-1;y++)
  {
    int a=(y%2)?2:1;
    for(x=a;x<W_Map-1;x+=2)
    {
      if((a==1 && tab[x][y-1]!=tab[x][y+1])||(a==2 && tab[x-1][y]!=tab[x+1][y]))
      {
	int alea=entier_aleatoire(H_Map*W_Map/3);
	if(alea==1)
	{
	  map[x][y].wall=0;
	  set_Path(tab,x,y);
	  return;
	}
      }
    }
  }
}

void set_Path(int tab[][H_Map],int x,int y)
{
  if(tab[x+1][y]!=0)
    tab[x][y]=tab[x+1][y];
  else if(tab[x][y+1]!=0)
    tab[x][y]=tab[x][y+1];
  set_Path_Rec(tab,x,y,x,y);
}

void set_Path_Rec(int tab[][H_Map], int x, int y,int from_x,int from_y)
{
  if(x+1>=W_Map || x-1<0 || y+1>=H_Map || y-1<0 )
    return;

  if((tab[x+1][y]+tab[x-1][y]+tab[x][y+1]+tab[x][y-1])==tab[x][y])
    return;

  if(tab[x+1][y]!=0 && from_x !=x+1)
  {
    tab[x+1][y]=tab[x][y];
    set_Path_Rec(tab,x+1,y,x,y);
  }
  if(tab[x-1][y]!=0 && from_x!=x-1)
  {
    tab[x-1][y]=tab[x][y];
    set_Path_Rec(tab,x-1,y,x,y);
  }
  if(tab[x][y+1]!=0 && from_y!=y+1)
  {
    tab[x][y+1]=tab[x][y];
    set_Path_Rec(tab,x,y+1,x,y);
  }
  if(tab[x][y-1]!=0 && from_y!=y-1)
  {
    tab[x][y-1]=tab[x][y];
    set_Path_Rec(tab,x,y-1,x,y);
  }
}

void debug_Print_Tab(int tab[][H_Map])
{
  int x=0,y;
  for(;x<W_Map;x++)
  {
    for(y=0;y<H_Map;y++)
    {
      printf("%d ",tab[x][y]);
    }
    printf("\n");
  }
}
