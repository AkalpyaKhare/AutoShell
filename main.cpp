#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// Show available commands
void showHelp() {
    cout << "\nAvailable Commands:\n";
    cout << "help              - Show commands\n";
    cout << "history           - Show command history\n";
    cout << "find <filename>   - Search for a file\n";
    cout << "ls                - Show files in current folder\n";
    cout << "pwd               - Show current folder\n";
    cout << "clear             - Clear screen\n";
    cout << "exit              - Exit AutoShell\n";
}

// Show command history
void showHistory(vector<string> history) {

    if (history.empty()) {
        cout << "No command history.\n";
        return;
    }

    for (int i = 0; i < history.size(); i++) {
        cout << i + 1 << ". " << history[i] << endl;
    }
}

// Show current directory
void showCurrentDirectory() {
    cout << "Current directory: "
         << fs::current_path() << endl;
}

// Show files and folders
void listFiles() {

    cout << "\nFiles and folders:\n";

    for (const auto& item : fs::directory_iterator(fs::current_path())) {

        cout << item.path().filename().string();

        if (item.is_directory())
            cout << " [Folder]";

        cout << endl;
    }
}

// Search for a file
void findFile(string filename) {

    bool found = false;

    cout << "Searching for " << filename << "...\n";

    for (const auto& item :
         fs::recursive_directory_iterator(fs::current_path())) {

        if (item.is_regular_file() &&
            item.path().filename() == filename) {

            cout << "Found: " << item.path() << endl;
            found = true;
        }
    }

    if (!found)
        cout << "File not found.\n";
}

int main() {

    string command;
    vector<string> history;

    cout << "=================================\n";
    cout << "          AutoShell\n";
    cout << "=================================\n";

    cout << "Type 'help' to see available commands.\n\n";

    while (true) {

        cout << "autoshell> ";
        getline(cin, command);

        // Save command to history
        if (command != "")
            history.push_back(command);

        // Exit
        if (command == "exit") {
            cout << "Goodbye!\n";
            break;
        }

        // Help
        else if (command == "help") {
            showHelp();
        }

        // History
        else if (command == "history") {
            showHistory(history);
        }

        // Current directory
        else if (command == "pwd") {
            showCurrentDirectory();
        }

        // List files
        else if (command == "ls") {
            listFiles();
        }

        // Clear screen
        else if (command == "clear") {

#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif

        }

        // Find file
        else if (command.rfind("find ", 0) == 0) {

            string filename = command.substr(5);

            if (filename.empty()) {
                cout << "Please enter a filename.\n";
            }
            else {
                findFile(filename);
            }
        }

        // Empty command
        else if (command.empty()) {
            continue;
        }

        // Unknown command
        else {
            cout << "Unknown command: " << command << endl;
            cout << "Type 'help' for available commands.\n";
        }
    }

    return 0;
}