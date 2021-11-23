#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    printf("Hello world!\n");
    if (argc != 3)
    { 
        fprintf(stderr, "Incorrect number of arguments");
        exit(EXIT_FAILURE);
    }
    char *nomTubeLect, *nomTubeEcrit;
    nomTubeLect = argv[1];
    nomTubeEcrit = argv[2];

    
    
    pid_t pid, dip;
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        fprintf(stderr, "fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) 
    { //processus fils
        printf("Le parent\n");
        mkfifo(nomTubeLect, S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH);
        mkfifo(nomTubeEcrit, S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH);
        
        dip = fork();
        if (dip == -1) 
        {
            perror("fork");
            fprintf(stderr, "fork");
            exit(EXIT_FAILURE);
        } else if (dip == 0)
        { //enfant
            printf("L'enfant\n");
            //lancement d'un processus ecrivain
            execlp("./ecrivain.out", "./ecrivain.out", nomTubeEcrit, NULL);    
        } else 
        { //parent
            printf("Encore le parent\n");
            //lancement d'un processus lecteur
            execlp("./lecteur.out", "./lecteur.out", nomTubeLect, NULL);
        }
    } else //pid > 0
    { //processus père
        printf("Le grand parent\n");
        wait(0);
    }

    return 0;
}