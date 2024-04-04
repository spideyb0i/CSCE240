#include "Item.h"
#include <string>

using namespace std;

Item::Item(string ti,string to,string n):data({ti,to,n}){}


string Item::getTitle() const{
	return data.title;
}
string Item::getTopic() const{
	return data.topic;
}
string Item::getNum() const{
	return data.num;
}

void Item::setTitle(const string& ti){
	data.title=ti;
}
void Item::setTopic(const string& top){
	data.topic=top;
}
void Item::setNum(const string& n){
	data.num=n;
}
