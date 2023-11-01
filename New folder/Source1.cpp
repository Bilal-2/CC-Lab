#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("C:/Users/Naumaan/source/repos/myProject1/myProject1/grades.txt"); // Open the input file

    if (!inputFile) {
        cout << "Error: Unable to open input file." << endl;
        return 1; // Return an error code
    }

    vector<string> studentsWithBGrade;

    string line;
    while (getline(inputFile, line)) {
        // Split each line into name and grade
        size_t pos = line.find(":");
        if (pos != string::npos && pos < line.length() - 1) {
            string name = line.substr(0, pos);
            string grade = line.substr(pos + 2);

            // Check if the grade is "B" and store the name
            if (grade == "B" || grade == " B" || grade == "B ") {
                studentsWithBGrade.push_back(name);
            }
        }
    }

    // Display the names of students who received a "B" grade
    cout << "Students who received a 'B' grade:" << endl;
    for (const string& student : studentsWithBGrade) {
        cout << student << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}