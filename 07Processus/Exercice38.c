#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>
int main(){
    printf("PID: %d (à l'intérieur du recouvrement, donc après le recouvrement)\n",getpid());

    return 0;
}
