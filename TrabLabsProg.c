#include <stdio.h>
#include <string.h>

#define N 18

//Menu que aparece ao executar o programa
void menuDeInicio(int *vet)
{
    //recebe ponteiro do arr onde vamos guardar os números;

    //imprime no ecrã as informações do trabalho
    //(possivelmente a UC e nomes de todos nós, mas tem de dizer que vamos pedir 18 nums e vamos dar estatísticas sobre eles);

    //recebe input validado do utilizador de 18 numeros entre 6 e 28, e armazen-os em posições contíguas do array;
}

//Menu principal que devolve o numero da operação a realizar no array
int menuPrincipal(void)
{
    //imprime as opções de operações que podem ser feitas ao vetor;

    //recebe input validado do número da opção;

    //devolve número da opção;
}

//Imprime o vetor por ordem crescente
void ordemCrescente(int *vet)
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

    for (i = 0; i < N; ++i)
    {
        printf("O conjunto por ordem crescente é: ");
        printf("%d, \n", vet[i]);
    }
}

//Cálcula a mediana dos elementos do vetor
void medianaDosElementos(int *vet)
{
    int soma, mediana;
    ordemCrescente(vet);
    // 18 / 2 = 9;
    
    soma = (vet[9]+ vet[10]); // Como N é par, 18, e a sua metade é ímpar, a mediana é através da soma dos seus valores 'do meio'
    mediana = soma / 2;

    printf("A mediana do conjunto dado é: %d", mediana);
}

//Multiplica os elementos por 3
void multiplicaPorTres(int *vet)
{
}

//Cria um arrAuxiliar para armazenar os quádruplos e com 2 ciclos for, armazena tudo num arr[2][N]
void matriz18Por2ComQuadruplos(int *vet)
{
}

//Calcula o logaritmo de todos os elementos do vetor
void logaritmoDosElementos(int *vet)
{
}

//Valores dos elementos que estão em posições multiplas de 3
void valoresDasPosicoesMult3(int *vet)
{
    //Cria-se um arrAuxiliar de tamanho N/3 = 18/3 = 6 para se armazenarem os elementos

    //Ciclo for em que quando (i % 3) == 0 o valor da posição do vetor é armazenado no ArrAuxiliar
}

//Não pode levar void no argumento por causa do --help
int main()
{
    int vet[N], vetAux[N];
    int resposta_menu;

    menuDeInicio(vet);

    do
    {
        resposta_menu = menuPrincipal();

        for (int i = 0; i < N; i++) //Faz o vetor auxiliar igual ao do input para não estarmos a alterar o do input consecutivamente
        {
            vetAux[i] = vet[i];
        }

        switch (resposta_menu)
        {
        case 1:
            ordemCrescente(vetAux);

        case 2:
            medianaDosElementos(vetAux);

        case 3:
            multiplicacaoPorTres(vetAux);

        case 4:
            matriz18Por2ComQuadruplos(vetAux);

        case 5:
            logaritmoDosElementos(vetAux);

        case 6:
            valoresDasPosicoesMult3(vetAux);
        }

    } while (1); //condição para repetir o menu

        return 0;
}
