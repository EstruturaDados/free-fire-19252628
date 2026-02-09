#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURAS
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Estrutura para a Lista Encadeada (O "No")
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// 2. FUNÇÕES DO VETOR
void ordenarVetor(Item vetor[], int n, int* comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(vetor[j].nome, vetor[j + 1].nome) > 0) {
                Item temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int buscaBinariaVetor(Item vetor[], int n, char* alvo, int* comparacoes) {
    int inicio = 0, fim = n - 1;
    *comparacoes = 0;
    while (inicio <= fim) {
        (*comparacoes)++;
        int meio = (inicio + fim) / 2;
        int res = strcmp(vetor[meio].nome, alvo);
        if (res == 0) return meio;
        if (res < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// 3. FUNÇÕES DA LISTA ENCADEADA
No* inserirLista(No* inicio, Item novoItem) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dados = novoItem;
    novoNo->proximo = inicio;
    return novoNo;
}

void listarLista(No* inicio) {
    No* atual = inicio;
    while (atual != NULL) {
        printf("- %s [%s] (x%d)\n", atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->proximo;
    }
}

// 4. MAIN (MENU INTERATIVO)
int main() {
    Item mochilaVetor[10];
    int totalVetor = 0;
    No* mochilaLista = NULL;
    int opcao, comp;

    do {
        printf("\n--- MATECHECK: DESAFIO DA ILHA ---\n");
        printf("1. Inserir Item (Vetor e Lista)\n");
        printf("2. Listar Itens (Vetor)\n");
        printf("3. Listar Itens (Lista Encadeada)\n");
        printf("4. Ordenar Vetor e Buscar Binaria\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Item novo;
            printf("Nome do item: "); scanf(" %[^\n]s", novo.nome);
            printf("Tipo: "); scanf("%s", novo.tipo);
            printf("Quantidade: "); scanf("%d", &novo.quantidade);

            // Insere no Vetor
            if (totalVetor < 10) {
                mochilaVetor[totalVetor++] = novo;
            }
            // Insere na Lista
            mochilaLista = inserirLista(mochilaLista, novo);
            printf("Item guardado nas duas estruturas!\n");

        } else if (opcao == 2) {
            printf("\n--- VETOR (ESTATICO) ---\n");
            for(int i=0; i<totalVetor; i++) printf("- %s\n", mochilaVetor[i].nome);

        } else if (opcao == 3) {
            printf("\n--- LISTA ENCADEADA (DINAMICA) ---\n");
            listarLista(mochilaLista);

        } else if (opcao == 4) {
            char alvo[30];
            ordenarVetor(mochilaVetor, totalVetor, &comp);
            printf("\nVetor ordenado! Comparacoes feitas: %d\n", comp);
            printf("Buscar qual item por Busca Binaria? ");
            scanf(" %[^\n]s", alvo);
            int pos = buscaBinariaVetor(mochilaVetor, totalVetor, alvo, &comp);
            if (pos != -1) printf("Achado na posicao %d! Comparacoes na busca: %d\n", pos, comp);
            else printf("Item nao encontrado.\n");
        }

    } while (opcao != 0);

    return 0;
}



