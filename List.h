#pragma once
#include "Node.h"

template<typename T>
class List
{

public:
	List();
	List & List(const List & copy);
	List & operator=(const List & rhs);
	~List();
	bool isEmpty();
	Node & First() const;
	Node & Last() const;
	void Prepend(T Data); //adds to the front of the list
	void Append(T Data); //adds to the end of the list maybe pointer?
	void Purge();
	void Extract(T Data);
	void InsertAfter(T Data, T insertafter); //(element to insert, after other node)
	void InsertBefore(T Data, T insertbefore); //(element to insert, before other node)
	
private:
	Node<T> * m_Head;
	Node<T> * m_Tail;
};

