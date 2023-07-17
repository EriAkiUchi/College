/*
Nome: Eric Akio Uchiyamada                  TIA: 42107865
Nome: Oliver Kieran Galvão McCormack		    TIA: 42122058
Nome: Pedro Loureiro Morone Branco Volpe		TIA: 42131936
Nome: Renan Luiz Rodrigues Tagliaferro		  TIA: 42105846
*/
//pequeno projeto de manipulação de threads com semáforos
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>

sem_t sem_ContaA;
sem_t sem_ContaB;

void *transferirParaA(void *arg)
{
  int valor = *((int *)arg);
  int saldoA,saldoB,sitA,sitB;//sitX = 0 significa conta X travada
  //abrir, travar ler e printar A
  //sem_getvalue(&sem_ContaA, &sitA);
  sem_wait(&sem_ContaA);
  FILE* A = fopen("saldoA.txt", "r+");
  fscanf(A, "%d ", &saldoA);
  //abrir B, travar e ler o saldo
  sleep(1);
  sem_wait(&sem_ContaB);
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
  
  // fechar e liberar os arquivos
  sem_post(&sem_ContaA);
  sem_post(&sem_ContaB);
  fclose(A);
  fclose(B);
  return NULL;
}

void *transferirParaB(void *arg)
{
  int valor = *((int *)arg);
  int saldoA,saldoB;
  //abrir ler e printar B
  sem_wait(&sem_ContaB);
  FILE* B = fopen("saldoB.txt", "r+");
  fscanf(B, "%d ", &saldoB);
  //abrir B e ler o saldo
  sem_wait(&sem_ContaA);
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
  sem_post(&sem_ContaB);
  sem_post(&sem_ContaA);
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
  
  sem_init(&sem_ContaA, 0, 1); 
  sem_init(&sem_ContaB, 0, 1); 
  
  pthread_create(&TA, NULL, transferirParaA, &valorB);
  pthread_create(&TB, NULL, transferirParaB, &valorA);

  pthread_join(TA, NULL);
  pthread_join(TB, NULL);

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
