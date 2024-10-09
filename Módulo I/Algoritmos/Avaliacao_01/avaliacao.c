#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define NUMERO_DE_OVOS_DE_PASCOA 4
#define VALOR_MINIMO 0

float mediaDosPrecos(float precoOvosDePascoa[]) {
  float soma = 0;
  for(int i = 0; i < NUMERO_DE_OVOS_DE_PASCOA; i++) {
    soma += precoOvosDePascoa[i];
  }

  return soma / NUMERO_DE_OVOS_DE_PASCOA;
}

int min(float precoOvosDePascoa[]) {
  int indexDoOvoMaisBarato = 0;

  for(int i = 1; i < NUMERO_DE_OVOS_DE_PASCOA; i++) {
    if(precoOvosDePascoa[i] < precoOvosDePascoa[indexDoOvoMaisBarato]) {
      indexDoOvoMaisBarato = i;
    }
  }

  return indexDoOvoMaisBarato;
}

int main() {  
  setlocale(LC_ALL, "Portuguese");

  float precoOvosDePascoa[NUMERO_DE_OVOS_DE_PASCOA];
  int index = 0;

  printf("Exemplo de entrada: R$ 3,2");

  while(index < NUMERO_DE_OVOS_DE_PASCOA) {
  printf("\nInsira o valor do %d� ovo de p�scoa: R$ ", index + 1);
  scanf("%f", &precoOvosDePascoa[index]);
    if(precoOvosDePascoa[index] <= VALOR_MINIMO) {
      printf("\nValor inv�lido! O valor do ovo de p�scoa deve ser maior que zero.");
      continue;
    } else {
      index++;
    }
  }

  printf("\nA m�dia dos pre�os dos ovos de p�scoa �: R$%.2f", mediaDosPrecos(precoOvosDePascoa));
  printf("\nO ovo de p�scoa mais barato � o %d�, e ele custa: R$%.2f", min(precoOvosDePascoa) + 1, precoOvosDePascoa[min(precoOvosDePascoa)]);

  return 0;
}
