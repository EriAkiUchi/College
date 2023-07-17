#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void Insert(int data);
	void Append(int data);

	Node* RemoveHead();
	Node* RemoveTail();
	Node* RemoveNode(int data);

	// Palavra-chave const após a assinatura do método? Consulte:
	// - Const Correctness, C++ FAQ.
	// https://isocpp.org/wiki/faq/const-correctness#const-member-fns.
	// - MIZRAHI, V. V. Treinamento em Linguagem C++: módulo 2 - 2a edição. São Paulo: Editora Pearson, 2006.
	// Capítulo 8 - Classes e objetos, página 16 (Objetos Constantes).

	Node* GetHead() const;
	Node* GetTail() const;
	Node* GetNode(int data) const;

	int Count() const;
	bool IsEmpty() const;
	void Clear();

private:
	int m_Count;
	Node* m_Head;
	Node* m_Tail;
};

#endif //  __LINKED_LIST_H__
