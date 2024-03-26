//============================================================================
// Name        : FactorialFun.cpp
// Author      : Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <regex>

using namespace std;

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

unsigned long long combination(int num1, int num2){
	if(num1<num2||num1<0||num2<0){
		return 0;
	}
		return factorial(num1)/(factorial(num2)*factorial(num1-num2));
}

int main() {
	bool onenum=false;
	bool twonum=false;
	bool compnum=false;
	string input, word;
	int num1, num2;
    cout << "Enter one number, two numbers, or two numbers and 'compare'";
    getline(cin,input);
    istringstream iss(input);


    cout<<input<<endl;

    regex factor("^\\d+$");
    regex comb("^\\d+\\s\\d+$");
    regex comp("^\\d+\\s\\d+\\scompare$");

    smatch match;

if(regex_search(input,match,factor)){
	onenum=true;
	twonum=false;
	compnum=false;
}
if(regex_search(input,match,comb)){
	onenum=false;
		twonum=true;
		compnum=false;
}
if(regex_search(input,match,comp)){
	onenum=false;
		twonum=false;
		compnum=true;
}

    if(onenum){
    	iss>>num1;
    	// Start the timer
    	    		auto Fstart = chrono::high_resolution_clock::now();
    	    		// Calculate factorial
    	    		unsigned long long fresult = factorial(num1);
    	    		// Stop the timer
    	    		auto Fstop = chrono::high_resolution_clock::now();

    	    		// Calculate processing time
    	    		auto Fduration = chrono::duration_cast<chrono::nanoseconds>(Fstop - Fstart);


    	    		cout<<num1<<"! is "<<fresult<<", took : "<<Fduration.count()<<" seconds"<<endl;
    	}
    else if(twonum){
        iss>>num1>>num2;
    	cout<<num2;
        		// Start the timer
        		auto Cstart = chrono::high_resolution_clock::now();
        		// Calculate combination
        	    unsigned long long cresult = combination(num1, num2);
        		// Stop the timer
        		auto Cstop = chrono::high_resolution_clock::now();

        		// Calculate processing time
        		auto Cduration = chrono::duration_cast<chrono::nanoseconds>(Cstop - Cstart);

        		cout<<"C^"<<num1<<"_"<<num2<<" is "<<cresult<<", took : "<<Cduration.count()<<" seconds"<<endl;
        		}

    else if(compnum){
    	iss>>num1>>num2;
    	iss>>word;
    	cout<<word;
        			// Start the timer
        			auto Fstart = chrono::high_resolution_clock::now();
        			// Calculate factorial
        			unsigned long long fresult = factorial(num1);
        			// Stop the timer
        			auto Fstop = chrono::high_resolution_clock::now();

        			// Start the timer
        			auto Cstart = chrono::high_resolution_clock::now();
        			// Calculate combination
        			unsigned long long cresult = combination(num1, num2);
        			// Stop the timer
        			auto Cstop = chrono::high_resolution_clock::now();

        			//Compare Numbers
        			// Calculate processing time
        			auto Fduration = chrono::duration_cast<chrono::nanoseconds>(Fstop - Fstart);
        			// Calculate processing time
        			auto Cduration = chrono::duration_cast<chrono::nanoseconds>(Cstop - Cstart);

        			cout<<num1<<"! is "<<fresult<<", took : "<<Fduration.count()<<" seconds"<<endl;
        			cout<<"C^"<<num1<<"_"<<num2<<" is "<<cresult<<", took : "<<Cduration.count()<<" seconds"<<endl;

        			if(Fduration>Cduration){
        				cout<<num1<<"! is more"<<endl;
        			}
        			else{
        				cout<<"C^"<<num1<<"_"<<num2<<" is more"<<endl;
        			}
    }
    else{
    	cout<<"invalid input"<<endl;
    }
    return 0;
}
