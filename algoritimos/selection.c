#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;
    printf("Quantidade de numeros: "); 
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Quantidade invalida.\n");
    return 0;
    }
    int *qnt = (int *)malloc(num * sizeof(int)); 
    if (qnt == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &qnt[i]) != 1) {
            free(qnt); 
        return 0;
        }
    }
    for (int i = 0; i < num - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < num; j++) {
            if (qnt[j] < qnt[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = qnt[i];
            qnt[i] = qnt[min_idx];
            qnt[min_idx] = temp;
        }
    }
    for (int i = 0; i < num; i++) {
        printf("%d", qnt[i]);
        if (i < num - 1) {
            printf(" ");
        }
    }
    printf("\n");
    free(qnt); 

    return 0;
}