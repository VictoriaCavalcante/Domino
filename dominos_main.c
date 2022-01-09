#include"dominos_ordenacao.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int q;
    printf("Entre com a quantidade de peças de dominó.\n");
    scanf("%d", &q);
    while(q != 0)//condição para continuar executando
    {
        int x, y;
        domino *inicio = cria();//ponteiro que aponta para o inicio da lista

        for(int i=0 ; i<q ; i++)//estrutura de repetição para leitura de dominós
        {
            printf("Lado 1: ");
            scanf("%d", &x);
            printf("Lado 2: ");
            scanf("%d", &y);
            add(&inicio, x, y);
            printf("\n");
        }
        printf("\nPeças inseridas.\n");//um feedback para o usuário
        imprime(inicio);

        //ordenação em andamento
        ordena(&inicio);
        ordena_2(&inicio);
        ordena_3(&inicio);

        //verificação para impressão de texto "sim" para caso a lista possa ser ordenada ou "não" em caso negativo
        verifica_string(inicio);

        if(verifica(inicio)==1)//condição para impressão e finalmente impressão se for o caso
            imprime(inicio);
        else
            printf("nao\n\n");

        printf("Entre com a quantidade de peças de dominó.\n");
        scanf("%d", &q);//entrada para o próximo teste
    }

    printf("\nObrigado por usar o programa.\n\n");

    return 0;
}
