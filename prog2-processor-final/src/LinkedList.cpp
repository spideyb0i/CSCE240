//============================================================================
// Name        : prog2-processor.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "LinkedList.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <string>

LinkedList::LinkedList():head(nullptr){}

LinkedList::~LinkedList(){
	Node* current=head;
	while(current!=nullptr){
		Node* temp=current;
		current=current->next;
		delete temp;
	}
}

void LinkedList::insert(Item temp){
	Node* newNode = new Node(temp);
	newNode->next=head;
	head=newNode;
}

void LinkedList::append(Item temp) {
        Node* newNode = new Node(temp);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
    }

void LinkedList::display() const{
	Node* current=head;
	while(current!=nullptr){
		std::cout<<current->datav.val.getTitle()<<"\n"<<current->datav.val.getTopic()<<" on page "<<current->datav.val.getNum()<<endl;
		current=current->next;
	}
}

Node* LinkedList::getHead(){
	return head;
}
