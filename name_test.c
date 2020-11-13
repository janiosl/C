#include <stdio.h>
int main() {
    char first_name[20];
    char last_name[20];
    printf("Enter first name and last name: ");
    scanf("%19s %19s", first_name, last_name);
    printf("First name: %s Last name: %s\n", first_name, last_name);
    return 0;
}