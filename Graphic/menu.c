void load_screen(int percent)
{
  Point corner_screen={0,0};
  
  int W_window=W*2+lenght_Case, H_window=H+lenght_Case*H_Map/4;
  
  Point corner={W_window/8,H_window-H_window/8};
  int Largeur=W_window-W_window/4;
  dessiner_rectangle(corner,Largeur,H_window/16,white);
  corner.x+=1;
  corner.y+=1;
  int percent_pixel=Largeur/100;
  if (percent<=102)
    dessiner_rectangle(corner,percent_pixel*percent+2,H_window/16-2,darkred);
  else
    dessiner_rectangle(corner,Largeur-2,H_window/16-2,darkgreen);
  actualiser();
}

void load_file()
{
	char text[1000] = "";
	fichier = fopen("score.txt", "r");
	Point corner = {0,0};
	dessiner_rectangle(corner,W*2+lenght_Case,H+lenght_Case*H_Map/4,black);
	Point corner2={0,0};
	Point size={W*2,H+lenght_Case*H_Map/4};
	afficher_image_resize("picture/Menu_template.bmp",corner2,size);
	if (fichier != NULL)
    {
    	int i=0;
    	while (fgets(text, 1000, fichier) != NULL) // On lit le fichier ligne par ligne  tant qu'on ne reçoit pas d'erreur (NULL)
        {
        		i+=1;
        		corner.y=(lenght_Case+taille_texte(text,20).y)*i;
        		corner.x=W+lenght_Case/2-taille_texte(text,20).x/2; 
            afficher_texte(text,20,corner,darkgoldenrod); // On affiche la chaîne qu'on vient de lire
        }
        fclose(fichier);
    }
   else
   {
			printf(" ERROR :score.txt -> no such file or directory\n");  
   }
   
   
}

void Input_file(int Timer_min,int Timer_sec,int Timer_cent_sec)
{
	char text[1000] = "Default player";
	fichier = fopen("score.txt", "a");
	Point corner = {0,0};
	dessiner_rectangle(corner,W*2+lenght_Case,H+lenght_Case*H_Map/4,black);
	corner.y=(H+lenght_Case*H_Map/4)/2-taille_texte("Rentrez votre pseudo dans la Console",50).y;
  corner.x=(W+(lenght_Case/2))-(taille_texte("Rentrez votre pseudo dans la Console",50).x/2);
  afficher_texte("Rentrez votre pseudo dans la Console",50,corner,darkgreen);
  actualiser();
  
  //scanf(text,"%s",text);
  if (fichier != NULL)
  {
  	if(Timer_cent_sec>=10)
  		fprintf(fichier, "%s : %dm %d,%ds \n", text,Timer_min,Timer_sec,Timer_cent_sec);
  	else 
  		fprintf(fichier, "%s : %dm %d,0%ds \n", text,Timer_min,Timer_sec,Timer_cent_sec);
  	fclose(fichier);
  }
  attendre_touche();
  attente(100);
	load_file();
	actualiser();
	attente(100);
	attendre_touche();
	
	
}
int Menu_display(int is_selected)
{
	Point corner={0,0};
	Point size={W*2,H+lenght_Case*H_Map/4};
	afficher_image_resize("picture/Menu_template.bmp",corner,size);
	corner.x=size.x/2-W/4;
	corner.y=lenght_Case*2;
	size.x=W/2;
	size.y=H/4;
	
	afficher_image_resize("picture/Menu_bar.bmp",corner,size);
	size.x=W/4;
	size.y=H/8;
	corner.x+=W/8;
	corner.y+=H/4+H/16;
	switch(is_selected)
	{
		case 0:
		afficher_image_resize("picture/Menu_play_on.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_option_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_score_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_quit_off.bmp",corner,size);
		break;
		
		case 1:
		afficher_image_resize("picture/Menu_play_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_option_on.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_score_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_quit_off.bmp",corner,size);
		break;
		
		case 2:
		afficher_image_resize("picture/Menu_play_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_option_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_score_on.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_quit_off.bmp",corner,size);
		break;
		
		case 3:
		afficher_image_resize("picture/Menu_play_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_option_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_score_off.bmp",corner,size);
		corner.y+=H/5;
		afficher_image_resize("picture/Menu_quit_on.bmp",corner,size);
		break;
	}
	actualiser();
}

int Menu_play_display(int is_selected)
{
	Point corner={0,0};
	Point size={W*2,H+lenght_Case*H_Map/4};
	afficher_image_resize("picture/Menu_template.bmp",corner,size);
	corner.x=size.x/2-W/4;
	corner.y=lenght_Case*2;
	size.x=W/2;
	size.y=H/4;
	
	afficher_image_resize("picture/Menu_bar_play.bmp",corner,size);
	size.x=W/4;
	size.y=H/8;
	corner.x+=W/8;
	corner.y+=H/4+H/16;
	switch(is_selected)
	{
		case 0:
		afficher_image_resize("picture/Menu_local_on.bmp",corner,size);
		corner.y+=H/4;
		afficher_image_resize("picture/Menu_ia_off.bmp",corner,size);
		corner.y+=H/4;
		afficher_image_resize("picture/Menu_multi_off.bmp",corner,size);
		break;
		
		case 1:
		afficher_image_resize("picture/Menu_local_off.bmp",corner,size);
		corner.y+=H/4;
		afficher_image_resize("picture/Menu_ia_on.bmp",corner,size);
		corner.y+=H/4;
		afficher_image_resize("picture/Menu_multi_off.bmp",corner,size);
		break;
		
		case 2:
		afficher_image_resize("picture/Menu_local_off.bmp",corner,size);
		corner.y+=H/4;
		afficher_image_resize("picture/Menu_ia_off.bmp",corner,size);
		corner.y+=H/4;
		afficher_image_resize("picture/Menu_multi_on.bmp",corner,size);
		break;
	}
	actualiser();
}

int Menu() 
{
  Point corner={0,0};
  Point size={W*2,H+lenght_Case*H_Map/4};
 	Menu_display(0);
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
    if((touche==SDLK_DOWN || touche==SDLK_s) && a<3)
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
				Menu_display(0);
				if(b)
				{
					done=1;
					type_partie=Menu_play();
				}
				break;
	 		case 1:
				Menu_display(1);
				break;

      case 2:
			Menu_display(2);
			if(b)
			{
				load_file();
				actualiser();
				attente(200);
				attendre_touche();
				Menu_display(2);
				actualiser();
				b=0;
			}
  	break;

      case 3:
	Menu_display(3);
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
  Menu_play_display(0);
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
	Menu_play_display(0);
	if(b)
	  done=1;
	break;

      case 1:
	Menu_play_display(1);
	if(b)
	  done=1;
  	break;

      case 2:
	Menu_play_display(2);
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
