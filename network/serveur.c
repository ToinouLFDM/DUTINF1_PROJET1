#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>

#include "../parametre.h"

void fin (int i);
void appli(int no_client_socket);
Case[W_Map] buffer[2048];
int ma_socket;

void receive_map (Case map[][H_Map])
{
  int client_socket;
  struct sockaddr_in mon_address, client_address;
  int mon_address_longueur, lg;

  bzero(&mon_address,sizeof(mon_address));
  mon_address.sin_port = htons(30000);
  mon_address.sin_family = AF_INET;
  mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

  /* creation de socket */
  if ((ma_socket = socket(AF_INET,SOCK_STREAM,0))== -1)
  {
    printf("Problème : Création du socket\n");
    exit(0);
  }
  signal(SIGINT,fin);
  /* bind serveur - socket */
  bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));

  /* ecoute sur la socket */
  listen(ma_socket,5);

  /* accept la connexion */
  mon_address_longueur = sizeof(client_address);
  int i;
  for (i = 0; i<W_Map ; i++)
  {
    client_socket = accept(ma_socket,
	(struct sockaddr *)&client_address,
	&mon_address_longueur);

    if (fork() == 0)
    {
      close(ma_socket);

      lg = read(client_socket,buffer, 2048);
      printf("le serveur a recu la ligne %d\n",i);
      map[i] = buffer;
      write(client_socket,buffer, 2048);
      shutdown(client_socket,2);
      close(client_socket);
      exit(0);
    }
  }
  shutdown(ma_socket,2);
  close(ma_socket);
}


void appli(int no_client_socket)
{
  printf("ici le serveur\n");
}

void fin(int i)
{
  shutdown(ma_socket,2);
  close(ma_socket);
}
