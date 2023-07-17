#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
	Node();
	Node(int data, Node* next);
	~Node();

	int GetData() const;
	void SetData(int data);

	Node* GetNext() const;
	void SetNext(Node* next);

private:
	int m_Data;
	Node* m_Next;
};

#endif // __NODE_H__
