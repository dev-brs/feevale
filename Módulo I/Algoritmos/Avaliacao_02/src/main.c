#include <locale.h>
#include <stdio.h>
#include <string.h>

#define QUANTIDADE_DE_PRODUTOS 10

typedef enum {
    CERVEJA = 1200,      // R$ 12.00
    WHISKY = 3500,       // R$ 35.00
    VINHO = 2000,        // R$ 20.00
    REFRIGERANTE = 800,  // R$ 8.00
    AGUA = 500,          // R$ 5.00
    DRINKS = 2600,       // R$ 26.00
    APERITIVOS = 1200,   // R$ 12.00
    HAMBURGUER = 2500,   // R$ 25.00
    PIZZA = 4500,        // R$ 45.00
    PASTEL = 1200        // R$ 12.00
} Precos;

const char *produtos[QUANTIDADE_DE_PRODUTOS] = {
    "CERVEJA", "WHISKY", "VINHO", "REFRIGERANTE", "AGUA",
    "DRINKS", "APERITIVOS", "HAMBURGUER", "PIZZA", "PASTEL"};

const float precosEmReais[QUANTIDADE_DE_PRODUTOS] = {
    CERVEJA / 100.0, WHISKY / 100.0, VINHO / 100.0, REFRIGERANTE / 100.0, AGUA / 100.0,
    DRINKS / 100.0, APERITIVOS / 100.0, HAMBURGUER / 100.0, PIZZA / 100.0, PASTEL / 100.0};

void printBoasVindas();
void printCardapio();
void realizarCompra();
void imprimirNotaFiscal(char *nomeCliente, char *endereco, int *itens, int *quantidades, int totalItens);

int main() {
    setlocale(LC_ALL, "Portuguese");

    printBoasVindas();
    realizarCompra();

    return 0;
}

void printBoasVindas() {
    printf("Seja muito bem-vindo ao nosso querido boteco!\n");
    printf("Confira abaixo o nosso cardápio:\n\n");
    printCardapio();
}

void printCardapio() {
    printf("============= CARDÁPIO ==============\n");
    printf("| %-2s | %-15s | %-9s |\n", "ID", "Nome", "Preço");
    printf("-------------------------------------\n");

    for (int i = 0; i < QUANTIDADE_DE_PRODUTOS; i++) {
        printf("| %-2d | %-15s | R$ %-6.2f |\n", i + 1, produtos[i], precosEmReais[i]);
    }

    printf("=====================================\n\n");
}

void realizarCompra() {
    char nomeCliente[50];
    char endereco[100];
    int itens[QUANTIDADE_DE_PRODUTOS] = {0};
    int quantidades[QUANTIDADE_DE_PRODUTOS] = {0};
    int codigoProduto, quantidade, totalItens = 0;
    char escolha;

    printf("Digite o seu nome: ");
    fgets(nomeCliente, 50, stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

    printf("Digite o seu endereço: ");
    fgets(endereco, 100, stdin);
    endereco[strcspn(endereco, "\n")] = '\0';
 
    do {
        printCardapio();
        printf("Digite o código do produto para comprar (1 a 10) ou 'F' para finalizar a compra: ");
        scanf(" %c", &escolha);

        if (escolha >= '1' && escolha <= '9') {
            codigoProduto = escolha - '1';
            printf("Digite a quantidade desejada de %s: ", produtos[codigoProduto]);
            scanf("%d", &quantidade);

            itens[totalItens] = codigoProduto;
            quantidades[totalItens] = quantidade;
            totalItens++;

            printf("Adicionado %d unidade(s) de %s ao carrinho.\n\n", quantidade, produtos[codigoProduto]);
        } else if (escolha == 'F' || escolha == 'f') {
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n\n");
        }
    } while (1);

    imprimirNotaFiscal(nomeCliente, endereco, itens, quantidades, totalItens);
}

void imprimirNotaFiscal(char *nomeCliente, char *endereco, int *itens, int *quantidades, int totalItens) {
    float totalGeral = 0;

    printf("\n============= NOTA FISCAL ==============\n");
    printf("Cliente: %s\n", nomeCliente);
    printf("Endereço: %s\n", endereco);
    printf("----------------------------------------\n");
    printf("| %-15s | %-5s | %-9s |\n", "Produto", "Qtd", "Total");
    printf("----------------------------------------\n");

    for (int i = 0; i < totalItens; i++) {
        int produtoIndex = itens[i];
        float totalProduto = precosEmReais[produtoIndex] * quantidades[i];
        totalGeral += totalProduto;

        printf("| %-15s | %-5d | R$ %-6.2f |\n", produtos[produtoIndex], quantidades[i], totalProduto);
    }

    printf("----------------------------------------\n");
    printf("Total Geral: R$ %.2f\n", totalGeral);
    printf("========================================\n");
}

