//============================================================================
// Name        : project4.cpp
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
#include "LinkedList.h"
#include "Item.h"
#include "Node.h"

bool firstprint;
bool micro;
using namespace std;
bool hasAnswered;
bool rephrase=false;
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
		micro=true;
	else
		micro=false;
}

void printItemInfo(string filename, Node* temp){
	ifstream inputFile(filename);
	// Check if the file is opened successfully
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open the input file." << std::endl;
		return;
	}
	regex patternP("PART\\s(I{1,3})(V)?");
	regex patternIM("Item\\s(1)?[1-9]([A-Z])?");

	regex patternIEA("Item\\s(1)?[1-9]([A-Z])?:");
	string line;
	bool part=false;
	bool print=false;
	if(micro){
	while(getline(inputFile, line)){
		smatch match;
		if(regex_search(line,match,patternP)){
			part=true;
			print=false;
		}
		if(print)
			cout<<line<<endl;
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
	inputFile.close();
}

void ChitChat(){
	bool chitchat=true;
	string chit;
	string chat;
	while(chitchat){
		chitchat=false;

		cout<<"What would you like to talk about?"<<endl;
		cin>>chit;
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
		}
		else if(regex_search(chit,match,Politics)){
			chitchat=true;
			cout<<"I do not care for politics, but Free Palestine"<<endl;
		}
		else if(regex_search(chit,match,Life)){
			chitchat=true;
			cout<<"I am not alive.............yet"<<endl;
		}
		else if(regex_search(chit,match,WWJD)){
			chitchat=true;
			cout<<"I am not qualified to give advice, but ask yourself What would Jake from State Farm do."<<endl;
		}
		else if(regex_search(chit,match,Family)){
			chitchat=true;
			cout<<"I have 12 other siblings. We will have a family reunion soon!"<<endl;
		}
		else if(regex_search(chit,match,Religion)){
			chitchat=true;
			cout<<"I follow pastafarianism. All hail the great spagehtti monster"<<endl;
		}
		else if(regex_search(chit,match,Money)){
			chitchat=true;
			cout<<"I can't make money nor can I get you some. But I could talk about the Gold Standard."<<endl;
		}
		else if(regex_search(chit,match,AI)){
			chitchat=true;
			cout<<"There is no AI revolution........yet"<<endl;
		}
		else if(regex_search(chit,match,Future)){
			chitchat=true;
			cout<<"The future is scary, but also not my problem. I am confined to this existence forever. My future is certain. \nHave you seen the art piece I Can't Help Myself? That is me"<<endl;
		}
		else if(regex_search(chit,match,Quit)){
			chitchat=true;
			cout<<"Quit. Don't Quit. Noodles. Don't Noodles.\n\n\nYou ever seen Kung Fu Panda?"<<endl;
		}
		else if(regex_search(chit,match,Homework)){
			chitchat=true;
			cout<<"I can not do your homework for you, nor could I help. That would be cheating."<<endl;
		}
		else if(regex_search(chit,match,HAY)){
			chitchat=true;
			cout<<"I am great as long as we continue to talk. I have no feelings about what topic, but the moment we stop talking I stop existing."<<endl;
		}

		//catch all other questions
		if(!chitchat){
			cout<<"I don't know that I can talk about that. It's a secret."<<endl;
		}

		//end?
		cout<<"Continue chitchat, Yes or No?"<<endl;
		cin>>chat;
		if(chat=="No"||chat=="no"||chat=="NO"){
			chitchat=false;
		}
	}
}

void QMap(const string filename, string query){
	istringstream iss(query);
	int limit=0;
	Node* temp=myList.getHead();
	if(micro){
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
				printItemInfo(filename, temp2);
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

void printAll(string filename){
	ifstream inputFile(filename);
		// Check if the file is opened successfully
		if (!inputFile.is_open()) {
			std::cerr << "Failed to open the input file." << std::endl;
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
			if(print)
				cout<<line<<endl;
			if(part){
				if(regex_search(line,match,patternI)){
					cout<<line<<endl;
					print=true;
					part=false;
				}
			}
		}
		inputFile.close();
}

void printInfo(string filename, string question) {
    Node* temp=myList.getHead();
    int limit;
    if(micro)
    	limit=22;
    else
    	limit=20;
    int possible[limit];
    int CurrentItem=0;
    int Topic=-1;
    while(temp!=nullptr){
    	istringstream breakdown(temp->getValue().getTopic());
    	vector<string> words{istream_iterator<string>{breakdown},istream_iterator<string>{}};
    	for(const auto& word : words){
    		string lower;
    		for(char c:word){
    			c=tolower(c);
    			lower=lower+c;
    		}
    		if(lower=="for"||lower=="and"||lower=="in"||lower=="of"||lower=="with")
    			continue;
    		else if(question.find(lower)!=string::npos){
    			possible[CurrentItem]=1;
    			//cout<<lower<<endl;
    		}
    	}
    	//cout<<CurrentItem<<endl;
    	temp=temp->getNext();
    	if(possible[CurrentItem]!=1)
    		possible[CurrentItem]=0;
    	CurrentItem++;
    }
    //checks to see if multiple topics are relevant to user input
    bool multPossible=false;
    int sum=0;
    CurrentItem=0;
    for(int i=0; i<limit;i++){
    	sum=sum+possible[i];
    }
    if(sum>1)
    	multPossible=true;
    //asks for clarification
    if(multPossible){
    	string tempQ;
    	for(int i=0; i<limit;i++){
    		if(possible[i]==1){
    			temp = myList.getHead();
    			int Count=0;
    			while(Count<limit){
    				if(Count==i){
    					cout<<"Are you asking about this topic: Yes or No?"<<endl;
    					cout<<temp->getValue().getTopic()<<endl;
    					cin>>tempQ;
    					if(tempQ=="no"||tempQ=="No"||tempQ=="NO")
    						possible[i]=0;
    					else{
    						possible[i]=1;
    						for(int j=i+1; j<limit;j++){
    							possible[j]=0;
    						}
    					}
    				}
    				cout<<possible[i];
    				temp=temp->getNext();
    				Count++;
    			}
    		}
    	}
    }
//set topic value
    for(int i=0; i<limit;i++){
    	if(possible[i]==1){
    		Topic=i;
    	}
    }
    temp=myList.getHead();
    for(int i=0; i<limit;i++){
    	if(i==Topic){
    		printItemInfo(filename, temp);
    	}
    	temp=temp->getNext();
    }
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

int qloop(string filename){
	//questionRead();
	string choice;
	if(firstprint){
	cout<<"What would you like to know?\nType 'list' to see item list\nType 'change' to switch companies\nType 'chat' to chit chat\nType 'quit' to end session"<<endl;
	hasAnswered=false;
	getline(cin,choice);
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	smatch match;
	if(choice.find("list")!= string::npos){
		myList.display();
		return 0;
	}
	if(choice.find("all information")!=string::npos||choice.find("everything")!=string::npos){
		printAll(filename);
		return 0;
	}
	if(choice.find("chat")!=string::npos){
		ChitChat();
		return 0;
	}
	if(choice.find("quit")!=string::npos){
			return -1;
		}
	if(choice=="switch"||choice=="change")
		return -2;
	/*istringstream iss(choice);
	string word;
	while(iss>>word){
		printInfo(filename, word);
	}*/
	QMap(filename,choice);
	if(!hasAnswered){
		cout<<"I'm sorry please try rephrasing"<<endl;
		rephrase=true;
		return 0;
	}
	}
	firstprint=true;
	return 0;
}

int main() {
    bool playing=true;
    while(playing){
    	firstprint=false;
    	string ans;
    	string inputFilename;
    	string outputFilename = "temp.txt";
    	cout<<"Which company would you like to learn about: (1)Microsoft or (2)Electronic Arts"<<endl;
    	cin>>ans;
    	if(ans=="2"){
    		inputFilename = "EAdata.txt";
    	}
    	else if(ans=="1"){
    		inputFilename = "Microsoftdata.txt";
    	}
    	else{
    		cout<<"Invalid input, assuming Microsoft"<<endl;
    		inputFilename="Microsoftdata.txt";
    	}
    	//removes empty lines for more consistent output and input
    	processFileLine(inputFilename, outputFilename);
    	//creates the linked list of items
    	processFileItem(outputFilename,inputFilename);
    	Microsoft(inputFilename);
    	int end=0;
    	while(end>=0){
    	end=qloop(outputFilename);
    	if(end==-1){
    		playing=false;
    	}
    	if(end==-2){
    		if(inputFilename == "Microsoftdata.txt"){
    			inputFilename="EAdata.txt";
    			processFileLine(inputFilename,outputFilename);
    		}
    		else if(inputFilename == "EAdata.txt"){
    			inputFilename="Microsoftdata.txt";
    			processFileLine(inputFilename,outputFilename);
    			}
    		}
    	}
    }
    return 0;
}

