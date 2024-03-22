//============================================================================
// Name        : prog2-processor.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//#include "Item.h"
#include "Node.h"

//Function declarations
class LinkedList {
private:
	Node* head;
	Node* tail;
public:
    LinkedList();
    ~LinkedList();
	void insert(Item newItem);
	void append(Item newItem);
	void display() const;
	void clear();
	Node* getHead();
};

#endif
