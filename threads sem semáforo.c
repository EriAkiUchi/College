/*
Nome: Eric Akio Uchiyamada                  TIA: 42107865
Nome: Oliver Kieran Galvão McCormack		    TIA: 42122058
Nome: Pedro Loureiro Morone Branco Volpe		TIA: 42131936
Nome: Renan Luiz Rodrigues Tagliaferro		  TIA: 42105846
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <unistd.h>
//pequeno projeto de manipulação de threads
void *transferirParaA(void *arg)
{
  int valor = *((int *)arg);
  int saldoA,saldoB;
  //abrir ler e printar A
  FILE* A = fopen("saldoA.txt", "r+");
  fscanf(A, "%d ", &saldoA);
  //abrir B e ler o saldo
  FILE* B = fopen("saldoB.txt", "r+");
  fscanf(B,"%d " ,&saldoB);
  // subtrair x do saldoB e passar ao A
  saldoB -= valor;
  saldoA += valor;
  // mover o cursor para o início dos arquivos
  rewind(A);
  rewind(B);
  // escrever o novo saldo nos arquivos
  fprintf(A, "%d ", saldoA);
  fprintf(B, "%d ", saldoB);
  //atualiza valor nas variaveis
  fscanf(A, "%d ", &saldoA);
  fscanf(B,"%d ", &saldoB);
  printf("\nSaldo após tranferencia em A(A): %d\n",saldoA);
  printf("\nSaldo após tranferencia em B(A): %d\n",saldoB);
  // fechar os arquivos
  fclose(A);
  fclose(B);
  return NULL;
}

void *transferirParaB(void *arg)
{
  int valor = *((int *)arg);
  int saldoA,saldoB;
  //abrir ler e printar A
  FILE* B = fopen("saldoB.txt", "r+");
  fscanf(B, "%d ", &saldoB);
  //abrir B e ler o saldo
  FILE* A = fopen("saldoA.txt", "r+");
  fscanf(A,"%d " ,&saldoA);
  // subtrair x do saldoB e passar ao A
  saldoA -= valor;
  saldoB += valor;
  // mover o cursor para o início dos arquivos
  rewind(B);
  rewind(A);
  // escrever o novo saldo nos arquivos
  fprintf(B, "%d ", saldoB);
  fprintf(A, "%d ", saldoA);
  //atualiza valor nas variaveis
  fscanf(B, "%d ", &saldoB);
  fscanf(A,"%d ", &saldoA);
  printf("\nSaldo após tranferencia em B(B): %d\n",saldoB);
  printf("\nSaldo após tranferencia em A(B): %d\n",saldoA);
  // fechar os arquivos
  fclose(A);
  fclose(B);
  return NULL;
}

int main(void) 
{
  pthread_t TA,TB;
  int valorA,valorB;

  //padronizar os arquivos como 1000
  FILE* AI = fopen("saldoA.txt", "r+");
  FILE* BI = fopen("saldoB.txt", "r+");
  fprintf(AI, "%d ", 1000);
  fprintf(BI, "%d ", 1000);
 
  fclose(AI);
  fclose(BI);
  
  printf("\nValor que A transfere para B: ");
  scanf("%d",&valorA);
  printf("\nValor que B transfere para A: ");
  scanf("%d",&valorB);
  
  pthread_create(&TA, NULL, transferirParaA, &valorB);
  pthread_create(&TB, NULL, transferirParaB, &valorA);

  sleep(3);
  
  int saldoA, saldoB;
  FILE* A = fopen("saldoA.txt", "r+");
  fscanf(A, "%d ", &saldoA);
  FILE* B = fopen("saldoB.txt", "r+");
  fscanf(B, "%d ", &saldoB);
  
  printf("\nvalor final de A: %d", saldoA);
  printf("\nValor final de B: %d", saldoB);
  printf("\n\n***FIM***");
  fclose(A);
  fclose(B);
}
