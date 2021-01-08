#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 18
#define M 1

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

    printf("\e[1;1H\e[2J");
    printf("Menu 1\n\n");
    printf("1. Ordenar Vetor por Ordem Crescente\n");
    printf("2. Mediana dos Elementos do Vetor\n");
    printf("3. Multiplicar Todos os Elementos do Vetor por 3\n");
    printf("4. Criar Matriz com Vetor e com Quádruplos\n");
    printf("5. Cálcular o Logaritmo de Base Natural de Todos os Elementos do Vetor\n");
    printf("6. Valores das Posições Múltiplas de Três do Vetor\n");
    printf("\n0. Sair\n");
    //Fazer mais uma opção para trocar vetor;

    do
    {
        if (scanf("%d", &resposta) != 1 || resposta < 0 || resposta > 6)
        {
            printf("\nInput inválido! Tente novamente.\n");
        }
        limpaInputBuffer();
    }
    while (resposta < 0 || resposta > 6);
    printf("\n");

    return resposta;
}

//Imprime o vetor por ordem crescente
void ordemCrescente(int vet[N][1])
{
    int i, j, aux;

    for (i = 0; i < N; ++i)
    {
        for (j = i + 1; j < N; ++j)
        {
            if (vet[i][0] > vet[j][0])
            {
                aux = vet[i][0];
                vet[i][0] = vet[j][0];
                vet[j][0] = aux;
            }
        }
    }

    printf("O conjunto por ordem crescente é: ");
    for (i = 0; i < N; ++i)
    {
        printf("%d ", vet[i][0]);
    }
    printf("Prima 'Enter' para continuar.\n");
    limpaInputBuffer();
}

//Cálcula a mediana dos elementos do vetor
void medianaDosElementos(int vet[N][1])
{
    int i, j, aux;
    float mediana, soma;
    //ordemCrescente(vet);
    // 18 / 2 = 9;

    for (i = 0; i < N; ++i)
    {
        for (j = i + 1; j < N; ++j)
        {
            if (vet[i][0] > vet[j][0])
            {
                aux = vet[i][0];
                vet[i][0] = vet[j][0];
                vet[j][0] = aux;
            }
        }
    }

    soma = (vet[8][0] + vet[9][0]); // Como N é par, 18, e a sua metade é ímpar, a mediana é através da soma dos seus valores 'do meio'
    printf("1nSoma: %d\n", soma);
    mediana = soma / 2;

    printf("A mediana do conjunto dado é: %.2f\n", mediana);
}

//Multiplica os elementos por 3
void multiplicaPorTres(int vet[N][1])
{
    int i;

    for (i = 0; i < N; i++)
    {
        vet[i][0] = vet[i][0] * 3;
    }

    //Vetor final:
    printf("O conjunto dos elementos multiplicados por 3 é: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", vet[i][0]);
    }
    printf("\n");
}

//Cria um arrAuxiliar para armazenar os quádruplos e com 2 ciclos for, armazena tudo num arr[2][N]
void matriz2Por18ComQuadruplos(int vet[N][1])
{
    int arrVetor[2][N];
    int i, j;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            for (j = 0; j < N; j++)
            {
                arrVetor[i][j] = vet[j][0];
            }
        }

        if (i == 1)
        {
            for (j = 0; j < N; j++)
            {
                arrVetor[i][j] = 4 * vet[j][0];
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", arrVetor[i][j]);
        }
        printf("\n");
    }
}

//Calcula o logaritmo de todos os elementos do vetor
void logaritmoDosElementos(int vet[N][1])
{
    int i;
    float vetAux[N][1] = {};

    for (i = 0; i < N; i++)
    {
        vetAux[i][0] = log(vet[i][0]);
    }

    printf("O conjunto dos logaritmo de base 10 dos elementos é: ");
    for (i = 0; i < N; i++)
    {
        printf("%.2f ", vetAux[i][0]);
    }
    printf("\n");
}

//Valores dos elementos que estão em posições multiplas de 3
void valoresDasPosicoesMult3(int vet[N][1])
{
    int i;

    printf("O conjunto dos elementos das posições múltiplas de 3 é: ");
    for (i = 0; i < N; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("%d ", vet[i][0]);
        }
    }
    printf("\n");
}

// Leitura de um novo vetor, e mostra um vetor que mistura metade do primeiro vetor e metade do segundo
void misturaMetadeVetores(int vet1[N][1], int vet2[N][1])
{
    int i, j;
    int vet3[N][0];

    for (i = 0; i < N / 2; i++)
    {
        vet3[i][0] = vet1[i][0];
    }

    for (i = N / 2; i < N; i++)
    {
        vet3[i][0] = vet2[i][0];
    }

    printf("O novo vetor com metade do primeiro e metade do segundo é:\n");
    for (j = 0; j < N; j++)
    {
        printf("%d ", vet3[j][0]);
    }
}

void decompoeImparesEmPrimos(int vet[N][1])
{
    int i, j, k, contador, aux, posicao = 0;
    int primos[8] = {};
    int fatores[10] = {};

    //Armazena os numeros primos maiores que 2 num array, dado que os números a verificar são ímpares
    for (i = 3; i <= 28; i++)
    {
        contador = 0;
        for (j = 1; j <= 28; j++)
        {
            if (i % j == 0)
            {
                contador++;
            }
        }
        if (contador == 2)
        {
            primos[posicao] = i;
            posicao++;
        }
    }

    for (i = 0; i < N; k++)
    {
        aux = 1;
        contador = -1;

        //Verifica se o número do array é ímpar
        if (vet[i][0] % 2 != 0)
        {
            contador = 0;
            aux = vet[i][0];
            for (j = 0; j < 8; j++)
            {
                //Guarda os numeros primos pelos quais o ímpar é divisível
                if (aux % primos[j] == 0)
                {
                    fatores[contador] = primos[j];
                    aux = aux / primos[j];
                    contador++;
                    j--;
                }

                if (aux == 1)
                {
                    printf("Decomposição do número %d na posição: %d\n", vet[i], i + 1);
                    for (int k = 0; k < contador; k++)
                    {
                        if (k < contador && k != 0)
                        {
                            printf(" *");
                        }
                        printf(" %d", fatores[k]);
                    }
                    printf("\n\n");

                    break;
                }
            }
        }
    }

    if (contador == -1)
    {
        printf("\nNão há números ímpares!\n");
    }
}

int **matriz18por18(int vet[N][1])
{

    int vet18x18[N][N] = {}, vet3[1][N];

    int i, j, k;

    // Terceiro Vetor
    printf("Terceiro vetor:\n");
    for (j = 0; j < N; j++)
    {
        do
        {
            printf("Posição nº%d: ", j + 1); //Nota verificar se 6 e 28 pertencem a input;
            if (scanf("%d", &vet3[0][j]) != 1 || vet3[0][j] <= 6 || vet3[0][j] >= 28)
            {
                printf("\nInput inválido. Tente novamente.\n");
            }
            printf("\n");
            limpaInputBuffer();
        }
        while (vet3[0][j] <= 6 || vet3[0][j] >= 28);
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            vet18x18[i][j] = 0;
            for (k = 0; k < M; k++)
            {
                vet18x18[i][j] += vet[i][k] * vet3[k][j];
            }
        }
    }

    printf("\nMatrzi 18x18 multiplicação de ambos os vetores:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", vet18x18[i][j]);
        }
        printf("\n");
    }

    return vet18x18;
}

void transposta18por18(int vet[N][N])
{
    int transposta[N][N]= {};
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            transposta[j][i] = vet[i][j];
        }
    }

    printf("\nMatriz transposta da resultante da multiplicação de ambos os vetores:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }
}

//Não pode levar void no argumento por causa do --help
int main()
{
    int vet[N][M], vetAux[N], vetAux2[N], vetAux3[N], vetAux4[N], vetAux5[N], vetAux6[N];
    int vet2[N] = {};
    int vet3[N][M];
    int i, j, resposta_menu;

    printf("\e[1;1H\e[2J");
    printf("Seja bem-vindo(a) ao trabalho do Grupo N!\n");
    printf("\nInsira 18 números inteiros compreendidos entre 6 e 28:\n");

    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Posição nº%d: ", i + 1); //Nota verificar se 6 e 28 pertencem a input;
            if (scanf("%d", &vet[i][0]) != 1 || vet[i][0] <= 6 || vet[i][0] >= 28)
            {
                printf("\nInput inválido. Tente novamente.\n");
            }
            printf("\n");
            limpaInputBuffer();
        }
        while (vet[i][0] <= 6 || vet[i][0] >= 28);
    }

    /*
    for (i = 0; i < N; i++)
    {
        vetAux[i] = vet[i];
        vetAux2[i] = vet[i];
        vetAux3[i] = vet[i];
        vetAux4[i] = vet[i];
        vetAux5[i] = vet[i];
        vetAux6[i] = vet[i];
    }
    */

    do
    {
        resposta_menu = menuPrincipal();
        switch (resposta_menu)
        {
        case 1:
            ordemCrescente(vet);
            break;
        case 2:
            medianaDosElementos(vet);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 3:
            multiplicaPorTres(vet);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 4:
            matriz2Por18ComQuadruplos(vet);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 5:
            logaritmoDosElementos(vet);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 6:
            valoresDasPosicoesMult3(vet);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        /*
        case 7:
        decompoeImparesEmPrimos(vetAux5);
        break;
        */
        case 0:
            resposta_menu = 0;
        default:
            printf("Input inválido, por favor tente novamente.\n");
            break;
        }
    }
    while (resposta_menu != 0);   //condição para repetir o menu

    /* Segundo Vetor
    printf("Segundo vetor:\n");
    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Posição nº%d: ", i + 1); //Nota verificar se 6 e 28 pertencem a input;
            if (scanf("%d", &vet2[i]) != 1 || vet2[i] <= 6 || vet2[i] >= 28)
            {
                printf("\nInput inválido. Tente novamente.\n");
            }
            printf("\n");
            limpaInputBuffer();
        } while (vet2[i] <= 6 || vet2[i] >= 28);
    }
    misturaMetadeVetores(vet, vet2);*/

    int **mat = matriz18por18(vet);
    transposta18por18(mat);

    return 0;
}
