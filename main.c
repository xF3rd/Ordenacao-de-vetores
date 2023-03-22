#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//============================================================================================================================
void Bubble_Sort(int vetor[], int tam)
{
    int aux;
    for (int i = tam - 1; i > 0; i--) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (vetor[j] > vetor[j + 1]) 
            {
                aux = vetor[j]; //Ocorre a troca
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
} 
//============================================================================================================================
void Insertion_Sort(int vetor[], int tam)
{
    for (int i = 1; i < tam; i++)
    {
        int tmp = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > tmp)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = tmp;
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
void inverte(int *vetor, int *copia, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        *(vetor + i) = *(copia + i);
    }
}
//============================================================================================================================
int BuscaSequencial(int *vetor, int tamanho, int item)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (*(vetor + i) == item)
        {
            return i;
        }
    }
    return -1;
}
//============================================================================================================================
int BuscaBinaria(int *vetor, int tamanho, int item)
{
    int comeco = 0;
    int fim = tamanho - 1;

    while (comeco <= fim)
    {
        int i = comeco + (fim - comeco) / 2;

        if (*(vetor + i) == item)
        {
            return i;
        }
        if (*(vetor + i) < item)
        {
            comeco = i + 1;
        }
        else
        {
            fim = i - 1;
        }
    }
    return -1;
}
//============================================================================================================================
void rando(int *vet, int tam, int *vet_copy)
{
    for (int i = 0; i < tam; i++)
    {
        *(vet + i) = 20 + (1999.98 * (rand() % 1000));
    }
    for (int i = 0; i < tam; i++)
    {
        *(vet_copy + i) = *(vet + i);
    }
}
//============================================================================================================================
void medeOrdenar(int *vet, int tam, int op){
    clock_t start, end;
    double time_spent;
    start = clock();
    if(op == 1){
        Bubble_Sort(vet, tam);
    }else if(op == 2){
        Insertion_Sort(vet, tam);
    }else{
        Quick_Sort(vet, 0, tam - 1);
    }
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    if (op == 1)
    {
        printf("||  %f segundos   ||", time_spent);
    }
    else if (op == 2)
    {
        printf("    %f segundos    ||", time_spent);
    }
    else
    {
        printf("  %f segundos  ||", time_spent);
    }
}
//============================================================================================================================
void medeBusca(int *vet, int tam, int op, int item){
    clock_t start, end;
    double time_spent;
    int indice;
    start = clock();
    if(op == 1){
        indice = BuscaSequencial(vet, tam, item);
    }else{
        indice = BuscaBinaria(vet, tam, item);
    }
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    if (op == 1)
    {
        printf("    %f segundos     ||", time_spent);
    }
    else
    {
        printf("   %f segundos   ||", time_spent);
        if(indice == -1){
            printf("Item nao encontrado");
        }else{
                printf("INDICE: %d", indice + 1);
        }
    }
}
//============================================================================================================================
int main()
{
    int item1, item2, item3, item4, item5, tam1, tam2, tam3, tam4, tam5, *seq1, *seq2, *seq3, *seq4, *seq5, *seq1_copy, *seq2_copy, *seq3_copy, *seq4_copy, *seq5_copy;
    //====================================================
    srand((unsigned)time(NULL));
    tam1 = 10000 + (1000 * (rand() % 990));
    tam2 = 10000 + (1000 * (rand() % 990));
    tam3 = 10000 + (1000 * (rand() % 990));
    tam4 = 10000 + (1000 * (rand() % 990));
    tam5 = 10000 + (1000 * (rand() % 990));
    //====================================================
    tam1 = 50000;
    tam2 = 50000;
    tam3 = 50000;
    tam4 = 50000;
    tam5 = 50000;
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
    rando(seq1, tam1, seq1_copy);
    rando(seq2, tam2, seq2_copy);
    rando(seq3, tam3, seq3_copy);
    rando(seq4, tam4, seq4_copy);
    rando(seq5, tam5, seq5_copy);
    //============================================================================================================================
    printf("=================================================================================================================================\n");
    printf("Digite um numero (20 a 2.000.000) para ser procurado na sequencia 1: ");
    scanf("%d", &item1);
    printf("Digite um numero (20 a 2.000.000) para ser procurado na sequencia 2: ");
    scanf("%d", &item2);
    printf("Digite um numero (20 a 2.000.000) para ser procurado na sequencia 3: ");
    scanf("%d", &item3);
    printf("Digite um numero (20 a 2.000.000) para ser procurado na sequencia 4: ");
    scanf("%d", &item4);
    printf("Digite um numero (20 a 2.000.000) para ser procurado na sequencia 5: ");
    scanf("%d", &item5);
    printf("=================================================================================================================================\n");
    printf("||======================||=========================||=====================||==========================||=======================||\n");
    //============================================================================================================================
    printf("||        Bubble        ||        Insertion        ||        Quick        ||        Sequencial        ||        Binaria        ||\n");
    printf("||======================||=========================||=====================||==========================||=======================||\n");
    medeOrdenar(seq1, tam1, 1);
    inverte(seq1, seq1_copy, tam1);
    //====================================================
    medeOrdenar(seq1, tam1, 2);
    inverte(seq1, seq1_copy, tam1);
    //====================================================
    medeOrdenar(seq1, tam1, 3);
    //====================================================
    medeBusca(seq1, tam1, 1, item1);
    medeBusca(seq1, tam1, 2, item1);
    printf("\n||======================||=========================||=====================||==========================||=======================||\n");
    //============================================================================================================================
    medeOrdenar(seq2, tam2, 1);
    inverte(seq2, seq2_copy, tam2);
    //====================================================
    medeOrdenar(seq2, tam2, 2);
    inverte(seq2, seq2_copy, tam2);
    //====================================================
    medeOrdenar(seq2, tam2, 3);
    //====================================================
    medeBusca(seq2, tam2, 1, item2);
    medeBusca(seq2, tam2, 2, item2);
    printf("\n||======================||=========================||=====================||==========================||=======================||\n");
    //============================================================================================================================
    medeOrdenar(seq3, tam3, 1);
    inverte(seq3, seq3_copy, tam3);
    //====================================================
    medeOrdenar(seq3, tam3, 2);
    inverte(seq3, seq3_copy, tam3);
    //====================================================
    medeOrdenar(seq3, tam3, 3);
    //====================================================
    medeBusca(seq3, tam3, 1, item3);
    medeBusca(seq3, tam3, 2, item3);
    printf("\n||======================||=========================||=====================||==========================||=======================||\n");
    //============================================================================================================================
    medeOrdenar(seq4, tam4, 1);
    inverte(seq4, seq4_copy, tam4);
    //====================================================
    medeOrdenar(seq4, tam4, 2);
    inverte(seq4, seq4_copy, tam4);
    //====================================================
    medeOrdenar(seq4, tam4, 3);
    //====================================================
    medeBusca(seq4, tam4, 1, item4);
    medeBusca(seq4, tam4, 2, item4);
    printf("\n||======================||=========================||=====================||==========================||=======================||\n");
    //============================================================================================================================
    medeOrdenar(seq5, tam5, 1);
    inverte(seq5, seq5_copy, tam5);
    //====================================================
    medeOrdenar(seq5, tam5, 2);
    inverte(seq5, seq5_copy, tam5);
    //====================================================
    medeOrdenar(seq5, tam5, 3);
    //====================================================
    medeBusca(seq5, tam5, 1, item5);
    medeBusca(seq5, tam5, 2, item5);
    printf("\n||======================||=========================||=====================||==========================||=======================||\n");
    //====================================================
        free(seq1);
        free(seq2);
        free(seq3);
        free(seq4);
        free(seq5);
        free(seq1_copy);
        free(seq2_copy);
        free(seq3_copy);
        free(seq4_copy);
        free(seq5_copy);
        //====================================================
        return 0;
}