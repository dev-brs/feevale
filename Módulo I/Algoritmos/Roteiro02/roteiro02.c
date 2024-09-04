#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num;

  printf("-=+ Roteiro 02 +=-\n");
  printf("\nInsira um numero:");
  scanf("%d", &num);
  
  printf("\nO antecessor de %d eh: %d",num, num - 1);
  printf("\nO sucessor de %d eh: %d", num, num +1 );
  
  return 0;
}