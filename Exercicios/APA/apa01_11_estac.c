#include <stdio.h>
#include <stdlib.h>
/*=========================*/
/*Cria a estrutura da pilha*/
/*=========================*/
struct pilha {
    int info[2];
    int capacidade;
    int uso;
    struct pilha* prox;
};typedef struct pilha Pilha;
/*==========================================*/
/*Função de criação: retorna uma pilha vazia*/
/*==========================================*/
void pilha_cria(Pilha *plh, int cp){
    /*Atualiza uso se a pilha é estacionamento*/
    plh->uso = 0;
    plh->capacidade = cp;
    plh->prox = NULL;
}
/*======================================*/
/*Função verifica se a pilha está vazia*/
/*======================================*/
int pilha_vazia(Pilha *plh){
    if(plh->prox == NULL){
        return 1;
    } else {
        return 0;
    }
}
/*==========================*/
/*Consulta vagas disponíveis*/
/*==========================*/
int conf_vagas(Pilha *plh){
    int vagas = plh->capacidade - plh->uso;
    printf("Vagas: %i\n", vagas);
    return vagas;
}
/*========================================*/
/*Função de inserção de elementos à pilha*/
/*========================================*/
void pilha_insere(Pilha* plh, int item[2]){
    if(plh->uso==plh->capacidade){
        puts("Estacionamento cheio");
        exit(1);
    }
    /*Alocação da memória*/
    Pilha *novo=(Pilha*)malloc(sizeof(Pilha));
    /*Inserção do item novo*/
    if(!novo){
        puts("Sem memoria\n");
        exit(1);
    }else{
        novo->info[0] = item[0]; /*Placa*/
        novo->info[1] = item[1]; /*Manobras*/
    }
    novo->prox = NULL;
    if(pilha_vazia(plh)){
        plh->prox = novo;
    } else{
        Pilha *t = plh->prox;
        while(t->prox != NULL){
            t = t->prox;
        }
        t->prox = novo;
    }
    plh->uso++;
}
/*========================================*/
/*Função de exclusão de elementos da pilha*/
/*========================================*/
Pilha* pilha_exclui(Pilha* plh){
    if(pilha_vazia(plh)){
        puts("Nenhum carro!");
        return NULL;
    } else{
        /*Variáveis de apoio para percorrer pilha*/
        Pilha *u = plh->prox; /*Último item*/
        Pilha *pu = plh;      /*Penúltimo item*/
        /*Lógica para ajustar posição dos itens*/
        while(u->prox != NULL){
            pu = u;
            u = u->prox;
        }
        pu->prox = NULL;
        plh->uso--;
        return u;
    }
}
/*==================================================*/
/*Função de impressão: imprime valores dos elementos*/
/*==================================================*/
void pilha_imprime(Pilha *plh){
    if(pilha_vazia(plh)){
        puts("Nenhum carro!");
        return;
    }
    puts("===========================================");
    Pilha *p, *t; /*p = próximo; t = atual*/
    t = plh->prox;
    while(t != NULL){
        p = t->prox;
        printf(" Placa: %i - ", t->info[0]);
        printf("Manobras: %i\n", t->info[1]);
        t = p;
    }
    puts("===========================================");
}
/*==================================================*/
/*Função libera: libera a pilha completa da memória */
/*==================================================*/
void pilha_liberar(Pilha *plh){
    /*Executa a lógica apenas se a pilha não estiver vazia*/
    if(!pilha_vazia(plh)){
        /*Variáveis auxiliares para percorrer a pilha*/
        Pilha *p, *t; /* p = Próximo; t = Atual*/
        t = plh->prox;
        while(t != NULL){
            p = t->prox;
            free(t);
            t = p;
        }
    }
}
/*==================================================*/
/*Função saída: Processa a saída e manobra de carros*/
/*==================================================*/
Pilha* est_saida(Pilha* plhE, Pilha* plhR, int placa){
    Pilha* saida=(Pilha*)malloc(sizeof(Pilha));
    saida = pilha_exclui(plhE);
    /*Se o carro a sair está desbloqueado: processa saída direta*/
    if(saida->info[0]==placa){
        printf("Carro placa %i liberado\n", saida->info[0]);
        printf("Manobras ate a retirada: %i\n", saida->info[1]);
    } else {
        /*Se o carro do topo não é o que irá sair: manobra para rua*/
        printf("Carro %i manobrado\n", saida->info[0]);
        saida->info[1]++; /*Atualiza manobras do carro*/
        pilha_insere(plhR, saida->info);
    }
    return saida;
}
/*========================================*/
/*Função busca: busca um elemento na pilha*/
/*========================================*/
int pilha_busca(Pilha* plh, int v)
{
    Pilha* p;
    for (p = plh; p != NULL; p = p->prox){
        if (p->info[0] == v)
            return 1;
    }
    return 0;
}
/*==================*/
/*Programa principal*/
/*==================*/
int main(){
    /*Criar estacionamento*/
    /*====================*/
    puts("Criando estrutura do estacionamento...");
    Pilha* est=(Pilha*)malloc(sizeof(Pilha));
    int c=10; /*Vagas totais do estacionamento*/
    pilha_cria(est, c);
    Pilha* rua=(Pilha*)malloc(sizeof(Pilha));
    pilha_cria(rua, c);
    /*Verificar se o estacionamento está vazio*/
    /*========================================*/
    int v;
    v = pilha_vazia(est);
    printf("Estacionamento vazio: %i\n", v);
    conf_vagas(est);
    /*Entrada de carro*/
    /*================*/
    int carro[2]; /*Placa do carro que será inserido*/
    carro[1] = 0; /*Quantidade PADRÃO inicial de manobras*/
    carro[0] = 1234;
    pilha_insere(est, carro);
    carro[0] = 2468;
    pilha_insere(est, carro);
    /*Impressão do relatório de carros no estacionamento*/
    /*==================================================*/
    puts("\n Carros no estacionamento:");
    pilha_imprime(est);
    /*Verificar se o estacionamento está vazio*/
    v = pilha_vazia(est);
    printf("\nEstacionamento vazio: %i\n", v);
    conf_vagas(est);
    /*Entrada de mais carros*/
    /*======================*/
    carro[0] = 2610;
    pilha_insere(est, carro);
    carro[0] = 2611;
    pilha_insere(est, carro);
    carro[0] = 2612;
    pilha_insere(est, carro);
    carro[0] = 2613;
    pilha_insere(est, carro);
    /*Impressão do relatório de carros no estacionamento*/
    /*==================================================*/
    puts("\nCarros no estacionamento:");
    pilha_imprime(est);
    conf_vagas(est);
    /*Retirada de carro do estacionamento*/
    /*===================================*/
    int plc;
    printf("Placa do carro para remover: ");
    scanf("%i", &plc);
    Pilha* sd=(Pilha*)malloc(sizeof(Pilha));
    int i = 0;
    int prim = 0;
    puts("-------------------------------------------");
    printf("Solicitada retirada do carro %i\n", plc);
    /*Retirada e/ou manobra do estacionamento para rua*/
    /*================================================*/
    while(1){
        if(pilha_busca(est,plc)!=1){
            puts("Este carro nao esta no estacionamento");
            break;
        }
        sd = est_saida(est, rua, plc);
        if(sd->info[0]==plc){
            break;
        }
        /*Guarda o primeiro carro colocado na rua*/
        if(i==0)
            prim=sd->info[0];
        i++;
    }
    /*Manobra da rua para o estacionamento*/
    /*====================================*/
    if(prim!=0){
        puts("Manobrando carros de volta da rua ao estacionamento");
        while (1){
            sd = est_saida(rua, est, prim);
            if(pilha_vazia(rua)){
                /*Devolve o último carro retirado da rua*/
                /*Esta parte permite o reaproveitamento da função pilha_insere*/
                /*Sem ela teria que ser alterada a função ou criada outra para o retorno*/
                sd->info[1]++;
                pilha_insere(est, sd->info);
                printf("Carros retornaram ao estacionamento\n");
                break;
            }
        }
    }
    /*Confere novamente a situação do estacionamento e da rua*/
    /*=======================================================*/
    puts("-------------------------------------------");
    puts("\nCarros no estacionamento:");
    pilha_imprime(est);
    conf_vagas(est);
    puts("\nCarros na rua:");
    pilha_imprime(rua);
    /*Adicionando novo carro*/
    puts("\nAdicionando novo carro");
    carro[0] = 4026;
    pilha_insere(est, carro);
    puts("\nCarros no estacionamento:");
    pilha_imprime(est);
    /*Liberando as pilhas da memória*/
    /*==============================*/
    pilha_liberar(est);
    pilha_liberar(rua);
    pilha_liberar(sd);
    return 0;
}