// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D

#include <iostream>
#include <fstream>
#include <sstream>
#include "DoublyCircularLinkedList.h"
#include "Utils.h"
//--------------------------------------------------------------------------------------------------    

void ClearScreen()//limpar a tela
{
#if _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
//--------------------------------------------------------------------------------------------------    

std::string __pause_hack__;
void Pause(const std::string& message)//pausar o programa
{
	std::cout << message;
	std::getline(std::cin, __pause_hack__);
}
//--------------------------------------------------------------------------------------------------    

int GetIntFromString(const std::string &str) { //transformar string em inteiro
  try {
    return std::stoi(str);
  } catch (...) {
    return -1;
  }
}
//--------------------------------------------------------------------------------------------------    

bool GetBoolFromString(const std::string str){//transformar char em booleano

  char ch = str.at(0);
  ch = toupper(ch);
  
  if(ch == 'S'){
    return true;
  }
  else return false;
}
//--------------------------------------------------------------------------------------------------    

