#include "LinkedList.h"

LinkedList::LinkedList()
	: m_Count(0)
	, m_Head(nullptr)
	, m_Tail(nullptr)
{
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Insert(int data)
{
	Node* node = new Node(data, m_Head);

	if (IsEmpty())
	{
		m_Tail = node;
	}
		
	m_Head = node;
	++m_Count;
}

void LinkedList::Append(int data)
{
	Node* node = new Node(data, nullptr);

	if (IsEmpty())
	{
		m_Head = node;
	}
	else
	{
		m_Tail->SetNext(node);
	}
	m_Tail = node;

	++m_Count;
}

Node* LinkedList::RemoveHead()
{
	if (IsEmpty())
	{
		return nullptr;
	}

	Node* toRemove = m_Head;

	if (m_Head == m_Tail)
	{
		m_Head = m_Tail = nullptr;
	}
	else
	{
		m_Head = m_Head->GetNext();
	}

	--m_Count;

	toRemove->SetNext(nullptr);	
	return toRemove;
}

Node* LinkedList::RemoveTail()
{
	if (m_Head == m_Tail)
	{
		return RemoveHead();
	}

	Node* toRemove = m_Head;
	Node* previous = nullptr;

	while (toRemove != m_Tail)
	{
		previous = toRemove;
		toRemove = toRemove->GetNext();
	}

	previous->SetNext(nullptr);
	m_Tail = previous;

	--m_Count;
	
	toRemove->SetNext(nullptr);
	return toRemove;
}

Node* LinkedList::RemoveNode(int data)
{
	Node* toRemove = m_Head;
	Node* previous = nullptr;

	while (toRemove != nullptr && toRemove->GetData() != data)
	{
		previous = toRemove;
		toRemove = toRemove->GetNext();
	}

	if (toRemove == m_Head)
	{
		return RemoveHead();
	}
	else if (toRemove == m_Tail)
	{
		return RemoveTail();
	}
	else if (toRemove != nullptr)
	{
		previous->SetNext(toRemove->GetNext());

		--m_Count;

		toRemove->SetNext(nullptr);
		return toRemove;
	}

	return nullptr;
}

Node* LinkedList::GetHead() const
{
	return m_Head;
}

Node* LinkedList::GetTail() const
{
	return m_Tail;
}

Node* LinkedList::GetNode(int data) const
{
	Node* node = m_Head;
	while (node != nullptr)
	{
		if (node->GetData() == data)
		{
			return node;
		}
		node = node->GetNext();
	}

	return nullptr;
}

int LinkedList::Count() const
{
	return m_Count;
}

bool LinkedList::IsEmpty() const
{
	return m_Head == nullptr && m_Tail == nullptr;
}

void LinkedList::Clear()
{
	Node* node = m_Head;
	Node* next = nullptr;

	while (node != nullptr)
	{
		next = node->GetNext();
		delete node;
		node = next;
	}

	m_Head = m_Tail = nullptr;
	m_Count = 0;
}
