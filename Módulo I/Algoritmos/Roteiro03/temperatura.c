#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define TEMPERATURA_LIMITE_INFERIOR 10
#define TEMPERATURA_LIMITE_SUPERIOR 30

int main() {  
  setlocale(LC_ALL, "Portuguese");

  double temp;

  printf("-=+ Roteiro 03 +=-\n\n");
  printf("Insira uma temperatura (Celsius): ");
  scanf("%lf", &temp);

  if(temp > TEMPERATURA_LIMITE_SUPERIOR ) {
    printf("\nMuito quente");
    return 0;
  }

  if(temp < TEMPERATURA_LIMITE_INFERIOR) {
    printf("\nMuito frio");
    return 0;
  }

  printf("\nTudo bem");
  
  return 0;
}