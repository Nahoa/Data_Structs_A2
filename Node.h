#pragma once

//class List<T>;


template <typename T>
class Node
{
	friend class List<T>;
public:
	Node();
	Node & Node(const Node & copy);
	Node & operator=(const Node & rhs);
	~Node();
private:
	T Data;
	Node * m_Next;
	Node * m_Previous;
};

