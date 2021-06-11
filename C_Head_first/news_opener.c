#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void error(char *msg)
{
    printf("%s: %s", msg, strerror(errno));
    exit(1);
}

void open_url(char *url)
{
    char launch[255];
    /*Abertura de site no Windows*/
    //sprintf(launch, "cmd /c start %s", url);
    //system(launch);

    /*Abertura de site no Linux*/
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);

    /*Abertura de site no Mac*/
    //sprintf(launch, "open '%s'", url);
    //system(launch);

}

int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    //char *vars[] = {"RSS_FEED=https://rss.tecmundo.com.br/feed", NULL};
    char *vars[] = {"RSS_FEED=http://g1.globo.com/dynamo/carros/rss2.xml", NULL};

    /*Pipe para tratar entrada e saída em processos paralelos*/
    int fd[2];
    if (pipe(fd) == -1) {
        error("Cant create the pipe");
    }

    /*Fork para parelelizar os processso*/
    pid_t pid = fork();
    if (pid == -1) {
        error("Cant fork process");
    }

    if(!pid) {
        dup2(fd[1], 1);
        close(fd[0]);
        if (execle("/usr/bin/python2.7", "/usr/bin/python2.7", "./rssgossip.py", "-u", phrase, NULL, vars) == -1) {
            error("Cant run the script");
        }
    }

    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];
    while (fgets(line, 255, stdin)) {
        if (line[0] == '\t')
            open_url(line + 1);
    }
    return 0;
}