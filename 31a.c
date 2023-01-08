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
    int status;
    status = mkfifo("serwer2", 0640);
    printf("Status kolejki: %d\n", status);

    pdesk = open("serwer2", O_RDONLY);
    printf("Polaczono %d\n", pdesk);
    char buf[100];
    int cdesk;
    int id;
    int rs;
    while (1)
    {
        rs = read(pdesk, buf, 100);
        printf("Odczytano: %d\n", rs);
        if (rs > 0)
        {
            printf("Message received! %s\n", buf);
            id = fork();
            if (id == 0)
            {
                cdesk = open(buf, O_WRONLY);
                close(STDOUT_FILENO);
                dup(cdesk);
                close(cdesk);
                execlp("ls", "ls", NULL);
            }
            close(cdesk);
        }
        printf("working...\n");
        sleep(1);
    }
    close(pdesk);

    return 0;
}