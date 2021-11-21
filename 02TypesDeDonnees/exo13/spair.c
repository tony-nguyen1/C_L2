#include "pair.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]/*, char* env[]*/) {

    if (argc!=2) {
        fprintf(stdin, "Syntaxe:%s <entier>", argv[0]);
        return 1; //error
    }

    if (pair(atoi(argv[1]))) {
        printf("%s est pair", argv[1]);
    } else {
        printf("%s est impair", argv[1]);
    }

    return 0;
}

/**
{Compilation :
gcc -c pair.c impair.c spair.c -Wall

Éditeur de liens
gcc *.o -o spair}

ou

{gcc -o spair *.c -Wall}

Exécution
./spair 18
./spair 19
**/