#include <stdio.h>

int main(void) {
    const int max = 10;
    int num;
    printf("Quantidade de numeros (max %d): ", max);
    if (scanf("%d", &num) != 1 || num <= 0 || num > max) 
    return 0;

    int qnt[max];
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &qnt[i]) != 1) 
        return 0;
    }

    for (int i = 1; i < num; i++) {
        int key = qnt[i];
        int j = i - 1;
        while (j >= 0 && qnt[j] > key) {
            qnt[j + 1] = qnt[j];
            j--;
        }
        qnt[j + 1] = key;
    }

    for (int i = 0; i < num; i++) {
    printf("%d", qnt[i]);
    if (i < num - 1) {
        printf(" ");
    }
}
printf("\n");

return 0;
}