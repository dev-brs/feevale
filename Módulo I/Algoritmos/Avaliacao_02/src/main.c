#include <locale.h>
#include <stdio.h>

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

const char *produtos[QUANTIDADE_DE_PRODUTOS] = {"CERVEJA", "WHISKY",     "VINHO",      "REFRIGERANTE", "AGUA",
                                                "DRINKS",  "APERITIVOS", "HAMBURGUER", "PIZZA",        "PASTEL"};

const float precosEmReais[QUANTIDADE_DE_PRODUTOS] = {
    CERVEJA / 100.0, WHISKY / 100.0,     VINHO / 100.0,      REFRIGERANTE / 100.0, AGUA / 100.0,
    DRINKS / 100.0,  APERITIVOS / 100.0, HAMBURGUER / 100.0, PIZZA / 100.0,        PASTEL / 100.0};

void printBoasVindas();
void printCardapio();
void printMenuDeCompra();

int main() {
    setlocale(LC_ALL, "Portuguese");

    printBoasVindas();

    return 0;
}

void printBoasVindas() {
    printf(
        "Seja muito bem vindo ao nosso querido boteco, os preços estão logo "
        "abaixo para você dar uma conferida!\n\n");
    printCardapio();

    return;
}

void printCardapio() {
    printf("=============CARDÁPIO==============\n");
    printf("| %-2s | %-15s | %-9s |\n", "ID", "Nome", "Preço");
    printf("-----------------------------------\n");

    for (int i = 0; i < QUANTIDADE_DE_PRODUTOS; i++) {
        printf("| %-2d | %-15s | R$ %-5.2f |\n", i, produtos[i], precosEmReais[i]);
    }

    printf("===================================\n");

    return;
}

void printMenuDeCompra() { return; }
