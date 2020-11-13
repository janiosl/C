#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *vars[] = {"RSS_FEED=http://g1.globo.com/dynamo/carros/rss2.xml"};
    char *phrase = argv[1];

    FILE *f = fopen("stories.txt", "w");
    if (!f) {
        error("Can't open stories.txt\n");
    }

    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process\n");
    }
        
    if (!pid) {
        if (dup2(fileno(f), 1) == -1) {
            error("Can't redirect Standard Output\n");
        }
        /*Este código não está funcionado devido problemas no script rssgossip.py*/
        if (execle ("/usr/bin/python2.7", "/usr/bin/python2.7", "./rssgossip.py", phrase, NULL, vars) == -1) {
            error("Can't run script\n");
        }
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("Error waiting for child process");
    }

    return 0;
}