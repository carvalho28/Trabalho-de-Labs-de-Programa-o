#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
  * @file main.c
  * @brief This program asks the user 18 numbers that are stored in a vector to provide a way to calculate some statistics or make operations with those values. The input values should be between 6 and 28.
  * @version 0.1
  * @authors <c>Team 13</c><ul><li>Diogo Carvalho Nº 45716 </li> <li>Eduardo Mendes Nº 45916 </li> <li>Francisco Casais Nº 45465 </li> <li>Guilherme Barata Nº 45779</li> <li>João Marques Nº 45722</li> </ul>
  * @copyright Copyright 2021 <c>Team 13</c>. All rights reserved. \n This project is released under the Apache License 2.0.
  */

#define N 18
#define M 1

//Função que limpa o buffer do input. Útil para elminar "\n" do buffer após o uso da função scanf;
void limpaInputBuffer(void)
{
    while (getchar() != '\n')
        ;
}

//Função do Socorro

void imprimeSocorro(void)
{
    printf("\e[1;1H\e[2J");
    printf("*****************************\n");
    printf(" Bem-vindo ao Menu de Ajuda! \n");
    printf("*****************************\n\n");
    printf("-> Inicialmente irá ser pedido ao utilizador para inserir valores para a contrução de uma matriz;\n");
    printf("-> Após o input de uma matriz, o utilizador tem várias escolhas sobre o que pode fazer com a sua matriz;\n");
    printf("-> Para cada opção o utilizador deve inserir o número indicado seguido de 'Enter';\n");
    printf("-> Para sair da escolha anterior pressionar a tecla 'Enter';\n");
    printf("-> Se desejar inserir outros valores pode fazê-lo, inserindo '0', seguido de 'Enter', no menu principal;\n");
    printf("-> Para execurtar o programa inserir na linha de comandos ./a.out;");
    printf("-> Votos de bons cálculos!\n\n");
}
//Menu principal que devolve o numero da operação a realizar no array
int menuPrincipal(void)
{
    int resposta = -1;

    printf("\e[1;1H\e[2J");
    printf("Menu Principal\n\n");
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
    } while (resposta < 0 || resposta > 6);
    printf("\n");

    return resposta;
}

//Função que copia o vetor dado pelo utilizador para um vetor auxiliar
void criaVetorAuxiliar(int vetInicial[N][M], int vetAuxiliar[N][M])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            vetAuxiliar[i][j] = vetInicial[i][j];
        }
    }
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
            printf("%4d ", arrVetor[i][j]);
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

    printf("O conjunto dos logaritmo de base 10 dos elementos é:\n");
    for (i = 0; i < N; i++)
    {
        printf("%5.2f ", vetAux[i][0]);
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
void misturaMetadeVetores(int vet1[N][M])
{
    int i, j;
    int vet2[N][1], vet3[N][1];

    //Segundo Vetor
    printf("Segundo vetor:\n");
    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Posição nº%d: ", i + 1); //Nota verificar se 6 e 28 pertencem a input;
            if (scanf("%d", &vet2[i][0]) != 1 || vet2[i][0] <= 6 || vet2[i][0] >= 28)
            {
                printf("\nInput inválido. Tente novamente.\n");
            }
            printf("\n");
            limpaInputBuffer();
        } while (vet2[i][0] <= 6 || vet2[i][0] >= 28);
    }

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
                    printf("Decomposição do número %d na posição: %d\n", vet[i][0], i + 1);
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

void matriz18por18(int vet[N][1], int vet18x18[N][N])
{

    int vet3[1][N];

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
        } while (vet3[0][j] <= 6 || vet3[0][j] >= 28);
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

    printf("\nMatriz 18x18 multiplicação de ambos os vetores:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d ", vet18x18[i][j]);
        }
        printf("\n");
    }
}

void transposta18por18(int vet[N][N])
{
    int transposta[N][N] = {};
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            transposta[j][i] = vet[i][j];
        }
    }

    printf("\nMatriz transposta da resultante da multiplicação de ambos os vetores:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d ", transposta[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc < 1 || argc > 2)
    {
        printf("Número incorreto de argumentos.\n");
        exit(1);
    }
    else if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        imprimeSocorro();
        printf("Prima 'Enter' para continuar.\n");
        limpaInputBuffer();
        exit(1);
    }
    else
    {
        int vet[N][M] = {}, vetAux[N][M] = {};
        int vet2[N][M] = {};
        int vet18x18[N][N] = {};
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
            } while (vet[i][0] <= 6 || vet[i][0] >= 28);
        }

        do
        {
            criaVetorAuxiliar(vet, vetAux);

            resposta_menu = menuPrincipal();
            switch (resposta_menu)
            {
            case 1:
                ordemCrescente(vetAux);
                printf("O conjunto por ordem crescente é:\n");
                for (i = 0; i < N; ++i)
                {
                    printf("%d ", vetAux[i][M - 1]);
                }
                printf("\n");
                printf("\nPrima 'Enter' para continuar.\n");
                limpaInputBuffer();
                break;
            case 2:
                medianaDosElementos(vetAux);
                printf("\nPrima 'Enter' para continuar.\n");
                limpaInputBuffer();
                break;
            case 3:
                multiplicaPorTres(vetAux);
                printf("\nPrima 'Enter' para continuar.\n");
                limpaInputBuffer();
                break;
            case 4:
                matriz2Por18ComQuadruplos(vetAux);
                printf("\nPrima 'Enter' para continuar.\n");
                limpaInputBuffer();
                break;
            case 5:
                logaritmoDosElementos(vetAux);
                printf("\nPrima 'Enter' para continuar.\n");
                limpaInputBuffer();
                break;
            case 6:
                valoresDasPosicoesMult3(vetAux);
                printf("\nPrima 'Enter' para continuar.\n");
                limpaInputBuffer();
                break;
                /*
        case 7:
        decompoeImparesEmPrimos(vetAux5);
        break;
        */
            case 10:

            case 0:
                resposta_menu = 0;
            default:
                printf("Input inválido, por favor tente novamente.\n");
                break;
            }
        } while (resposta_menu != 0); //condição para repetir o menu

        criaVetorAuxiliar(vet, vetAux);

        matriz18por18(vetAux, vet18x18);
        transposta18por18(vet18x18);
    }

    return 0;
}
