//============================================================================
// Name        : prog2-processor.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Node.h"

Node::Node(Item temp):datav({temp}),next(nullptr),prev(nullptr){}

Item Node::getValue()const{
	return datav.val;
}
Node* Node::getNext(){
	return next;
}
void Node::setValue(Item nItem){
	datav.val=nItem;
}
void Node::setNext(Node* n){
	next=n;
}
void Node::setPrev(Node* n){
	prev=n;
}
