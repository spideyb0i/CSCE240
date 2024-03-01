//============================================================================
// Name        : prog2-processor-final.cpp
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

bool micro;
using namespace std;
bool hasAnswered;
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

void printItemInfo(string filename, Node* temp){
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
			if(regex_search(line,match,patternI)&&line.find(temp->getValue().getTopic())!=string::npos){
				cout<<line<<endl;
				print=true;
				part=false;
			}
		}
	}
	inputFile.close();
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
    					else
    						Count=limit;
    				}
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
	cout<<"What would you like to know?\nType 'list' to see item list\nType 'change' to switch companies\nType 'quit' to end session"<<endl;
	hasAnswered=false;
	string choice;
	cin>>choice;
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	smatch match;
	if(choice.find("list")!= string::npos){
		myList.display();
		return 0;
	}
	if(choice.find("all information")!=string::npos){
		printAll(filename);
		return 0;
	}
	if(choice.find("quit")!=string::npos){
			return -1;
		}
	if(choice=="switch"||choice=="change")
		return -2;
	printInfo(filename, choice);
	if(!hasAnswered){
		cout<<"I'm sorry please try rephrasing"<<endl;
		return 0;
	}
	return 0;
}

int main() {
    bool playing=true;
    while(playing){
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
