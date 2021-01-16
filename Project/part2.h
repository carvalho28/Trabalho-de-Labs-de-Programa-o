/**
  * @file part2.h
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
  * Reading a new vector, and shows a vector that mixes half of the first vector and half of the second.
  */
void mixHalfVectors(int vet1[N][M])
{
    int i, j;
    int vet2[N][1], vet3[N][1];

    //Segundo Vetor
    printf("Second vector:\n");
    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Position no. %d: ", i + 1); // Verify if the input is between 6 and 28
            if (scanf("%d", &vet2[i][0]) != 1 || vet2[i][0] <= 6 || vet2[i][0] >= 28)
            {
                printf("\nInvalid input. Please try again!\n");
            }
            printf("\n");
            while (getchar() != '\n')
                ;
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

    printf("The new vector result of half of the first vector and half of the second:\n");
    for (j = 0; j < N; j++)
    {
        printf("%d ", vet3[j][0]);
    }
}

/**
  * Decompose odd and prime numbers.
  */
void decomposeIntoPrimes(int vet[N][M])
{
    int i, j, k, contador, aux, posicao = 0;
    int primos[8] = {};
    int fatores[10] = {};

    // Stores the prime numbers bigger than 2 in an array, since the numbers to verify are odd
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

    for (i = 0; i < N; i++)
    {
        aux = 1;
        contador = -1;

        // Verifies if the number of the array is odd or not
        if (vet[i][0] % 2 != 0)
        {
            contador = 0;
            aux = vet[i][0];
            for (j = 0; j < 8; j++)
            {
                // Stores the prime numbers by which the vector is divisible
                if (aux % primos[j] == 0)
                {
                    fatores[contador] = primos[j];
                    aux = aux / primos[j];
                    contador++;
                    j--;
                }

                if (aux == 1)
                {
                    printf("Decomposition of the number %d on position no. %d\n", vet[i][0], i + 1);
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
        printf("\nThere are no odd numbers.\n");
    }
}

/**
  * 18 by 18 matrix.
  */
void matrix18x18(int vet[N][M], int vet18x18[N][N])
{

    int vet3[M][N];

    int i, j, k;

    // Third vector
    printf("Values of the 1x18 vector by which you want to multiply the initial vector:\n");
    for (j = 0; j < N; j++)
    {
        do
        {
            printf("Position no. %d: ", j + 1); // Verify if input is between 6 and 28
            if (scanf("%d", &vet3[0][j]) != 1 || vet3[0][j] <= 6 || vet3[0][j] >= 28)
            {
                printf("\nInvalid input. Please try again!\n");
            }
            printf("\n");
            while (getchar() != '\n')
                ;
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
}

/**
  * Transposed from matrix 18 by 18.
  */
void transpose18x18(int vet[N][N])
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

    printf("\nTransposed matrix, product of both vectors:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d ", transposta[i][j]);
        }
        printf("\n");
    }
}

/**
  * This function shows the user the help menu.
  */
// Help function
void printHelp(void)
{
    printf("\e[1;1H\e[2J");
    printf("***************************\n");
    printf(" Welcome to the Help Menu! \n");
    printf("***************************\n\n");
    printf("-> Initially, the user will be asked to input values for the creation of a new vector;\n");
    printf("-> Then, the user can choose what to do with the newly created vector;\n");
    printf("-> To select an option, the user may input its respective number and then press 'Enter';\n");
    printf("-> To quit from the previous selected option, the user just needs to press 'Enter' again;\n");
    printf("-> If the user wants to input new values for the vector, select option 9 in the main menu;\n");
    printf("-> To execute the program, type './a.out' in the terminal;");
    printf("-> Thank you for reading!\n\n");
}