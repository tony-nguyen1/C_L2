#include <stdio.h>
#include <unistd.h> //fork(), getpid(), exec()
#include <sys/types.h> //toutes
#include <sys/wait.h>
int main(){
pid_t nPid;
if ((nPid = fork())==0){ //l'enfant
printf("Salut\n");
execlp("gcc", "gcc", "-Wall", "./monsh.c", "-o", "monsh", NULL);
}else{//le parent
int status;
wait(&status);}//chaque parent attend la fin de ses enfants

}
//execlp("ls", "ls", NULL);
//execl("/bin/ls", "ls", NULL);
//code source
//le fichier exécutable binaire
//l'exécutable binaire en mémoire centrale