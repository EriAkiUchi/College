// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D

#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include "DoublyCircularLinkedList.h"
void ClearScreen();
void Pause(const std::string& message = "Pressione ENTER para continuar...");
int GetIntFromString(const std::string& str);
bool GetBoolFromString(const std::string str);

#endif
