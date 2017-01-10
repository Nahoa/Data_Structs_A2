#pragma once

class List;

template <typename T>
class Node
{
	friend class List;
public:
	Node();
	~Node();
private:
	T * Data;
	Node * m_next;
	Node * m_previous;
};

