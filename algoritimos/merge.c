#include <stdio.h>
#include <stdlib.h> 

void merge(int vetor[], int aux[], int esq, int meio, int dir) {
    int i = esq, j = meio + 1, indiceAtual = esq;
    while (i <= meio && j <= dir) {
        if (vetor[i] <= vetor[j]) 
            aux[indiceAtual++] = vetor[i++];
        else 
            aux[indiceAtual++] = vetor[j++];
    } 
    while (i <= meio) 
        aux[indiceAtual++] = vetor[i++];
    while (j <= dir) 
        aux[indiceAtual++] = vetor[j++];
    for (int t = esq; t <= dir; t++) 
        vetor[t] = aux[t];
}

void mergeSort(int vetor[], int aux[], int esq, int dir) {
    if (esq >= dir) return;
    int meio = (esq + dir) / 2;
    mergeSort(vetor, aux, esq, meio);
    mergeSort(vetor, aux, meio + 1, dir);
    merge(vetor, aux, esq, meio, dir);
}

int main(void) {
    int num;
    printf("Quantidade de numeros: "); 
    if (scanf("%d", &num) != 1 || num <= 0) 
    return 0;
    int *qnt = (int *)malloc(num * sizeof(int));
    int *aux = (int *)malloc(num * sizeof(int));
    if (qnt == NULL || aux == NULL) {
    free(qnt);
    free(aux);
    return 0; 
    }
    
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &qnt[i]) != 1) {
        free(qnt);
        free(aux);
        return 0;
        }
    }

    mergeSort(qnt, aux, 0, num - 1);
    for (int i = 0; i < num; i++) {
        printf("%d", qnt[i]);
        if (i < num - 1) {
            printf(" ");
        }
    }
 printf("\n");
 free(qnt);
free(aux);
return 0;
}