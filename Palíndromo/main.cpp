//Nome: Eric Akio Uchiyamada    TIA: 42107865

#include <iostream>
#include <string>
#include <algorithm>

#include "palindromo.h"


int main()
{       
    std::string entrada, saida;
    std::cout << "Digite uma palavra ou frase para verificar se é um palíndromo ou não:" << std::endl;
    std::getline(std::cin,entrada); //pegar a entrada incluindo símbolos e espaços
   
    saida = RemoveSpaces(entrada); //remover espaços da frase
    saida  = Maiusculo(saida); //transformar todas as letras em maiúsculo
    
    if(Palindromo(saida) == true) //verificar se é palíndromo
      std::cout << entrada << " é um palíndromo" << std::endl;
    else
      std::cout << entrada << " não é um palíndromo" << std::endl;
  
    return 0;
}
