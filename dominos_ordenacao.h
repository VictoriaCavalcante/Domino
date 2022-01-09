#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Essa estrutura representa o domin�, � uma lista duplamente encadeada.
//esquedo e direito reprasentam o conte�do das pe�as de domin�, os ponteiros ligam as estruturas em uma lista e testado ajuda na compila��o, evita loops eternos
//de modo a n�o mover uma pe�a j� movimentada.
typedef struct Domino
{
    int esquerdo;
    int direito;
    struct Domino *prox;
    struct Domino *ant;
    int testado;
}domino;
typedef struct Domino domino;

//apenas n�o criar uma estrutura vazia
domino* cria()
{
    return NULL;
}

//essa fun��o adiciona os domin�s na lista e os liga na lista duplamente encadeada
void add(domino **d, int x, int y)
{
    domino *novo = (domino*) malloc (sizeof(domino));

    novo->esquerdo = x;
    novo->direito = y;
    novo->testado = 0;
    if(*d != NULL)
    {
        (*d)->ant = novo;
    }
    novo->ant = NULL;
    novo->prox = *d;
    *d = novo;
}

//imprime todos os domin�s da lista
void imprime(domino *d)
{
    domino *aux = d;
    while(aux != NULL)
    {
        printf("|%d %d|", aux->esquerdo, aux->direito);
        aux = aux->prox;
    }
    printf("\n");
}

//para retornar um texto relacionado a ordena��o da lista
void verifica_string(domino *d)
{
    int verificador = 1;
    domino *aux = d;
    while(aux->prox != NULL)
    {
        if(aux->direito != aux->prox->esquerdo)
            verificador = 0;
        if(verificador == 0)
            break;
            aux = aux->prox;
    }
    if(verificador == 1)
        printf("\nsim\n");
    else
        printf("\nnao\n");
}

//verifica a ordena��o da lista, desta vez retornando um inteiro
int verifica(domino *d)
{
    int verificador = 1;
    domino *aux = d;
    while(aux->prox != NULL)
    {
        if(aux->direito != aux->prox->esquerdo)//usando o m�todo da contradi��o, verifica-se se as liga��es das pe�as(lado direito com lado esquerdo da pr�xima) s�o iguais
            verificador = 0;
        if(verificador == 0)
            break;
            aux = aux->prox;
    }
    return verificador;
}

//essa fun��o compara a primeira pe�a com as demais, movendo-as quando esta se encaixar no come�o
void ordena(domino **d)
{
    domino *primeiro = *d;
    primeiro->testado = 1;
    domino *aux = primeiro->prox;

    while(aux != NULL)
    {
        if(verifica(*d) == 1)
            break;
        if(primeiro->esquerdo == aux->direito && aux->testado != 1)
        {
            aux->testado = 1;
            aux->ant->prox = aux->prox;
            if(aux->prox != NULL)
                aux->prox->ant = aux->ant;
            primeiro->ant = aux;
            aux->ant = NULL;
            aux->prox = primeiro;
            *d = aux;
            primeiro = *d;
        }
        aux = aux->prox;
    }
}

//essa fun��o compara o primeiro domin� com os demais, por�m verifica se a liga��o do primeiro (lado esquerdo) se d� com o lado direito do domino
//se sim, a pe�a � invertida e depois levada ao come�o, encaixando-se a lista. N�o esquecendo de mudar o campo "testado" para 1, afim de evitar loops eternos.
void ordena_2(domino **d)
{
    domino *primeiro = *d;
    domino *aux = primeiro->prox;

    while(aux != NULL)
    {
        if(verifica(*d)==1)
            break;
        if(primeiro->esquerdo == aux->esquerdo && aux->testado != 1)
        {
            //invers�o
            int aux_int;
            aux_int = aux->esquerdo;
            aux->esquerdo = aux->direito;
            aux->direito = aux_int;
            //
            aux->testado = 1;
            aux->ant->prox = aux->prox;
            if(aux->prox != NULL)
                aux->prox->ant = aux->ant;
            primeiro->ant = aux;
            aux->ant = NULL;
            aux->prox = primeiro;
            *d = aux;
            primeiro = *d;
        }
        aux = aux->prox;
    }
}

//�ltima forma de ordena��o proposta para solu��o
//essa fun��o cuida de inverter pe�as caso elas n�o tenham sido usadas e se encaixem com seu vizinho anterior
void ordena_3(domino **d)
{
    domino *aux = *d;

    while(aux != NULL)
    {
        if(verifica(*d)==1)

            break;
        if(aux->testado == 0 )
        {
           if(aux->ant->direito == aux->direito)
           {
               //invers�o
                int aux_int;
                aux_int = aux->esquerdo;
                aux->esquerdo = aux->direito;
                aux->direito = aux_int;
                //
           }

        }
        aux = aux->prox;
    }
}
