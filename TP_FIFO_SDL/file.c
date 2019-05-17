#include "file.h"

void initialisationFile(File * suite){
  suite->debut = NULL;
  suite->fin = NULL;
  suite->taille = 0;
}

/* enfiler (ajouter) un élément dans la file */
int enFiler (File * suite, Element * courant, tActor *donnee){
  Element *nouveau_element;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
        return -1;
  if ((nouveau_element->donnee = (tActor *) malloc (sizeof (tActor)))
      == NULL)
        return -1;

  nouveau_element->donnee=donnee;

  if(courant == NULL && suite->taille == 0){

        suite->fin = nouveau_element;
        nouveau_element->suivant = suite->debut;
        suite->debut = nouveau_element;

  }else {
    if(courant->suivant == NULL){
        suite->fin = nouveau_element;
        nouveau_element->suivant = courant->suivant;
        courant->suivant = nouveau_element;
    }

  }
  suite->taille++;
  return 0;
}

/* deFiler (supprimer) un élément de la file */
int deFiler (File * suite){
  Element *supp_element;

  if (suite->taille == 0)
    return -1;

  supp_element = suite->debut;
  suite->debut = suite->debut->suivant;
  free (supp_element->donnee);
  free (supp_element);
  suite->taille--;
  return 0;
}

/* affichage de la file*/
void afficheFile(File *suite, tGame *tJeu){
//VAR
  SDL_Rect rectangleDest;
  SDL_Rect rectangleSource;
  Element *courant;
  int i;

    courant = suite->debut;
    printf("\n taille :%d \n",suite->taille);

  for(i=0;i<suite->taille;++i){
    printf("l'image numéro %d est mis dans le renderer \n",i);

    tJeu->pSurface = NULL;
    tJeu->pSurface = IMG_Load(courant->donnee->cChemin);

    courant->donnee->TextActor = SDL_CreateTextureFromSurface(tJeu->pRenderer,tJeu->pSurface);

    SDL_FreeSurface(tJeu->pSurface);


    rectangleSource.x=0;
    rectangleSource.y=0;
    rectangleSource.w=courant->donnee->nWidth;
    rectangleSource.h=courant->donnee->nHeight;

    SDL_QueryTexture(courant->donnee->TextActor,NULL,NULL,NULL,NULL);

    //Définition du rectangle dest pour dessiner Bitmap
    rectangleDest.x=courant->donnee->Vect.nX+i*300;//debut x
    rectangleDest.y=courant->donnee->Vect.nY;//debut y
    rectangleDest.w=rectangleSource.w; //Largeur
    rectangleDest.h=rectangleSource.h; //Hauteur

    SDL_RenderCopy(tJeu->pRenderer, courant->donnee->TextActor, &rectangleSource, &rectangleDest);
    SDL_RenderPresent(tJeu->pRenderer);
    SDL_Delay(2000);
    printf("Le renderer est affiché\n");

    if(suite->taille>1){
    printf("Ras le chemin est $%s et le cheminsuivant est %s\n",courant->donnee->cChemin,courant->suivant->donnee->cChemin);
    strcpy(courant->donnee->cChemin,courant->suivant->donnee->cChemin);
    }
  }
  //  SDL_RenderPresent(tJeu->pRenderer);
  //  SDL_Delay(2000);
}
