#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int vet[], int tam)
{
    clock_t Ticks[2];
    Ticks[0] = clock();

    int i, j, aux;

    for(i = 0; i < tam; i ++)
    {
        for(j = 0; j < tam; j ++)
        {
            if(vet[j] > vet[j+1])
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms \n", Tempo);
}

void selectionsort(int vet[], int tam)
{
    clock_t Ticks[2];
    Ticks[0] = clock();

    int i, j, min, aux;

    for(i = 0; i < (tam-1); i++)
    {
        min = i;

        for(j = (i+1); j < tam; j++)
        {
            if(vet[j] < vet[min])
            min = j;
        }
        if(vet[i] != vet[min])
        {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms \n", Tempo);
}

void insertionsort(int vet[], int tam)
{
    clock_t Ticks[2];
    Ticks[0] = clock();

    int i, key, j;

    for(i = 1; i < tam; i++)
    {
        key = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms \n", Tempo);
}

void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));


    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergesortfunc(int vetor[], int comeco, int fim){

    if (comeco < fim) {
        int meio = (fim+comeco)/2;
        mergesortfunc(vetor, comeco, meio);
        mergesortfunc(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void mergesort(int vetor[], int inteiro)
{
    clock_t Ticks[2];
    Ticks[0] = clock();

    mergesortfunc(vetor,0,inteiro);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms \n", Tempo);
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quick(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quick(array, low, pi - 1);
    quick(array, pi + 1, high);
  }
}

void quicksort(int vetor[], int inteiro)
{
    clock_t Ticks[2];
    Ticks[0] = clock();

    quick(vetor,0,inteiro);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms \n", Tempo);
}

void preenchervetor(int vet[], int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        vet[i] = rand()%tam;
    }
}

void imprimirvetor(int vet[], int tam)
{
    int i;

    printf("Vetor: ");

    for(i = 0; i < tam; i ++)
    {
        printf("%d ",vet[i]);
    }

    printf("\n");
}

void copiarvetor(int vet2[], int vet1[], int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        vet2[i] = vet1[i];
    }
}

int main()
{
    int vet10[10], vet50[50], vet100[100], vet500[500], vet1000[1000], vet5000[5000], vet10000[10000], vet15000[15000], vet100000[100000];
    int aux10[10], aux50[50], aux100[100], aux500[500], aux1000[1000], aux5000[5000], aux10000[10000], aux15000[15000], aux100000[100000];

    preenchervetor(vet10,10);
    preenchervetor(vet50,50);
    preenchervetor(vet100,100);
    preenchervetor(vet500,500);
    preenchervetor(vet1000,1000);
    preenchervetor(vet5000,5000);
    preenchervetor(vet10000,10000);
    preenchervetor(vet15000,15000);
    preenchervetor(vet100000,100000);

    copiarvetor(aux10,vet10,10);
    copiarvetor(aux50,vet50,50);
    copiarvetor(aux100,vet100,100);
    copiarvetor(aux500,vet500,500);
    copiarvetor(aux1000,vet1000,1000);
    copiarvetor(aux5000,vet5000,5000);
    copiarvetor(aux10000,vet10000,10000);
    copiarvetor(aux15000,vet15000,15000);
    copiarvetor(aux100000,vet100000,100000);

    printf("Bubble Sort \n");
    bubblesort(aux10,10);
    bubblesort(aux50,50);
    bubblesort(aux100,100);
    bubblesort(aux500,500);
    bubblesort(aux1000,1000);
    bubblesort(aux5000,5000);
    bubblesort(aux10000,10000);
    bubblesort(aux15000,15000);
    bubblesort(aux100000,100000);

    printf("\n");printf("\n");

    copiarvetor(aux10,vet10,10);
    copiarvetor(aux50,vet50,50);
    copiarvetor(aux100,vet100,100);
    copiarvetor(aux500,vet500,500);
    copiarvetor(aux1000,vet1000,1000);
    copiarvetor(aux5000,vet5000,5000);
    copiarvetor(aux10000,vet10000,10000);
    copiarvetor(aux15000,vet15000,15000);
    copiarvetor(aux100000,vet100000,100000);

    printf("Selection Sort \n");
    selectionsort(aux10,10);
    selectionsort(aux50,50);
    selectionsort(aux100,100);
    selectionsort(aux500,500);
    selectionsort(aux1000,1000);
    selectionsort(aux5000,5000);
    selectionsort(aux10000,10000);
    selectionsort(aux15000,15000);
    selectionsort(aux100000,100000);

    printf("\n");printf("\n");

    copiarvetor(aux10,vet10,10);
    copiarvetor(aux50,vet50,50);
    copiarvetor(aux100,vet100,100);
    copiarvetor(aux500,vet500,500);
    copiarvetor(aux1000,vet1000,1000);
    copiarvetor(aux5000,vet5000,5000);
    copiarvetor(aux10000,vet10000,10000);
    copiarvetor(aux15000,vet15000,15000);
    copiarvetor(aux100000,vet100000,100000);

    printf("Insertion Sort \n");
    insertionsort(aux10,10);
    insertionsort(aux50,50);
    insertionsort(aux100,100);
    insertionsort(aux500,500);
    insertionsort(aux1000,1000);
    insertionsort(aux5000,5000);
    insertionsort(aux10000,10000);
    insertionsort(aux15000,15000);
    insertionsort(aux100000,100000);

    printf("\n");printf("\n");

    copiarvetor(aux10,vet10,10);
    copiarvetor(aux50,vet50,50);
    copiarvetor(aux100,vet100,100);
    copiarvetor(aux500,vet500,500);
    copiarvetor(aux1000,vet1000,1000);
    copiarvetor(aux5000,vet5000,5000);
    copiarvetor(aux10000,vet10000,10000);
    copiarvetor(aux15000,vet15000,15000);
    copiarvetor(aux100000,vet100000,100000);

    printf("Merge Sort \n");
    mergesort(aux10,10);
    mergesort(aux50,50);
    mergesort(aux100,100);
    mergesort(aux500,500);
    mergesort(aux1000,1000);
    mergesort(aux5000,5000);
    mergesort(aux10000,10000);
    mergesort(aux15000,15000);
    mergesort(aux100000,100000);

    printf("\n");printf("\n");

    copiarvetor(aux10,vet10,10);
    copiarvetor(aux50,vet50,50);
    copiarvetor(aux100,vet100,100);
    copiarvetor(aux500,vet500,500);
    copiarvetor(aux1000,vet1000,1000);
    copiarvetor(aux5000,vet5000,5000);
    copiarvetor(aux10000,vet10000,10000);
    copiarvetor(aux15000,vet15000,15000);
    copiarvetor(aux100000,vet100000,100000);

    printf("Quick Sort \n");
    quicksort(aux10,10);
    quicksort(aux50,50);
    quicksort(aux100,100);
    quicksort(aux500,500);
    quicksort(aux1000,1000);
    quicksort(aux5000,5000);
    quicksort(aux10000,10000);
    quicksort(aux15000,15000);
    quicksort(aux100000,100000);
/*
    imprimirvetor(aux10,10);
    imprimirvetor(aux50,50);
    imprimirvetor(aux100,100);
    imprimirvetor(aux500,500);
    imprimirvetor(aux1000,1000);
    imprimirvetor(aux5000,5000);
    imprimirvetor(aux10000,10000);
    imprimirvetor(aux15000,15000);
    imprimirvetor(aux100000,100000);

*/
    return 0;
}
