// main.cpp
// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE ----- TIA: 42131936 ----- TURMA: 03D

#include <iostream>
#include "LinkedList.h"

#define SAFE_DELETE(ptr) { if(ptr) { delete ptr; ptr = nullptr; }}
#define SAFE_DELETE_ARRAY(arr) { if (arr) { delete [] arr; arr = nullptr; }}

using namespace std;
void PrintListInfo(const LinkedList* list)
{
 if (IsEmpty(list))
 {
 cout << "Lista vazia!\n";
 }
 else
 {
 // Percorrer todos os nós da lista e imprimir os valores de cada nó
 // (veja saída de exemplo no enunciado).
  Node *node = list->head;
  cout << "Lista com " << Count(list) <<  " elementos: "; 
  while (node != nullptr) {
    cout << node->data << " ";
    node = node->next;
  }
   cout << "\n\n";
 }
}

int main()
{
 cout << "*** Lista Ligada/Encadeada (Linked List) ***\n\n";
 LinkedList* list = Create();
 PrintListInfo(list);
 Insert(list, 1);
 Insert(list, 2);
 Insert(list, 3);
 Append(list, 4);
 Append(list, 5);
 Append(list, 6);
 PrintListInfo(list);
 Clear(list);
 PrintListInfo(list);
 Insert(list, 77);
 Append(list, 88);
 Insert(list, 99);
 Append(list, 3);
 Insert(list, 2);
 Append(list, 1);
 Insert(list, 0);
 PrintListInfo(list);
  
 Node* temp = RemoveNode(list, 3);
 cout << "Nó removido: " << temp->data << '\n';
  
 // Liberar memória alocada para o nó que foi removido.
 SAFE_DELETE(temp);
 
 PrintListInfo(list);
 temp = RemoveHead(list);
 cout << "Nó removido: " << temp->data << '\n';
  
 // Liberar memória alocada para o nó que foi removido.
 SAFE_DELETE(temp);
  
 PrintListInfo(list);
 temp = RemoveTail(list);
 cout << "Nó removido: " << temp->data << '\n';
  
 // Liberar memória alocada para o nó que foi removido.
 SAFE_DELETE(temp);
  
 PrintListInfo(list);

 // Imprimir o primeiro elemento da lista
  
 cout << "Primeiro nó da lista: " << GetHead(list)->data << '\n' << endl;   
  
 // Imprimir o último elemento da lista
  
 cout << "Ultimo nó da lista: " << GetTail(list)->data << '\n' << endl;
// Tentar encontrar o nó de valor 3 na lista
  
 if (GetNode(list, 3)!= nullptr){
   cout << "O endereço de memória do nó de valor " << 3 << " na lista é: " << GetNode(list,3) << '\n' << endl;
 }
 else{
   cout << "Valor dado não se encontra na lista\n" << endl;
}
 
Destroy(list);// Liberar memória alocada para a lista.
if(list == nullptr)
  cout << "Lista foi desalocada\n";
else  cout << "Lista não foi desalocada\n";
cout << "Fim.\n";
}


/* 
REFERENCIAS: 
- Aulas de ponteiros e linkedList dadas pelo professor Kishimoto, Mackenzie

- Avoid Memory Leak 
https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/#:~:text=Memory%20leakage%20occurs%20in%20C%2B%2B,by%20using%20wrong%20delete%20operator.

---------------------------------------------------------------------------------------------------

AUTO AVALIAÇÃO:

----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------

-PEDRO L M B VOLPE- 

Item avaliado                                                               Pontuação 
----------------------------------------------------------------------------------------------------
Implementação das funções:

Create(), Destroy(), Clear(), Insert(), Append(), RemoveHead(),         8,0 (TODAS AS FUNÇÕES FORAM 
RemoveTail(), RemoveNode().                                                 IMPLEMENTADAS)                                                                                                                         
----------------------------------------------------------------------------------------------------                                                                         
Implementação das funções:
GetHead(), GetTail(), GetNode(), Count(), IsEmpty().                     1,25 (Todas as funções foram)
                                                                              implementadas no código)
----------------------------------------------------------------------------------------------------
Implementação da função main().                                             0,5 (Implementada)
----------------------------------------------------------------------------------------------------
Autoavaliação (individual).                                                 0,25 (Feita)
----------------------------------------------------------------------------------------------------

                                            Total: 10 

----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------

-ERIC AKIO UCHIYAMADA-

Item avaliado                                                                Pontuação 
----------------------------------------------------------------------------------------------------
Implementação das funções:

Create(), Destroy(), Clear(), Insert(), Append(), RemoveHead(),                 8,0
RemoveTail(), RemoveNode().                                                 
                                                                           
-----------------------------------------------------------------------------------------------------
Implementação das funções:
GetHead(), GetTail(), GetNode(), Count(), IsEmpty().                            1,25
-----------------------------------------------------------------------------------------------------
Implementação da função main().                                                 0,5
-----------------------------------------------------------------------------------------------------
Autoavaliação (individual).                                                     0,25
-----------------------------------------------------------------------------------------------------
                                                                              Total: 10
-----------------------------------------------------------------------------------------------------

*/
