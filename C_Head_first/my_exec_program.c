#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    char *my_env[] = {"JUICE=peach and apple", NULL};
    if (execle("diner_info", "diner_info", "4", NULL, my_env) == -1) {
        fprintf(stderr, "Cannot run the program. Error: %s\n", strerror(errno));
        return -1;
    }
        
    return 0;
}