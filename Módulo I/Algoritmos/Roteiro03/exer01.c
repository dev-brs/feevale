#include <stdio.h>
#include <locale.h>

#define TAM_MAX 127

int max(int *nums, int size) {
  int max = nums[0];
  for(int i = 1; i < size; i++) {
    if(nums[i] > max)
      max = nums[i];
  } 

  return max;
}

int min(int *nums, int size) {
  int min = nums[0];
  for(int i = 1; i < size; i++) {
    if(nums[i] < min)
      min = nums[i];
  } 

  return min;
}

int main() {
  int nums[TAM_MAX], qntNums, num;
  
  printf("Quantos números você deseja inserir? ");
  scanf("%d", &qntNums);

  for(int i = 0;i < qntNums; i++) {
    printf("\nInsira o [%d]: ", i);
    scanf("%d", &num);
    nums[i] = num;
  }

  printf("\nO numeros máximo entre os digitados é: %d", max(&nums[0],qntNums));
  printf("\nO numero mínimo entre os digitados é: %d", min(&nums[0],qntNums));
 
  return 0;
}