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
    dessiner_rectangle(corner,percent_pixel*percent,H_window/16-2,red);
  actualiser();
}
