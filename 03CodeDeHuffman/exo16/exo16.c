#include <sys/types.h>
#include <sys/stat.h>
//pour open
#include <stdio.h>
//pour fgetc

//TODO à finir
//+créer une fonction

int main (int argc, char* argv[]/*, char* env[]*/) {

    //création et initialisation du tableau à 0
    int nbOc[256];
    for (int i = 0; i < 256; i++) { nbOc[i] = 0;}

    //ouverture du fichier entrée en paramètre
    FILE * f = fopen(argv[1], "r");

    //gestion des erreurs de fopen
    if (f==NULL) {
        return -1;
    }

    int i;
    do {
        //lecture du fichier charactère par charactère
        i = fgetc(f);
        printf("%i = %c\n", i, (char) i);

        nbOc[i] += 1;
    } while (i != EOF);//End Of File or -1
    printf("End Of File\n");

    printf("Here : %i\n", nbOc[0]);

    //fermeture du fichier f
    fclose(f);

    return 0;
}