#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream inputFile("C:/Users/Naumaan/source/repos/myProject1/myProject1/Input File.txt"); // Open the input file
    ofstream outputFile("OutputFile.txt"); // Create the output file

    if (!inputFile) {
        cout << "Error: Unable to open input file." << endl;
        return 1; // Return an error code
    }

    if (!outputFile) {
        cout << "Error: Unable to create output file." << endl;
        return 1; // Return an error code
    }

    string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (getline(inputFile, line)) {
        lineCount++; // Increment line count for each line read
        charCount += line.length(); // Increment character count by the length of the line

        // Use a stringstream to split the line into words
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++; // Increment word count for each word found
        }
    }

    // Write the results to the output file
    outputFile << "Character count: " << charCount << std::endl;
    outputFile << "Word count: " << wordCount << std::endl;
    outputFile << "Line count: " << lineCount << std::endl;

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Counting complete. Results written to 'output.txt'." << std::endl;

    return 0;
}
