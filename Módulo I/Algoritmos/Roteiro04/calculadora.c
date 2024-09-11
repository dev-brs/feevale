#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define TAM_MAX 127
#define NUMEROS_PERMITIDOS_DIVISAO 2

double sub(double *nums, int size) {
  double result = nums[0];

  for(int i = 0; i < size; i++) {
    result -= nums[i];
  }

  printf("\nO resultado é: %.2lf", result);
  return result;
}

double sum(double *nums, int size) {
  double sum = nums[0];
  for(int i = 1; i < size; i++) {
    sum += nums[i];
  }

  printf("\nO resultado é: %.2lf", sum);
  return sum;
}

double prod(double *nums, int size) {
  double prod = nums[0];
  for(int i = 1; i < size; i++) {
    prod *= nums[i];
  }

  printf("\nO resultado é: %.2lf", prod);
  return prod;
}

double divide(double *nums, int size) {
  double dividendo = nums[0];
  double divisor = nums[1];
  double result;

  if(size != NUMEROS_PERMITIDOS_DIVISAO) {
    printf("Você só pode inserir dois números para a divisão");
    return 0;
  }

  if(!divisor) {
    printf("O divisor deve ser diferentes de zero");
    return 0;
  }

  result = dividendo/divisor;

  printf("\nO resultado é: %.2lf", result);
  return result;
}

void menu() {
  system("clear");

  printf("-=+ Calculadora +=-");
  printf("\n\nOBS:\n-Se for subtração o primeiro número será o todo, e o resto irá subtrair desse todo");
  printf("\n-Se for divisão, ela só aceita DOIS números, com o primeiro sendo o dividendo e o segundo o divisor");

  printf("\n\n-MENU DE OPÇÕES-");
  printf("\n[-] - Subtração");
  printf("\n[+] - Soma");
  printf("\n[*] - Produto");
  printf("\n[-] - Divisão");

  printf("\n\nInsira qual operação você deseja: ");
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  int qntNums;
  char operacao;
  double num, nums[TAM_MAX];

  printf("\nQuantos números você deseja manipular: ");
  scanf("%d", &qntNums);

  for(int i = 0; i < qntNums; i++) {
    printf("\nInsira o numero[%d]: ", i);
    scanf("%lf", &num);
    nums[i] = num;
  }

  while(true) {
    menu();
    scanf("%c", &operacao);

    switch(operacao) {
      case '-':
        sub(&nums[0], qntNums);
        return 0;

      case '+':
        sum(&nums[0], qntNums);
        return 0;
      
      case '*':
        prod(&nums[0], qntNums);
        return 0;
      
      case '/':
        divide(&nums[0], qntNums);
        return 0;
    }
  }
}