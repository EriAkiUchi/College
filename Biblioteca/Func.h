// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D
//--------------------------------------------------------------------------------------------------    

#ifndef __FUNC_H__
#define __FUNC_H__

#include <string>
#include "DoublyCircularLinkedList.h"
//--------------------------------------------------------------------------------------------------    

Data SaveData(Data database, std::string data, int count);
void ReadArchive(LinkedList* list);
void Print(const LinkedList* list);
bool WriteStringToFile(LinkedList *list,const std::string& filename);
void InsertBook(LinkedList* list);
bool RemoveBook(LinkedList* list);
bool CountBook(LinkedList* list);
bool BooksBetween2002_2010(LinkedList* list);
bool BooksAges(LinkedList* list);
//--------------------------------------------------------------------------------------------------    

#endif
