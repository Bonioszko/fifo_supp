#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{

    mkfifo("kolejka", 0640);
    int k = open("kolejka", O_WRONLY);
    close(1);
    dup(k);
    execlp("ls", "ls", NULL);
    unlink("kolejka");
    return 0;
}