#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Open file in append mode
    ofstream outFile("users.txt", ios::app);
    if (outFile) {
        outFile << username << "\n" << password << "\n";
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file for registration.\n";
    }
    outFile.close();
}

void loginUser() {
    string username, password, fileUsername, filePassword;
    bool found = false;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open file to read user data
    ifstream inFile("users.txt");
    if (inFile) {
        while (getline(inFile, fileUsername) && getline(inFile, filePassword)) {
            if (fileUsername == username && filePassword == password) {
                found = true;
                break;
            }
        }
        inFile.close();
    } else {
        cout << "Error opening file for login.\n";
        return;
    }

    if (found) {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
