#include <stdio.h>
//exercício para mostrar as combinações possíveis de ordem de gols que aconteceram em uma partida de futebol
void printArray(char solucoes[],int n,int nA, int nB){
  int countA = 0, countB = 0;
  for(int i = 0;i < n;i++){
    if(solucoes[i] == 'A')
      countA++;
    else if(solucoes[i] == 'B')
      countB++;
  }
  if(countA == nA && countB == nB){
    for(int i = 0;i < n;i++)
      printf("%c ",solucoes[i]);
    printf("\n");
  }
}


void combinacoesBinarias(char solucoes[],int i,int countA,int countB,int n,int nA,int nB){
  if(countA+countB == n){
    printArray(solucoes, n,nA, nB);
    return;
  }

  solucoes[i] = 'A';
  combinacoesBinarias(solucoes,i+1, countA+1,countB, n, nA, nB);

  solucoes[i] = 'B';
  combinacoesBinarias(solucoes,i+1,countA, countB+1, n, nA, nB);
}


int main(void) {
  char valores[2] = {'A','B'};
  int countA = 0,countB = 0,i = 0,nA,nB;
  printf("Digite os gols de A: ");
  scanf("%d",&nA);
  printf("Digite os gols de B: ");
  scanf("%d",&nB);
  char solucoes[nA+nB];
  int n = nA+nB;
  combinacoesBinarias(solucoes, i,countA, countB, n, nA, nB);
  return 0;
}
