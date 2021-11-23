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
    printf("Lancement du lecteur\n");
    if (argc != 2)
    { 
        fprintf(stderr, "Incorrect number of arguments");
        exit(EXIT_FAILURE);
    }

    int in = open("monfifo",O_RDONLY);

    if (in < 0) 
    {
        fprintf(stderr, "Value of errno: %d\n", errno);
        fprintf(stderr, "Error opening file: %s\n", strerror( errno ));
        //printf("arrive pas a ouvrir %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char s[64];
    int nbLu;

    //printf("reading\n");
    while ((nbLu = read(in, s, 64)) != 0)
    {
        
        s[nbLu]='\0';
        printf("%s\n", s);


        if (strcmp(s, "exit") == 0) 
        {
            printf("\"%s\" compared to \"exit\" = True; exiting now\n", s);
        }
    }

    return 0;
}