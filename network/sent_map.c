void send_map (char buffer[])
{
  char *server_name = SERVEURNAME1;
  struct sockaddr_in serverSockAddr;
  struct hostent *serverHostEnt;
  long hostAddr;
  long status;
  bzero(&serverSockAddr,sizeof(serverSockAddr));
  hostAddr = inet_addr(SERVEURNAME1);
  if ( (long)hostAddr != (long)-1)
    bcopy(&hostAddr,&serverSockAddr.sin_addr,sizeof(hostAddr));
  else
  {
    serverHostEnt = gethostbyname(SERVEURNAME1);
    if (serverHostEnt == NULL)
    {
      printf("gethost rate\n");
      exit(0);
    }
    bcopy(serverHostEnt->h_addr,&serverSockAddr.sin_addr,serverHostEnt->h_length);
  }
  serverSockAddr.sin_port = htons(30000);
  serverSockAddr.sin_family = AF_INET;
  /* creation de la socket */
  if ( (to_server_socket = socket(AF_INET,SOCK_STREAM,0)) < 0)
  {
    printf("creation socket client ratee\n");
    exit(0);
  }
  /* requete de connexion */
  if(connect( to_server_socket,
	(struct sockaddr *)&serverSockAddr,
	sizeof(serverSockAddr)) < 0 )
  {
    printf("demande de connection ratee\n");
    exit(0);
  }
  /* envoie de donne et reception */
  write(to_server_socket,buffer,512);
  read(to_server_socket,buffer,512);
  printf("Envoi de : %s",buffer);
  /* fermeture de la connection */
  shutdown(to_server_socket,2);
  close(to_server_socket);
}

int fill (Case map[][H_Map],char buffer[] ,int index)
{
  int i;
  for (i = 0; i<500;i++)
  {	
    if (index >=H_Map*W_Map)
      return -2;
    int col = index/H_Map;
    if (map[col][index%H_Map].wall)
      buffer[i]='1';
    else if (map[col][index%H_Map].exit)
      buffer[i]='2';
    else if (map[col][index%H_Map].own.key1)
      buffer[i]='3';
    else if (map[col][index%H_Map].own.key2)
      buffer[i]='4';
    else if (map[col][index%H_Map].own.key3)
      buffer[i]='5';
    else 
      buffer[i]='0';
    index +=1;
  }
  return index;
}

void call_send_map(Case map[][H_Map])
{
  int index = -1;
  while (index != -2)
  {
    char buffer[512];
    index = fill (map,buffer,index);
    send_map(buffer);
  }
  char buffer[512];
  buffer[1] = '9';
  send_map(buffer);
  printf ("Fin de l'envoi de la map");
}

