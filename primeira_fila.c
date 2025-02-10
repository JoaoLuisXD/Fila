#include <stdio.h>
#include <stdlib.h>

struct lista
{
    float info;
    struct lista * prox;
};
typedef struct lista Lista;

struct fila
{
    struct lista * inicio;
    struct lista * fim;
};
typedef struct fila Fila;

Fila * cria_fila();
void insere_fila(Fila * f,float valor);
float retira_fila(Fila * f);
int fila_vazia(Fila * f);
void libera_fila(Fila * f);

int main()
{
    return 0;
}

Fila * cria_fila()
{
    Fila * f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}
void insere_fila(Fila * f,float valor)
{
    Lista * n = (Lista*)malloc(sizeof(Lista));
    n->info = valor;
}
float retira_fila(Fila * f)
{

}
int fila_vazia(Fila * f)
{

}
void libera_fila(Fila * f)
{

}