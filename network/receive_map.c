
void receive_map(Case map[][H_Map])
{
  int client_socket;
  int index = 0;
  struct sockaddr_in mon_address, client_address;
  int mon_address_longueur, lg;
  bzero(&mon_address,sizeof(mon_address));
  mon_address.sin_port = htons(30000);
  mon_address.sin_family = AF_INET;
  mon_address.sin_addr.s_addr = htonl(INADDR_ANY);
  /* creation de socket */
  if ((ma_socket = socket(AF_INET,SOCK_STREAM,0))== -1)
  {
    printf("la creation rate\n");
    exit(0);
  }
  //signal(SIGINT,fin);
  /* bind serveur - socket */
  bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));
  /* ecoute sur la socket */
  listen(ma_socket,5);
  /* accept la connexion */
  mon_address_longueur = sizeof(client_address);
  while(1)
  {
    client_socket = accept(ma_socket,(struct sockaddr *)&client_address, &mon_address_longueur);
    if (fork() == 0)
    {
      close(ma_socket);
      lg = read(client_socket,buffer, 512);
      printf("le serveur a recu: %s\n",buffer);
      index = complete_map(map,index,buffer);
      if (index == -2)
	return;
      sprintf(buffer,"%s du serveur",buffer);
      write(client_socket,buffer, 512);
      shutdown(client_socket,2);
      close(client_socket);
      exit(0);
    }
  }
  shutdown(ma_socket,2);
  close(ma_socket);
}



int complete_map (Case map[][H_Map], int index, char buffer[])
{
  int i;
  for (i = 0; i<500;i++)
  {	
    if (index >=H_Map*W_Map)
      return -2;	
    int col = index/H_Map;
    switch (buffer[i])
    {
      case '1':
	map[col][index%H_Map].wall=1;
	break;
      case '2':
	map[col][index%H_Map].exit=1;
	break;
      case '3':
	map[col][index%H_Map].own.key1=1;
	break;
      case '4':
	map[col][index%H_Map].own.key2=1;
	break;
      case '5':
	map[col][index%H_Map].own.key3=1;
	break;
      default:
	break;
    }
    index++;
  }
  return index;
}



