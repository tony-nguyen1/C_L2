#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h> //printf()
#include <stdlib.h> //exit()

int main(int argc, char *argv[]) {
    printf("Hello world !\n");

    if (argc < 2) { 
        printf("Pas assez d'argument, write a path to a file.\n");
        exit(EXIT_FAILURE);
    }


    struct stat buf;
    int res = stat(argv[1], &buf);

    if (res == 1) {
        printf("problème avec stat");
    }

    if (S_ISREG(buf.st_mode)) {
        printf("%s is a file\n", argv[1]);
    } else if (S_ISDIR(buf.st_mode)) {
        printf("%s is a directory\n", argv[1]);
    } else {
        printf("other ... \n");
    }

    

    exit(EXIT_SUCCESS);
}
//http://manpagesfr.free.fr/man/man2/stat.2.html