#include <stdio.h>

enum result_type {HIRED, NEXT_STEP, REFUSED};
typedef struct {
    char *name;
    enum result_type result;
} response;

void hired(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Congratulations! The Area that is evaluating your");
    puts("contacted us to confirm that you are HIRED to the position!");
    puts("--------------------------------------------------------------");
}

void next_step(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Good news: You are invited to the next step");
    puts("on evaluation process. Contact us ASAP.");
    puts("--------------------------------------------------------------");
}

void refused(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your resume was refused on the");
    puts("evaluating process. But we hope see you in a next oportunity.");
    puts("--------------------------------------------------------------");
}

void (*replies[])(response) = {hired, next_step, refused};

int main()
{
    response r[] = {
        {"Janio", HIRED},
        {"Joyce", NEXT_STEP},
        {"Joaquim", REFUSED},
        {"Marcos", NEXT_STEP}
    };
    int i;

    for (i = 0; i < 4; i++) {
        (replies[r[i].result])(r[i]);
    }
    return 0;
}