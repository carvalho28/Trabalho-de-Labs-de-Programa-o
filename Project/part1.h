/**
  * @file part1.h
  * @brief This file of the project contains the main features of the program.
  * @version 0.69
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
  * @brief Prints the vector in ascending order.
  * @param vet[N][M] it is the vector created by the user.
  */
void ordemCrescente(int vet[N][M])
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
  * @brief Calculates the median of the vector elements.
  * @param vet[N][M] it is the vector created by the user.
  */
void medianaDosElementos(int vet[N][M])
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

/**
  * @brief Multiplies the vector elements by 3.
  * @param vet[N][M] it is the vector created by the user.
  */
void multiplicaPorTres(int vet[N][M])
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

/**
  * @brief Creates an auxiliary array to store quadruples and with 2 cycles for, stores everything in an arr[2][N].
  * @param vet[N][M] it is the vector created by the user.
  */
void matriz2Por18ComQuadruplos(int vet[N][M])
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
  * @brief Calculates the logarithm of all elements of the vector.
  * @param vet[N][M] it is the vector created by the user.
  */
void logaritmoDosElementos(int vet[N][M])
{
    int i;
    float vetAux[N][M] = {};

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

/**
  * @brief Values ​​of elements that are in multiple positions of 3.
  * @param vet[N][M] it is the vector created by the user.
  */
void valoresDasPosicoesMult3(int vet[N][M])
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
