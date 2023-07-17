// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D

#include <iostream>
#include "DoublyCircularLinkedList.h"

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
void Insert(LinkedList *list, Data database){
  Node *node = new Node;
  node->dados = database;
  
  if (IsEmpty(list)){
    list->tail = node;
  }
  else{
    list->head->previous = node;
  }

  node->next = list->head;
  
  list->head = node;
  node->previous = list->tail;
  list->count++;
}
//----------------------------------------------------------------------------
//Inserir nó com elemento no final da lista
void Append(LinkedList *list, Data database){
  Node *node = new Node;
  node->dados = database;

  node->previous = list->tail;
  
  node->next = list->head;
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
  toRemove->previous = nullptr;
  
  list->head->previous = list->tail;
  list->tail->next = list->head;
  
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
  Node *toRemove = list->tail;
  list->tail = toRemove->previous;
  list->tail->next = list->head;
  list->head->previous = list->tail;
  
  list->count--;
  toRemove->next = toRemove->previous = nullptr;
  return toRemove;
}
//----------------------------------------------------------------------------
//Remover nó com elemento específico da lista (podendo ser o ISBN ou o TITULO do livro a ser removido)
Node *RemoveNode(LinkedList *list, std::string data){
  if (IsEmpty(list)){
    return nullptr;
  }
  Node *toRemove = list->head;
  int i = 0;
  while(i < list->count){
    if(toRemove->dados.Isbn == data) 
      break;
    if(toRemove->dados.Titulo == data)
      break;
    
    toRemove = toRemove->next; 
    i++;
  }
  
  if (toRemove == nullptr)
    return nullptr;
  else if(toRemove == list->head)
    return RemoveHead(list);
  else if(toRemove == list->tail)
    return RemoveTail(list);
  else{
    toRemove->previous->next = toRemove->next;
    toRemove->next->previous = toRemove->previous;
    list->count--;
    toRemove->next = toRemove->previous = nullptr;
    return toRemove;
  }
}
//----------------------------------------------------------------------------
//Retorna uma referência do nó com o elemento específico da lista com base no ISBN
Node *GetNode(const LinkedList *list, std::string data){
  if (IsEmpty(list)){
    return nullptr;
  }
  Node *node = list->head;
  for (int i = 0; i < list->count; i++){
    if (node->dados.Isbn == data)
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
  for(int i = 0; i < list->count; i++){
    next = node->next;
    delete node;
    node = next;
  }
  node = next = nullptr;
  list->head = list->tail = nullptr;
  list->count = 0;
}
//----------------------------------------------------------------------------
