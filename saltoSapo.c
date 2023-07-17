//Eric Akio Uchiyamada   42107865
//exercício de determinar a menor quantidade de posições até chegar em seu destino
#include <stdio.h>
#include <stdlib.h>

int *saltoSapo(int  p[],int n,int delta){
  int *u = malloc(sizeof(float)*n);
  *u = p[0];
  int  k = 1;
  int ultimaPosicao = p[0];
  for (int i = 1;i < n;i++){
    if(p[i] - ultimaPosicao > delta){
      ultimaPosicao = p[i-1];
      u[k] = p[i-1];
      k++;
    }
  }
  u[k] = p[n-1];
  return u;
}

int main(){
  int n = 6, delta = 2;
  int p[6] = {1,2,3,5,6,7};
  int* u;
  u = saltoSapo(p, n, delta);
  printf("Posições: ");
  for(int i = 0;i < n;i++){
    if(u[i] == 0) break;
    printf("%d ",u[i]);
  }
  free(u);
  return 0;
}
