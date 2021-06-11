/*
Head First C
Programa para leitura de dados separados por vírgula (csv) e
conversão em formato json
*/
#include <stdio.h>
int main() {
    //Declaração das variáveis usadas para leitura dos dados
    float latitude;
    float longitude;
    char info[80];
    int started = 0;
    //Cabeçalo do formulário json
    puts("data=[");
    //Leitura dos dados de origem
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if (started)
            printf(",\n");
        else {
            started = 1;
        }
        //Validação dos dados de lat e lon
        if ((latitude < -90) || (latitude > 90)) {
            fprintf(stderr, "Invalid latitude %f\n", latitude);
            return 2;
        }
        if ((longitude < -180) || (longitude > 180)) {
            fprintf(stderr, "Invalid longitude %f\n", longitude);
            return 2;
        }
        //Gravação dos dados lidos no formato json
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    //Fechamento do formulário json
    puts("\n]");
    return 0;
}