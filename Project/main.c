#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "part1.h"
#include "part2.h"

/**
  * @file main.c
  * @brief This program asks the user 18 numbers that are stored in a vector to provide a way to calculate some statistics or make operations with those values. The input values should be between 6 and 28.
  * @version 0.1
  * @authors <c>Team 13</c><ul><li>Diogo Carvalho Nº 45716 </li> <li>Eduardo Mendes Nº 45916 </li> <li>Francisco Casais Nº 45465 </li> <li>Guilherme Barata Nº 45779</li> <li>João Marques Nº 45722</li> </ul>
  * @copyright Copyright 2021 <c>Team 13</c>. All rights reserved. \n This project is released under the Apache License 2.0.
  */

/**
  * N is the number of rows of the matrix.
  */
#define N 18
/**
  * M is the number os columns of the matrix.
  */
#define M 1

/**
  * Function that clears the input buffer. Useful for clearing "\n" from the buffer after using the scanf function.
  */
//Função que limpa o buffer do input. Útil para elminar "\n" do buffer após o uso da função scanf;
void limpaInputBuffer(void)
{
    while (getchar() != '\n')
        ;
}

/**
  * This function shows the user the main menu of the program.
  */
//Menu principal que devolve o numero da operação a realizar no array
int menuPrincipal(int vet[N][M])
{
    int i, j, resposta = -1;

    printf("\e[1;1H\e[2J");
    printf("Menu Principal\n\n");
    printf("1. Ordenar Vetor por Ordem Crescente\n");
    printf("2. Mediana dos Elementos do Vetor\n");
    printf("3. Multiplicar Todos os Elementos do Vetor por 3\n");
    printf("4. Criar Matriz com Vetor e com Quádruplos\n");
    printf("5. Cálcular o Logaritmo de Base Natural de Todos os Elementos do Vetor\n");
    printf("6. Valores das Posições Múltiplas de Três do Vetor\n");
    printf("7. Ajuda\n");
    printf("8. Opções Extra\n");
    printf("\n9. Criar novo vetor\n");
    printf("0. Sair\n");

    printf("\nVetor (em linha):\n(");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (i != N - 1)
            {
                printf("%3d, ", vet[i][j]);
            }
            else
            {
                printf("%3d ", vet[i][j]);
            }
        }
    }
    printf(" )\n\n");

    do
    {
        if (scanf("%d", &resposta) != 1 || resposta < 0 || resposta > 9)
        {
            printf("\nInput inválido! Tente novamente.\n");
        }
        limpaInputBuffer();
    } while (resposta < 0 || resposta > 9);
    printf("\n");

    return resposta;
}

/**
  *Extra options menu that returns the option number the user has chosen.
  */
//Menu das opções extra que devolve o número da opção que o utilizador escolheu
int menuExtra(int vet[N][M])
{
    int i, j, resposta = -1;

    printf("\e[1;1H\e[2J");
    printf("Menu Extra\n\n");
    printf("1. Misturar Metade do Vetor com Metade de Outro Novo\n");
    printf("2. Decomposição por Fatores Primos dos elementos Ímpares\n");
    printf("3. Multiplicar o Vetor Inicial por um Novo (Criar Matriz 18x18)\n");
    printf("4. Transposta da Matriz 18x18 da Opção Anterior\n");
    printf("\n0. Sair\n");

    printf("\nVetor (em linha):\n(");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (i != N - 1)
            {
                printf("%3d, ", vet[i][j]);
            }
            else
            {
                printf("%3d ", vet[i][j]);
            }
        }
    }
    printf(" )\n\n");

    do
    {
        if (scanf("%d", &resposta) != 1 || resposta < 0 || resposta > 4)
        {
            printf("\nInput inválido! Tente novamente.\n");
        }
        limpaInputBuffer();
    } while (resposta < 0 || resposta > 4);
    printf("\n");

    return resposta;
}

/**
  * This Function copies the vector given by the user to an auxiliary vector.
  */
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

/**
  * Realization of extra features depending on the user's option.
  */
//Realização das funcionalidades extra em função da opção do utilizador
void OpcoesExtra(int vet[N][M])
{
    int vetAux[N][M] = {}, vet18x18[N][N] = {};
    int i, j, resposta = -1, flag = 0;

    do
    {
        criaVetorAuxiliar(vet, vetAux);
        resposta = menuExtra(vetAux);

        switch (resposta)
        {
        case 1:
            misturaMetadeVetores(vetAux);
            printf("\nPrima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 2:
            decompoeImparesEmPrimos(vetAux);
            printf("\nPrima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 3:
            matriz18por18(vetAux, vet18x18);
            printf("\nMatriz 18x18 multiplicação de ambos os vetores:\n");
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    printf("%4d ", vet18x18[i][j]);
                }
                printf("\n");
            }
            flag++;
            printf("\nPrima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 4:
            if (flag == 0)
            {
                printf("Matriz 18x18 inexistente!\nExecute a opção 3 deste menu para criar uma matriz 18x18.\n");
            }
            else
            {
                transposta18por18(vet18x18);
            }
            printf("\nPrima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 0:
            resposta = 0;
            break;
        default:
            printf("Input inválido, por favor tente novamente.\n");
            break;
        }
    } while (resposta != 0); //condição para repetir o menu
}

/**
  * This is the main function os this program.
  */
int main(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("Número incorreto de argumentos.\n");
        exit(1);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            imprimeSocorro();
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            exit(1);
        }
        else
        {
            printf("Argumento inválido.\n");
            exit(1);
        }
    }
    else
    {
        int vet[N][M] = {}, vetAux[N][M] = {};
        int vet18x18[N][N] = {};
        int i, j, resposta_menu;

        printf("\e[1;1H\e[2J");
        printf("Seja bem-vindo(a) ao trabalho da Team 13!\n");
        printf("Este programa vai pedir um vetor ao utilizador e pode apresentar algumas estatisticas ou operações sobre ele.\n");
        printf("Prima 'Enter' para continuar.\n");
        limpaInputBuffer();
        printf("\nInsira 18 números inteiros compreendidos entre 6 e 28:\n");

        do
        {
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

                resposta_menu = menuPrincipal(vetAux);

                switch (resposta_menu)
                {
                case 1:
                    ordemCrescente(vetAux);
                    printf("O conjunto por ordem crescente é:\n");
                    for (i = 0; i < N; ++i)
                    {
                        printf("%d ", vetAux[i][M - 1]);
                    }
                    printf("\n\nPrima 'Enter' para continuar.\n");
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
                case 7:
                    imprimeSocorro();
                    break;
                case 8:
                    OpcoesExtra(vetAux);
                    break;
                case 9:
                    resposta_menu = 9;
                    break;
                case 0:
                    resposta_menu = 0;
                    break;
                default:
                    printf("Input inválido, por favor tente novamente.\n");
                    break;
                }
            } while (resposta_menu != 0 && resposta_menu != 9); //condição para repetir o menu
        } while (resposta_menu == 9);
    }

    return 0;
}
