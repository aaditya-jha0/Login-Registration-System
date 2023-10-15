#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LoginSystem {
private:
    string user_name;
    string password;
    long int number;
    string email;
    string city;

public:
    void login();
    void registration();
    void forgot();
    bool checklogin();
    void start();
    void intro();
    void adminPanel();
};

void LoginSystem::login() {
    if (!checklogin()) {
        cout << "Invalid credentials. Please try again." << endl;
    } else {
        cout << "Successful login." << endl;
    }
}

bool LoginSystem::checklogin() {
    string input_username, input_password;

    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, input_username);

    cout << "Enter your password: ";
    getline(cin, input_password);

    ifstream input("userdata.txt");

    if (!input) {
        cout << "Error: Unable to open the file." << endl;
        return false;
    }

    while (input >> user_name >> password >> number >> city >> email) {
        if (user_name == input_username && password == input_password) {
            input.close();
            return true;
        }
    }

    input.close();
    return false;
}

void LoginSystem::registration() {
    cout << "Enter username: ";
    cin.ignore();
    getline(cin, user_name);
    cout << "Enter password: ";
    getline(cin, password);
    cout << "Enter your phone number: ";
    cin >> number;
    cin.ignore();
    cout << "Enter your city name: ";
    getline(cin, city);
    cout << "Enter your email: ";
    getline(cin, email);

    ofstream output("userdata.txt", ios::out | ios::app);
    output << user_name << '\n' << password << '\n' << number << '\n' << city << '\n' << email << '\n';
    output.close();
}

void LoginSystem::forgot() {
    long int input_number, number;
    cout << "Enter your  number: ";
    cin >> input_number;
    ifstream input("userdata.txt");

    if (!input) {
        cout << "Error: Unable to open the file" << endl;
        return;
    }

    bool found = false;

    while (input >> user_name >> password >> number >> city >> email) {
        if (number == input_number) {
            found = true;
            cout << "Congratulations! You remembered your  number." << endl;
            cout << "Your password is: " << password << endl;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, we couldn't find your number in our records." << endl;
    }

    input.close();
}

void LoginSystem::adminPanel() {
    string adminUsername = "iamatomic";
    string adminPassword = "lord";

    string inputUsername, inputPassword;

    cout << "Enter admin username: ";
    cin.ignore();
    getline(cin, inputUsername);

    cout << "Enter admin password: ";
    getline(cin, inputPassword);

    if (adminUsername == inputUsername && adminPassword == inputPassword) {
        cout << "Admin Panel" << endl;
        ifstream input("userdata.txt");

        if (!input) {
            cout << "Error: Unable to open the file." << endl;
            return;
        }

        while (input >> user_name >> password >> number >> city >> email) {
            cout << "Username: " << user_name << endl;
            cout << "Password: " << password << endl;
            cout << "Number: " << number << endl;
            cout << "City: " << city << endl;
            cout << "Email: " << email << endl;
            cout << "--------------------" << endl;
        }

        input.close();
    } else {
        cout << "Invalid admin credentials." << endl;
    }
}

void LoginSystem::intro() {
    cout << "LOGIN SYSTEM, MADE BY CODE WIZARDS GROUP" << endl;
}

void LoginSystem::start() {
    while (1) {
        int choice;
        cout << "\n\n\t\t           Welcome!\n\n";
        cout << "\t|| Press 1 to LOGIN                    ||\n";
        cout << "\t|| Press 2 to REGISTER                 ||\n";
        cout << "\t|| Press 3 if you FORGOT your PASSWORD ||\n";
        cout << "\t|| Press 4 for ADMIN PANEL             ||\n";
        cout << "\t|| Press 5 to EXIT                     ||\n";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");//credit::Gaurav
            login();
            break;
        case 2:
            system("cls");
            registration();
            break;
        case 3:
            system("cls");
            forgot();
            break;
        case 4:
            system("cls");
            adminPanel();
            break;
        case 5:
            cout << "You have chosen to exit from our project" << endl;
            exit(2);
        default:
            cout << "Invalid input. Please select from the given options." << endl;
        }
    }
}

int main() {
    LoginSystem loginSystem;
    loginSystem.intro();
    loginSystem.start();
    return 0;
}

