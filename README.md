# Projeto 2 — Codificando Mapas

## Integrantes
- Isabella Rubio Venancio - RA10778364
- Matheus Alves de Miranda - RA10746221

## Disciplina
**Algoritmos e Programação II**  
Universidade Presbiteriana Mackenzie — Campus Alphaville

---

## Descrição

Este projeto implementa um sistema de **codificação recursiva de mapas**.

O mapa é composto por uma matriz onde cada célula pode conter:

- `#` → parede
- `.` → corredor

O programa converte esse mapa em um código compacto utilizando:

- `P` → submapa composto apenas por paredes
- `C` → submapa composto apenas por corredores
- `X` → submapa misto (necessita divisão recursiva)

---

## Funcionamento

O algoritmo verifica se o submapa é uniforme.

### Caso Base

Se todas as células forem iguais:

- imprime `P` se forem paredes
- imprime `C` se forem corredores

A recursão é encerrada.

---

### Caso Recursivo

Se houver mistura de `#` e `.`:

1. imprime `X`
2. divide o mapa em até 4 quadrantes
3. chama recursivamente a função `codificar()`

Ordem dos quadrantes:

- **Q1** → superior esquerdo
- **Q2** → superior direito
- **Q3** → inferior esquerdo
- **Q4** → inferior direito

---

## Estrutura do Código

### `main()`

Responsável por:

- leitura das dimensões do mapa
- chamada da leitura recursiva
- inicialização da codificação
- impressão do código final

---

### `lerMapa()`

Realiza a leitura recursiva do mapa informado pelo usuário.

#### Parâmetros

- `i` → linha atual
- `j` → coluna atual
- `linhas` → quantidade total de linhas
- `colunas` → quantidade total de colunas

---

### `uniforme()`

Verifica se uma região do mapa possui apenas um único tipo de caractere.

A função utiliza a função auxiliar `verificaUniforme()` para percorrer o submapa recursivamente.

#### Retorno

- `1` → região uniforme
- `0` → região não uniforme

---

### `verificaUniforme()`

Função auxiliar recursiva utilizada por `uniforme()`.

Responsável por percorrer célula por célula dentro do submapa analisado.

#### Parâmetros

- `i` → linha atual
- `j` → coluna atual
- `li` → linha inicial
- `ci` → coluna inicial
- `lf` → linha final
- `cf` → coluna final
- `valor` → caractere esperado (`#` ou `.`)

---

### `codificar()`

Função principal responsável pela codificação recursiva do mapa.

#### Responsabilidades

- verificar se o submapa é uniforme
- imprimir `P`, `C` ou `X`
- dividir o mapa em quadrantes
- realizar chamadas recursivas para cada quadrante

#### Parâmetros

- `li` → linha inicial
- `ci` → coluna inicial
- `lf` → linha final
- `cf` → coluna final

---

## Regras de Divisão

Quando o número de linhas ou colunas é ímpar:

- o quadrante esquerdo recebe a coluna extra
- o quadrante superior recebe a linha extra

Casos especiais:

- mapas com apenas 1 linha não possuem quadrantes inferiores
- mapas com apenas 1 coluna não possuem quadrantes direitos

---

## Exemplo de Entrada

```txt
3
5
# # . # #
# . . # #
# # # . .


Saída:
Codigo: XXPCXPCCPPC
