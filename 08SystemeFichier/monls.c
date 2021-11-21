#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h> //printf()
#include <stdlib.h> //exit()
#include <dirent.h>
#include <string.h>

void afficheTypeEtDroit(char* s);

int main(int argc, char *argv[]) {
    printf("Hello world !\n");

    DIR* dir = opendir(argv[1]);
    
    struct dirent* dirEntry;

    while (dirEntry != NULL) {
        dirEntry = readdir(dir);
        if (dirEntry != NULL) {

            printf("%li ", dirEntry->d_ino);
            //récupération du type et des droits
            afficheTypeEtDroit(dirEntry->d_name);

            printf("%s\n", dirEntry->d_name);
        }
    }

    closedir(dir);
    exit(EXIT_SUCCESS);
}
//http://manpagesfr.free.fr/man/man2/stat.2.html

void afficheTypeEtDroit(char* s) {
    struct stat buf;
    int res = stat(s, &buf);

    if (res == 1) {
        printf("problème avec stat");
    }

    if (S_ISREG(buf.st_mode)) {
        printf("f");
    } else if (S_ISDIR(buf.st_mode)) {
        printf("d");
    } else {
        printf("?");
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
    printf(" ");
}