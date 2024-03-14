#include "OutlookHeader.h"
#include <string>

using namespace std;

OutlookHeader::OutlookHeader(string date, string RB, string RF, string From, string T, string subject, string MID, string reply,
			string Authentication, string Application, string Transfer, string Topic, string Index, string References, string AcceptLang, string ContentLang, string Attach, string Exchange, string cc)
	: Header(date, RB, RF, From, T, subject, MID, reply),
	  Authentication(Authentication), Application(Application), Transfer(Transfer), Topic(Topic), Index(Index), References(References), AcceptLang(AcceptLang), ContentLang(ContentLang), Attach(Attach), Exchange(Exchange), CC(cc) {}


string OutlookHeader::getAuthentication() const{
	return Authentication;
}
string OutlookHeader::getApplication() const{
	return Application;
}
string OutlookHeader::getTransfer() const{
	return Transfer;
}
string OutlookHeader::getTopic() const{
	return Topic;
}
string OutlookHeader::getIndex() const{
	return Index;
}
string OutlookHeader::getReferences() const{
	return References;
}
string OutlookHeader::getAcceptLang() const{
	return AcceptLang;
}
string OutlookHeader::getContentLang() const{
	return ContentLang;
}
string OutlookHeader::getAttach() const{
	return Attach;
}
string OutlookHeader::getExchange() const{
	return Exchange;
}
string OutlookHeader::getCC() const{
	return CC;
}

void OutlookHeader::setAuthentication(const string& date){
	this->Authentication = date;
}
void OutlookHeader::setApplication(const string& RB){
	this->Application = RB;
}
void OutlookHeader::setTransfer(const string& RF){
	this->Transfer = RF;
}
void OutlookHeader::setTopic(const string& From){
	this->Topic = From;
}
void OutlookHeader::setIndex(const string& CC){
	this->Index = CC;
}
void OutlookHeader::setReferences(const string& subject){
	this->References=subject;
}
void OutlookHeader::setAcceptLang(const string& MID){
	this->AcceptLang = MID;
}
void OutlookHeader::setContentLang(const string& reply){
	this->ContentLang = reply;
}
void OutlookHeader::setAttach(const string& CC){
	this->Index = CC;
}
void OutlookHeader::setExchange(const string& CC){
	this->Index = CC;
}
void OutlookHeader::setCC(const string& CC){
	this->Index = CC;
}

