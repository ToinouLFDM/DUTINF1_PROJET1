//fonction Pathfiniding
Point path_monster(Case map[][H/taille_Case], Point monster, Point player);
void path_monster_rec (Case map[][H/taille_Case], int tab[][H/taille_Case], int i, int j);
int min(  int a, int b, int c, int d);

//fonction Pathfiniding
		Point path_monster(Case map[][H/taille_Case], Point m, Point p)
		{
			int tabx1[W/taille_Case][H/taille_Case]= {0};
			int tabx2[W/taille_Case][H/taille_Case]= {0};
			int taby1[W/taille_Case][H/taille_Case]= {0};
			int taby2[W/taille_Case][H/taille_Case]= {0};
			
			printf("player %d %d \n",p.x,p.y );
			printf("monster %d %d \n",m.x,m.y );
			if (m.x<(W/taille_Case) && !map[m.x][m.y].wall_r)
			{	
				tabx1[m.x+1][m.y]=1;
				path_monster_rec(map, tabx1, m.x+1, m.y);
				printf("path1\n" );
			}
			if (m.x>0 && !map[m.x-1][m.y].wall_r)
			{	
				tabx2[m.x-1][m.y]=1;
				path_monster_rec(map, tabx2, m.x-1, m.y);
				printf("path2\n" );
			}
			if (m.y<(H/taille_Case) && !map[m.x][m.y].wall_b)
			{	
				taby1[m.x][m.y+1]=1;
				path_monster_rec(map, taby1, m.x, m.y+1);
				printf("path3\n" );
			}
			if (m.y>0 && !map[m.x][m.y-1].wall_b)
			{	
				taby2[m.x][m.y-1]=1;
				path_monster_rec(map, taby2, m.x, m.y-1);
				printf("path4\n" );
			}
			printf("%d %d %d %d\n", tabx1[p.x][p.y],tabx2[p.x][p.y],taby1[p.x][p.y],taby2[p.x][p.y]);
			int mini = min(tabx1[p.x][p.y],tabx2[p.x][p.y],taby1[p.x][p.y],taby2[p.x][p.y]);
			map[m.x][m.y].monster=0;
			graphisme_case(m.x,m.y, map[m.x][m.y].c);
			switch (mini)
			{
				case 1:
				m.x+=1;
				break;
				
				case 2:
				m.x -=1;
				break;
				
				case 3:
				m.y+=1;
				break;
				
				case 4:
				m.y-=1;
				break;
			}
			map[m.x][m.y].monster=1;
			graphisme_case(m.x,m.y, jaune);
			
			printf("monster %d %d \n",m.x,m.y );
			return m;
		}
		int min( int a, int b, int c, int d)
		{
			
			if ((a<=b && a>0) || !b)
			{
				if (a<=c || !c)
				{
					if (a<=d || !d)
					{
						return 1;
					}		
				}
			}
			if ((b<=a && b>0) || !a)
			{
				if (b<=c|| !c)
				{
					if ( b<=d || !d)
					{
						return 2;
					}		
				}
			}
			if ((c<=a && c>0) || !a)
			{
				if (c<=b || !b)
				{
					if (c<=d || !d)
					{
						return 3;
					}		
				}
			}
			if ((d<=a && d>0 ) || !a)
			{
				if (d<=b || !b)
				{
					if (d<=c || !c)
					{
						return 4;
					}		
				}
			}
			return 0;
		}
		
		void path_monster_rec (Case map[][H/taille_Case], int tab[][H/taille_Case], int i, int j)
		{
			if (i-1>=0 && !map[i-1][j].wall_r)
			{
		  	if (tab[i-1][j] == 0)
		  	{
				  tab[i-1][j]=tab[i][j]+1;
				  path_monster_rec(map, tab,i-1,j);
    		}
		  	else if (tab[i-1][j] > tab[i][j])
		  	{
				  tab[i-1][j]=tab[i][j]+1;
				  path_monster_rec(map, tab,i-1,j);
    		}
 		 	}

			if (j-1>=0 && !map[i][j-1].wall_b)
			{
				if (tab[i][j-1] == 0)
				{
				  tab[i][j-1]=tab[i][j]+1;
				  path_monster_rec(map, tab,i,j-1);
				}
				else if (tab[i][j-1] > tab[i][j])
				{
				  tab[i][j-1]=tab[i][j]+1;
					path_monster_rec(map, tab,i,j-1);
				}
			}


			if (i+1<(W/taille_Case) && !map[i][j].wall_r)
			{
				if (tab[i+1][j] == 0)
				{
					tab[i+1][j]=tab[i][j]+1;
					path_monster_rec(map, tab,i+1,j);
				}
				else if (tab[i+1][j] > tab[i][j])
				{
					tab[i+1][j]=tab[i][j]+1;
					path_monster_rec(map, tab,i+1,j);
				}
			}

			if (j+1<(H/taille_Case) && !map[i][j].wall_b)
			{
				if (tab[i][j+1] == 0)
				{
				tab[i][j+1]=tab[i][j]+1;
				path_monster_rec(map, tab,i,j+1);
				}
				else if (tab[i][j+1] > tab[i][j])
				{
					tab[i][j+1]=tab[i][j]+1;
					path_monster_rec(map, tab,i,j+1);
				}
			}
			//printf("%d ",tab[i][j]);
		}
