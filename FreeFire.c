#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do Componente da Torre de Fuga
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// 1. BUBBLE SORT: Ordenar por NOME (String)
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

// 2. INSERTION SORT: Ordenar por TIPO (String)
void insertionSortTipo(Componente lista[], int n, int *comp) {
    *comp = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = lista[i];
        int j = i - 1;
        while (j >= 0 && strcmp(lista[j].tipo, chave.tipo) > 0) {
            (*comp)++;
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = chave;
    }
}

// 3. SELECTION SORT: Ordenar por PRIORIDADE (Inteiro)
void selectionSortPrioridade(Componente lista[], int n, int *comp) {
    *comp = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (lista[j].prioridade < lista[min_idx].prioridade)
                min_idx = j;
        }
        Componente temp = lista[min_idx];
        lista[min_idx] = lista[i];
        lista[i] = temp;
    }
}

// 4. BUSCA BINÁRIA: Só funciona após ordenar por NOME
int buscaBinariaPorNome(Componente lista[], int n, char alvo[], int *comp) {
    int esq = 0, dir = n - 1;
    *comp = 0;
    while (esq <= dir) {
        (*comp)++;
        int meio = esq + (dir - esq) / 2;
        int res = strcmp(lista[meio].nome, alvo);
        if (res == 0) return meio;
        if (res < 0) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

void exibirTorre(Componente lista[], int n) {
    printf("\n--- COMPONENTES DA TORRE ---\n");
    printf("%-20s | %-15s | %s\n", "NOME", "TIPO", "PRIORIDADE");
    for (int i = 0; i < n; i++) {
        printf("%-20s | %-15s | %d\n", lista[i].nome, lista[i].tipo, lista[i].prioridade);
    }
}

int main() {
    Componente torre[20];
    int total = 0, opcao, comp;
    clock_t t_inicio, t_fim;
    double tempo;

    do {
        printf("\n--- DESAFIO CODIGO DA ILHA: MESTRE ---\n");
        printf("1. Adicionar Componente (Max 20)\n");
        printf("2. Ordenar por Nome (Bubble Sort)\n");
        printf("3. Ordenar por Tipo (Insertion Sort)\n");
        printf("4. Ordenar por Prioridade (Selection Sort)\n");
        printf("5. Buscar Componente-Chave (Busca Binaria)\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (total < 20) {
                    printf("Nome: "); scanf(" %[^\n]s", torre[total].nome);
                    printf("Tipo: "); scanf(" %[^\n]s", torre[total].tipo);
                    printf("Prioridade (1-10): "); scanf("%d", &torre[total].prioridade);
                    total++;
                } else printf("Torre completa!\n");
                break;

            case 2:
                t_inicio = clock();
                bubbleSortNome(torre, total, &comp);
                t_fim = clock();
                tempo = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;
                exibirTorre(torre, total);
                printf("\nTempo: %f s | Comparacoes: %d\n", tempo, comp);
                break;

            case 3:
                t_inicio = clock();
                insertionSortTipo(torre, total, &comp);
                t_fim = clock();
                tempo = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;
                exibirTorre(torre, total);
                printf("\nTempo: %f s | Comparacoes: %d\n", tempo, comp);
                break;

            case 4:
                t_inicio = clock();
                selectionSortPrioridade(torre, total, &comp);
                t_fim = clock();
                tempo = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;
                exibirTorre(torre, total);
                printf("\nTempo: %f s | Comparacoes: %d\n", tempo, comp);
                break;

            case 5: {
                char busca[30];
                printf("Nome do item chave: "); scanf(" %[^\n]s", busca);
                // IMPORTANTE: A busca binaria exige que esteja ordenado por nome primeiro
                bubbleSortNome(torre, total, &comp); 
                int pos = buscaBinariaPorNome(torre, total, busca, &comp);
                if (pos != -1) printf("\nItem encontrado na posicao %d! Comparacoes: %d\n", pos, comp);
                else printf("\nItem nao encontrado.\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}






