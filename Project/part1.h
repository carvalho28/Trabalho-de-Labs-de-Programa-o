/**
  * @file part1.h
  * @brief In this part of the program we implemented the main features of our program.
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
  * Prints the vector in ascending order.
  */
void ascendingOrder(int vet[N][M])
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

/**
  * Calculates the median of the vector elements.
  */
void elementsMedian(int vet[N][M])
{
    int i, j, aux;
    float mediana, soma;

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

    soma = (vet[8][0] + vet[9][0]); // Since N is even (18) and its half is odd (9), the calculation of the median is done by adding the two numbers in the middle.
    mediana = soma / 2;

    printf("The median is: %.2f\n", mediana);
}

/**
  * Multiplies the vector elements by 3.
  */
void multiplyBy3(int vet[N][M])
{
    int i;

    for (i = 0; i < N; i++)
    {
        vet[i][0] = vet[i][0] * 3;
    }

    // Final vector
    printf("The set of elements multiplied by 3 is: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", vet[i][0]);
    }
    printf("\n");
}

/**
  * Creates an auxiliary array to store the quadrupled values, and with 2 'for' loops, stores everything in an arr[2][N].
  */
void matrix2x18Quadruples(int vet[N][M])
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

/**
  * Calculates the natural logarithm of all the elements of the vector.
  */
void elementsLogarithm(int vet[N][M])
{
    int i;
    float vetAux[N][M] = {};

    for (i = 0; i < N; i++)
    {
        vetAux[i][0] = log(vet[i][0]);
    }

    printf("The natural logarithm of all elements is:\n");
    for (i = 0; i < N; i++)
    {
        printf("%5.2f ", vetAux[i][0]);
    }
    printf("\n");
}

/**
  * Values of elements in positions that are multiple of 3
  */
void mult3PositionsValues(int vet[N][M])
{
    int i;

    printf("The elements in positions that are multiple of 3 are: ");
    for (i = 0; i < N; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("%d ", vet[i][0]);
        }
    }
    printf("\n");
}
