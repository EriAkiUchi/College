//Nome: Eric Akio Uchiyamada    TIA: 42107865

#ifndef __PALINDROMO_H__
#define __PALINDROMO_H__

#include <iostream>
#include <string>
const int TAMANHO_MAXIMO = 100;//definição do tamanho máximo do vetor
struct Pilha
{
    int topo;
    char frase[TAMANHO_MAXIMO];
};

//declaração de todas as funções utilizadas
bool Push(Pilha &stack,char e);
char Pop(Pilha &stack);
char Top(const Pilha &stack);
Pilha Create();
bool Empty(Pilha& stack);
std::string RemoveSpaces(std::string frase);
bool Palindromo(const std::string frase);
std::string Maiusculo(std::string frase);

#endif