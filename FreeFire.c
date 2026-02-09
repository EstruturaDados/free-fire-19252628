#include <stdio.h>
#include <string.h>

// Definindo como é um item da nossa mochila
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {
    struct Item mochila[10]; // Vetor fixo para 10 itens
    int totalItens = 0;      // Contador para saber quantos itens já temos
    int opcao;

    do {
        // Menu interativo
        printf("\n--- MOCHILA DE SOBREVIVENCIA (FREE FIRE) ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Listar Itens\n");
        printf("3. Remover Ultimo Item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalItens < 10) {
                    printf("\nNome do item: ");
                    scanf(" %[^\n]s", mochila[totalItens].nome);
                    printf("Tipo (Arma/Municao/Cura): ");
                    scanf("%s", mochila[totalItens].tipo);
                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    
                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                } else {
                    printf("\nMochila cheia! Nao cabe mais nada.\n");
                }
                break;

            case 2:
                if (totalItens == 0) {
                    printf("\nA mochila esta vazia.\n");
                } else {
                    printf("\n--- ITENS NA MOCHILA ---\n");
                    printf("%-15s | %-10s | %-5s\n", "NOME", "TIPO", "QTD");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-15s | %-10s | %-5d\n", 
                               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;

            case 3:
                if (totalItens > 0) {
                    totalItens--; // Apenas diminuímos o contador para "esconder" o item
                    printf("\nUltimo item removido da mochila.\n");
                } else {
                    printf("\nNada para remover.\n");
                }
                break;

            case 0:
                printf("\nSaindo... Boa sorte na ilha!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
