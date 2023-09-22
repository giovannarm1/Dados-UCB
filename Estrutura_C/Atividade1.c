#include <stdio.h>


int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    fprintf(saida, "Nome,Nota Média,Situação\n"); 

    char nome[50];
    float nota1, nota2;
    while (fscanf(entrada, "%49[^,],%f,%f\n", nome, &nota1, &nota2) != EOF) {
        float media = (nota1 + nota2) / 2.0;
        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        fprintf(saida, "%s,%.2f,%s\n", nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento concluído. Os resultados foram salvos em SituacaoFinal.csv.\n");

    return 0;
}