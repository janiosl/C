/* TAD: lista de inteiros */

typedef struct lista Lista;

Lista* lst_cria (void);
void lst_libera (Lista* lst);

Lista* lst_insere (Lista* lst, int val);
Lista* lst_retira (Lista* lst, int val);

int lst_vazia (Lista* lst);
Lista* lst_busca (Lista* lst, int val);
void lst_imprime (Lista* lst);

Lista* lst_insere_ordenado(Lista* lst, int val);