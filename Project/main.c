#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "part1.h"
#include "part2.h"

/**
  * @file main.c
  * @brief This file contains the main function, adtional features and menus of the program.
  * @version 1.00
  * @authors <c>Team 13</c><ul><li>Diogo Carvalho Nº 45716 </li> <li>Eduardo Mendes Nº 45916 </li> <li>Francisco Casais Nº 45465 </li> <li>Guilherme Barata Nº 45779</li> <li>João Marques Nº 45722</li> </ul>
  * @copyright Copyright 2021 <c>Team 13</c>. All rights reserved. \n This project is released under the Apache License 2.0.
  */

/**
  * N is the number of rows of the matrix.
  */
#define N 18
/**
  * M is the number of columns of the matrix.
  */
#define M 1

/**
  * @brief Function that clears the input buffer. Useful for clearing "\n" from the buffer after using the scanf function.
  */
void cleanInputBuffer(void)
{
    while (getchar() != '\n')
        ;
}

/**
  * @brief This function shows the user the main menu of the program.
  * @param vet[N][M] it is the vector created by the user.
  */
int mainMenu(int vet[N][M])
{
    int i, j, resposta = -1;

    printf("\e[1;1H\e[2J");

    printf("\nTransposed Matriz:\n[");
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
    printf("]\n\n");

    printf("Main Menu\n\n");
    printf("1. Sort Vector by Ascending Order\n");
    printf("2. Median of Given Vector\n");
    printf("3. Multiply All Vector Elements by 3\n");
    printf("4. Create Matrix with Vector and Quadruples\n");
    printf("5. Natural Base Logarithm of All Vector Elements\n");
    printf("6. Value of Elements in Positions Multiple of Three\n");
    printf("7. Help\n");
    printf("8. Additional Options\n");
    printf("\n9. Create New Vector\n");
    printf("0. Exit\n");

    do
    {
        if (scanf("%d", &resposta) != 1 || resposta < 0 || resposta > 9)
        {
            printf("\nInvalid input. Please try again!\n");
        }
        cleanInputBuffer();
    } while (resposta < 0 || resposta > 9);
    printf("\n");

    return resposta;
}

/**
  * @brief Extra options menu that returns the option number the user has chosen.
  * @param vet[N][M] it is the vector created by the user.
  */
int extraMenu(int vet[N][M])
{
    int i, j, resposta = -1;

    printf("\e[1;1H\e[2J");
    printf("\nTransposed Matriz:\n[");
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
    printf("]\n\n");
    printf("Additional Options\n\n");
    printf("1. Mix Half of the Vector with Half of a New One\n");
    printf("2. Prime Factorization of the Vector's Odd Numbers\n");
    printf("3. Multiply the First Vector by a New One (Create 18x18 Matrix)\n");
    printf("4. Previous Option's 18x18 Matrix Transposition\n");
    printf("\n0. Exit\n");

    

    do
    {
        if (scanf("%d", &resposta) != 1 || resposta < 0 || resposta > 4)
        {
            printf("\nInvalid input. Please try again!\n");
        }
        cleanInputBuffer();
    } while (resposta < 0 || resposta > 4);
    printf("\n");

    return resposta;
}

/**
  * @brief This Function copies the vector given by the user to an auxiliary vector.
  * @param vetInicial it is the initional vector wich was asked to the user;
  * @param vetAuxiliar it is the aditional vector created by the user.
  */
void createAuxVec(int vetInicial[N][M], int vetAuxiliar[N][M])
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
  * @brief Realization of extra features depending on the user's option.
  * @param vet[N][M] it`s the vector created by the user.
  */
void extraOptions(int vet[N][M])
{
    int vetAux[N][M] = {}, vet18x18[N][N] = {};
    int i, j, resposta = -1, flag = 0;

    do
    {
        createAuxVec(vet, vetAux);
        resposta = extraMenu(vetAux);

        switch (resposta)
        {
        case 1:
            mixHalfVectors(vetAux);
            printf("\nPress 'Enter' to continue.\n");
            cleanInputBuffer();
            break;
        case 2:
            OddPrimeFactoring(vetAux);
            printf("\nPress 'Enter' to continue.\n");
            cleanInputBuffer();
            break;
        case 3:
            matrix18x18(vetAux, vet18x18);
            printf("\nThe 18x18 matrix which isthe product of the two vectors is:\n");
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    printf("%4d ", vet18x18[i][j]);
                }
                printf("\n");
            }
            flag++;
            printf("\nPress 'Enter' to continue.\n");
            cleanInputBuffer();
            break;
        case 4:
            if (flag == 0)
            {
                printf("A 18x18 matrix does not exist.\nSelect option '3' to create a 18x18 matrix.\n");
            }
            else
            {
                transpose18x18(vet18x18);
            }
            printf("\nPress 'Enter' to continue.\n");
            cleanInputBuffer();
            break;
        case 0:
            resposta = 0;
            break;
        default:
            printf("Invalid input. Please try again!\n");
            break;
        }
    } while (resposta != 0); // menu loop condition
}

/**
  * @brief This is the main function os this program.
  * @param argc it is the quantity of arguments;
  * @param argv it is a pointer for the arguments, which are strings.
  */
int main(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("Incorrect number of arguments.\n");
        exit(1);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            printHelp();
            printf("Press 'Enter' to continue.\n");
            cleanInputBuffer();
            exit(1);
        }
        else
        {
            printf("Invalid argument.\n");
            exit(1);
        }
    }
    else
    {
        int vet[N][M] = {}, vetAux[N][M] = {};
        int i, resposta_menu;

        printf("\e[1;1H\e[2J");
        printf("Welcome to B1nV3ctor!\n");
        printf("This program will ask the user to insert a vector and then present some statistics or operations using it.\n");
        printf("Press 'Enter' to continue.\n");
        cleanInputBuffer();
        printf("\nInsert 18 integers between 6 and 28:\n");

        do
        {
            for (i = 0; i < N; i++)
            {
                do
                {
                    printf("Position no. %d: ", i + 1); // Verify if input is between 6 and 28
                    if (scanf("%d", &vet[i][0]) != 1 || vet[i][0] <= 6 || vet[i][0] >= 28)
                    {
                        printf("\nInvalid input. Please try again!\n");
                    }
                    printf("\n");
                    cleanInputBuffer();
                } while (vet[i][0] <= 6 || vet[i][0] >= 28);
            }

            do
            {
                createAuxVec(vet, vetAux);

                resposta_menu = mainMenu(vetAux);

                switch (resposta_menu)
                {
                case 1:
                    ascendingOrder(vetAux);
                    printf("The vector's elements in ascending order are as follows:\n");
                    for (i = 0; i < N; ++i)
                    {
                        printf("%d ", vetAux[i][M - 1]);
                    }
                    printf("\n\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 2:
                    elementsMedian(vetAux);
                    printf("\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 3:
                    multiplyBy3(vetAux);
                    printf("\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 4:
                    matrix2x18Quadruples(vetAux);
                    printf("\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 5:
                    elementsLogarithm(vetAux);
                    printf("\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 6:
                    mult3PositionsValues(vetAux);
                    printf("\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 7:
                    printHelp();
                    printf("\nPress 'Enter' to continue.\n");
                    cleanInputBuffer();
                    break;
                case 8:
                    extraOptions(vetAux);
                    break;
                case 9:
                    resposta_menu = 9;
                    break;
                case 0:
                    resposta_menu = 0;
                    break;
                default:
                    printf("Invalid input. Please try again!\n");
                    break;
                }
            } while (resposta_menu != 0 && resposta_menu != 9); // menu loop condition
        } while (resposta_menu == 9);
    }

    return 0;
}
