


//fonction graphique
void init_ecran(Couleur c)
{
	int i=0,j=0;
	while(j<H)
	{
		while(i<((W*2)+lenght_Case))
		{
			Point p={i,j};
			changer_pixel(p,c);
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
void graphic_player(int i, int j,int nb_map)
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
	dessiner_rectangle(pp, lenght_Case, lenght_Case,darkblue);
}

void graphic_exit(int i, int j, int nb_map)
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
	dessiner_rectangle(pp, lenght_Case, lenght_Case,jaune);
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
 
void screen_victory(Player *player1, Player *player2)
{
  Point corner={0,0};
  Point size={W,H};
  dessiner_rectangle(corner,W+W+lenght_Case,H,black);
  corner.x=W/2;
  /*
  Point ptext={25,25};
  char text[12];
  sprintf(text,"%d",((player1->Victory)?player1->ID:player2->ID));
  strcat(text," est le gagnant");
  dessiner_rectangle(corner,25,25,white);
  afficher_texte(text,100,ptext,white);
  int i;
  for(i=1;i<256;i++)
  {
    afficher_texte("yolo",i,ptext,white);
    actualiser();
  }*/
  if(player1->Victory)
    afficher_image_resize("picture/victory_player1.bmp",corner,size);
  if(player2->Victory)
    afficher_image_resize("picture/victory_player2.bmp",corner,size);

  actualiser();

}
 
 
 

