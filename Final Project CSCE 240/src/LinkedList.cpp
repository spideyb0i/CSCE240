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
using namespace std;

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

void LinkedList::display(string StatFile) const{
	Node* current=head;

	ofstream outputFile(StatFile, ios_base::app);
		    if (!outputFile.is_open()) {
		    	std::cerr << "Error creating output file.\n";
		    	return;
	}

	while(current!=nullptr){
		std::cout<<current->datav.val.getTitle()<<"\n"<<current->datav.val.getTopic()<<" on page "<<current->datav.val.getNum()<<endl;
		outputFile<<current->datav.val.getTitle()<<"\n"<<current->datav.val.getTopic()<<" on page "<<current->datav.val.getNum()<<endl;
		current=current->next;
	}

	outputFile.close();
}

Node* LinkedList::getHead(){
	return head;
}

void LinkedList::clear(){
	while (head != nullptr) {
	    Node* temp = head;
	    head = head->getNext(); // Move head to the next node
	    delete temp; // Delete the current node
	}
}
