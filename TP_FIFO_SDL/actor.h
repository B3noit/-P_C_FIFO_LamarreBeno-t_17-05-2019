#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include "game.h"
#include "vector2d.h"

#include <string.h>

typedef struct tActor{

SDL_Texture *TextActor;//Texture de l'acteur
tVector2d Vect;//coordonées
char cChemin[50];//Chemin de l'image de l'acteur
int nHeight;//Longueur de l'acteur
int nWidth;//Largeur de l'acteur
}tActor;

#endif // ACTOR_H_INCLUDED
