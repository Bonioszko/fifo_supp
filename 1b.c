#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
    char buf[10];
    int k = open("kolejka", O_RDONLY);
    read(k, buf, 6);
    printf("%s", buf);
    close(k);
}