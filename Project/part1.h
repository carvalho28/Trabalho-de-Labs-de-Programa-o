/**
  * @file part1.h
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
  * Prints the vector in ascending order.
  */
//Imprime o vetor por ordem crescente
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
  * Calculates the median of the vector elements.
  */
//Cálcula a mediana dos elementos do vetor
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
  * Multiplies the vector elements by 3.
  */
//Multiplica os elementos por 3
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
  * Creates an auxiliary array to store quadruples and with 2 cycles for, stores everything in an arr[2][N].
  */
//Cria um arrAuxiliar para armazenar os quádruplos e com 2 ciclos for, armazena tudo num arr[2][N]
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
  * Calculates the logarithm of all elements of the vector.
  */
//Calcula o logaritmo de todos os elementos do vetor
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
  * Values ​​of elements that are in multiple positions of 3
  */
//Valores dos elementos que estão em posições multiplas de 3
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