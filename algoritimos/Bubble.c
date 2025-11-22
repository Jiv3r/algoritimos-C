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
        printf("Quantidade invalida.\n");
        return 0;
    }
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &qnt[i]) != 1) {
            free(qnt); 
            return 0;
        }
    }
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - 1 - i; j++) {
            if (qnt[j] > qnt[j + 1]) {
                int a = qnt[j];
                qnt[j] = qnt[j + 1];
                qnt[j + 1] = a;
            }
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