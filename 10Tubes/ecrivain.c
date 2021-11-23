#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    printf("Lancement de l'écrivain\n");
    if (argc != 2)
    { 
        fprintf(stderr, "Incorrect number of arguments");
        exit(EXIT_FAILURE);
    }

    int r = mkfifo(argv[1], S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH);
    int out = open(argv[1], O_WRONLY);

    if (out < 0) 
    {
        fprintf(stderr, "Value of errno: %d\n", errno);
        fprintf(stderr, "Error opening file: %s\n", strerror( errno ));
        //printf("arrive pas a ouvrir %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char s[64];
    do 
    {
        printf("you$ ");
        scanf("%s",s);

        int nbEcrit = write(out, s, strlen(s));
    } while(strcmp(s,"exit")!=0);

    return 0;
}