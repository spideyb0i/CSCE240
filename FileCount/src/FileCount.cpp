//============================================================================
// Name        : FileCount.cpp
// Author      :Charlie Grant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // Ask the user to provide the input file name
    std::cout << "What company would you like to know about:\n1. for Sony\n2. for Microsoft";
    std::string filename;
    int choice;
    std::cin >> choice;
    if(choice==1){
    	filename="Sonydata.txt";
    }
    else if(choice==2){
    	filename="Microsoftdata.txt";
    }
    else{
    	std::cout<<"Error in input";
    	return 1;
    }


    // Open the file
    std::ifstream inputFile(filename);

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1; // Return an error code
    }

    // Initialize counters
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    int partCount = 0;

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Increment line count
        lineCount++;

        // Increment word count
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            wordCount++;
        }
        if(filename=="Sonydata.txt")
        {
        	partCount =4;
        }
        else{
        	partCount=4;
        }

        // Increment character count (including newline character)
        charCount += line.length() + 1;
    }

    // Close the file
    inputFile.close();

    // Output the results
    std::cout << "Number of lines: " << lineCount << std::endl;
    std::cout << "Number of words: " << wordCount << std::endl;
    std::cout << "Number of characters: " << charCount << std::endl;
    std::cout << "Number of parts: " << partCount << std::endl;

    return 0; // Return success code
}

