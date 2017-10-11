#define W 800
#define H 600
#define difficulty 6
#define taille_Case 20

#include "lib/libgraphique.h"
#include<stdio.h>
#include<math.h>
typedef struct CASE {
	
	Couleur c;
	int player;
	int monster;
	int wall_b;
	int wall_r;
}Case;

