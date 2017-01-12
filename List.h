#pragma once
#include "Node.h"

template<typename T>
class List
{

public:
	List();
	//List & List(const List & copy);
	//List & operator=(const List & rhs);
	~List();
	T gethead();
	T gettail();
	//bool isEmpty();
	//Node & First() const;
	//Node & Last() const;
	//void Prepend(T Data); //adds to the front of the list
	//void Append(T Data); //adds to the end of the list maybe pointer?
	//void Purge();
	//void Extract(T Data);
	//void InsertAfter(T Data, T insertafter); //(element to insert, after other node)
	//void InsertBefore(T Data, T insertbefore); //(element to insert, before other node)

private:
	Node<T> * m_head;
	Node<T> * m_tail;
};

template<typename T>
inline List<T>::List() : m_head(nullptr), m_tail(nullptr) //base member so the head and the tail both point to null
{
	//nn stands for new node
	Node<T> * nn = new Node<T>();
}

//template<typename T>
//inline List<T>::List(const List & copy)
//{
//}
//
//template<typename T>
//inline List & List<T>::operator=(const List & rhs)
//{
//	// TODO: insert return statement here
//}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline T List<T>::gethead()
{
	
	/*if (m_head->m_next != nullptr)
	{
		cout << m_head->Data;
	}
*/
	return m_head;

	//return m_head;// returns the data that m_head is pointing at
}

template<typename T>
inline T List<T>::gettail()
{
	//return m_tail->m_previous; // returns the data that m_tail is pointing at
}

//template<typename T>
//inline bool List<T>::isEmpty()
//{
//	return false;
//}
//
//template<typename T>
//inline Node & List<T>::First() const
//{
//	// TODO: insert return statement here
//}
//
//template<typename T>
//inline Node & List<T>::Last() const
//{
//	// TODO: insert return statement here
//}
//
//template<typename T>
//inline void List<T>::Prepend(T Data)
//{
//}
//
//template<typename T>
//inline void List<T>::Append(T Data)
//{
//}
//
//template<typename T>
//inline void List<T>::Purge()
//{
//}
//
//template<typename T>
//inline void List<T>::Extract(T Data)
//{
//}
//
//template<typename T>
//inline void List<T>::InsertAfter(T Data, T insertafter)
//{
//}
//
//template<typename T>
//inline void List<T>::InsertBefore(T Data, T insertbefore)
//{
//}
