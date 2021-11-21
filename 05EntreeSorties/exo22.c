#include <stdio.h> //fopen
#include <unistd.h> //exit
#include <stdlib.h> 


int main (int argc, char* argv[]/*, char* env[]*/) {
    if (argc == 1) {
        printf("pas d'argument\n");
        exit(EXIT_FAILURE);
    }

    FILE * f;
    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("arrive pas a ouvrir %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int nbTotal = 0;
    int c;

    c = fgetc(f);

    while (c != EOF) {
        nbTotal++;

        c = fgetc(f);
    }

    printf("%s : %i\n", argv[1], nbTotal);

    exit(EXIT_SUCCESS);
}
/*
tony.nguyen@etu.umontpellier.fr@t12:~/L2_info/C/5EntreeSorties$ time wc -c toto.txt12 toto.txt

real    0m0,003s
user    0m0,002s
sys     0m0,000s
tony.nguyen@etu.umontpellier.fr@t12:~/L2_info/C/5EntreeSorties$ time ./a.out toto.txt
toto.txt : 12

real    0m0,006s
user    0m0,001s
sys     0m0,000s

normalement sys avec fct de lib C plus petit (donc mieux)
normalement real avec wc plus grand (donc pire)
*/