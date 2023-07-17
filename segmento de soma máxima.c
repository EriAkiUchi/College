#include <stdio.h>
#include <limits.h>
//exercício de encontrar o subarray de maior soma dentro de um array
int max(int x, int y)
{
  return(x > y) ? x : y;
}
int max_sum_subarray(int array[],int esq,int dir)
{
  if(dir <= esq)
    return array[esq];
  
  int meio = (esq+dir)/2;

  int left_max = INT_MIN,right_max = INT_MIN,soma = 0;
  for(int i = meio;i >= esq;i--)
  {  
    soma += array[i];
    if(soma > left_max)
      left_max = soma;
  }
  soma = 0;
  for(int j = meio+1;j <= dir;j++)
  {
    soma += array[j];
    if(soma > right_max)
      right_max = soma;
  }
  int max_left_right = max(max_sum_subarray(array, esq, meio),max_sum_subarray(array,meio+1,dir));
  return max(max_left_right,left_max+right_max);
}

int main(void) {
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d",&n);
  int array[n];
  for(int i = 0;i < n;i++)
  {
    printf("Digite um numero inteiro para inserir no vetor: ");
    scanf("%d",&array[i]);
  }
  printf("\n");
  printf("A Maior soma do subarray é de: %d",max_sum_subarray(array, 0, n-1));


        
  return 0;
}
