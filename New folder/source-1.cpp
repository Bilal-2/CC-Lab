#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

void task() {

	ifstream inputf("code.txt");
	ofstream outputf("iden.txt");

	string word;

	if (inputf.is_open())
	{
		while (!inputf.eof())
		{
			inputf >> word;

			if (word[0] == '_')
			{
				outputf << word << "-";
			}
			else if (isalpha(word[0]))
			{
				outputf << word << "-";
			}
		}
	}

	inputf.close();
	outputf.close();

	cout << "Done" << endl;
}

int task1() {
    // Open the input file
    ifstream inputFile("input.txt");

    // Check if the input file is open
    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file." << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile("output.txt");

    // Check if the output file is open
    if (!outputFile.is_open()) {
        cout << "Error: Could not open output file." << endl;
        inputFile.close();
        return 1;
    }

    string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (getline(inputFile, line)) {
        // Count characters
        charCount += line.length();

        // Count words
        size_t pos = 0;
        while ((pos = line.find_first_not_of(" \t", pos)) != string::npos) {
            pos = line.find_first_of(" \t", pos);
            wordCount++;
        }

        // Count lines
        lineCount++;
    }

    // Write the results to the output file
    outputFile << "Character Count: " << charCount << endl;
    outputFile << "Word Count: " << wordCount << endl;
    outputFile << "Line Count: " << lineCount << endl;

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    cout << "Counting completed. Results written to output.txt." << endl;

    return 0;
}

// Set of C++ keywords (you can add more if needed)
set<string> cppKeywords = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

// Function to check if a string is a valid C++ identifier
bool isIdentifier(const string& str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }
    for (char c : str) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

int task3() {
    // Open the C++ source code file
    ifstream inputFile("source.txt");

    // Check if the source code file is open
    if (!inputFile.is_open()) {
        cout << "Error: Could not open source code file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        lineNumber++;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            if (cppKeywords.count(word) > 0) {
                cout << "<keyword, " << word << ">" << endl;
            }
            else if (isIdentifier(word)) {
                cout << "<Identifier, " << word << ">" << endl;
            }
            else {
                cout << "Unknown token at line " << lineNumber << ": " << word << endl;
            }
        }
    }

    // Close the source code file
    inputFile.close();

    return 0;
}



void main() {
	// task(); // lab 2 task 1

    // task1(); // lab 1 task 1

    // task3(); // lab 2 task 1

}