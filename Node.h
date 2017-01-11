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

template<typename T>
inline Node<T>::Node()
{
}

template<typename T>
inline Node<T>::Node(const Node & copy)
{
}

template<typename T>
inline Node & Node<T>::operator=(const Node & rhs)
{
	// TODO: insert return statement here
}

template<typename T>
inline Node<T>::~Node()
{
}
