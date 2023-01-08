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
    write(k, "HALLO", 6);
    close(k);
}