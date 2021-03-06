#include <stdio.h>

typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

int main()
{
    margarita m1 = {2.0, 1.0, {2}};
    printf("Drink 1: \n%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n",
    m1.tequila, m1.cointreau, m1.citrus.lemon);

    margarita m2 = {2.0, 1.0, {0.5}};
    printf("Drink 2: \n%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n",
    m2.tequila, m2.cointreau, m2.citrus.lemon);

    margarita m3 = {2.0, 1.0, {.lime_pieces=1}};
    printf("Drink 3: \n%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n",
    m3.tequila, m3.cointreau, m3.citrus.lime_pieces);

    return 0;
}