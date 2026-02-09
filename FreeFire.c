#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para medir o tempo com clock()

// 1. ESTRUTURA DO COMPONENTE
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// 2. BUBBLE SORT (Ordenar por Nome)
void bubbleSortNome(Componente lista[], int n, int *comp) {
    *comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                Componente temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {
    Componente torre[20];
    int total = 0, comparacoes;
    clock_t inicio, fim;
    double tempo_cpu;

    printf("--- TORRE DE RESGATE: NIVEL MESTRE ---\n");
    printf("Sistema iniciado. Aguardando componentes...\n");

    return 0;
}





