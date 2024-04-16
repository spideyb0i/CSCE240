//============================================================================
// Name        : Code.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


//for p4 statfile is simply used for statistics in my code, likely can be deleted for your code
void QMap(const string filename, string query, string StatFile){
	//string stream
	istringstream iss(query);
	int limit=0;
	//resets linked list, is where you would need to assign question values
	Node* temp=myList.getHead();
	//checks which company is being asked about cause that changes array size
	if(soft){
		limit=22;
	}
	else{
		limit=20;
	}
	//creates question percent
	double percent[limit];
//checks for match of each word, need to change Node temp to string array
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
//for me this stores the item with the highest value by moving down the percent array and item list at the same time
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
//checks to make sure a value was given and at least two words matched
	Node* temp2=myList.getHead();
	for(int i=0;i<limit;i++){
		if(Best==temp2->getValue().getTopic()){
			//cout<<"best found"<<endl;
			if(percent[i]>.25){
				//cout<<"print item entered"<<endl;
				printItemInfo(filename, temp2, StatFile);
			}
		}
		if(temp2->getNext()!=nullptr){
					temp2=temp2->getNext();
				}
	}
}


//p5 in total you could pick and choose

//this checks the last session number that was stored
int checkSession(string filename){
	int SessionNum=0;
//creates input file reader and creates empty strings
	ifstream file(filename);
	string lastLine, currentLine="";

		    if (!file.is_open()) {
		        std::cerr << "Error opening file.\n";
		        return -1;
		    }
//I am not sure this is necessary but it made sense at the time
	while(getline(file, currentLine))
		lastLine=currentLine;
//my lines are stored in the exact layout of the example output so this code makes word = Chat and then SessionNum is the session number
	string word;
	istringstream iss(lastLine);
	iss>>word;
	iss>>SessionNum;

	file.close();
	return SessionNum;
}

//adds line in stat file for current session
void addStatistics(auto Time){
	string StatFile="./CSCE240data/ChatStats.txt";
	string line;
	int sessionNum=0;

	std::ofstream outputFile(StatFile, ios_base::app);
	    if (!outputFile.is_open()) {
	        std::cerr << "Error creating output file.\n";
	        return;
	    }

	sessionNum=checkSession(StatFile);

	sessionNum++;
	//Set up for statistics in file, you may have to change Time depending on how you are tracking time stats, i used chrono auto start stop duration method
	line="Chat "+to_string(sessionNum)+" has user asking "+to_string(User)+" times and the system responding "+to_string(System)+" times. Total duration is "+to_string(Time.count())+" seconds";

	outputFile << line << endl;

	outputFile.close();
}

//returns summary data
void StatSummary(string StatSeshFile){
	string StatFile="./CSCE240data/ChatStats.txt";
	string currentLine,word;
	int UserTot=0;
	int SystemTot=0;
	double TotTime=0;
//output to specific session file that stores all interactions
	ofstream outputFile(StatSeshFile,ios_base::app);
	if(!outputFile.is_open()){
		cerr<<"Failed to find Stat Session file.\n";
		return;
	}
//input of statistics file
	ifstream inputFile(StatFile);
	if (!inputFile.is_open()) {
			std::cerr << "Failed to open the input file." << std::endl;
			return;
		}
	//reads the file and totals all numbers, layout needs to be matched in string for this to work
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
//prints to console and to specific session file
	cout<<"There are "+to_string(checkSession(StatFile))+" chats to date with user asking "+to_string(UserTot)+" questions and system responding "+to_string(SystemTot)+" times. Total duration is "+to_string(TotTime)+" seconds"<<endl;
	outputFile<<"There are "+to_string(checkSession(StatFile))+" chats to date with user asking "+to_string(UserTot)+" questions and system responding "+to_string(SystemTot)+" times. Total duration is "+to_string(TotTime)+" seconds"<<endl;

	inputFile.close();
	outputFile.close();
}
//shows session specific chat and all interactions
void ShowChat(string choice, string StatSeshFile){
	int seshNum=0;
	string word;
	string StatFile="./CSCE240data/ChatStats.txt";
	seshNum=checkSession(StatFile);

	ofstream outputFile(StatSeshFile,ios_base::app);
	if(!outputFile.is_open()){
		cerr<<"Error finding Stat Session File\n";
		return;
	}

	istringstream iss(choice);
	iss>>word;
	iss>>seshNum;

	string FileName="./CSCE240data/Session"+to_string(seshNum)+".txt";
//creates inputFile of specific session file, relies onlayout of choice being one word and then chat, I specified that showchat 3 would display session 3
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
//reads statistics file for one specific line and prints it
void ShowSummary(string choice, string StatSeshFile){
	string StatFile="./CSCE250data/ChatStats.txt";//change to fit your statistics title
	ifstream inputFile(StatFile);
//creates input file reader to scan statistics file
	if (!inputFile.is_open()) {
		        std::cerr << "Error opening file.\n";
		        return;
		    }
//output file to write to session logger all interactions for this chat
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
//checks for chosen session in statistics file
	while(getline(inputFile,line)){
		if(line.find(searchGood)!=string::npos){
				cout<<line<<endl;
				outputFile<<line<<endl;
		}
	}

	inputFile.close();
	outputFile.close();

}
//checks which aspect of project 5 was intended
void sessionLogger(string choice, string StatFile){
	regex Summary("summary");
	regex Show("showchat");


	smatch match;

	//all of the if ifstatements below call above methods, the statfile is used to write to the specific session logger that stores all interactions

//show summary command means only one specific session statistics, I used showchat-summary 4 as the command that triggers this
	if(regex_search(choice, match, Show)&&regex_search(choice,match,Summary)){
		ShowSummary(choice,StatFile);
	}
	//just the word summary triggers this
	else if(regex_search(choice,match,Summary)){
		StatSummary(StatFile);
	}
	//showchat 4 triggers this
	else if(regex_search(choice,match,Show)){
		ShowChat(choice,StatFile);
	}
}
