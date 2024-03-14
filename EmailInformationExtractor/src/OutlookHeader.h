#ifndef OUTLOOKHEADER_H
#define OUTLOOKHEADER_H

#include "Header.h"
#include <string>
using namespace std;

class OutlookHeader:public Header{
private:
	string Authentication;
	string Application;
	string Transfer;
	string Topic;
	string Index;
	string References;
	string AcceptLang;
	string ContentLang;
	string Attach;
	string Exchange;
	string CC;

public:
	OutlookHeader(const string date, const string RB, const string RF, const string From, const string T, const string subject, const string MID, const string reply,
			const string Authentication, const string Application, const string Transfer, const string Topic, const string Index, const string References, const string AcceptLang, const string ContentLang, const string Attach, const string Exchange, const string cc);

string getAuthentication() const;
string getApplication() const;
string getTransfer() const;
string getTopic() const;
string getIndex() const;
string getReferences() const;
string getAcceptLang() const;
string getContentLang() const;
string getAttach() const;
string getExchange() const;
string getCC() const;

void setAuthentication(const string& date);
void setApplication(const string& RB);
void setTransfer(const string& RF);
void setTopic(const string& From);
void setIndex(const string& CC);
void setReferences(const string& subject);
void setAcceptLang(const string& MID);
void setContentLang(const string& reply);
void setAttach(const string& CC);
void setExchange(const string& CC);
void setCC(const string& CC);



};
#endif
