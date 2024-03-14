#include "Header.h"
#include <string>

using namespace std;

Header::Header(string date, string RB, string RF, string From, string subject, string MID, string reply, string to)
	: Date(date), ReceivedBy(RB), ReceivedFrom(RF), From(From), Subject(subject), MessageID(MID), Reply(reply), To(to) {}

string Header::getDate() const{
	return Date;
}
string Header::getRecievedBy() const{
	return ReceivedBy;
}
string Header::getRecievedFrom() const{
	return ReceivedFrom;
}
string Header::getFrom() const{
	return From;
}
string Header::getTo() const{
	return To;
}
string Header::getSubject() const{
	return Subject;
}
string Header::getMessageID() const{
	return MessageID;
}
string Header::getReply() const{
	return Reply;
}

void Header::setDate(const string& date){
	this->Date = date;
}
void Header::setReceivedBy(const string& RB){
	this->ReceivedBy = RB;
}
void Header::setReceivedFrom(const string& RF){
	this->ReceivedFrom = RF;
}
void Header::setFrom(const string& From){
	this->From = From;
}
void Header::setTo(const string& CC){
	this->To = CC;
}
void Header::setSubject(const string& subject){
	this->Subject=subject;
}
void Header::setMID(const string& MID){
	this->MessageID = MID;
}
void Header::setReply(const string& reply){
	this->Reply = Reply;
}
