#pragma once

#include "Node.h"


class List
{
public:
	List();
	~List();
private:
	Node * m_head;
	Node * m_tail;
};

