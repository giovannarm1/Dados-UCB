#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área do polígono
float calcularArea(Ponto vertices[], int n) {
    float area = 0.0;
    int j;

    for (int i = 0; i < n; i++) {
        j = (i + 1) % n;
        area += (vertices[i].X * vertices[j].Y - vertices[j].X * vertices[i].Y);
    }

    area = area / 2.0;
    if (area < 0)
        area = -area;

    return area;
}

int main() {
    FILE *entrada, *saida;
    entrada = fopen("vertices.txt", "r"); // Certifique-se de que o arquivo "vertices.txt" existe

    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    int numVertices;
    fscanf(entrada, "%d", &numVertices);

    Ponto *vertices = malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++) {
        fscanf(entrada, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(entrada);

    float area = calcularArea(vertices, numVertices);

    printf("A area do poligono e %.2f\n", area);

    saida = fopen("saida.txt", "w"); // Cria um arquivo de saída chamado "saida.txt"

    if (saida == NULL) {
        perror("Erro ao criar o arquivo de saida");
        return 1;
    }

    fprintf(saida, "A area do poligono e %.2f\n", area);
    fclose(saida);

    free(vertices);

    return 0;
}
