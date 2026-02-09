#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para ordenar o Vetor (Bubble Sort)
void ordenarVetor(Item vetor[], int n, int* comp) {
    *comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (strcmp(vetor[j].nome, vetor[j + 1].nome) > 0) {
                Item temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função de Busca Binária
int buscaBinaria(Item vetor[], int n, char* alvo, int* comp) {
    int inicio = 0, fim = n - 1;
    *comp = 0;
    while (inicio <= fim) {
        (*comp)++;
        int meio = (inicio + fim) / 2;
        int res = strcmp(vetor[meio].nome, alvo);
        if (res == 0) return meio;
        if (res < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main() {
    Item mochilaVetor[10];
    int totalVetor = 0, opcao, comparacoes;

    printf("--- MATECHECK: MODO VETOR ---\n");
    // Aqui voce cadastraria e testaria a busca...
    // (Apenas para o primeiro commit)
    printf("Sistema de Vetor pronto para receber itens.\n");

    return 0;
}


