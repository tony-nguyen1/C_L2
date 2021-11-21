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

    if (buf.st_mode & S_IRUSR) { printf("r"); } else { printf("-"); }
    if (buf.st_mode & S_IWUSR) { printf("w"); } else { printf("-"); }
    if (buf.st_mode & S_IXUSR) { printf("x"); } else { printf("-"); }
    if (buf.st_mode & S_IRGRP) { printf("r"); } else { printf("-"); }
    if (buf.st_mode & S_IWGRP) { printf("w"); } else { printf("-"); }
    if (buf.st_mode & S_IXGRP) { printf("x"); } else { printf("-"); }
    if (buf.st_mode & S_IROTH) { printf("r"); } else { printf("-"); }
    if (buf.st_mode & S_IWOTH) { printf("w"); } else { printf("-"); }
    if (buf.st_mode & S_IXOTH) { printf("x"); } else { printf("-"); }
    printf("\n");
    

    exit(EXIT_SUCCESS);
}
//http://manpagesfr.free.fr/man/man2/stat.2.html