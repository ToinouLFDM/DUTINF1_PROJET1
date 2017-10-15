//foncion calcul initialision
Point init_damier(Case map[][H/taille_Case]);

//fonction calcul inGame
Point deplacement_player(Case map[][H/taille_Case], Point player, int *isMoving );
void Game(Case map[][H/taille_Case],Case map2[][H/taille_Case], Point p, Point m);

//foncion calcul initialision
Point init_damier(Case map[][H/taille_Case])
{
	int i=0,j=0, count=0;
	
	while (j<(H/taille_Case))
	{
		while(i<(W/taille_Case))
		{
			
			map[i][j].c=((count%2)==0)?gray:gray;
			map[i][j].wall_r=(entier_aleatoire(difficulty)==1)?1:0;
			map[i][j].wall_b=(entier_aleatoire(difficulty)==1)?1:0;
			map[i][j].player=0;
			map[i][j].monster=0;
			i++;
			count+=1;
		}
		i=0;
		j++;
	}
	Point p={0,0};
	map[0][0].player=1;
	return p;
}




//fonction calcul inGame
void Game(Case map[][H/taille_Case],Case map2[][H/taille_Case], Point p, Point m)
{
	int life=1;
	int isMoving=0;
	map[m.x][m.y].monster=1;
	while(life)
	{
		p=deplacement_player(map,p, &isMoving );
		if (isMoving)
		{
			m=path_monster(map2, m, p);
		}
		
		actualiser();
	}
}
Point deplacement_player(Case map[][H/taille_Case], Point p, int *isMoving  )
{
	int touche=0;
	
	touche = attendre_touche();
	if(touche == SDLK_DOWN && !map[p.x][p.y].wall_b && p.y<(H/taille_Case) && !*isMoving)
	{
		map[p.x][p.y].player=0;
		graphisme_case(p.x,p.y, map[p.x][p.y].c);
		p.y+=1;
		map[p.x][p.y].player=1;
		graphisme_case(p.x,p.y, darkblue);
	}
	if(touche == SDLK_RIGHT && !map[p.x][p.y].wall_r && p.y<(W/taille_Case) && !*isMoving)
	{
		map[p.x][p.y].player=0;
		graphisme_case(p.x,p.y, map[p.x][p.y].c);
		p.x+=1;
		map[p.x][p.y].player=1;
		graphisme_case(p.x,p.y, darkblue);
	}
	if(touche == SDLK_UP && !map[p.x][p.y-1].wall_b && p.y>0 && !*isMoving)
	{
		map[p.x][p.y].player=0;
		graphisme_case(p.x,p.y, map[p.x][p.y].c);
		p.y-=1;
		map[p.x][p.y].player=1;
		graphisme_case(p.x,p.y, darkblue);
	}
	if(touche == SDLK_LEFT && !map[p.x-1][p.y].wall_r && p.y>0 && !*isMoving)
	{
		map[p.x][p.y].player=0;
		graphisme_case(p.x,p.y, map[p.x][p.y].c);
		p.x-=1;
		map[p.x][p.y].player=1;
		graphisme_case(p.x,p.y, darkblue);
	}
	
	if (*isMoving)
	{
		*isMoving=0;
		attente(200);
	}
	else 
	{
		*isMoving=touche;
	}
	return p;
}
