/*
Isabella Rubio Venancio - RA10778364
Matheus Alves de Miranda - RA10746221
Projeto 2 - Algoritmos e Programação II 
Codificando Mapas
*/

#include <stdio.h>

// Definindo as dimensões máximas do mapa
#define MAX_L 1024
#define MAX_C 768

char mapa[MAX_L][MAX_C];

// Declaração das funções
void lerMapa(int i, int j, int linhas, int colunas);
int uniforme(int i, int j, int lf, int cf, char valor);

int main() {
    int linhas, colunas;

    // Solicitando ao usuário o número de linhas e colunas do mapa
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    printf("Digite o mapa (# para parede, . para corredor):\n");

    // Lendo o mapa do usuário
    lerMapa(0, 0, linhas, colunas);

    return 0;
}

// Função para ler o mapa do usuário
void lerMapa(int i, int j, int linhas, int colunas) {
    if(i == linhas) return;

    scanf(" %c", &mapa[i][j]);

    if(j + 1 < colunas)
        lerMapa(i, j + 1, linhas, colunas);
    else
        lerMapa(i + 1, 0, linhas, colunas);
}

// Função para verificar se uma região do mapa é uniforme (toda composta por um mesmo caractere)
// Retorna 1 se for uniforme, 0 caso contrário
int uniforme(int i, int j, int lf, int cf, char valor) {
    if(i > lf) return 1;

    if(mapa[i][j] != valor)
        return 0;

    if(j < cf)
        return uniforme(i, j + 1, lf, cf, valor);

    return uniforme(i + 1, 0, lf, cf, valor);
}