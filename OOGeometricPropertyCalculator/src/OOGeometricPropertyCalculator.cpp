//============================================================================
// Name        : OOGeometricPropertyCalculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class Shape {
protected:
    double area;
    double perimeter;
    string errorMessage;

public:
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void readData(ifstream& inputFile) = 0;

    double getArea() const {
        return area;
    }

    double getPerimeter() const {
        return perimeter;
    }

    string getErrorMessage() const {
        return errorMessage;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    double calculateArea() override {
        area = length * width;
        return area;
    }

    double calculatePerimeter() override {
        perimeter = 2 * (length + width);
        return perimeter;
    }

    void readData(ifstream& inputFile) override {
        inputFile >> length >> width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    double calculateArea() override {
        area = M_PI * pow(radius, 2);
        return area;
    }

    double calculatePerimeter() override {
        perimeter = 2 * M_PI * radius;
        return perimeter;
    }

    void readData(ifstream& inputFile) override {
        inputFile >> radius;
    }
};

class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    double calculateArea() override {
        // Assuming you have the necessary formula to calculate the area of a triangle
        // For example, using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        return area;
    }

    double calculatePerimeter() override {
        perimeter = side1 + side2 + side3;
        return perimeter;
    }

    void readData(ifstream& inputFile) override {
        inputFile >> side1 >> side2 >> side3;
    }
};

void writeOutput(double value, ofstream& outputFile) {
    outputFile << value << endl;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    Shape* shape = nullptr;
    char choice;
    cout << "Enter '1' for area or '2' for perimeter: ";
    cin >> choice;

    char shapeType;
    while (inputFile >> shapeType) {
        switch (shapeType) {
            case 'R':
                shape = new Rectangle();
                break;
            case 'C':
                shape = new Circle();
                break;
            case 'T':
                shape = new Triangle();
                break;
            default:
                cerr << "Invalid shape type." << endl;
                continue;
        }

        shape->readData(inputFile);
        if (choice == '1') {
            writeOutput(shape->calculateArea(), outputFile);
        } else if (choice == '2') {
            writeOutput(shape->calculatePerimeter(), outputFile);
        } else {
            cerr << "Invalid choice." << endl;
            break;
        }

        delete shape;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

