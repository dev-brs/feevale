#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num;

  printf("-=+ Roteiro 01 +=-\n");
  printf("\nInsira um numero:");
  scanf("%d", &num);
  
  printf("\nO quadrado de %d eh: %d", num, num * num);
  
  return 0;
}