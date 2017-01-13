#pragma once
//forward declaration NEEDED
template <typename T>
class List;


template <typename T>
class Node
{
	friend class List<T>;
public:
	Node();
	Node(T Data);
	//Node * getnext() { return m_next; }//returns the next pointer
	//Node * getprevious() { return m_previous; }// returns the previous pointer
	/*Node & Node(const Node & copy);
	Node & operator=(const Node & rhs);*/
	~Node();
private:
	T Data;
	Node * m_next;
	Node * m_previous;
};

template<typename T>
inline Node<T>::Node() : m_next(nullptr), m_previous(nullptr) //base memeber so the first node created points to null both ways
{
}

template<typename T>
inline Node<T>::Node(T Data) : Data(Data), m_next(nullptr),m_previous(nullptr) // creates a node with Data in it 
{

}

//template<typename T>
//inline Node<T>::Node(const Node & copy)
//{
//}
//
//template<typename T>
//inline Node & Node<T>::operator=(const Node & rhs)
//{
//	// TODO: insert return statement here
//}

template<typename T>
inline Node<T>::~Node()
{

}
