


//fonction graphique
void init_ecran()
{
	int i=0,j=0;
	while(j<H)
	{
		while(i<((W*2)+lenght_Case))
		{
			Point p={i,j};
			changer_pixel(p,gray);
			i++;
		}	
		i=0;
		j++;
	}
	Point p1={W,0};
	dessiner_rectangle(p1,lenght_Case,H,darkgray);
}





void graphic_case(int i, int j,int nb_map)
{
	Point pp;
	if (nb_map==2){
		Point p={W+lenght_Case+(i*lenght_Case),j*lenght_Case};
		pp=p;
		}
	else{
		Point p={i*lenght_Case,j*lenght_Case};
		pp=p;
		}
	dessiner_rectangle(pp, lenght_Case, lenght_Case, gray);
}




void graphic_wall(int i, int j, int nb_map)
{
	Point p;
	if (nb_map==2){
		p.x=W+lenght_Case+(i*lenght_Case);
		p.y=j*lenght_Case;
		}
	else{
		p.x=i*lenght_Case;
		p.y=j*lenght_Case;
		
		}
	dessiner_rectangle(p, lenght_Case, lenght_Case, black);
}
 
 
 
 
 

