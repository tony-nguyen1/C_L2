#include <stdlib.h>

struct fifo {
    char** file; //tableau circulaire
    int tete;////tete de "lecture"
    int nb;//nombre d'éléments dans la file d'attente
    int taille;//nombre maximal d'éléments dans la liste
};


struct fifo * filocreer(int taille) {
    struct fifo * res;
    res = (struct fifo *) malloc(sizeof(struct fifo));
    //callo = malloc mais initialise tout
    //avec taille éléments de longueur char*
    res->file = (char**) calloc(taille, sizeof(char *));
    res->tete = 0;
    res->nb = 0;
    res->taille = 0;


    return res;
}
int fifo_supp(struct fifo * f) {
    free(f->file);
    return 0;
}

int fifo_ajouter(struct fifo * f, char* s) {
    if (f->nb >= f->taille) { //file d'attente pleine
        exit(EXIT_FAILURE);
    } else if (f->tete == f->taille-1) {//au bord du tableau
        f->file[0] = s;
    } else {
        f->file[f->tete+1] = s;
    }
    return 0;
}