


//fonction graphique
void init_ecran(Couleur c)
{
  int i=0,j=0;
  while(j<H*(H/2))
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
  Point size={lenght_Case,lenght_Case};
  afficher_image_resize("picture/Case_player.bmp",pp,size);
}
void graphic_anim(int pos_graph_x, int pos_graph_y, int nb_map)
{
  Point p;
  if(nb_map==2)
  {
    p.x=W+lenght_Case+pos_graph_x;
    p.y=pos_graph_y;
  }
  else
  {
    p.x=pos_graph_x;
    p.y=pos_graph_y;
  }
  Point size={lenght_Case,lenght_Case};
  afficher_image_resize("picture/Case_player.bmp",p,size);
}
void graphic_anim_erase(int pos_graph_x, int pos_graph_y, int nb_map)
{
  Point p;
  if(nb_map==2)
  {
    p.x=W+lenght_Case+pos_graph_x;
    p.y=pos_graph_y;
  }
  else
  {
    p.x=pos_graph_x;
    p.y=pos_graph_y;
  }
  dessiner_rectangle(p,lenght_Case,lenght_Case,gray);
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
  Point size={lenght_Case,lenght_Case};
  afficher_image_resize("picture/Case_exit.bmp",pp,size);
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
  Point size={lenght_Case,lenght_Case};
  afficher_image_resize("picture/Case_wall.bmp",p,size);
}
void graphic_key(int i, int j, int nb_map)
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
  Point size={lenght_Case,lenght_Case};
  afficher_image_resize("picture/Case_key.bmp",p,size);
}

void screen_victory(Player *player1, Player *player2)
{
  Point corner={0,0};
  Point size={(W*2)+lenght_Case,H+lenght_Case*H_Map/4};
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
   attente(2000);
   attendre_touche();

}
int Menu() 
{
  Point corner={0,0};
  Point size={W*2,H+lenght_Case*H_Map/4};
  afficher_image_resize("picture/Menu_template_play.bmp",corner,size);
  int a=0;
  actualiser();
  int done=0;
  int type_partie=0;
  while(!done)
  {
    attente(100);
    int touche=attendre_touche();
    printf("%d\n ",a);
    if((touche==SDLK_UP || touche==SDLK_z)&& a>0 )
    {
      a-=1;
    }
    if((touche==SDLK_DOWN || touche==SDLK_s) && a<2)
    {
      a+=1;
    }
    int b=0;
    if(touche==SDLK_RETURN)
      b=1;
    printf("%d\n ",a);
    switch(a)
    {
      case 0:
				afficher_image_resize("picture/Menu_template_play.bmp",corner,size);
	if(b)
	{
	  done=1;
	  type_partie=Menu_play();
	}
	break;

      case 1:
			afficher_image_resize("picture/Menu_template_option.bmp",corner,size);
			if(b)
			{
				load_file();
				actualiser();
				attente(200);
				attendre_touche();
				afficher_image_resize("picture/Menu_template_option.bmp",corner,size);
				actualiser();
				b=0;
			}
  	break;

      case 2:
	afficher_image_resize("picture/Menu_template_quit.bmp",corner,size);
	if(b)
	{
	done=1;
	type_partie=0;
	}
	break;
    }
    actualiser(); 
  }
  return type_partie;
}
int Menu_play()
{
  Point corner={0,0};
  Point size={(W*2)+lenght_Case,H+lenght_Case*H_Map/4};
  afficher_image_resize("picture/Menu_template_hotseat.bmp",corner,size);
  int a=0;
  actualiser();
  int done=0;
  while(!done)
  {
    attente(100);
    int touche=attendre_touche();
    printf("%d\n ",a);
    if((touche==SDLK_UP || touche==SDLK_z)&& a>0 )
    {
      a-=1;
    }
    if((touche==SDLK_DOWN || touche==SDLK_s) && a<2)
    {
      a+=1;
    }
    int b=0;
    if(touche==SDLK_RETURN)
      b=1;
    printf("%d\n ",a);
    switch(a)
    {
      case 0:
	afficher_image_resize("picture/Menu_template_hotseat.bmp",corner,size);
	if(b)
	  done=1;
	break;

      case 1:
	afficher_image_resize("picture/Menu_template_ia.bmp",corner,size);
	if(b)
	  done=1;
  	break;

      case 2:
	afficher_image_resize("picture/Menu_template_multiplayer.bmp",corner,size);
	if(b)
	  done=1;
	break;

    }
    if(touche==SDLK_BACKSPACE)
    {
      return Menu();
    }
    actualiser(); 
  }
  return a+1;
}
void dessiner_timer(int timer_min,int timer_sec,int timer_cent_sec)
{
	Point p={W,H+lenght_Case};
	
	char text[120];
	if (timer_min>=10)
  	sprintf(text,"%d ",timer_min);
  else 
  	sprintf(text,"0%d ",timer_min);
  char text2[120];
  if (timer_sec>=10)
  	sprintf(text2,": %d ",timer_sec);
  else
  	 sprintf(text2,": 0%d ",timer_sec);
  char text3[120];
  if(timer_cent_sec>=10)
  	sprintf(text3,": %d",timer_cent_sec);
  else
  	sprintf(text3,": 0%d",timer_cent_sec);
  strcat(text2,text3);
  strcat(text,text2);
  p.x-=taille_texte(text,30).x/2;
  dessiner_rectangle(p,taille_texte(text,30).x,taille_texte(text,30).y,gray);
  printf("%s\n",text);
	afficher_texte(text,30,p,red);
	if(timer_cent_sec==0)
		actualiser();
}
