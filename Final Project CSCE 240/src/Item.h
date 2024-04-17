//============================================================================
// Name        : prog2-processor.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

struct Data{
	string title;
	string topic;
	string num;
};

class Item{
private:
	Data data;
public:
	Item(string ti,string top, string num);
	friend class LinkedList;

//Accessors
string getTitle() const;
string getTopic() const;
string getNum() const;

//Mutators
void setTitle(const string& ti);
void setTopic(const string& top);
void setNum(const string& n);
};

#endif
