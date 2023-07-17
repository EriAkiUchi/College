// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D

#include <iostream>

#include "DoublyCircularLinkedList.h"
#include "Utils.h"
#include "Func.h"

int main() 
{

  LinkedList *list = Create(); //criar a lista encadeada

  std::string input = "";
  int option = -1;

  do {
    std::cout << "\n\n*** MENU ***\n"//menu de opções
              << "1 - Ler dados.\n"
              << "2 - Exibir dados.\n"
              << "3 - Salvar dados.\n"
              << "4 - Inserir livro.\n"
              << "5 - Remover livro.\n"
              << "6 - Análise de dados A.\n"
              << "7 - Análise de dados B.\n"
              << "8 - Análise de dados C.\n"
              << "9 - Encerrar programa.\n"
              << "Opcao: ";

    std::getline(std::cin, input);

    option = GetIntFromString(input);
    switch (option) {
      
    case 1: //"Ler dados"
      ClearScreen();//reiniciar a tela
	    ReadArchive(list);    
      Pause();
      break;
          
//--------------------------------------------------------------------------------------------------
    case 2://"Exibir dados"
      ClearScreen();//reiniciar a tela      
      Print(list);      
      Pause(); 
      break;
//--------------------------------------------------------------------------------------------------
    case 3://"Salvar dados"      
      ClearScreen();  //reiniciar a tela
      WriteStringToFile(list,"bibliografia2.csv");
      Pause();
      break;
//--------------------------------------------------------------------------------------------------
    case 4://"Inserir livro"
      ClearScreen();//reiniciar a tela
      InsertBook(list);
      Pause();
      break;
//--------------------------------------------------------------------------------------------------
    case 5: //"Remover livro"
      ClearScreen();//reiniciar a tela
      RemoveBook(list);
      Pause();
      break;
//--------------------------------------------------------------------------------------------------      

    case 6: //"Ver quais livros são brasileiros e estrangeiros"
      ClearScreen();//reiniciar a tela
      CountBook(list);
      Pause();
      break;
//--------------------------------------------------------------------------------------------------      
    case 7: //"Obter a quantidade de livros com bibliografia publicados entre os anos de 2002 e 2010, e a respectiva porcentagem"
      ClearScreen();
      BooksBetween2002_2010(list);
      Pause();
      break; 
//--------------------------------------------------------------------------------------------------      
    case 8: //"Obter o nome, data de publicação e a idade de um dos livros mais antigo e um dos livros mais recentes, e obter a media da idade destes livros"
      ClearScreen();
      BooksAges(list);
      Pause();
      break; 
//--------------------------------------------------------------------------------------------------      
    case 9://"Encerrar o programa"
      std::cout << "Fim.\n\n";
      Destroy(list);
      break;
//-------------------------------------------------------------------------------------------------- 
      
    default:
      std::cout << "*** ERRO: Opcao invalida!\n\n";
      Pause();
    }
    
//-------------------------------------------------------------------------------------------------- 
  } while (option != 9);
}
//-------------------------------------------------------------------------------------------------- 
/*

Referências:

-Aulas de Lista encadeada, duplamente encadeada e circularmente encadeada

https://www.geeksforgeeks.org/csv-file-management-using-c/

https://www.tutorialkart.com/cpp/cpp-get-char-at-index-in-string/#:~:text=C%2B%2B%20Get%20Char%20from%20String%20at%20Index,the%20char%20at%20given%20index.

https://stackoverflow.com/questions/58151350/more-elegant-way-to-get-the-current-year-in-c


*/
