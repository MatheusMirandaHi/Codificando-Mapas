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
int uniforme(int li, int ci, int lf, int cf, char valor);
void codificar(int li, int ci, int lf, int cf);

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

    printf("Codigo: ");
    codificar(0, 0, linhas - 1, colunas - 1);

    printf("\n");

    return 0;
}

// Função para ler o mapa do usuário
void lerMapa(int i, int j, int linhas, int colunas) {
    if(i == linhas)
        return;

    scanf(" %c", &mapa[i][j]);

    if(j + 1 < colunas)
        lerMapa(i, j + 1, linhas, colunas);
    else
        lerMapa(i + 1, 0, linhas, colunas);
}

// Função auxiliar recursiva para verificar uniformidade
int verificaUniforme(int i, int j, int li, int ci, int lf, int cf, char valor) {

    if(i > lf)
        return 1;

    if(mapa[i][j] != valor)
        return 0;

    if(j < cf)
        return verificaUniforme(i, j + 1, li, ci, lf, cf, valor);

    return verificaUniforme(i + 1, ci, li, ci, lf, cf, valor);
}

// Verifica se toda a região possui o mesmo caractere
int uniforme(int li, int ci, int lf, int cf, char valor) {
    return verificaUniforme(li, ci, li, ci, lf, cf, valor);
}

// Função principal de codificação
void codificar(int li, int ci, int lf, int cf) {

    // Caso base: tudo parede
    if(uniforme(li, ci, lf, cf, '#')) {
        printf("P");
        return;
    }

    // Caso base: tudo corredor
    if(uniforme(li, ci, lf, cf, '.')) {
        printf("C");
        return;
    }

    // Caso recursivo
    printf("X");

    int meioLinha = (li + lf) / 2;
    int meioColuna = (ci + cf) / 2;

    // Q1 - superior esquerdo
    codificar(li, ci, meioLinha, meioColuna);

    // Q2 - superior direito
    if(meioColuna + 1 <= cf)
        codificar(li, meioColuna + 1, meioLinha, cf);

    // Q3 - inferior esquerdo
    if(meioLinha + 1 <= lf)
        codificar(meioLinha + 1, ci, lf, meioColuna);

    // Q4 - inferior direito
    if(meioLinha + 1 <= lf && meioColuna + 1 <= cf)
        codificar(meioLinha + 1, meioColuna + 1, lf, cf);
}
