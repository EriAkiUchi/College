// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <string>
#include <iostream>

//----------------------------------------------------------------------------
//Struct de dados do Nó
struct Data{
std::string Disciplina;
std::string Isbn;
std::string Titulo;
std::string Autor;
int Edicao;
std::string Cidade;
std::string Editora;
int Ano;
bool Bibliografia;
};

//----------------------------------------------------------------------------
// struct do nó
struct Node
{
Data dados;
Node *next;
Node *previous;
};
//----------------------------------------------------------------------------
//struct da lista
struct LinkedList
{
int count;
Node *head;
Node *tail;
};
//----------------------------------------------------------------------------
LinkedList *Create();
void Destroy(LinkedList *&list);
void Insert(LinkedList *list, Data database);
void Append(LinkedList *list, Data database);
Node *RemoveHead(LinkedList *list);
Node *RemoveTail(LinkedList *list);
Node *RemoveNode(LinkedList *list, std::string data);
Node *GetNode(const LinkedList *list, std::string data);
Node *GetHead(const LinkedList *list);
Node *GetTail(const LinkedList *list);
int Count(const LinkedList *list);
bool IsEmpty(const LinkedList *list);
void Clear(LinkedList *list);

//---------------------------------------------------------------------------

#endif
