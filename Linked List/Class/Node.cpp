#include "Node.h"

Node::Node()
	: m_Data(0)
	, m_Next(nullptr)
{
}

Node::Node(int data, Node* next)
	: m_Data(data)
	, m_Next(next)
{
}

Node::~Node()
{
	m_Next = nullptr;
}

int Node::GetData() const
{
	return m_Data;
}

void Node::SetData(int data)
{
	m_Data = data;
}

Node* Node::GetNext() const
{
	return m_Next;
}

void Node::SetNext(Node* next)
{
	m_Next = next;
}
