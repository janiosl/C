#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "now.h"

/*Master Control Program Utility.
Records guard patrol check-ins.
*/

int main()
{
    char comment[80];
    char cmd[120];
    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    system(cmd);
    return 0;
}