#include <stdio.h> // <cstdio> en C++
#include <stdlib.h> //pour atoi

//déclaration des prototypes de mes fonctions
//pour pouvoir l'écrire après le main qui l'utilise
void carToChar(int nb);

int main (/*int argc, char* argv[]*/) {

    carToChar(123);


    return 0;
}

void carToChar(int nb) {
    //char c;
    //while (nb > 0) {
    int dernierChiffreADroite;

    dernierChiffreADroite = nb % 10; //le chiffre le plus à droite

    char ch = dernierChiffreADroite + '0';

    printf("%c", ch);

    printf("hello\n");

    nb = nb / 10;//on décale tous les chiffres vers la droite 

    //}
}