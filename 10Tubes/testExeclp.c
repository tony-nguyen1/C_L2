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
    execlp("./ecrivain.out", "./ecrivain.out", "tdg", NULL);
}