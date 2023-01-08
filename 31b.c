#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pdesk;
    char name[100] = "klient1";
    int status = mkfifo(name, 0640);
    printf("Status kolejki %d\n", status);

    pdesk = open("serwer2", O_WRONLY);
    printf("Polaczono %d\n", pdesk);
    write(pdesk, name, 100);

    int cdesk = open(name, O_RDONLY);
    char buf[500];
    read(cdesk, buf, 500);
    printf("%s\n", buf);
    close(cdesk);

    return 0;
}