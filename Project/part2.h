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

    printf("O novo vetor com metade do primeiro e metade do segundo é:\n");
    for (j = 0; j < N; j++)
    {
        printf("%d ", vet3[j][0]);
    }
}

/**
  * Decompose odd and prime numbers.
  */
void decompoeImparesEmPrimos(int vet[N][M])
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

    for (i = 0; i < N; i++)
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

/**
  * 18 by 18 matrix.
  */
void matriz18por18(int vet[N][M], int vet18x18[N][N])
{

    int vet3[M][N];

    int i, j, k;

    // Terceiro Vetor
    printf("Valores do vetor 1x18 pelo qual quer multiplicar o vetor inicial:\n");
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

/**
  * This function shows the user the help menu.
  */
//Função do Socorro
void imprimeSocorro(void)
{
    printf("\e[1;1H\e[2J");
    printf("*****************************\n");
    printf(" Bem-vindo ao Menu de Ajuda! \n");
    printf("*****************************\n\n");
    printf("-> Inicialmente irá ser pedido ao utilizador para inserir valores para a contrução de um vetor;\n");
    printf("-> Após o input de um vetor, o utilizador tem várias escolhas sobre o que pode fazer com o seu vetor;\n");
    printf("-> Para cada opção o utilizador deve inserir o número indicado seguido de 'Enter';\n");
    printf("-> Para sair da escolha anterior pressionar a tecla 'Enter';\n");
    printf("-> Se desejar inserir outros valores pode fazê-lo, inserindo '9', seguido de 'Enter', no menu principal;\n");
    printf("-> Para execurtar o programa inserir na linha de comandos ./a.out;");
    printf("-> Votos de bons cálculos!\n\n");
}