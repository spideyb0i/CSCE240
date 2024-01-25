/*
 * GeometricPropertyCalculator.cpp
 *
 *  Created on: Jan 23, 2024
 *      Author: cagra
 */

#include "GeometricPropertyCalculator.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

// Function prototypes
double calculateRectangleArea(double length, double width);
double calculateRectanglePerimeter(double length, double width);
double calculateCircleArea(double radius);
double calculateCirclePerimeter(double radius);
double calculateTriangleArea(double side1, double side2, double side3);
double calculateTrianglePerimeter(double side1, double side2, double side3);

void writeOutput(const string& shape, const string& calculationType, double result);

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    double dim1, dim2, dim3;

    if (!inputFile || !outputFile) {
        cerr << "Error opening input or output file.\n";
        return 1;
    }
    string shape;
    while (inputFile >> shape) {
        outputFile << "Shape: " << shape << endl;
        std::transform(shape.begin(),shape.end(),shape.begin(), ::toupper);
        if (shape == "RECTANGLE") {
            inputFile >> dim1 >> dim2;
        } else if (shape == "CIRCLE") {
            inputFile >> dim1;
        } else if (shape == "TRIANGLE") {
            inputFile >> dim1 >> dim2 >> dim3;
        } else {
            cerr << "Invalid shape found in input file.\n";
            continue;
        }

        char choice;
        cout << "Calculate (A)rea or (P)erimeter? ";
        cin >> choice;

        if (choice == 'A' || choice == 'a') {
            if (shape == "RECTANGLE") {
                double area = calculateRectangleArea(dim1, dim2);
                outputFile << "Calculation Type: Area, Result: " << area << endl;
                writeOutput(shape, "Area", area);
            } else if (shape == "CIRCLE") {
                double area = calculateCircleArea(dim1);
                outputFile << "Calculation Type: Area, Result: " << area << endl;
                writeOutput(shape, "Area", area);
            } else if (shape == "TRIANGLE") {
                double area = calculateTriangleArea(dim1, dim2, dim3);
                outputFile << "Calculation Type: Area, Result: " << area << endl;
                writeOutput(shape, "Area", area);
            } else {
                cerr << "Invalid shape.\n";
            }
        } else if (choice == 'P' || choice == 'p') {
            if (shape == "RECTANGLE") {
                double perimeter = calculateRectanglePerimeter(dim1, dim2);
                outputFile << "Calculation Type: Perimeter, Result: " << perimeter << endl;
                writeOutput(shape, "Perimeter", perimeter);
            } else if (shape == "CIRCLE") {
                double perimeter = calculateCirclePerimeter(dim1);
                outputFile << "Calculation Type: Perimeter, Result: " << perimeter << endl;
                writeOutput(shape, "Perimeter", perimeter);
            } else if (shape == "TRIANGLE") {
                double perimeter = calculateTrianglePerimeter(dim1, dim2, dim3);
                outputFile << "Calculation Type: Perimeter, Result: " << perimeter << endl;
                writeOutput(shape, "Perimeter", perimeter);
            } else {
                cerr << "Invalid shape.\n";
            }
        } else {
            cerr << "Invalid choice.\n";
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

// Function definitions
double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateCirclePerimeter(double radius) {
    return 2 * M_PI * radius;
}

double calculateTriangleArea(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double calculateTrianglePerimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

void writeOutput(const string& shape, const string& calculationType, double result) {
    ofstream outputFile("output.txt", ios::app);
    if (outputFile) {
        outputFile << "Shape: " << shape << ", Calculation Type: " << calculationType << ", Result: " << result << endl;
        outputFile.close();
    } else {
        cerr << "Error opening output file for writing.\n";
    }
}

GeometricPropertyCalculator::GeometricPropertyCalculator() {
	// TODO Auto-generated constructor stub

}

GeometricPropertyCalculator::~GeometricPropertyCalculator() {
	// TODO Auto-generated destructor stub
}

