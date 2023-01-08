#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
    int stat = mkfifo("kolejka22", 0640);
    printf("Status kolejki: %d \n", stat);
    char buf[100];
    int id;
    int klient;
    int ts;
    int serwer = open("kolejka", O_RDONLY);
    printf("Polaczono: %d\n", serwer);
    while (1)
    {
        ts = read(serwer, buf, 100);
        printf("oczytano: %d\n", ts);
        if (ts > 0)
        {
            printf("mess: %s\n", buf);
            id = fork();
            if (id == 0)
            {
                klient = open(buf, O_WRONLY);
                close(STDOUT_FILENO);
                dup(klient);
                close(klient);
                execlp("ls", "ls", NULL);
            }
            close(klient);
        }
        printf(" work... \n");
        sleep(1);
    }
    
    close(serwer);
    return 0;
}