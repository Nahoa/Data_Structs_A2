#pragma once
#include "Node.h"

template<typename T>
class List
{

public:
	List();
	List(const List & copy);
	//List & operator=(const List & rhs);
	~List();
	int Search(T Data);
//	List * gethead() { return m_head; }
//	List * gettail() { return m_tail; }
	bool isEmpty();
	//Node & First() const;
	//Node & Last() const;
	void Prepend(T Data); //adds to the front of the list
	//void Append(T Data); //adds to the end of the list maybe pointer?
	Node<T> * Extract(T Data);
	//void InsertAfter(T NData, T insertafter); //(element to insert, after other node)
	//void InsertBefore(T NData, T insertbefore); //(element to insert, before other node)
	void Purge();

private:
	Node<T> * m_head;
	Node<T> * m_tail;
};

template<typename T>
inline List<T>::List() : m_head(nullptr), m_tail(nullptr) //base member so the head and the tail both point to null
{
	
}

template<typename T>
inline List<T>::List(const List & copy)
{
	if (copy.m_head != nullptr && copy.m_tail != nullptr)
	{
		m_head = copy.m_head;
		m_tail = copy.m_tail;
		//m_head->Data = copy.m_head->Data;
		//m_head->m_next = copy.m_head->m_next;
		//m_head->m_previous = copy.m_head->m_previous;



		List<T> clist; //creates a new list to copy the data into 

		while (m_head) // while m_head != nullptr
		{
			m_head = clist.m_head; // puts 
			m_tail = clist.m_tail;
			//m_head->m_data = clist.m_head->Data;
			//m_head->m_next = clist.m_head->m_next;
			//m_head->m_previous = clist.m_head->m_previous;

			m_head = m_head->m_next;
			m_tail = m_tail->m_previous;
			
		}
	}
}


//template<typename T>
//inline List & List<T>::operator=(const List & rhs)
//{
//	// TODO: insert return statement here
//}

template<typename T>
inline List<T>::~List()
{
	Purge(); //calls the purge function
}

template<typename T>
inline int List<T>::Search(T Data)
{
	Node<T> * travel = m_head;
	int i = 0; //starts at 0
	bool found = false;
	while (travel != nullptr)
	{
		if (Data == travel->Data)
		{
			i = i - 1;
			found = true;
		}
		travel = travel->m_next;
		i++;
	}

	if (found = false)
	{
		i = -1; // if the data isn't found it returns -1
	}
	
	return i;
}

template<typename T>
inline void List<T>::Purge()
{
	Node<T> * travel = m_head;

	while (m_head) // while m_head != nullptr
	{
		travel = m_head;
		m_head = m_head->m_next;

		delete travel;
	}

	m_head = nullptr; //sets the head back to nullptr
	m_tail = nullptr; //sets the tail back to nullptr
}

template<typename T>
inline bool List<T>::isEmpty()
{
	bool found = false;
	
	Node<T> * travel = m_head;
	Node<T> * back = m_tail;

	if (m_head == nullptr && m_tail == nullptr) // if the head and tail point to nullptr then the string is empty
		found = true;

	return found;
}
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
template<typename T>
inline void List<T>::Prepend(T Data)
{
	//nn stands for new node
	Node<T> * nn = new Node<T>(Data); // creates a new node
	if(m_head == nullptr) // when the first node is created it will allways be the tail
		m_tail = nn;
	nn->m_next = m_head; //assigning the m_head to new nodes m_next pointer
	m_head = nn; //head is always going to be the new node

	if (m_tail != nullptr)
	{
		
	}

	

}

template<typename T>
inline Node<T>* List<T>::Extract(T Data)
{
	Node<T> * travel = m_head;



	return ;
}

//template<typename T>
//inline void List<T>::Append(T Data)
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
