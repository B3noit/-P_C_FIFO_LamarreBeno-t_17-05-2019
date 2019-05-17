#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "game.h"
#include "actor.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ElementListe{

    tActor *donnee;
    struct ElementListe *suivant;

} Element;

typedef struct ListeReperePile{
  Element *debut;
  Element *fin;
  int taille;
} File;

/* initialisation */
extern void initialisationFile (File * suite);


/* ENFILER*/
extern int enFiler (File * suite, Element * courant, tActor *donnee);

/* DE_FILER*/
extern int deFiler (File * suite);

/* FirstInFirstOut */
#define file_donnee(suite) suite->debut->donnee

/* Affiche la file */
extern void afficheFile(File *suite, tGame *tJeu);
#endif // FILE_H_INCLUDED
