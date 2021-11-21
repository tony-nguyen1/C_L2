#include "fifo.h" //struct fifo
#include "custom.h" //readNChar() & 
#include <stdio.h>
#include <string.h>//strcmp()
#include <stdlib.h>
#include <stdio.h> //fopen

int main (int argc, char* argv[]/*, char* env[]*/) {
    int nb = 0;
    int mode_lecture = 0;
    //par défaut, 0 c'est lecture en ligne
    // 1 c'est lecture charactère par charactère
    char input[] = "entreStandard"; //ou fichier
    if (argc >= 4) {
        printf("trop d'argument\n");
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        char* s;
        if (argv[1][1] == 'c') { //TODO -c123
            mode_lecture = 1;
            s = &argv[1][2];
            nb = atoi(s);
        } else {//-123
            mode_lecture = 0;
            s = &argv[1][1];
            nb = atoi(s); //head -3 monfic.txt
        }
        printf("nb = %i\n", nb);
    } 
    if (argc == 0) {
        printf("0 arg\n");
    }

    struct fifo * fileAttente;
    fileAttente = filocreer(nb);

    if (strcmp(input, "entreStandard")==0) {//lecture dans sdtin
        if (mode_lecture==0) {//par ligne
            readNLigne(nb, stdin);
            printf("\n");
        } else if (mode_lecture==1) {//par charactère
            int c = fgetc(stdin);

            printf("ici\n");

            while (c != EOF) {//lecture du fichier entier
                printf("là\n");
                char mot[2] = "";
                mot[0] = (char) c;
                mot[1] = '\0';
                printf("nb : %i; taille : %i\n", fileAttente->nb, fileAttente->taille);
                
                fifo_ajouter(fileAttente, mot);
                printf("là\n");
                c = fgetc(stdin);
            }
            
            int i = fileAttente->nb;
            while (i < fileAttente->taille) {
                printf("%s", fileAttente->file[i]);
                if (i == fileAttente->taille-1) { i = 0; }
                else { i++; }
            }
            printf("\n");
        }
    } else { //lecture dans un fichier

    }

    exit(EXIT_SUCCESS);
}