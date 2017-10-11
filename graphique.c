#include "parametre.h"


//fonction graphique
void init_ecran(Couleur c)
{
	int i=0,j=0;
	while(j<H)
	{
		while(i<W)
		{
			Point p={i,j};
			changer_pixel(p,c);
			i++;
		}	
		i=0;
		j++;
	}
}




void graphisme_case(int i, int j, Couleur c)
{
	Point p={i*taille_Case,j*taille_Case};
	dessiner_rectangle(p, taille_Case-1, taille_Case-1, c);
}




void graphisme_wall(int i, int j, int wall_r, int wall_b)
{
	Point p={i*taille_Case,j*taille_Case};
	Point p2={i*taille_Case,j*taille_Case};
	p.x+= (wall_r)?taille_Case-1:0;
	p.y+= (wall_r)?0:taille_Case-1;
	p2.x+=taille_Case-1;
	p2.y+=taille_Case-1;
	printf("p1 %d %d, p2 %d %d \n",p.x,p.y,p2.x,p2.y );
	dessiner_ligne(p,p2,black);
}
 
 
 
 
 
void graphisme_damier(Case map[][H/taille_Case],Point player)
{
	int i=0, j=0;
	init_ecran(gray);
	while (j<(H/taille_Case))
	{
		while(i<(W/taille_Case))
		{
			graphisme_case(i,j,map[i][j].c);
			if(map[i][j].wall_r)
			{
				
				graphisme_wall(i,j, 1, 0);
			}
			if(map[i][j].wall_b)
			{
				
				graphisme_wall(i,j, 0, 1);
			}
			
			i++;
		}
		j++;
		i=0;
	}
	graphisme_case(player.x/taille_Case,player.y/taille_Case,darkblue);
	actualiser();
}

