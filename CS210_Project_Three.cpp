#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <cctype>

using namespace std;

string ToLower(const string& s) {
    string out = s;
    for (char& ch : out) {
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    }
    return out;
}

class ItemTracker {
public:
    bool LoadFromFile(const string& inputFileName) {
        ifstream inFS(inputFileName);
        if (!inFS.is_open()) {
            return false;
        }

        string item;
        while (inFS >> item) {
            freqMap[ToLower(item)]++;
        }

        inFS.close();
        return true;
    }

    bool WriteBackupFile(const string& outputFileName) const {
        ofstream outFS(outputFileName);
        if (!outFS.is_open()) {
            return false;
        }

        for (const auto& pair : freqMap) {
            outFS << pair.first << " " << pair.second << endl;
        }

        outFS.close();
        return true;
    }

    int GetItemCount(const string& item) const {
        string key = ToLower(item);
        auto it = freqMap.find(key);
        if (it == freqMap.end()) {
            return 0;
        }
        return it->second;
    }

    void PrintAllFrequencies() const {
        for (const auto& pair : freqMap) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void PrintHistogram(char symbol = '*') const {
        for (const auto& pair : freqMap) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << symbol;
            }
            cout << endl;
        }
    }

private:
    map<string, int> freqMap;
};

void PrintMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

int GetValidatedChoice(int minChoice, int maxChoice) {
    int choice;

    while (true) {
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number (" << minChoice << "-" << maxChoice << "): ";
            continue;
        }

        if (choice < minChoice || choice > maxChoice) {
            cout << "Please enter a number (" << minChoice << "-" << maxChoice << "): ";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
}

int main() {
    const string inputFileName = "C:\\Users\\Administrator\\source\\repos\\CS210_Project_Three\\CS210_Project_Three\\CS210_Project_Three_Input_File.txt";
    const string backupFileName = "frequency.dat";

    ItemTracker tracker;

    if (!tracker.LoadFromFile(inputFileName)) {
        cout << "Error: Could not open input file.\n";
        return 1;
    }

    tracker.WriteBackupFile(backupFileName);

    while (true) {
        PrintMenu();
        int choice = GetValidatedChoice(1, 4);

        if (choice == 1) {
            string item;
            cout << "Enter item name: ";
            getline(cin, item);

            int count = tracker.GetItemCount(item);
            cout << item << " appears " << count << " time(s).\n";
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}