#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//============================================================================================================================
void Bubble_Sort(int vetor[], int tam)
{
    int aux;
    for (int i = tam - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
//============================================================================================================================
void troca(int *vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}
//====================================================
int particiona(int *vetor, int inicio, int fim)
{
    int pivo, pivo_indice, i;
    pivo = vetor[fim];
    pivo_indice = inicio;
    for (i = inicio; i < fim; i++)
    {
        if (vetor[i] <= pivo)
        {
            troca(vetor, i, pivo_indice);
            pivo_indice++;
        }
    }
    troca(vetor, pivo_indice, fim);
    return pivo_indice;
}
//====================================================
int particiona_random(int *vetor, int inicio, int fim)
{
    int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
    troca(vetor, pivo_indice, fim);
    return particiona(vetor, inicio, fim);
}
//====================================================
void Quick_Sort(int *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo_indice = particiona_random(vetor, inicio, fim);
        Quick_Sort(vetor, inicio, pivo_indice - 1);
        Quick_Sort(vetor, pivo_indice + 1, fim);
    }
}
//============================================================================================================================

int main(){
    int indice, item1, item2, item3, item4, item5, tam1, tam2, tam3, tam4, tam5, *seq1, *seq2, *seq3, *seq4, *seq5, *seq1_copy, *seq2_copy, *seq3_copy, *seq4_copy, *seq5_copy;
    clock_t start, end;
    double time_spent;
    //====================================================
    srand((unsigned)time(NULL));
    tam1 = 10000 + (1000 * (rand() % 990));
    tam2 = 10000 + (1000 * (rand() % 990));
    tam3 = 10000 + (1000 * (rand() % 990));
    tam4 = 10000 + (1000 * (rand() % 990));
    tam5 = 10000 + (1000 * (rand() % 990));
    //====================================================
    printf("==============================================================================================================\n");
    printf("O tamanho da sequencia 1 e: %d\n", tam1);
    printf("O tamanho da sequencia 2 e: %d\n", tam2);
    printf("O tamanho da sequencia 3 e: %d\n", tam3);
    printf("O tamanho da sequencia 4 e: %d\n", tam4);
    printf("O tamanho da sequencia 5 e: %d\n", tam5);
    //====================================================
    /*tam1 = 10000;
    tam2 = 10000;
    tam3 = 10000;
    tam4 = 10000;
    tam5 = 10000;*/
    seq1 = malloc(tam1 * sizeof(int));
    seq2 = malloc(tam2 * sizeof(int));
    seq3 = malloc(tam3 * sizeof(int));
    seq4 = malloc(tam4 * sizeof(int));
    seq5 = malloc(tam5 * sizeof(int));
    seq1_copy = malloc(tam5 * sizeof(int));
    seq2_copy = malloc(tam5 * sizeof(int));
    seq3_copy = malloc(tam5 * sizeof(int));
    seq4_copy = malloc(tam5 * sizeof(int));
    seq5_copy = malloc(tam5 * sizeof(int));
    //====================================================
    srand((unsigned)time(NULL));
    for (int i = 0; i < tam1; i++)
    {
        *(seq1 + i) = 20 + (1999.98 * (rand() % 1000));
    }
    for (int i = 0; i < tam1; i++)
    {
        *(seq1_copy + i) = *(seq1 + i);
    }
    //====================================================
    for (int i = 0; i < tam2; i++)
    {
        *(seq2 + i) = 20 + (1999.98 * (rand() % 1000));
    }
    for (int i = 0; i < tam2; i++)
    {
        *(seq2_copy + i) = *(seq2 + i);
    }
    //====================================================
    for (int i = 0; i < tam3; i++)
    {
        *(seq3 + i) = 20 + (1999.98 * (rand() % 1000));
    }
    for (int i = 0; i < tam3; i++)
    {
        *(seq3_copy + i) = *(seq3 + i);
    }
    //====================================================
    for (int i = 0; i < tam4; i++)
    {
        *(seq4 + i) = 20 + (1999.98 * (rand() % 1000));
    }
    for (int i = 0; i < tam4; i++)
    {
        *(seq4_copy + i) = *(seq4 + i);
    }
    //====================================================
    for (int i = 0; i < tam5; i++)
    {
        *(seq5 + i) = 20 + (1999.98 * (rand() % 1000));
    }
    for (int i = 0; i < tam5; i++)
    {
        *(seq5_copy + i) = *(seq5 + i);
    }

    return 0;
}