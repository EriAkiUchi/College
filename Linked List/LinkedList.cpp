// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE ----- TIA: 42131936 ----- TURMA: 03D

#include <iostream>
#include "LinkedList.h"

//----------------------------------------------------------------------------
//Criar lista encadeada vazia
LinkedList *Create(){ 
  LinkedList *newList = new LinkedList;
  newList->count = 0;
  newList->head = newList->tail = nullptr;
  return newList;
}
//----------------------------------------------------------------------------
//Liberar memória alocada para a lista
void Destroy(LinkedList *&list){
  
  Clear(list);
  delete list;
  list = nullptr;
}
//----------------------------------------------------------------------------
//Inserir nó com elemento no início da lista
void Insert(LinkedList *list, int elem){
  Node *node = new Node;
  node->data = elem;
  node->next = list->head;
  if (IsEmpty(list)){
    list->tail = node;
  }
  list->head = node;
  list->count++;
}
//----------------------------------------------------------------------------
//Inserir nó com elemento no final da lista
void Append(LinkedList *list, int elem){
  Node *node = new Node;
  node->data = elem;
  node->next = nullptr;
  if (IsEmpty(list)){
    list->head = node;
  }
  else{
    list->tail->next = node;
  }
  list->tail = node;
  list->count++;
}
//----------------------------------------------------------------------------
//Remover o nó do início da lista
Node *RemoveHead(LinkedList *list){
  if (IsEmpty(list)){
    return nullptr;
  }
  Node *toRemove = list->head;
  if (list->head == list->tail){
    list->head = list->tail = nullptr;
  }
  else{
    list->head = list->head->next;
  }
  list->count--;
  toRemove->next = nullptr;
  
  return toRemove;
}
//----------------------------------------------------------------------------
//Remover o nó do final da lista
Node *RemoveTail(LinkedList *list){
  if (IsEmpty(list)){
    return nullptr;
  }
  if (list->head == list->tail){
    return RemoveHead(list);
  }
  Node *toRemove = list->head;
  Node *previous = nullptr;
  while(toRemove != list->tail){
    previous = toRemove;
    toRemove = toRemove->next;
  }
  previous->next = nullptr;
  list->tail = previous;
  list->count--;
  toRemove->next = nullptr;
  return toRemove;
}
//----------------------------------------------------------------------------
//Remover nó com elemento específico da lista
Node *RemoveNode(LinkedList *list, int value){
  if (IsEmpty(list)){
    return nullptr;
  }
  Node *toRemove = list->head;
  Node *previous = nullptr;
  while ((toRemove != nullptr) && (toRemove->data != value)){
    previous = toRemove;
    toRemove = toRemove->next;
  }
  if (toRemove == nullptr)
    return nullptr;
  else if(toRemove == list->head)
    return RemoveHead(list);
  else if(toRemove == list->tail)
    return RemoveTail(list);
  else{
    previous->next = toRemove->next;
    list->count--;
    toRemove->next = nullptr;
    return toRemove;
  }
}
//----------------------------------------------------------------------------
//Retorna uma referência do nó com o elemento específico da lista
Node *GetNode(const LinkedList *list, int value){
  if (IsEmpty(list)){
    return nullptr;
  }
  Node *node = list->head;
  while (node != nullptr){
    if (node->data == value)
      return node;
    node = node->next;
  }
  return nullptr;
}
//----------------------------------------------------------------------------
//Retorna uma referência do primeiro nó da lista
Node *GetHead(const LinkedList *list){
  if (IsEmpty(list)){
    return nullptr;
  }
  return list->head;
}
//----------------------------------------------------------------------------
//Retorna uma referência do último nó da lista
Node *GetTail(const LinkedList *list){ 
  if (IsEmpty(list)){
    return nullptr;
  }
  return list->tail;
}
//----------------------------------------------------------------------------
//Contar o tamanho da lista
int Count(const LinkedList *list){
  return list->count;
}
//----------------------------------------------------------------------------
//Verificar se a lista está vazia
bool IsEmpty(const LinkedList *list){
  if (list->count == 0)
    return true;
  return false;
}
//----------------------------------------------------------------------------
//Desalocar cada nó da lista
void Clear(LinkedList *list){
  Node *node = list->head;
  Node *next = nullptr;
  while(node != nullptr){
    next = node->next;
    delete node;
    node = next;
  }
  node = next = nullptr;
  list->head = list->tail = nullptr;
  list->count = 0;
}
//----------------------------------------------------------------------------
