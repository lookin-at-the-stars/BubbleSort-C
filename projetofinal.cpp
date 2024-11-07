#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void separaPivo(int array[], int maxTamanho, int tamanho, int pivo,
                int *vetorParte1, int *tamParte1,
                int *vetorParte2, int *tamParte2, int *iguais, int *tamIguais) {
    *tamParte1 = 0;
    *tamParte2 = 0;
    *tamIguais = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] < pivo) {
            vetorParte1[(*tamParte1)++] = array[i];
        } else if (array[i] > pivo) {
            vetorParte2[(*tamParte2)++] = array[i];
        } else {
            iguais[(*tamIguais)++] = array[i];
        }
    }
}

void juntaListas(int array[], int *vetorParte1, int *vetorParte2,
                 int tamParte1, int tamParte2, int *iguais, int tamIguais) {
    int index = 0;
    
    for (int i = 0; i < tamParte1; i++) {
        array[index++] = vetorParte1[i];
    }
    
    for (int i = 0; i < tamIguais; i++) {
        array[index++] = iguais[i];
    }
    
    for (int i = 0; i < tamParte2; i++) {
        array[index++] = vetorParte2[i];
    }
}

void quicksortIterativo(int array[], int maxTamanho, int tamanho) {
    if (tamanho <= 1) return;

    int *vetorParte1 = (int *)malloc(tamanho * sizeof(int));
    int *vetorParte2 = (int *)malloc(tamanho * sizeof(int));
    int *iguais = (int *)malloc(tamanho * sizeof(int));
    int pivo = array[tamanho / 2];
    int tamParte1, tamParte2, tamIguais;
    
    separaPivo(array, maxTamanho, tamanho, pivo,
               vetorParte1, &tamParte1,
               vetorParte2, &tamParte2,
               iguais, &tamIguais);
    
    if (tamParte1 > 1) {
        quicksortIterativo(vetorParte1, maxTamanho, tamParte1);
    }
    if (tamParte2 > 1) {
        quicksortIterativo(vetorParte2, maxTamanho, tamParte2);
    }
    
    juntaListas(array, vetorParte1, vetorParte2, tamParte1, tamParte2, iguais, tamIguais);
    
    free(vetorParte1);
    free(vetorParte2);
    free(iguais);
}

void bubbleSort(int vetor[], int n) {
    int x = 1, y = 0;
    while(x != 0) {
        for (int j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
                y = 1;
            }
        }
        if (y == 1) {
            y = 0;
        } else {
            x = 0;
        }
    }
}

void imprimeArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    struct timeval tvalBS_Inicio, tvalBS_Fim, tvalQS_Inicio, tvalQS_Fim;

    // Vetor original com 10000 elementos aleatórios
    int Vo[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        Vo[i] = rand() % 10000;
    }

    // Cria cópias de Vo para ordenar com BubbleSort e QuickSort
    int Vb[10000], Vq[10000];
    for (int i = 0; i < 10000; i++) {
        Vb[i] = Vo[i];
        Vq[i] = Vo[i];
    }

    // Bubble Sort com contagem de tempo
    printf("Bubble Sort\n\n");
    printf("- Início\n");
    gettimeofday(&tvalBS_Inicio, NULL);
    printf("- Ordenando\n");
    bubbleSort(Vb, 10000);
    printf("- Fim\n");
    gettimeofday(&tvalBS_Fim, NULL);

    // Quick Sort com contagem de tempo
    printf("Quick Sort\n\n");
    printf("- Início\n");
    gettimeofday(&tvalQS_Inicio, NULL);
    printf("- Ordenando\n");
    quicksortIterativo(Vq, 10000, 10000);
    printf("- Fim\n");
    gettimeofday(&tvalQS_Fim, NULL);

    // Exibe o tempo total para cada ordenação
    printf("\nTempo Total\n");
    printf("Bubble Sort = %.3f segundos\n",
           (double)(tvalBS_Fim.tv_usec - tvalBS_Inicio.tv_usec) / 1000000 +
           (double)(tvalBS_Fim.tv_sec - tvalBS_Inicio.tv_sec));
    printf("Quick Sort = %.3f segundos\n",
           (double)(tvalQS_Fim.tv_usec - tvalQS_Inicio.tv_usec) / 1000000 +
           (double)(tvalQS_Fim.tv_sec - tvalQS_Inicio.tv_sec));

    return 0;
}
