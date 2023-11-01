#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace std;

int main() {
    fstream cpp("C:/Users/Naumaan/Downloads/drive-download-20230917T094517Z-001/Cpp Program.txt"); // Open the input file
    if (!cpp.is_open()) {
        cout << "Error: Unable to open log file." << endl;
        return 1;
    }

    string line;
    string cppProgram;

    // Read the entire C++ program into a single string
    while (getline(cpp, line)) {
        cppProgram += line + '\n';
    }

    cpp.close();

    // Regular expressions to match single-line and multiline comments in C++
    regex singleLineCommentPattern(R"(\/\/[^\n]*)");
    regex multilineCommentPattern(R"(/\*([\s\S]*?)\*/)");

    // Find and print single-line comments
    cout << "Single-line comments:" << std::endl;
    smatch match;
    while (std::regex_search(cppProgram, match, singleLineCommentPattern)) {
        cout << match[0] << std::endl;
        cppProgram = match.suffix().str();
    }

    // Find and print multiline comments
    cout << "\nMultiline comments:" << std::endl;
    while (std::regex_search(cppProgram, match, multilineCommentPattern)) {
        cout << match[0] << std::endl;
        cppProgram = match.suffix().str();
    }

    return 0;
}
        
    
