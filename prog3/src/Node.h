//============================================================================
// Name        : prog2-processor.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef NODE_H
#define NODE_H

#include<string>
#include "Item.h"

struct Datan{
	Item val;
};

class Node{
private:
	Datan datav;
	Node* next;
	Node* prev;

public:
	Node(Item val);
	Node* getNext();
	Item getValue() const;
	friend class LinkedList;
	void setValue(Item i);
	void setPrev(Node* n);
	void setNext(Node* n);
};
#endif
