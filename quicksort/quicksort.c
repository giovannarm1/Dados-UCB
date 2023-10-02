#include <stdio.h>
#include <string.h>

void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(char *arr[], int baixo, int alto, int *trocas, int *comparacoes) {
    char *pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j <= alto - 1; j++) {
        (*comparacoes)++;
        if (strcmp(arr[j], pivo) < 0) {
            i++;
            (*trocas)++;
            trocar(&arr[i], &arr[j]);
        }
    }
    (*trocas)++;
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(char *arr[], int baixo, int alto, int *trocas, int *comparacoes) {
    if (baixo < alto) {
        int pivo = particionar(arr, baixo, alto, trocas, comparacoes);
        quicksort(arr, baixo, pivo - 1, trocas, comparacoes);
        quicksort(arr, pivo + 1, alto, trocas, comparacoes);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };
    int trocas = 0;
    int comparacoes = 0;
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, tamanho - 1, &trocas, &comparacoes);

    printf("Numero de trocas: %d\n", trocas);
    printf("Numero de comparacoes: %d\n", comparacoes);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", arr[i]);
    }

    // Calculando a mediana
    char *mediana = arr[tamanho / 2];
    printf("Mediana: %s\n", mediana);

    return 0;
}
