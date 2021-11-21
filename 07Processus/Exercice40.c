#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>
#include <stdlib.h> //atoi()

    int main(int argc, char *argv[]){
        //printf("%d enfants", atoi(argv[1]));

        for(int i=0 ; i< atoi(&argv[1][0]) ; i++){
            pid_t nPid = fork();
            if (nPid==0){
                printf("[son] pid %d from [parent] pid %d\n",getpid(), getppid());
                exit(0);
            }

            //if (i == atoi(&argv[1][0])) wait(&nPid);
        }

        wait(NULL);

        return 0;
    }