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

template<typename T>
inline List<T>::List()
{
}

template<typename T>
inline List<T>::List(const List & copy)
{
}

template<typename T>
inline List & List<T>::operator=(const List & rhs)
{
	// TODO: insert return statement here
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline bool List<T>::isEmpty()
{
	return false;
}

template<typename T>
inline Node & List<T>::First() const
{
	// TODO: insert return statement here
}

template<typename T>
inline Node & List<T>::Last() const
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::Prepend(T Data)
{
}

template<typename T>
inline void List<T>::Append(T Data)
{
}

template<typename T>
inline void List<T>::Purge()
{
}

template<typename T>
inline void List<T>::Extract(T Data)
{
}

template<typename T>
inline void List<T>::InsertAfter(T Data, T insertafter)
{
}

template<typename T>
inline void List<T>::InsertBefore(T Data, T insertbefore)
{
}
