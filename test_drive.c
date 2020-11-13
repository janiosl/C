#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b - a;
}

typedef struct {
    int width;
    int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
    rectangle* ra = (rectangle*)a;
    rectangle* rb = (rectangle*)b;
    int area_a = (ra->width * ra->height);
    int area_b = (ra->width * ra->height);
    return area_a - area_b;
}

int compare_names(const void* a, const void* b)
{
    char** sa = (char**)a;
    char** sb = (char**)b;
    return strcmp(*sa, *sb);
}

int compare_areas_desc(const void* a, const void* b)
{
    return compare_areas(b, a);
}

int compare_names_desc(const void* a, const void* b)
{
    return compare_names(b, a);
}

int compare_prices(const void* a, const void*b)
{
    float price_a = *(float*)a;
    float price_b = *(float*)b;
    return price_a - price_b;
}

int main()
{
    int i;
    int scores[] = {543, 323, 32, 554, 11, 3, 122};
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    float prices[] = {100.5, 520.3, 100.7, 300.3, 520.9, 55.87, 125.67, 255.7, 252.99, 255.9};

    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("There are the scores in order:");
    for (i = 0; i <7; i++) {
        printf("Socre = %i\n", scores[i]);
    }
    
    qsort(names, 4, sizeof(char*), compare_names);
    puts("These are the names in order:");
    for (i = 0; i <4; i++) {
        printf("%s\n", names[i]);
    }

    qsort(prices, 10, sizeof(float), compare_prices);
    puts("These are the prices in order:");
    for (i = 0; i < 10; i++) {
        printf("Price: $%.2f\n", prices[i]);
    }
    
    return 0;
}