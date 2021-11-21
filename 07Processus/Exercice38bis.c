#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>
int main(){
    printf("PID: %d (avant recouvrement)\n",getpid());
    execl("/home/e20180001091/L2_info/C/7Processus/exo38.out", "exo38.out", NULL);
    printf("PID: %d (après recouvrement\n",getpid());//ne s'éxécute jamais
    
    return 0;
}
