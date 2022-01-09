#include"dominos_ordenacao.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int q;
    printf("Entre com a quantidade de pe�as de domin�.\n");
    scanf("%d", &q);
    while(q != 0)//condi��o para continuar executando
    {
        int x, y;
        domino *inicio = cria();//ponteiro que aponta para o inicio da lista

        for(int i=0 ; i<q ; i++)//estrutura de repeti��o para leitura de domin�s
        {
            printf("Lado 1: ");
            scanf("%d", &x);
            printf("Lado 2: ");
            scanf("%d", &y);
            add(&inicio, x, y);
            printf("\n");
        }
        printf("\nPe�as inseridas.\n");//um feedback para o usu�rio
        imprime(inicio);

        //ordena��o em andamento
        ordena(&inicio);
        ordena_2(&inicio);
        ordena_3(&inicio);

        //verifica��o para impress�o de texto "sim" para caso a lista possa ser ordenada ou "n�o" em caso negativo
        verifica_string(inicio);

        if(verifica(inicio)==1)//condi��o para impress�o e finalmente impress�o se for o caso
            imprime(inicio);
        else
            printf("nao\n\n");

        printf("Entre com a quantidade de pe�as de domin�.\n");
        scanf("%d", &q);//entrada para o pr�ximo teste
    }

    printf("\nObrigado por usar o programa.\n\n");

    return 0;
}
