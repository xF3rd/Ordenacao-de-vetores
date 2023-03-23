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
    printf("Item nao encontrado\n");
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
int main()
{
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
    //============================================================================================================================
    printf("==============================================================================================================\n");
    start = clock();
    Bubble_Sort(seq1, tam1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 1 com Bubble Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq1, seq1_copy, tam1);
    //====================================================
    start = clock();
    Insertion_Sort(seq1, tam1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 1 com Insertion Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq1, seq1_copy, tam1);
    //====================================================
    start = clock();
    Quick_Sort(seq1, 0, tam1 - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 1 com Quick Sort: %f segundos\n", time_spent);
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    Bubble_Sort(seq2, tam2);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 2 com Bubble Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq2, seq2_copy, tam2);
    //====================================================
    start = clock();
    Insertion_Sort(seq2, tam2);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 2 com Insertion Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq2, seq2_copy, tam2);
    //====================================================
    start = clock();
    Quick_Sort(seq2, 0, tam2 - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 2 com Quick Sort: %f segundos\n", time_spent);
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    Bubble_Sort(seq3, tam3);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 3 com Bubble Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq3, seq3_copy, tam3);
    //====================================================
    start = clock();
    Insertion_Sort(seq3, tam3);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 3 com Insertion Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq3, seq3_copy, tam3);
    //====================================================
    start = clock();
    Quick_Sort(seq3, 0, tam3 - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 3 com Quick Sort: %f segundos\n", time_spent);
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    Bubble_Sort(seq4, tam4);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 4 com Bubble Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq4, seq4_copy, tam4);
    //====================================================
    start = clock();
    Insertion_Sort(seq4, tam4);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 4 com Insertion Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq4, seq4_copy, tam4);
    //====================================================
    start = clock();
    Quick_Sort(seq4, 0, tam4 - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 4 com Quick Sort: %f segundos\n", time_spent);
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    Bubble_Sort(seq5, tam5);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 5 com Bubble Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq5, seq5_copy, tam5);
    //====================================================
    start = clock();
    Insertion_Sort(seq5, tam5);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 5 com Insertion Sort: %f segundos\n", time_spent);
    //====================================================
    inverte(seq5, seq5_copy, tam5);
    //====================================================
    start = clock();
    Quick_Sort(seq5, 0, tam5 - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao da sequencia 5 com Quick Sort: %f segundos\n", time_spent);
    printf("==============================================================================================================\n");
    //============================================================================================================================
    printf("Digite um numero para ser procurado na sequencia 1: ");
    scanf("%d", &item1);
    printf("Digite um numero para ser procurado na sequencia 2: ");
    scanf("%d", &item2);
    printf("Digite um numero para ser procurado na sequencia 3: ");
    scanf("%d", &item3);
    printf("Digite um numero para ser procurado na sequencia 4: ");
    scanf("%d", &item4);
    printf("Digite um numero para ser procurado na sequencia 5: ");
    scanf("%d", &item5);
    printf("==============================================================================================================\n");
    //====================================================
    start = clock();
    indice = BuscaSequencial(seq1, tam1, item1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 1 com Busca Sequencial: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    //====================================================
    start = clock();
    indice = BuscaBinaria(seq1, tam1, item1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 1 com Busca Binaria: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    indice = BuscaSequencial(seq2, tam2, item2);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 2 com Busca Sequencial: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    //====================================================
    start = clock();
    indice = BuscaBinaria(seq2, tam2, item2);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 2 com Busca Binaria: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    indice = BuscaSequencial(seq3, tam3, item3);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 3 com Busca Sequencial: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    //====================================================
    start = clock();
    indice = BuscaBinaria(seq3, tam3, item3);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 3 com Busca Binaria: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    indice = BuscaSequencial(seq4, tam4, item4);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 4 com Busca Sequencial: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    //====================================================
    start = clock();
    indice = BuscaBinaria(seq4, tam4, item4);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 4 com Busca Binaria: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    printf("==============================================================================================================\n");
    //============================================================================================================================
    start = clock();
    indice = BuscaSequencial(seq5, tam5, item5);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 5 com Busca Sequencial: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    //====================================================
    start = clock();
    indice = BuscaBinaria(seq5, tam5, item5);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de busca na sequencia 5 com Busca Binaria: %f segundos\n", time_spent);
    if (indice != -1)
    {
        printf("INDICE: %d\n", indice + 1);
    }
    printf("==============================================================================================================\n");
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