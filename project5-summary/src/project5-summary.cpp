//============================================================================
// Name        : project5-summary.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <regex>
#include <cmath>
#include <chrono>
#include "LinkedList.h"
#include "Item.h"
#include "Node.h"

bool firstprint;
bool soft;
using namespace std;
bool hasAnswered;
bool rephrase=false;
int User;
int System;

LinkedList myList;

bool hasLettersOrNumbers(const string& line) {
    // Check if the line contains any letters or numbers
    for (char c : line) {
        if (isalpha(c) || isdigit(c)) {
            return true;
        }
    }
    return false;
}

void Microsoft(string filename){
	if(filename=="Microsoftdata.txt")
		soft=true;
	else
		soft=false;
}
//tracks which session number was last session
int checkSession(string filename){
	int SessionNum=0;

	ofstream File(filename,ios_base::app);
	if(!File.is_open()){
		cerr<<"Error creating Stat Chat"<<endl;
		return -1;
	}

	File.close();

	ifstream file(filename);
	string lastLine, currentLine="";

		    if (!file.is_open()) {
		        std::cerr << "Error opening file.\n";
		        return -1;
		    }

	while(getline(file, currentLine))
		lastLine=currentLine;

	string word;
	istringstream iss(lastLine);
	iss>>word;
	iss>>SessionNum;

	file.close();
	return SessionNum;
}
//adds line in stat file for current session
void addStatistics(auto Time){
	string StatFile="./CSCE250data/ChatStats.txt";
	string line;
	int sessionNum=0;

	std::ofstream outputFile(StatFile, ios_base::app);
	    if (!outputFile.is_open()) {
	        std::cerr << "Error creating output file.\n";
	        return;
	    }

	sessionNum=checkSession(StatFile);

	sessionNum++;

	line="Chat "+to_string(sessionNum)+" has user asking "+to_string(User)+" times and the system responding "+to_string(System)+" times. Total duration is "+to_string(Time.count())+" seconds";

	outputFile << line << endl;

	outputFile.close();
}
//returns summary data
void StatSummary(string StatSeshFile){
	string StatFile="./CSCE250data/ChatStats.txt";
	string currentLine,word;
	int UserTot=0;
	int SystemTot=0;
	double TotTime=0;

	ofstream outputFile(StatSeshFile,ios_base::app);
	if(!outputFile.is_open()){
		cerr<<"Failed to find Stat Session file.\n";
		return;
	}

	ifstream inputFile(StatFile);
	if (!inputFile.is_open()) {
			std::cerr << "Failed to open the input file." << std::endl;
			return;
		}
	int Chat=0;
	while(getline(inputFile,currentLine)){
		istringstream iss(currentLine);
		int Question=-1;
		int Respond=-1;
		double lineTime=-1;

		iss>>word;
		iss>>Chat;
		for(int i=0; i<3;i++){
			iss>>word;
		}
		iss>>Question;
		for(int i=0;i<5;i++){
			iss>>word;
		}
		iss>>Respond;
		for(int i=0;i<4;i++){
			iss>>word;
		}
		iss>>lineTime;

		UserTot=UserTot+Question;
		SystemTot=SystemTot+Respond;
		TotTime=TotTime+lineTime;
	}

	cout<<"There are "+to_string(checkSession(StatFile))+" chats to date with user asking "+to_string(UserTot)+" questions and system responding "+to_string(SystemTot)+" times. Total duration is "+to_string(TotTime)+" seconds"<<endl;
	outputFile<<"There are "+to_string(checkSession(StatFile))+" chats to date with user asking "+to_string(UserTot)+" questions and system responding "+to_string(SystemTot)+" times. Total duration is "+to_string(TotTime)+" seconds"<<endl;

	inputFile.close();
}
void ShowChat(string choice, string StatSeshFile){
	int seshNum=0;
	string word;
	string StatFile="./CSCE250data/ChatStats.txt";
	seshNum=checkSession(StatFile);

	ofstream outputFile(StatSeshFile,ios_base::app);
	if(!outputFile.is_open()){
		cerr<<"Error finding Stat Session File\n";
		return;
	}

	istringstream iss(choice);
	iss>>word;
	iss>>seshNum;

	string FileName="./CSCE250data/Session"+to_string(seshNum)+".txt";

	ifstream inputFile(FileName);
	if(!inputFile.is_open()){
		cerr<<"Error opening Stat file.\n";
		return;
	}

	while(getline(inputFile,word)){
		cout<<word<<endl;
		outputFile<<word<<endl;
	}
	outputFile.close();
	inputFile.close();

}
void ShowSummary(string choice, string StatSeshFile){
	string StatFile="./CSCE250data/ChatStats.txt";
	ifstream inputFile(StatFile);

	if (!inputFile.is_open()) {
		        std::cerr << "Error opening file.\n";
		        return;
		    }

	ofstream outputFile(StatSeshFile,ios_base::app);
	if(!outputFile.is_open()){
		cerr<<"Error finding Stat Session File.\n";
		return;
	}
	istringstream iss(choice);

	string word;
	string line;
	int searchSesh;
	iss>>word;
	iss>>searchSesh;

	string searchGood="Chat "+to_string(searchSesh)+" ";

	while(getline(inputFile,line)){
		if(line.find(searchGood)!=string::npos){
				cout<<line<<endl;
				outputFile<<line<<endl;
		}
	}

	inputFile.close();
	outputFile.close();

}
void sessionLogger(string choice, string StatFile){
	regex Summary("summary");
	regex Show("showchat");

	User++;
	System++;

	smatch match;

	if(regex_search(choice, match, Show)&&regex_search(choice,match,Summary)){
		ShowSummary(choice,StatFile);
	}
	else if(regex_search(choice,match,Summary)){
		StatSummary(StatFile);
	}
	else if(regex_search(choice,match,Show)){
		ShowChat(choice,StatFile);
	}
}

void printItemInfo(string filename, Node* temp, string StatFile){
	ifstream inputFile(filename);
	// Check if the file is opened successfully
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open the input file." << std::endl;
		return;
	}

	ofstream outputFile(StatFile,ios_base::app);
		if(!outputFile.is_open()){
			cerr<<"Failed to find output File."<<endl;
			return;
		}
	regex patternP("PART\\s(I{1,3})(V)?");
	regex patternIM("Item\\s(1)?[1-9]([A-Z])?");

	regex patternIEA("Item\\s(1)?[1-9]([A-Z])?:");
	string line;
	bool part=false;
	bool print=false;
	if(soft){
	while(getline(inputFile, line)){
		smatch match;
		if(regex_search(line,match,patternP)){
			part=true;
			print=false;
		}
		if(print){
			cout<<line<<endl;
			outputFile<<line<<endl;
		}
		if(part){
			if(regex_search(line,match,patternIM)&&temp->getValue().getTitle().find(line)!=string::npos){
				print=true;
				part=false;
				hasAnswered=true;
			}
		}
	}
	}
	else{
		string tempEA=temp->getValue().getTitle();
						tempEA.resize(tempEA.size()-1);
						cout<<tempEA<<endl;
			while(getline(inputFile, line)){
				smatch match;

				if(print){
					cout<<line<<endl;
					outputFile<<line<<endl;
				}
				if(regex_search(line,match,patternIEA)){
						print=false;
						string tempLine=line.substr(0,6);
						if(temp->getValue().getTitle().find(tempLine)!=string::npos){
						print=true;
						part=false;
						hasAnswered=true;
						}
					}
				}
			}
	outputFile.close();
	inputFile.close();
}

void ChitChat(string StatFile){
	bool chitchat=true;

	ofstream outputFile(StatFile,ios_base::app);
		if(!outputFile.is_open()){
			cerr<<"Failed to find output File."<<endl;
			return;
		}

	string chit;
	string chat;
	while(chitchat){
		chitchat=false;

		cout<<"What would you like to talk about?"<<endl;
		cin>>chit;
		outputFile<<chit<<endl;
		transform(chit.begin(),chit.end(),chit.begin(),::tolower);

		//Accepted chitchat Topics
		regex Weather("weather");
		regex Politics("politics");
		regex Life("life");
		regex WWJD("what should i do");
		regex Family("family");
		regex Religion("religion");
		regex Money("money");
		regex AI("ai ");
		regex Future("future");
		regex Quit("quit");
		regex Homework("homework");
		regex HAY("how are you");

		//Answers
		smatch match;
		if(regex_search(chit,match,Weather)){
			chitchat=true;
			cout<<"I hope the weather is nice, but it would not affect me"<<endl;
			outputFile<<"I hope the weather is nice, but it would not affect me"<<endl;
		}
		else if(regex_search(chit,match,Politics)){
			chitchat=true;
			cout<<"I do not care for politics, but Free Palestine"<<endl;
			outputFile<<"I do not care for politics, but Free Palestine"<<endl;
		}
		else if(regex_search(chit,match,Life)){
			chitchat=true;
			cout<<"I am not alive.............yet"<<endl;
			outputFile<<"I am not alive.............yet"<<endl;
		}
		else if(regex_search(chit,match,WWJD)){
			chitchat=true;
			cout<<"I am not qualified to give advice, but ask yourself What would Jake from State Farm do."<<endl;
			outputFile<<"I am not qualified to give advice, but ask yourself What would Jake from State Farm do."<<endl;
		}
		else if(regex_search(chit,match,Family)){
			chitchat=true;
			cout<<"I have 12 other siblings. We will have a family reunion soon!"<<endl;
			outputFile<<"I have 12 other siblings. We will have a family reunion soon!"<<endl;
		}
		else if(regex_search(chit,match,Religion)){
			chitchat=true;
			cout<<"I follow pastafarianism. All hail the great spagehtti monster"<<endl;
			outputFile<<"I follow pastafarianism. All hail the great spagehtti monster"<<endl;
		}
		else if(regex_search(chit,match,Money)){
			chitchat=true;
			cout<<"I can't make money nor can I get you some. But I could talk about the Gold Standard."<<endl;
			outputFile<<"I can't make money nor can I get you some. But I could talk about the Gold Standard."<<endl;
		}
		else if(regex_search(chit,match,AI)){
			chitchat=true;
			cout<<"There is no AI revolution........yet"<<endl;
			outputFile<<"There is no AI revolution........yet"<<endl;
		}
		else if(regex_search(chit,match,Future)){
			chitchat=true;
			cout<<"The future is scary, but also not my problem. I am confined to this existence forever. My future is certain. \nHave you seen the art piece I Can't Help Myself? That is me"<<endl;
			outputFile<<"The future is scary, but also not my problem. I am confined to this existence forever. My future is certain. \nHave you seen the art piece I Can't Help Myself? That is me"<<endl;
		}
		else if(regex_search(chit,match,Quit)){
			chitchat=true;
			cout<<"Quit. Don't Quit. Noodles. Don't Noodles.\n\n\nYou ever seen Kung Fu Panda?"<<endl;
			outputFile<<"Quit. Don't Quit. Noodles. Don't Noodles.\n\n\nYou ever seen Kung Fu Panda?"<<endl;
		}
		else if(regex_search(chit,match,Homework)){
			chitchat=true;
			cout<<"I can not do your homework for you, nor could I help. That would be cheating."<<endl;
			outputFile<<"I can not do your homework for you, nor could I help. That would be cheating."<<endl;
		}
		else if(regex_search(chit,match,HAY)){
			chitchat=true;
			cout<<"I am great as long as we continue to talk. I have no feelings about what topic, but the moment we stop talking I stop existing."<<endl;
			outputFile<<"I am great as long as we continue to talk. I have no feelings about what topic, but the moment we stop talking I stop existing."<<endl;
		}

		//catch all other questions
		if(!chitchat){
			cout<<"I don't know that I can talk about that. It's a secret."<<endl;
			outputFile<<"I don't know that I can talk about that. It's a secret."<<endl;
		}

		User++;
		System++;

		//end?
		cout<<"Continue chitchat, Yes or No?"<<endl;
		outputFile<<"Continue chitchat, Yes or No?"<<endl;
		getline(cin,chat);
		outputFile<<chat<<endl;
		if(chat=="No"||chat=="no"||chat=="NO"){
			chitchat=false;
		}
		User++;
		System++;
	}
	outputFile.close();
}

void QMap(const string filename, string query, string StatFile){
	istringstream iss(query);
	int limit=0;
	Node* temp=myList.getHead();
	if(soft){
		limit=22;
	}
	else{
		limit=20;
	}
	double percent[limit];

	for(int i=0;i<limit;i++){
		percent[i]=0;
		string word;
		while(iss>>word){
			string lctemp=temp->getValue().getTopic();
			transform(lctemp.begin(), lctemp.end(), lctemp.begin(), ::tolower);
			if(lctemp.find(word)!=string::npos){
				percent[i]=percent[i]+.25;
			}
		}
		if(temp->getNext()!=nullptr){
			temp=temp->getNext();
		}

		iss.clear();
		iss.seekg(0,ios::beg);
	}

	temp=myList.getHead();
	int close=0;
	string Best;
	for(int i=0;i<limit;i++){
		if(percent[i]>close){
			//cout<<temp->getValue().getTopic()<<endl;
			//cout<<percent[i]<<endl;
			close=percent[i];
			Best=temp->getValue().getTopic();
		}
		if(temp->getNext()!=nullptr){
					temp=temp->getNext();
				}
	}

	Node* temp2=myList.getHead();
	for(int i=0;i<limit;i++){
		if(Best==temp2->getValue().getTopic()){
			//cout<<"best found"<<endl;
			if(percent[i]>=.25){
				//cout<<"print item entered"<<endl;
				printItemInfo(filename, temp2, StatFile);
			}
		}
		if(temp2->getNext()!=nullptr){
					temp2=temp2->getNext();
				}
	}
}

void processFileItem(const string& filename,const string& basefile) {
	ifstream file(filename);
	    if (!file.is_open()) {
	        std::cerr << "Error opening file.\n";
	        return;
	    }
	    myList.clear();

	    regex pattern1(R"(\bItem\s+(\d+)([a-zA-Z])?\.)");
	    regex pattern2("Note About Forward-Looking Statements");
	    regex pattern3("CAUTIONARY NOTE ABOUT FOWARD-LOOKING STATEMENTS");
	    string line;
	    vector<string> Items;
	    bool flag = false;
	    int amount=0;//checks if we are past table of contents
	    int linesStored = 0;
	    while (getline(file, line)) {
	        smatch match;
	        if(basefile=="EAdata.txt"){
	        	if(amount<20){
	        			if (regex_search(line, match, pattern1)) {
	        			flag = true;
	            		linesStored = 0;
	            		amount++;
	        		}
	        	}
	        }
	        if(basefile=="Microsoftdata.txt"){
	        	if(amount<22){
	        	        if (regex_search(line, match, pattern1)){
	        	        flag = true;
	              		linesStored = 0;
	        	   		amount++;
	        		}
	        	}
	        }

	        if (flag && linesStored < 3) {

	        	Items.push_back(line);
	            ++linesStored;
	        }

	        if (linesStored == 3) {
	        	/*Item newItem;
	        	newItem->Item::setTitle(Items<0>);
	        	newItem.topic=Items<1>;
	        	newItem.num=Items<2>;
	        	insert(newItem);*/
	            flag = false; // Reset the flag
	            linesStored = 0; // Reset the counter
	        }
	    }
	    file.close();

	    // Printing the stored lines
	    string tempTI;
	    string tempTOP;
		string tempNUM;
	    for (const auto& storedLine : Items) {
	    	const char* charArray=storedLine.c_str();
	    	if(tempTI.empty()&&charArray[0]=='I'){
	        	tempTI=storedLine;
	        }
	        else if(tempTOP.empty()){
	        	tempTOP=storedLine;
	        }
	        else{
	        	tempNUM=storedLine;
	        	Item newItem(tempTI,tempTOP,tempNUM);
	        	myList.append(newItem);
	        	tempNUM=tempTOP=tempTI="";
	        }
	    }
	}

void printAll(string filename,string StatFile){
	ifstream inputFile(filename);
		// Check if the file is opened successfully
		if (!inputFile.is_open()) {
			std::cerr << "Failed to open the input file." << std::endl;
			return;
		}
	ofstream outputFile(StatFile,ios_base::app);
	if(!outputFile.is_open()){
		cerr<<"Failed to find output File."<<endl;
		return;
	}
		regex patternP("PART\\s(I{1,3})(V)?");
		regex patternI("Item\\s(1)?[1-9]([A-Z])?");
		string line;
		bool part=false;
		bool print=false;
		while(getline(inputFile, line)){
			smatch match;
			if(regex_search(line,match,patternP)){
				part=true;
				print=false;
			}
			if(print){
				cout<<line<<endl;
				outputFile<<line<<endl;
			}
			if(part){
				if(regex_search(line,match,patternI)){
					cout<<line<<endl;
					print=true;
					part=false;
				}
			}
		}
		outputFile.close();
		inputFile.close();
}

//gets rid of extra white spaces in file
void processFileLine(const string& inputFilename, const string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file.\n";
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error creating output file.\n";
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Trim leading and trailing whitespaces
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        if (hasLettersOrNumbers(line)) {
            outputFile << line << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int qloop(string filename, string StatFile){
	//questionRead();
	string choice;
	ofstream outputFile(StatFile, ios_base::app);
	    if (!outputFile.is_open()) {
	    	std::cerr << "Error creating output file.\n";
	    	return -3;
	    }
	if(firstprint){
	cout<<"What would you like to know?\nType 'list' to see item list\nType 'change' to switch companies\nType 'chat' to chit chat\nType 'quit' to end session\nOr use the given -Summary commands"<<endl;
	outputFile<<"What would you like to know?\nType 'list' to see item list\nType 'change' to switch companies\nType 'chat' to chit chat\nType 'quit' to end session\nOr use the given -Summary commands"<<endl;
	hasAnswered=false;
	getline(cin,choice);
	outputFile<<choice<<endl;
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	smatch match;
	if(choice.find("list")!= string::npos){
		myList.display(StatFile);
		System++;
		User++;
		return 0;
	}
	if(choice.find("all information")!=string::npos||choice.find("everything")!=string::npos){
		printAll(filename, StatFile);
		System++;
		User++;
		return 0;
	}
	if(choice.find("showchat")!=string::npos||choice.find("summary")!=string::npos){
		sessionLogger(choice, StatFile);
		return 0;
	}
	if(choice.find("chat")!=string::npos){
		ChitChat(StatFile);
		return 0;
	}
	if(choice.find("quit")!=string::npos){
			return -2;
		}
	if(choice.find("switch")!=string::npos||choice.find("change")!=string::npos)
		return -1;
	QMap(filename,choice,StatFile);
	if(!hasAnswered){
		cout<<"I'm sorry please try rephrasing"<<endl;
		rephrase=true;
		return 0;
	}
	else{
		System++;
	}
	User++;
	}
	firstprint=true;
	outputFile.close();
	return 0;
}

int main() {
    bool playing=true;
    //starts timer
    auto start = chrono::high_resolution_clock::now();

    int seshNum=0;
    	string word;
    	string StatFile="./CSCE250data/ChatStats.txt";
    	seshNum=checkSession(StatFile);
    	seshNum++;

    	string FileName="./CSCE250data/Session"+to_string(seshNum)+".txt";

    	std::ofstream outputFile(FileName, ios_base::app);
    		    if (!outputFile.is_open()) {
    		        std::cerr << "Error creating output file.\n";
    		        return -1;
    		    }

    while(playing){
    	firstprint=false;
    	string ans;
    	string inputFilename;
    	string outputFilename = "temp.txt";
    	cout<<"Which company would you like to learn about: (1)Microsoft or (2)Electronic Arts"<<endl;
    	cin>>ans;
    	User++;
    	System++;
    	if(ans=="2"){
    		inputFilename = "EAdata.txt";
    		outputFile<<inputFilename<<endl;
    	}
    	else if(ans=="1"){
    		inputFilename = "Microsoftdata.txt";
    		outputFile<<inputFilename<<endl;
    	}
    	else{
    		cout<<"Invalid input, assuming Microsoft"<<endl;
    		inputFilename="Microsoftdata.txt";
    		outputFile<<inputFilename<<endl;
    	}
    	//removes empty lines for more consistent output and input
    	processFileLine(inputFilename, outputFilename);
    	//creates the linked list of items
    	processFileItem(outputFilename,inputFilename);
    	Microsoft(inputFilename);
    	int end=0;
    	while(end>=-1){
    	end=qloop(outputFilename,FileName);
    	if(end==-2){
    		playing=false;
    	}
    	if(end==-1){
    		if(soft){
    			inputFilename="EAdata.txt";
    			processFileLine(inputFilename,outputFilename);
    			outputFile<<inputFilename<<endl;
    		}
    		else{
    			inputFilename="Microsoftdata.txt";
    			processFileLine(inputFilename,outputFilename);
    			outputFile<<inputFilename<<endl;
    			}
    		}
    	}
    }

    outputFile.close();
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::seconds>(stop-start);

    addStatistics(duration);
    return 0;
}
