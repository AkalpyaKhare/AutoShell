# AutoShell

AutoShell is a simple command-line shell built using C++17. It was created as a beginner-friendly project to understand how command-line interfaces work and to practice basic C++ programming concepts.

The program allows users to enter commands and perform simple tasks such as viewing files, searching for files, checking the current directory, and maintaining command history.

## Features

* Simple command-line interface
* Display available commands
* View command history
* Search for files recursively
* List files and folders
* Display the current working directory
* Clear the terminal
* Exit command
* Basic command parsing

## Commands

| Command           | Description                          |
| ----------------- | ------------------------------------ |
| `help`            | Displays available commands          |
| `pwd`             | Shows the current working directory  |
| `ls`              | Lists files and folders              |
| `find <filename>` | Searches for a file                  |
| `history`         | Displays previously entered commands |
| `clear`           | Clears the terminal                  |
| `exit`            | Exits AutoShell                      |

## Technologies Used

* C++
* C++17
* Standard Library
* `<filesystem>`
* `<vector>`
* `<string>`
* `<iostream>`

## Concepts Practiced

This project helped me practice:

* Functions
* Loops and conditional statements
* Strings and vectors
* User input handling
* Command parsing
* File and directory handling
* Recursive filesystem traversal
* Basic terminal application development

## How to Run

### 1. Clone the repository

```bash
git clone <your-repository-link>
cd AutoShell
```

### 2. Compile

Using g++:

```bash
g++ -std=c++17 main.cpp -o autoshell
```

### 3. Run

Linux/macOS:

```bash
./autoshell
```

Windows:

```bash
autoshell.exe
```

## Example

```text
=================================
          AutoShell
=================================
Type 'help' to see available commands.

autoshell> pwd
Current directory: "/home/user/AutoShell"

autoshell> ls
main.cpp
README.md

autoshell> find main.cpp
Searching for main.cpp...
Found: "./main.cpp"

autoshell> history
1. pwd
2. ls
3. find main.cpp

autoshell> exit
Goodbye!
```

## Future Improvements

Planned improvements include:

* Application launching
* Alias support
* Custom workflows
* Better command parsing
* Configuration files
* Improved cross-platform support
* Modular project structure



