#include "GmailHeader.h"
#include <string>

using namespace std;

GmailHeader::GmailHeader(string date, string RB, string RF, string From, string To, string subject, string MID, string reply,
			string DT, string XGoogle, string FromReply, string Unsub, string MIME, string alternative, string textplain, string Transfer)
	: Header(date, RB, RF, From, To, subject, MID, reply),
	DeliveredTo(DT), XGoogle(XGoogle), FromReply(FromReply), Unsubscribe(Unsub), MIME(MIME), alternative(alternative), textplain(textplain), Transfer(Transfer){}

string GmailHeader::getDeliveredTo() const{
	return DeliveredTo;
}
string GmailHeader::getXGoogle() const{
	return XGoogle;
}
string GmailHeader::getFromReply() const{
	return FromReply;
}
string GmailHeader::getUnsubscribe() const{
	return Unsubscribe;
}
string GmailHeader::getMIME() const{
	return MIME;
}
string GmailHeader::getalternative() const{
	return alternative;
}
string GmailHeader::gettextplain() const{
	return textplain;
}
string GmailHeader::getTransfer() const{
	return Transfer;
}


void GmailHeader::setDeliveredTo(const string& date){
	this->DeliveredTo = date;
}
void GmailHeader::setXGoogle(const string& RB){
	this->XGoogle = RB;
}
void GmailHeader::setFromReply(const string& RF){
	this->FromReply = RF;
}
void GmailHeader::setUnsubscribe(const string& From){
	this->Unsubscribe = From;
}
void GmailHeader::setMIME(const string& CC){
	this->MIME = CC;
}
void GmailHeader::setalternative(const string& subject){
	this->alternative=subject;
}
void GmailHeader::settextplain(const string& MID){
	this->textplain = MID;
}
void GmailHeader::setTransfer(const string& reply){
	this->Transfer = reply;
}

