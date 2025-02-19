#include <stdio.h>
#include <stdlib.h>

struct no_lista
{
    float info;
    struct no_lista * prox;
};
typedef struct no_lista No_lista;
typedef No_lista * NNo_lista;

struct fila
{
    No_lista * ini;
    No_lista * fim;
};
typedef struct fila Fila;
typedef Fila * FFila;

FFila cria_fila();
int verifica_vazia(FFila f);
void insere_fila(FFila f, float valor);
float retira_fila(FFila f);
void imprime_fila(FFila f);
void libera_fila(FFila f);


int main()
{
    FFila primeira_fila = cria_fila();
    insere_fila(primeira_fila,1);
    insere_fila(primeira_fila,2);
    insere_fila(primeira_fila,3);
    imprime_fila(primeira_fila);
    retira_fila(primeira_fila);
    retira_fila(primeira_fila);
    retira_fila(primeira_fila);
    imprime_fila(primeira_fila);



    return 0;
}



FFila cria_fila()
{
    FFila f = (FFila)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}
int verifica_vazia(FFila f)
{
    return f->ini == NULL && f->fim == NULL;
}
void insere_fila(FFila f, float valor)
{
    NNo_lista novo = (NNo_lista)malloc(sizeof(No_lista));
    novo->info = valor;
    novo->prox = NULL;
    if(verifica_vazia(f))
    {
        f->ini = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}
float retira_fila(FFila f)
{
    if(!verifica_vazia(f))
    {
        float valor = f->ini->info;
        NNo_lista novo_aux = f->ini;
        f->ini = f->ini->prox;
        free(novo_aux);
        return valor;
    }
    else
    {
        printf("fila vazia");
        exit (1);
    }
}
void imprime_fila(FFila f)
{
    NNo_lista novo_percorre = f->ini;
    while(novo_percorre != NULL)
    {
        printf("%f\n",novo_percorre->info);
        novo_percorre = novo_percorre->prox;
    }
}
void libera_fila(FFila f)
{
    NNo_lista novo_percorre = f->ini;
    while(novo_percorre != NULL)
    {
        NNo_lista aux = novo_percorre;
        novo_percorre = novo_percorre->prox;
        free(aux);
    }
    free (f);
}