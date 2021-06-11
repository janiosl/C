#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *feeds[] = {
        "http://www.cnn.com/rss/celebs.xml",
        "http://www.rollingstones.com/rock.xml",
        "http://eonline.com/gossip.xml"};

    int times = 3;
    char *phrase = argv[1];
    int i;

    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};

        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
            return 1;
        }

        if (!pid) {
            puts("----------------------------------------------------------");
            /*Este código não está funcionado devido problemas no script rssgossip.py*/       
            if (execle ("/usr/bin/python3.6", "/usr/bin/python3.6", "./rssgossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Can't run script: %s\n", strerror(errno));
                return 1;
            }

        }
    }
    return 0;
}