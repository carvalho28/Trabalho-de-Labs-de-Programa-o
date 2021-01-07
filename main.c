#include <stdio.h>
#include <stdlib.h>
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
    } while (resposta < 0 || resposta > 6);
    printf("\n");

    return resposta;
}

//Imprime o vetor por ordem crescente
int *ordemCrescente(int *vet)
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

    return vet;
}

//Cálcula a mediana dos elementos do vetor
void medianaDosElementos(int *vet)
{
    int soma;
    float mediana;
    //ordemCrescente(vet);
    // 18 / 2 = 9;

    soma = (vet[8] + vet[9]); // Como N é par, 18, e a sua metade é ímpar, a mediana é através da soma dos seus valores 'do meio'
    mediana = soma / 2;

    printf("A mediana do conjunto dado é: %.2f\n", mediana);
}

//Multiplica os elementos por 3
void multiplicaPorTres(int *vet)
{
    int i;

    for (i = 0; i < N; i++)
    {
        vet[i] = vet[i] * 3;
    }

    //Vetor final:
    printf("O conjunto dos elementos multiplicados por 3 é: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

//Cria um arrAuxiliar para armazenar os quádruplos e com 2 ciclos for, armazena tudo num arr[2][N]
void matriz2Por18ComQuadruplos(int *vet)
{
    int arrVetor[2][N];
    int i, j;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            for (j = 0; j < N; j++)
            {
                arrVetor[i][j] = vet[j];
            }
        }

        if (i == 1)
        {
            for (j = 0; j < N; j++)
            {
                arrVetor[i][j] = 4 * vet[j];
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
void logaritmoDosElementos(int *vet)
{
    int i;
    float vetAux[N] = {};

    for (i = 0; i < N; i++)
    {
        vetAux[i] = log(vet[i]);
    }

    printf("O conjunto dos logaritmo de base 10 dos elementos é: ");
    for (i = 0; i < N; i++)
    {
        printf("%.2f ", vetAux[i]);
    }
    printf("\n");
}

//Valores dos elementos que estão em posições multiplas de 3
void valoresDasPosicoesMult3(int *vet)
{
    int i;

    printf("O conjunto dos elementos das posições múltiplas de 3 é: ");
    for (i = 0; i < N; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d ", vet[i]);
        }
    }
    printf("\n");
}

// Leitura de um novo vetor, e mostra um vetor que mistura metade do primeiro vetor e metade do segundo
void misturaMetadeVetores(int *vet1, int *vet2)
{
    int i, j;
    int vet3[N];

    for (i = 0; i < N/2; i++)
    {
        vet3[i] = vet1[i];
    }

    for (i = N/2; i < N; i++)
    {
        vet3[i] = vet2[i];
    }

    printf("O novo vetor com metade do primeiro e metade do segundo é:\n");
    for(j = 0; j < N; j++)
    {
        printf("%d ", vet3[j]);
    }
}

void decompoeImparesEmPrimos(int *vet)
{
    int i, j, k, contador, aux, posicao = 0;
    int primos[8] = {};
    int fatores[10] = {};

    //Armazena os numeros primos maiores que 2 num array, dado que os números a verificar são ímpares
    for(i = 3; i <= 28; i++)
    {
            contador = 0;
            for(j = 1; j <= 28; j++)
            {
                if(i % j == 0)
                {
                    contador++;
                }
            }
            if(contador == 2)
            {
                primos[posicao] = i;
                posicao++;
            }
    }

    for(i = 0; i < N; k++)
    {
        aux = 1;
        contador = -1;

        //Verifica se o número do array é ímpar
        if(vet[i] % 2 != 0)
        {
            contador = 0;
            aux = vet[i];
            for(j = 0; j < 8; j++)
            {
                //Guarda os numeros primos pelos quais o ímpar é divisível
                if(aux % primos[j] == 0)
                {
                    fatores[contador] = primos[j];
                    aux = aux / primos[j];
                    contador++;
                    j--;
                }

                if(aux == 1)
                {
                    printf("Decomposição do número %d na posição: %d\n", vet[i], i+1);
                    for(int k = 0; k < contador; k++)
                    {
                        if(k < contador && k != 0)
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

    if(contador == -1)
    {
        printf("\nNão há números ímpares!\n");
    }
}

//Não pode levar void no argumento por causa do --help
int main()
{
    int vet[N], vetAux[N], vetAux2[N], vetAux3[N], vetAux4[N], vetAux5[N];
    int vet2[N] = {};
    int i, resposta_menu;

    printf("\e[1;1H\e[2J");
    printf("Seja bem-vindo(a) ao trabalho do Grupo N!\n");
    printf("\nInsira 18 números inteiros compreendidos entre 6 e 28:\n");

    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Posição nº%d: ", i + 1); //Nota verificar se 6 e 28 pertencem a input;
            if (scanf("%d", &vet[i]) != 1 || vet[i] <= 6 || vet[i] >= 28)
            {
                printf("\nInput inválido. Tente novamente.\n");
            }
            printf("\n");
            limpaInputBuffer();
        } while (vet[i] <= 6 || vet[i] >= 28);
    }

    for (i = 0; i < N; i++)
    {
        vetAux[i] = vet[i];
        vetAux2[i] = vet[i];
        vetAux3[i] = vet[i];
        vetAux4[i] = vet[i];
        vetAux5[i] = vet[i];
    }

    do
    {
        resposta_menu = menuPrincipal();
        switch (resposta_menu)
        {
        case 1:
            ordemCrescente(vet);
            printf("O conjunto por ordem crescente é: ");
            for (i = 0; i < N; ++i)
            {
                printf("%d ", vet[i]);
            }
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 2:
            medianaDosElementos(vet);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 3:
            multiplicaPorTres(vetAux);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 4:
            matriz2Por18ComQuadruplos(vetAux2);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 5:
            logaritmoDosElementos(vetAux3);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
        case 6:
            valoresDasPosicoesMult3(vetAux4);
            printf("Prima 'Enter' para continuar.\n");
            limpaInputBuffer();
            break;
            /*
        case 7:
            decompoeImparesEmPrimos(vetAux5);
            break;
            */
        case 0:
            exit(1);
        default:
            printf("Input inválido, por favor tente novamente.\n");
            break;
        }
    } while (resposta_menu != 0); //condição para repetir o menu


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


    return 0;
}
