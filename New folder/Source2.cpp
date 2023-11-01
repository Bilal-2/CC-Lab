#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct LogEntry {
    string host;
    string user_name;
    string time;
    string request;
};

int main() {
    ifstream logFile("C:/Users/Naumaan/source/repos/myProject1/myProject1/logdata.txt");
    if (!logFile.is_open()) {
        cout << "Error: Unable to open log file." << endl;
        return 1; // Return an error code
    }

    vector<LogEntry> logEntries;
    string line;

    while (getline(logFile, line)) {
        istringstream lineStream(line);
        LogEntry entry;

        // Read and parse the log entry components
        getline(lineStream, entry.host, '-');
        getline(lineStream, entry.user_name, '[');
        getline(lineStream, entry.time, ']');
        getline(lineStream, entry.request);

        // Add the log entry to the vector
        logEntries.push_back(entry);
    }

    // Print the first few log entries as an example
    for (size_t i = 0;i < logEntries.size(); ++i) {
        cout << "Host: " << logEntries[i].host << endl;
        cout << "User Name: " << logEntries[i].user_name << endl;
        cout << "Time: " << logEntries[i].time << endl;
        cout << "Request: " << logEntries[i].request << endl;
        cout << endl;
    }

    logFile.close();
    return 0;
}
