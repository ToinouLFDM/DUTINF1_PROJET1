#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include "../parametre.h"

#define SERVEURNAME "192.168.1.33"

struct sockaddr_in;
struct hostent;

typedef struct Map{
  int x;
  int y;
}Map;


int to_server_socket = -1;

void send_map ( Case map[][H_Map],int i)
{

  char *server_name = SERVEURNAME;
  struct sockaddr_in serverSockAddr;
  struct hostent *serverHostEnt;
  long hostAddr;
  long status;
  Case[W_Map] buffer[2048];

  bzero(&serverSockAddr,sizeof(serverSockAddr));
  hostAddr = inet_addr(SERVEURNAME);
  if ( (long)hostAddr != (long)-1)
    bcopy(&hostAddr,&serverSockAddr.sin_addr,sizeof(hostAddr));
  else
  {
    serverHostEnt = gethostbyname(SERVEURNAME);
    if (serverHostEnt == NULL)
    {
      printf("Probleme: hote introuvable \n");
      exit(0);
    }
    bcopy(serverHostEnt->h_addr,&serverSockAddr.sin_addr,serverHostEnt->h_length);
  }
  serverSockAddr.sin_port = htons(30000);
  serverSockAddr.sin_family = AF_INET;

  /* creation de la socket */
  if ( (to_server_socket = socket(AF_INET,SOCK_STREAM,0)) < 0)
  {
    printf("Problème: creation socket client\n");
    exit(0);
  }
  /* requete de connexion */
  if(connect( to_server_socket,
	(struct sockaddr *)&serverSockAddr,
	sizeof(serverSockAddr)) < 0 )
  {
    printf("Problème: demande de connection\n");
    exit(0);
  }
  /* envoie de donne et reception */
  write(to_server_socket,map[i],sizeof(Case)*H_Map);
  read(to_server_socket,buffer,2048);
  //printf("%s\n",buffer);
  /* fermeture de la connection */
  shutdown(to_server_socket,2);
  close(to_server_socket);
}

void call_send_map (Case map[][H_Map])
{
  int i;
  for (i = 0 ; i < W_Map ; i++)
    send_map(map,i);
}

