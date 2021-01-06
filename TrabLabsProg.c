#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 18

//To do: -Verficar a função do elemento maior maior; Verificar vetor como argumento (Ou criar função que iguala Aux ao do input)

//Função que limpa o buffer do input. Útil para elminar "\n" do buffer após o uso da função scanf;
void limpaInputBuffer()
{
    while (getchar() != '\n');
}

//Menu principal que devolve o numero da operação a realizar no array
int menuPrincipal(void)
{
    int resposta = -1;

    printf("\n\n\tMenu Principal\n\n");
    printf("\t1-\tOrdenar Vetor por Ordem Crescente\n");
    printf("\t2-\tMediana dos Elementos do Vetor\n");
    printf("\t3-\tMultiplicar Todos os Elementos do Vetor por 3\n");
    printf("\t4-\tCriar Matriz com Vetor e com Quádruplos\n");
    printf("\t5-\tCálcular o Logaritmo de Base Natural de Todos os Elementos do Vetor\n");
    printf("\t6-\tValores das Posições Múltiplas de Três do Vetor\n");
    printf("\n\t0-\tSair\n");
    //Fazer mais uma opção para trocar vetor;

    do
    {
        if(scanf("%d", &resposta) != 1 || resposta < 0 || resposta > 6)
        {
            printf("\nInput inválido! Tente novamente.\n");
        }
        limpaInputBuffer();
    } while(resposta < 0 || resposta > 6);

    return resposta;
}

//Imprime o vetor por ordem crescente
void ordemCrescente(int *vet)
{
    int i, j, aux;

    for (i = 0; i < N; ++i)
    {
        for (j = i + 1; j < N; ++j)
        {
            if (vet[i] > vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    printf("O conjunto por ordem crescente é: ");
    for (i = 0; i < N; ++i)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    limpaInputBuffer();
    printf("Prima 'Enter' para continuar.\n");
}

//Cálcula a mediana dos elementos do vetor
void medianaDosElementos(int *vet)
{
    int soma;
    float mediana;
    ordemCrescente(vet);
    // 18 / 2 = 9;

    soma = (vet[8] + vet[9]); // Como N é par, 18, e a sua metade é ímpar, a mediana é através da soma dos seus valores 'do meio'
    mediana = soma / 2;

    printf("A mediana do conjunto dado é: %.2f", mediana);
}

//Multiplica os elementos por 3
void multiplicaPorTres(int *vet)
{
    int i;

    for(i = 0; i < N; i++)
    {
        vet[i] = vet[i] * 3;
    }

    //Vetor final:
    printf("O conjunto dos elemntos multiplicados por 3 é:\n{");
    for(i = 0; i < N; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("}\n");
}

//Cria um arrAuxiliar para armazenar os quádruplos e com 2 ciclos for, armazena tudo num arr[2][N]
void matriz2Por18ComQuadruplos(int *vet)
{
    int arrVetor[2][N];
    int i, j;

    for(i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            for(j = 0; j < N; j++)
            {
                arrVetor[i][j] = vet[j];
            }
        }

        if(i == 1)
        {
            for(j = 0; j < N; j++)
            {
                arrVetor[i][j] = 4 * vet[j];
            }
        }
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", arrVetor[i][j]);
        }
        printf("\n");
    }
}

//Calcula o logaritmo de todos os elementos do vetor
void logaritmoDosElementos(int *vet)
{
    int i;

    for(i = 0; i < N; i++)
    {
        vet[i] = log(vet[i]);
    }

    printf("O conjunto dos logaritmo de base 10 dos elemntos é:\n{");
    for(i = 0; i < N; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("}\n");
}

//Valores dos elementos que estão em posições multiplas de 3
void valoresDasPosicoesMult3(int *vet)
{
    int i;

    printf("O conjunto dos elementos das posições múltiplas de 3 é:\n{");
    for(i = 0; i < N; i++)
    {
        if(i % 3 == 0)
        {
            printf("%d ", vet[i]);
        }
    }
    printf("}\n");
}

//Não pode levar void no argumento por causa do --help
int main()
{
    int vetAux[N], vet[N] = {};
    int i, resposta_menu;

    printf("Seja bem-vindo(a) ao trabalho do Grupo N!\n");
    printf("\nInsira 18 números inteiros compreendidos entre 6 e 28:\n");

    for(i = 0; i < N; i++)
    {
        do
        {
            printf("Posição nº%d: ", i+1);          //Nota verificar se 6 e 28 pertencem a input;
            if(scanf("%d", &vet[i]) != 1 || vet[i] <= 6 || vet[i] >= 28)
            {
                printf("\nInput inválido. Tente novamente.\n");
            }
            printf("\n");
            limpaInputBuffer();
        }
        while(vet[i] <= 6 || vet[i] >= 28);
    }

    for(i = 0; i < N; i++)
    {
        printf("%d\t", vet[i]);
        vetAux[i] = vet[i];
    }

    do
    {
        //resposta_menu = menuPrincipal();

        for (int i = 0; i < N; i++) //Faz o vetor auxiliar igual ao do input para não estarmos a alterar o do input consecutivamente
        {
            vetAux[i] = vet[i];
        }

        switch (resposta_menu)
        {
        case 1:
            ordemCrescente(vetAux);

        case 2:
            medianaDosElementos(vetAux);

        case 3:
            multiplicaPorTres(vetAux);

        case 4:
            matriz2Por18ComQuadruplos(vetAux);

        case 5:
            logaritmoDosElementos(vetAux);

        case 6:
            valoresDasPosicoesMult3(vetAux);
        }

    }
    while();   //condição para repetir o menu

    return 0;
}
