#include <stdio.h>


// Função para remover as tags HTML de uma string
void remove_html_tags(char *html) {
   char *dest = html;
    int inside_tag = 0;

    for (int i = 0; html[i]; i++) {
        if (html[i] == '<') {
            inside_tag = 1;
        } else if (html[i] == '>') {
            inside_tag = 0;
        } else if (!inside_tag) {
            *dest++ = html[i];
        }
    }

    *dest = '\0';
}

int main() {
  
    FILE *entrada = fopen("..\\main.txt", "r");

    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo ");
        return 1;
    }
    char texto[10000]; 
    size_t tamanho = fread(texto, 1, sizeof(texto), entrada);
    texto[tamanho] = '\0';

    fclose(entrada);
    remove_html_tags(texto);
    FILE *saida = fopen("arquivo_saida.txt", "w");

    if (saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }
   
    fputs(texto, saida);

    fclose(saida);

    printf("Texto foi salvo em arquivo_saida.txt.\n");

    return 0;
}