#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


void crible(int in[2]);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        perror("mauvais nb d'arg");
        exit(EXIT_FAILURE);
    }
    
    int fd[2];
    int childpid;

    pipe(fd);
        
    if((childpid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(childpid == 0) {//enfant
        crible(fd);
    }
    else {
        // Père

        //fermeture de la lecture
        close(fd[0]);

        for (int i = 2; i < atoi(argv[1]); i++) {
            //Write to the pipe
            //printf("%i\n", i);
            write(fd[1], &i, sizeof(int));
        }
        int status;
        wait(&status);
    }

    exit(EXIT_SUCCESS);
}

void crible(int in[2]) {
    //printf("Appel à crible()\n");

    //fermeture de in en écriture
    close(in[1]);

    int P, nbLu;
    nbLu = (read(in[0], &P, sizeof(int)));//lecture de in dans P

    if (0 != nbLu) {//vérification qu'on a bien lu qql chose
        /* P est premier */
        printf("Nombre premier: %i\n", P);

        int out[2]; pipe(out);

        pid_t f = fork();
        if (f == 0) {
            /* fils */

            //fermeture de in en lecture
            close(in[0]);   
            crible(out);
        } else if (f > 0) {
            /* Père */
            
            //fermeture de out en lecture
            close(out[0]);

            int i, nbLu;
            nbLu = read(in[0], &i, sizeof(int));
            while (nbLu != 0) { //on a lu qql chose ?
                if (i % P != 0) { //i mutiple de P ?
                    write(out[1], &i, sizeof(int));
                }
                nbLu = read(in[0], &i, sizeof(int)); //lecture du nombre suivants
            }
            close(in[0]);
            close(out[1]);
        } else {
            perror("Erreur du fork();");
        }
    }
}