#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
    char name[100] = "podkolejka";
    int stat = mkfifo(name, 0640);
    printf("otwarto: %d \n", stat);
    int serwer = open("kolejka", O_WRONLY);
    printf("polaczono: %d\n", serwer);
    write(serwer, name, 100);
    int client = open(name, O_RDONLY);
    char buf[100];
    read(client, buf, 100);
    printf("otrzynao%s \n", buf);
    close(client);
}