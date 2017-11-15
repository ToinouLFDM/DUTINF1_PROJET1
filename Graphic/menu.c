void load_screen(int percent)
{
  Point corner_screen={0,0};
  int W_window=W*2+lenght_Case, H_window=H+lenght_Case*H_Map/4;
  dessiner_rectangle(corner_screen,W_window,H_window,black);
  Point corner={W_window/8,H_window-H_window/8};
  int Largeur=W_window-W_window/4;
  dessiner_rectangle(corner,Largeur,H_window/16,white);
  corner.x+=1;
  corner.y+=1;
  int percent_pixel=Largeur/100;
  if (percent<=102)
    dessiner_rectangle(corner,percent_pixel*percent+2,H_window/16-2,red);
  else
    dessiner_rectangle(corner,Largeur-2,H_window/16-2,red);
  actualiser();
}

void load_file()
{
	char text[1000] = "";
	fichier = fopen("score.txt", "r");
	Point corner = {0,0};
	dessiner_rectangle(corner,W*2+lenght_Case,H+lenght_Case*H_Map/4,black);
	if (fichier != NULL)
    {
    	int i=0;
    	while (fgets(text, 1000, fichier) != NULL) // On lit le fichier ligne par ligne  tant qu'on ne reçoit pas d'erreur (NULL)
        {
        		i+=1;
        		corner.y=(lenght_Case+taille_texte(text,20).y)*i;
        		corner.x=W+lenght_Case/2-taille_texte(text,20).x/2; 
            afficher_texte(text,20,corner,darkgreen); // On affiche la chaîne qu'on vient de lire
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
