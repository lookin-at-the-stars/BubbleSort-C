#include <stdio.h>
int main() {
    int vetor[16] = {10, 9, 8, 7, 6, 5, 5, 22, 45, 67, 80, 3, 4, 3, 2, 1};
    int n = 16;
    int x = 1; 
    int y;
    while(x != 0){
        for (int j = 0; j < n-1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
                y = 1;
            } 
        }
        if(y == 1){
            y = 0;
        } else{ x = 0;}
    } 
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
