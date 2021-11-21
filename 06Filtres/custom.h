#include <stdio.h> //fopen

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