#include <math.h>
#include <stdio.h>
// Eric Akio Uchiyamada    TIA: 42107865
//exercício para mostrar a quantidade de notas e de moedas necessárias para formar a quantidade de dinheiro na main()
void trocoNotas(float valor) {
  int i = 0;
  int notas[6] = {10000, 5000, 2000, 1000, 500, 200}, notasUsadas[6];
  int moedas[6] = {100, 50, 25, 10, 5, 1}, moedasUsadas[6];
  float printMoedas[6] = {1.00, 0.5, 0.25, 0.1, 0.05, 0.01};
  int centavos = round(valor * 100);

  while (i < 6) {
    notasUsadas[i] = centavos / notas[i];
    centavos %= notas[i];
    printf("%d nota (s) de R$ %d\n", notasUsadas[i], notas[i] / 100);
    i++;
  }
  i = 0;
  printf("\n");
  while (i < 6) {
    moedasUsadas[i] = centavos / moedas[i];
    centavos %= moedas[i];
    printf("%d moeda (s) de R$ %.2f\n", moedasUsadas[i], printMoedas[i]);
    i++;
  }
}

int main(void) {
  float valor = 576.73;
  trocoNotas(valor);
  return 0;
}
