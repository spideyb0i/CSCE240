#ifndef GMAILHEADER_H
#define GMAILHEADER_H

#include "Header.h"
#include <string>
using namespace std;

class GmailHeader:public Header{
private:
	string DeliveredTo;
	string XGoogle;
	string FromReply;
	string Unsubscribe;
	string MIME;
	string alternative;
	string textplain;
	string Transfer;

public:

	GmailHeader(const string date, const string RB, const string RF, const string From, const string To, const string subject, const string MID, const string reply,
			const string DT, const string XGoogle, const string FromReply, const string Unsub, const string MIME, const string alternative, const string textplain, const string Transfer);

string getDeliveredTo() const;
string getXGoogle() const;
string getFromReply() const;
string getUnsubscribe() const;
string getMIME() const;
string getalternative() const;
string gettextplain() const;
string getTransfer() const;

void setDeliveredTo(const string& date);
void setXGoogle(const string& RB);
void setFromReply(const string& RF);
void setUnsubscribe(const string& From);
void setMIME(const string& CC);
void setalternative(const string& subject);
void settextplain(const string& MID);
void setTransfer(const string& reply);

};
#endif
