//============================================================================
// Name        : EmailInformationExtractor.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <algorithm>
#include "OutlookHeader.h"
#include "GmailHeader.h"
using namespace std;

OutlookHeader OH;
GmailHeader GH=new GmailHeader("empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty");

void qmatch(string part, int type){
	transform(part.begin(),part.end(),part.begin(), ::tolower);
	string temp;
	bool print=false;
	if(type==2){
		temp=GH.getDeliveredTo();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<GH.getDeliveredTo();
			print=true;
		}
		temp=GH.getRecievedBy();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
					cout<<GH.getRecievedBy();
					print=true;
				}
		temp=GH.getXGoogle();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
					cout<<GH.getXGoogle();
					print=true;
				}
		temp=GH.getRecievedFrom();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
					cout<<GH.getRecievedFrom();
					print=true;
				}
		temp=GH.getUnsubscribe();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
					cout<<GH.getUnsubscribe();
					print=true;
				}
		temp=GH.getDate();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getDate();
							print=true;
						}
		temp=GH.getFrom();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getFrom();
							print=true;
						}
		temp=GH.getReply();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getReply();
							print=true;
						}
		temp=GH.getTo();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getTo();
							print=true;
						}
		temp=GH.getMessageID();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getMessageID();
							print=true;
						}
		temp=GH.getSubject();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getSubject();
							print=true;
						}
		temp=GH.getMIME();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getMIME();
							print=true;
						}
		temp=GH.getalternative();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
							cout<<GH.getalternative();
							print=true;
						}
		temp=GH.gettextplain();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
				if(temp.find(part)!=string::npos){
									cout<<GH.gettextplain();
									print=true;
								}
				temp=GH.getTransfer();
				transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
						if(temp.find(part)!=string::npos){
											cout<<GH.getTransfer();
											print=true;
										}
	}
	else{
		temp=OH.getRecievedBy();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getRecievedBy();
			print=true;
		}
		temp=OH.getAuthentication();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getAuthentication();
			print=true;
		}
		temp=OH.getRecievedFrom();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getRecievedFrom();
			print=true;
		}
		temp=OH.getApplication();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getApplication();
			print=true;
		}
		temp=OH.getTransfer();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getTransfer();
			print=true;
		}
		temp=OH.getFrom();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getFrom();
			print=true;
		}
		temp=OH.getTo();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getTo();
			print=true;
		}
		temp=OH.getCC();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getCC();
			print=true;
		}
		temp=OH.getSubject();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getSubject();
			print=true;
		}
		temp=OH.getTopic();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getTopic();
			print=true;
		}
		temp=OH.getIndex();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getIndex();
			print=true;
		}
		temp=OH.getDate();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getDate();
			print=true;
		}
		temp=OH.getMessageID();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getMessageID();
			print=true;
		}
		temp=OH.getReferences();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getReferences();
			print=true;
		}
		temp=OH.getReply();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getReply();
			print=true;
		}
		temp=OH.getAcceptLang();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getAcceptLang();
			print=true;
		}
		temp=OH.getContentLang();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getContentLang();
			print=true;
		}
		temp=OH.getAttach();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getAttach();
			print=true;
		}
		temp=OH.getExchange();
		transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
		if(temp.find(part)!=string::npos){
			cout<<OH.getExchange();
			print=true;
		}

	}

	if(!print){
		cout<<"I'm sorry I couldn't find that part, please try rephrasing";
	}

}

void readGmail(string header){
	istringstream digest(header);
	string line;
	vector<string> lines;

	while(getline(digest,line)){
		lines.push_back(line);
	}

	regex Delivered("Delivered-To:");
	regex RecievedB("Received: by");
	regex XG("X-Google");
	regex RecievedF("Received: from");
	regex From("From:");
	regex Type("Content-Type:");
	regex Date("Date:");
	regex Reply("Reply-To:");
	regex To("To:");
	regex MID("^Message-ID:");
	regex Subject("Subject:");
	regex MIME("MIME-Version:");
	regex Transfer("Content-Transfer");

	string DeliveredTo;
	string RB;
	string XGoogle;
	string RF;
	string FromReply;
	string Unsub;
	string alternative;
	string plain;
	string mime;
	string transfer;
	string date;
	string from;
	string to;
	string subject;
	string MessageID;
	string reply;

	for(int i=0; !lines[i].empty();i++){
		smatch match;
		if(regex_search(lines[i],match,Delivered)){
			DeliveredTo=lines[i];
		}
		else if(regex_search(lines[i],match,RecievedB)){
			RB=lines[i];
		}
		else if(regex_search(lines[i],match,RecievedF)){
					RF=lines[i];
				}
		else if(regex_search(lines[i],match,XG)){
			XGoogle=lines[i];
		}
		else if(regex_search(lines[i],match,From)){
			from=lines[i];
		}
		else if(regex_search(lines[i],match,Type)){
			if(date.empty()){
				Unsub=lines[i];
			}
			else if(alternative.empty()){
				alternative=lines[i];
			}
			else{
				plain=lines[i];
			}
		}
		else if(regex_search(lines[i],match,Date)){
			date=lines[i];
		}
		else if(regex_search(lines[i],match,Reply)){
			reply=lines[i];
		}
		else if(regex_search(lines[i],match,To)){
			to=lines[i];
		}
		else if(regex_search(lines[i],match,MID)){
			MessageID=lines[i];
		}
		else if(regex_search(lines[i],match,Subject)){
			subject=lines[i];
		}
		else if(regex_search(lines[i],match,MIME)){
			mime=lines[i];
		}
		else if(regex_search(lines[i],match,Transfer)){
			transfer=lines[i];
		}
	}

	GH = new GmailHeader(date, RB, RF, from, to, subject, MessageID, reply, DeliveredTo, XGoogle, FromReply, Unsub, mime, alternative, plain, transfer);
}

void readMicro(string header){
	istringstream digest(header);
	string line;
	vector<string> lines;

	while(getline(digest,line)){
		lines.push_back(line);
	}

		regex RecievedB("Received: from");
		regex Authentication("Authentication-Results:");
		regex RecievedF("Received: from");
		regex From("From:");
		regex Type("Content-Type:");
		regex Date("Date:");
		regex Reply("Reply-To:");
		regex To("To:");
		regex MID("Message-ID:");
		regex Subject("Subject:");
		regex Topic("-Topic:");
		regex Index("-Index:");
		regex Transfer("Content-Transfer");
		regex CC("CC:");
		regex References("References:");
		regex Accept("Accept-Language:");
		regex Content("Content-Languange:");
		regex Attach("X-MS-Has-Attach:");
		regex Exchange("X-MS-Exchange-Organization-SCL:");

		string date;
		string ReceivedBy;
		string ReceivedFrom;
		string from;
		string subject;
		string MessageID;
		string reply;
		string to;
		string cc;
		string accept;
		string references;
		string content;
		string type;
		string index;
		string topic;
		string attach;
		string exchange;
		string transfer;
		string A;

		for(int i=0; !lines[i].empty();i++){
			smatch match;

			if(regex_search(lines[i],match,RecievedB)){
				ReceivedBy=lines[i];
			}
			else if(regex_search(lines[i],match,RecievedF)){
						ReceivedFrom=lines[i];
					}
			else if(regex_search(lines[i],match,Authentication)){
				A=lines[i];
			}
			else if(regex_search(lines[i],match,From)){
				from=lines[i];
			}
			else if(regex_search(lines[i],match,Type)){
				type=lines[i];
			}
			else if(regex_search(lines[i],match,Date)){
				date=lines[i];
			}
			else if(regex_search(lines[i],match,Reply)){
				reply=lines[i];
			}
			else if(regex_search(lines[i],match,To)){
				to=lines[i];
			}
			else if(regex_search(lines[i],match,MID)){
				MessageID=lines[i];
			}
			else if(regex_search(lines[i],match,Subject)){
				subject=lines[i];
			}
			else if(regex_search(lines[i],match,Index)){
				index=lines[i];
			}
			else if(regex_search(lines[i],match,CC)){
							cc=lines[i];
						}
			else if(regex_search(lines[i],match,Topic)){
							topic=lines[i];
						}
			else if(regex_search(lines[i],match,Content)){
							content=lines[i];
						}
			else if(regex_search(lines[i],match,Transfer)){
				transfer=lines[i];
			}
			else if(regex_search(lines[i],match,Attach)){
							attach=lines[i];
						}
			else if(regex_search(lines[i],match,Exchange)){
							exchange=lines[i];
						}
			else if(regex_search(lines[i],match,References)){
							references=lines[i];
						}
			else if(regex_search(lines[i],match,Accept)){
							accept=lines[i];
						}
		}

		OH= new OutlookHeader(date, ReceivedBy, ReceivedFrom, from, to, subject, MessageID, reply, A, type, transfer, topic, index, references, accept, content, attach, exchange,cc);
}

int main() {
	bool again=true;
	string header;
	int type;
	int quit;
	string part;

	cout<<"Please enter an email header";
	cin>>header;

	cout<<"Is this a (1) Microsoft Outlook or (2)Gmail header?";
	cin>>type;

	if(type==1){
		readMicro(header);
	}
	else if(type==2){
		readGmail(header);
	}
	else{
		cout<<"Assuming Outlook";
		readMicro(header);
	}

	while(again){
		cout<<"What part would you like to know?";
		cin>>part;

		qmatch(part,type);

		cout<<"Would you like to know another part? (1)Yes (2)No";
		cin>>quit;
		if(quit!=1){
			again=false;
			cout<<"Goodbye";
		}
	}

	return 0;
}
