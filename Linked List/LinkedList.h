// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE ----- TIA: 42131936 ----- TURMA: 03D

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

//----------------------------------------------------------------------------
// struct do nó
struct Node
{
int data;
Node *next;
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
void Insert(LinkedList *list, int elem);
void Append(LinkedList *list, int elem);
Node *RemoveHead(LinkedList *list);
Node *RemoveTail(LinkedList *list);
Node *RemoveNode(LinkedList *list, int value);
Node *GetNode(const LinkedList *list, int value);
Node *GetHead(const LinkedList *list);
Node *GetTail(const LinkedList *list);
int Count(const LinkedList *list);
bool IsEmpty(const LinkedList *list);
void Clear(LinkedList *list);

//----------------------------------------------------------------------------

#endif
