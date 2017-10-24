


//fonction graphique
void init_ecran()
{
	int i=0,j=0;
	while(j<H)
	{
		while(i<W)
		{
			Point p={i,j};
			changer_pixel(p,gray);
			i++;
		}	
		i=0;
		j++;
	}
}





/*void graphic_case(int i, int j,int nb_map)
{
	if (nb_map==2)
		Point p={W+lenght_Case+(i*lenght_Case),j*lenght_Case};
	else
		Point p={i*lenght_Case,j*lenght_Case};
	dessiner_rectangle(p, lenght_Case-1, lenght_Case-1, gray);
}




void graphic_wall(int i, int j, int nb_map)
{
	if (nb_map==2)
		Point p={W+lenght_Case+(i*lenght_Case),j*lenght_Case};
	else
		Point p={i*lenght_Case,j*lenght_Case};
	dessiner_rectangle(p, lenght_Case-1, lenght_Case-1, black);
}
 */
 
 
 
 
void graphic_map(Case map1[][H/lenght_Case],Case map2[][H/lenght_Case])
{
	int i=0, j=0;
	init_ecran();
	while (j<(H/lenght_Case))
	{
		while(i<(W/lenght_Case))
		{
			
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
