#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display(island *start)
{
    island *i = start;
    for (; i != NULL; i = i-> next) {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

island* create(char * name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for (;i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}

int main() {
    char name[80];
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;

    /*
    island amity = {"Amity", "09:00", "17:00", NULL};
    island craggy = {"Craggy", "09:00", "17:00", NULL};
    island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
    island shutter = {"Shutter", "09:00", "17:00", NULL};
    

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    island skull = {"Skull", "09:00", "17:00", NULL};
    //Em ANSI C não seria possível declarar esta variável neste local
    //A declaração de todas variáveis seria obrigatoriamente feita no início do código.
    //Esta forma, utilizada didaticamente pelo livro só é aceita nos padrões C99 e C11
    
    isla_nublar.next = &skull;
    skull.next = &shutter;
    */

    /*
    fgets(name, 80, stdin);
    island *p_island0 = create(name);

    fgets(name, 80, stdin);
    island *p_island1 = create(name);
    p_island0->next = p_island1;
    */

    for (;fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start = NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }

    display(start);
    release(start);
    
    return 0;
}