#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *feeds[] = {
        "/usr/",
        "/usr/local/bin/",
        "../"};

    int times = 3;
    char *phrase = argv[1];
    int i;

    for (i = 0; i < times; i++) {
        //char var[255];
        //sprintf(var, feeds[i]);
        char *vars[] = {feeds[i]};

        /*Este código não está funcionado devido problemas no script rssgossip.py*/       
        if (execl("dir", "dir", vars, NULL) == -1) {
            fprintf(stderr, "Can't run script: %s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}