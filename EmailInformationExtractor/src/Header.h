#ifndef HEADER_H
#define HEADER_H

#include <string>
using namespace std;

class Header{
private:
	string Date;
	string ReceivedBy;
	string ReceivedFrom;
	string From;
	string Subject;
	string MessageID;
	string Reply;
	string To;

public:
	Header(const string date, const string RB, const string RF, const string From, const string subject, const string MID, const string reply, const string to);

string getDate() const;
string getRecievedBy() const;
string getRecievedFrom() const;
string getFrom() const;
string getSubject() const;
string getMessageID() const;
string getReply() const;
string getTo() const;

void setDate(const string& date);
void setReceivedBy(const string& RB);
void setReceivedFrom(const string& RF);
void setFrom(const string& From);
void setSubject(const string& subject);
void setMID(const string& MID);
void setReply(const string& reply);
void setTo(const string& to);

};
#endif
