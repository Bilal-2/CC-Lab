#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int task33() {
    // Open the C++ source code file
    ifstream inputFile("s1.txt");

    // Check if the source code file is open
    if (!inputFile.is_open()) {
        cout << "Error: Could not open source code file." << endl;
        return 1;
    }

    string line;
    bool inMultiLineComment = false;

    while (getline(inputFile, line)) {
        size_t singleLineCommentPos = line.find("//");
        size_t multiLineCommentStartPos = line.find("/*");
        size_t multiLineCommentEndPos = line.find("*/");

        if (inMultiLineComment) {
            // Check if the multi-line comment ends on this line
            if (multiLineCommentEndPos != string::npos) {
                inMultiLineComment = false;
                line = line.substr(multiLineCommentEndPos + 2);
            }
            else {
                // The entire line is part of a multi-line comment
                continue;
            }
        }

        if (singleLineCommentPos != string::npos) {
            // Single-line comment found
            cout << "Single-line comment: " << line.substr(singleLineCommentPos) << endl;
        }
        else if (multiLineCommentStartPos != string::npos) {
            // Multi-line comment starts on this line
            if (multiLineCommentEndPos != string::npos) {
                // Multi-line comment ends on the same line
                cout << "Multi-line comment: " << line.substr(multiLineCommentStartPos, multiLineCommentEndPos - multiLineCommentStartPos + 2) << endl;
            }
            else {
                // Multi-line comment continues on subsequent lines
                inMultiLineComment = true;
                cout << "Multi-line comment: " << line.substr(multiLineCommentStartPos) << endl;
            }
        }
    }

    // Close the source code file
    inputFile.close();

    return 0;
}

const int MAX_LOG_ENTRIES = 1000;  // Define the maximum number of log entries

// Define a structure for each log entry
struct LogEntry {
    string host;
    string user_name;
    string time;
    string request;
};

int task13() {
    // Open the log file
    ifstream logFile("logdata.txt");

    // Check if the log file is open
    if (!logFile.is_open()) {
        cout << "Error: Could not open log file." << endl;
        return 1;
    }

    // Create an array of LogEntry structures
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    // Read and parse log entries from the file
    string line;
    while (getline(logFile, line) && numEntries < MAX_LOG_ENTRIES) {
        size_t hostStart = line.find("host:");
        size_t userStart = line.find("user_name:");
        size_t timeStart = line.find("time:");
        size_t requestStart = line.find("request:");

        if (hostStart != string::npos && userStart != string::npos &&
            timeStart != string::npos && requestStart != string::npos) {
            // Extract data and store it in the array of structures
            logEntries[numEntries].host = line.substr(hostStart + 5, userStart - hostStart - 6);
            logEntries[numEntries].user_name = line.substr(userStart + 10, timeStart - userStart - 11);
            logEntries[numEntries].time = line.substr(timeStart + 6, requestStart - timeStart - 7);
            logEntries[numEntries].request = line.substr(requestStart + 8);

            numEntries++;
        }
    }

    // Close the log file
    logFile.close();

    // Print the log entries
    for (int i = 0; i < numEntries; i++) {
        cout << "Entry " << (i + 1) << ":" << endl;
        cout << "host: " << logEntries[i].host << endl;
        cout << "user_name: " << logEntries[i].user_name << endl;
        cout << "time: " << logEntries[i].time << endl;
        cout << "request: " << logEntries[i].request << endl;
        cout << endl;
    }

    return 0;
}

void task1() {

}

void main()
{
    // task33(); // task 2 lab 3
    // task13(); // lab 1 task 3
}