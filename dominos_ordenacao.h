#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Essa estrutura representa o dominó, é uma lista duplamente encadeada.
//esquedo e direito reprasentam o conteúdo das peças de dominó, os ponteiros ligam as estruturas em uma lista e testado ajuda na compilação, evita loops eternos
//de modo a não mover uma peça já movimentada.
typedef struct Domino
{
    int esquerdo;
    int direito;
    struct Domino *prox;
    struct Domino *ant;
    int testado;
}domino;
typedef struct Domino domino;

//apenas não criar uma estrutura vazia
domino* cria()
{
    return NULL;
}

//essa função adiciona os dominós na lista e os liga na lista duplamente encadeada
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

//imprime todos os dominós da lista
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

//para retornar um texto relacionado a ordenação da lista
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

//verifica a ordenação da lista, desta vez retornando um inteiro
int verifica(domino *d)
{
    int verificador = 1;
    domino *aux = d;
    while(aux->prox != NULL)
    {
        if(aux->direito != aux->prox->esquerdo)//usando o método da contradição, verifica-se se as ligações das peças(lado direito com lado esquerdo da próxima) são iguais
            verificador = 0;
        if(verificador == 0)
            break;
            aux = aux->prox;
    }
    return verificador;
}

//essa função compara a primeira peça com as demais, movendo-as quando esta se encaixar no começo
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

//essa função compara o primeiro dominó com os demais, porém verifica se a ligação do primeiro (lado esquerdo) se dá com o lado direito do domino
//se sim, a peça é invertida e depois levada ao começo, encaixando-se a lista. Não esquecendo de mudar o campo "testado" para 1, afim de evitar loops eternos.
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
            //inversão
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

//última forma de ordenação proposta para solução
//essa função cuida de inverter peças caso elas não tenham sido usadas e se encaixem com seu vizinho anterior
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
               //inversão
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
