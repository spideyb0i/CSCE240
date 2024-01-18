/*
Name: FileBasedCalculator.cpp
Author: Charlie Grant
Version:
Copyright: This is mine thank you
Description: Calculator made that intakes a file to read operation type
*/

#include <iostream>
#include <stream>
#include <fstream>
#include <sstream>


void main() {

	string in_file_name = "data/input.txt";
	string out_file_name = "data/output.txt";
	string line;

	ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {
			//establishes needed variables
			int a = 0;
			int b = 0;
			int ans;
			string op;
			while (getline(in_myfile, line)) {
				//sets kind of operation
				if (line.contains("add"))
				{
					if (op = NULL)
						op = "addition"
				}
				else if (line.contains("subtract"))
				{
					if (op = NULL)
						op = "subtraction"
				}
				else if (line.contains("multiply"))
				{
					if (op = NULL)
						op = "multiplication"
				}
				else if (line.contains("divide"))
				{
					if (op = NULL)
						op = "division";
				}
				//carries out mathimatics based on what operation was stated
				if (op = "addition")
				{
					if (a == 0)
						a = line;
					else
						b = line;
					ans = a + b;
				}
				if (op = "subtraction")
				{
					if (a == 0)
						a = line;
					else
						b = line;
					ans = a - b;
				}
				if (op = "multiplication")
				{
					if (a == 0)
						a = line;
					else
						b = line;
					ans = a * b;
				}
				if (op = "division")
				{
					if (a == 0)
						a = line;
					else
						b = line;
					ans = a / b;
				}
			} // end-while
			string out_line = "The result of " + op + " on " + a + " and " + b + " is below.";
			out_myfile << out_line;
			out_myfile << ans;
			// Close output file
			out_myfile.close();
		}
		else {
			cout << "Unable to open output file - " << out_file_name << endl;
		} // end-if

		// Close input file
		in_myfile.close();
	}
	else
		cout << "Unable to open input file - " << in_file_name << endl;
}
