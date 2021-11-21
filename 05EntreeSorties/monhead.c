#include <stdio.h> //fopen
#include <unistd.h> //exit
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void readNChar(int n,FILE * f);
void readNLigne(int n,FILE * f);

    //TODO
    /**
    * refaire en utilisant fgets; plus tard ...
    * implémenter la fonction sans fichier, lecture de l'entrée
    * standard
    **/

int main (int argc, char* argv[]/*, char* env[]*/) {

    //gestion erreur nombre d'arguments
    if (argc > 3) {
        printf("trop d'argument\n");
        exit(EXIT_FAILURE);
    } else if (argc == 3) { //lecture d'un fichier
        FILE * f;
        f = fopen(argv[2], "r");
        
        //gestion erreur ouverture fichier
        if (f == NULL) {
            //fprintf(stderr, "Value of errno: %d\n", errno);
            //perror("Error printed by perror");
            fprintf(stderr, "Error opening file: %s\n", strerror( errno ));
            printf("Erreur : Impossible d'ouvrir %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        //gestion erreur 2nd argument quand il y a des arguments
        if (argc > 1) { //lecture d'un fichier
            if (argv[1][0] != '-') {
                printf("mauvais format d'argument, pas de type : -123\n");
                exit(EXIT_FAILURE);
            }
            else if (argv[1][1] == 'c') {//carcatère par caractère
                char* s = &(argv[1][2]);
                int nbCharALire = atoi(s);//on considère qu'il n'a pas mit de charactère mélanger à des nombres

                readNChar(nbCharALire, f);
                printf("\n");
            } else { //lecture ligne par ligne
                //récupération des charactères sans le - et converstion en int
                char* s = &(argv[1][1]);
                int nbLigneALire = atoi(s);//on considère qu'il n'a pas mit de charactère mélanger à des nombres
                //printf("nb : %s\n", s);
                //printf("nbNB : %i\n", nbLigneALire);
                

                readNLigne(nbLigneALire,f);
            }
        }

        
        
        fclose(f);
        exit(EXIT_SUCCESS);
    } else if (argc == 1) { //lecture de l'entrée std
        printf("ici\n");
        int nbCharLu = 0;
        int c = fgetc(stdin);

        while (c != EOF && 10 > nbCharLu) {
            printf("%c", c);
            nbCharLu++;

            c = fgetc(stdin);
        }

    }
}

void readNChar(int n,FILE * f) {
    int nbCharLu = 0;
    int c = fgetc(f);

    while (c != EOF && n > nbCharLu) {
        printf("%c", c);
        nbCharLu++;

        c = fgetc(f);
    }
    
}
void readNLigne(int nbLigneALire,FILE * f) {
    
    int nbLigneLu = 0;
    int c;

    //lecture
    c = fgetc(f);
    while (c != EOF && nbLigneALire > nbLigneLu) {
        printf("%c", c);

        if (c == '\n') { nbLigneLu++; }

        c = fgetc(f);
    }
    printf("\n%i ligne lu\n", nbLigneLu);
}