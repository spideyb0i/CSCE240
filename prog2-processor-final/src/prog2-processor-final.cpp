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
#include "LinkedList.h"
#include "Item.h"
#include "Node.h"

using namespace std;
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

void processFileItem(const string& filename,const string& basefile) {
	ifstream file(filename);
	    if (!file.is_open()) {
	        std::cerr << "Error opening file.\n";
	        return;
	    }
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

	    // Read and print each line of the file
	    std::string line;
	    while (std::getline(inputFile, line)) {
	        std::cout << line << std::endl;
	    }

	    // Close the file
	    inputFile.close();
}

void printInfo(string filename, Node* node) {
    regex pattern("^Item\\s+(1?[0-9])([a-zA-Z])?");
    ifstream inputFile(filename);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return;
    }

    string line;
    bool print = false;
    while (getline(inputFile, line)) {
        smatch match;
        if (print) {
            cout << line << endl;
        }
        if (regex_search(line, match, pattern)) {
            string temp=line+".";
            if(temp==node->getValue().getTitle()){
            	print=true;
            }
            if(temp==node->getNext()->getValue().getTitle())
            	print=false;

        }
    }

    // Close the file
    inputFile.close();
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
	cout<<"Which item would you like to learn about (please enter it in this format 'Item 1A'?\nType 'list' to see item list\nType 'change' to switch companies\nType 'quit' to end session"<<endl;
	Node* temp=myList.getHead();
	temp->setValue(myList.getHead()->getValue());
	string choice;
	cin>>choice;
	smatch match;
	if(choice=="list"){
		myList.display();
		return 0;
	}
	bool found=false;
	if(choice=="everything"||choice=="Everything"||choice=="all information"||choice=="all"){
		found=true;
		printAll(filename);
	}
	if(choice=="quit"||choice=="End"||choice=="Quit"){
			return -1;
		}
	if(choice=="switch"||choice=="change")
		return -2;
	while(temp->getNext()!=nullptr)
	{
		if(choice.find(temp->getValue().getTitle())){
			printInfo(filename,temp);
		}
		temp=temp->getNext();
	}
	if(!found){
		cout<<"I'm sorry please try rephrasing"<<endl;
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
