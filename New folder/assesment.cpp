#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <set>
#include <fstream>
using namespace std;

int task1() {
	ifstream inputf("quiz1.txt");

	string word;
	int count = 0;

	if (inputf.is_open())
	{
		while (!inputf.eof())
		{
			inputf >> word;

			if (isdigit(word[0]))
			{
				if (isdigit(word[1]))
				{
					if (isdigit(word[2]))
					{
						if (!isdigit(word[3]))
						{
							cout << "<INT, " << word << ">" << endl;
						}
					}
					else
					{
						cout << "<INT, " << word << ">" << endl;
					}
				}
				else {
					cout << "<INT, " << word[0] << ">" << endl;
				}
			}


		}
	}


	inputf.close();
	return 0;
}

void task2() {

	ifstream inputf("quiz2.txt");

	string line;
	bool inMultiLineComment = false;

	while (getline(inputf, line)) {
		size_t multiLineCommentStartPos = line.find("<");
		size_t multiLineCommentEndPos = line.find(">");

		if (inMultiLineComment) {
			if (multiLineCommentEndPos != string::npos) {
				inMultiLineComment = false;
				cout << line.substr(0, multiLineCommentEndPos + 2) << endl;
			}
			else {
				continue;
			}
		}

		if (multiLineCommentStartPos != string::npos) {
			if (multiLineCommentEndPos != string::npos) {
				cout << "<Multi-line comment: " << endl << line.substr(multiLineCommentStartPos, multiLineCommentEndPos - multiLineCommentStartPos + 2) << endl;
			}
			else {
				inMultiLineComment = true;
				cout << "Multi-line comment: " << endl << line.substr(multiLineCommentStartPos) << endl;
			}
		}
	}
	inputf.close();
}

void task11() {
	ifstream sourceFile("quiz1.txt"); // Replace 'source.cpp' with your source file's name
	if (!sourceFile.is_open()) {
		cout << "Failed to open source file." << endl;
	}

	string line;
	regex integerLiteralRegex("\\b\\d{1,3}\\b"); // Regex to match integer literals of up to three digits

	while (getline(sourceFile, line)) {
		smatch match;
		while (regex_search(line, match, integerLiteralRegex)) {
			for (auto& m : match) {
				cout << "<IL, " << m << ">" << endl;
			}
			line = match.suffix().str();
		}
	}

	sourceFile.close();
}

bool isDigit(char c) {
	return isdigit(static_cast<unsigned char>(c));
}

void task12()
{
	ifstream sourceFile("quiz1.txt"); // Replace 'source.cpp' with your source file's name
	if (!sourceFile.is_open()) {
		cout << "Failed to open source file." << endl;
	}

	char currentChar;
	string integerLiteral = "";

	while (sourceFile.get(currentChar)) {
		if (isDigit(currentChar)) {
			if (integerLiteral.empty() || integerLiteral.size() < 3) {
				integerLiteral += currentChar;
			}
			else
			{
				integerLiteral = "";
			}
		}
		else if (!integerLiteral.empty()) {
			// If we were collecting digits and the current character is not a digit, print the integer literal
			cout << "<IL, " << integerLiteral << ">" << endl;
			integerLiteral = ""; // Reset the integer literal string
		}
	}

	// Check if there's any integer literal left to print after reaching the end of the file
	if (!integerLiteral.empty()) {
		cout << "<IL, " << integerLiteral << ">" << endl;
	}

	sourceFile.close();
}

bool isInsideString(const string& line, int index) {
	int doubleQuotesCount = 0;
	for (int i = 0; i < index; ++i) {
		if (line[i] == '\"' && (i == 0 || line[i - 1] != '\\')) {
			doubleQuotesCount++;
		}
	}
	return (doubleQuotesCount % 2 == 1);
}

void task22()
{
	ifstream sourceFile("quiz2.txt"); // Replace 'source.cpp' with your source file's name
	if (!sourceFile.is_open()) {
		cout << "Failed to open source file." << endl;
	}

	string line;
	bool insideComment = false;
	string comment;

	while (getline(sourceFile, line)) {
		for (int i = 0; i < line.length(); ++i) {
			if (line[i] == '<' && !isInsideString(line, i)) {
				insideComment = true;
				//comment = "< ";
			}

			if (insideComment) {
				comment += line[i];
			}

			if (insideComment && line[i] == '>' && !isInsideString(line, i)) {
				insideComment = false;
				cout << "<ML, " << comment << endl;
			}
		}
	}

	sourceFile.close();
}



void main() {
	cout << "task1" << endl << endl;
	// task1();
	//task12();
	cout << endl << "task2" << endl << endl;
	//task2();
	//task22();
}

