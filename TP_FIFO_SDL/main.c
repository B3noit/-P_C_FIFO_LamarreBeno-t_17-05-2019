#define WINDOW_WIDTH 1440
#define WINDOW_LENGTH 810

#include "actor.h"
#include "file.h"


/*
1-Cr�ation d'une liste de donn�e dynamique FIFO de type tActor
2- Utiliser la SDL afin de coder la vue
*/
int main( int argc, char* args[] )
{
    tGame tJeu;

//Cr�ation de la fen�tre
tJeu.pWindow = NULL;
tJeu.pWindow = SDL_CreateWindow("PlaneSpace",SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    WINDOW_WIDTH,
                                                    WINDOW_LENGTH,
                                                    SDL_WINDOW_SHOWN);

//Cr�ation du Renderer
tJeu.pRenderer = NULL;
tJeu.pRenderer=SDL_CreateRenderer(tJeu.pWindow,-1,SDL_RENDERER_ACCELERATED);

tJeu.nGameState =1;

    while(tJeu.nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
    {
    handleEvents(&tJeu);


    File *suite;
    tActor *tTampon;

    if ((suite = (File *) malloc (sizeof (File))) == NULL)
        return -1;
    if ((tTampon = (tActor *) malloc (sizeof (tActor))) == NULL)
        return -1;

    initialisationFile(suite);



///////////////Insertion de la premi�re image.
    printf ("\nUne prmi�re image est rentre dans la liste : le lapin \n ");

    tTampon->Vect.nX=0;
    tTampon->Vect.nY=0;
    tTampon->nHeight=278;
    tTampon->nWidth=300;
    strcpy(tTampon->cChemin,"./Assets/lapin.png");

    enFiler (suite, suite->fin, tTampon);
    printf ("La file contient (%d image)\n",suite->taille);
    printf("\nDebut de la FILE : ");
    afficheFile(suite,&tJeu);

    SDL_RenderClear(tJeu.pRenderer);

//////////////////////////Insertion de la deuxi�me image

    printf ("\n Une deuxi�me image est rentre dans la liste : le chapeau \n ");

    tTampon->Vect.nX=0;
    tTampon->Vect.nY=0;
    tTampon->nHeight=308;
    tTampon->nWidth=350;
    strcpy(tTampon->cChemin,"./Assets/chapeauMagic.png");

    enFiler (suite, suite->fin, tTampon);
    printf ("La file contient (%d images)\n",suite->taille);
    printf("\nDebut de la FILE : ");
    afficheFile(suite,&tJeu);

    SDL_RenderClear(tJeu.pRenderer);




///////////////////Insertion de la troisi�me image
    printf ("\nUne troisi�me image est rentre dans la liste : la baguette magique \n ");

    tTampon->Vect.nX=0;
    tTampon->Vect.nY=0;
    tTampon->nHeight=161;
    tTampon->nWidth=302;
    strcpy(tTampon->cChemin,"./Assets/baguette.png");

    enFiler (suite, suite->fin, tTampon);
    printf ("La file contient (%d images)\n",suite->taille);
    printf("\nDebut de la FILE : ");
    afficheFile(suite,&tJeu);

    SDL_RenderClear(tJeu.pRenderer);

///////////////////Sortie de la premi�re image ins�r�e
    printf ("\nLe premier entre (FirstInFirstOut) le lapin sera supprime");
    deFiler(suite);              // suppression de premier element entre
    printf ("La file (%d elements): \n",suite->taille);
    printf("\nDebut de la FILE [ ");
    afficheFile(suite,&tJeu);
    printf(" ] Fin de la FILE\n\n");

    free(tTampon);
    free(suite);

    tJeu.nGameState = 0;

    }
    return 0;
}

