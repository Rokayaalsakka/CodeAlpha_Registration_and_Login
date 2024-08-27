#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Register() {
    string Username, password, file_name;
    ofstream Myfile;
    cout << "Please enter your username: ";
    getline(cin, Username);
    file_name = Username + ".txt";
    Myfile.open(file_name, ios::out);

    if (!Myfile) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    cout << "Please enter your password: ";
    getline(cin, password);

    Myfile << password << endl;
    Myfile.close();
    cout << "Registration Successful." << endl;
}

void Login() {
    string Username, password, file_name, real;
    ifstream Myfile;
    cout << "Please enter your username: ";
    getline(cin, Username);
    file_name = Username + ".txt";
    Myfile.open(file_name, ios::in);

    if (!Myfile) {
        cerr << "Error: Username does not exist." << endl;
        return;
    }

    getline(Myfile, real);
    Myfile.close();

    cout << "Please enter your password: ";
    getline(cin, password);

    while (real != password) {
        cout << "Wrong password, please re-enter: ";
        getline(cin, password);
    }

    cout << "Login Successful." << endl;
}

int main() {
    char ans;
    cout << "Do you want to register or login? (R/L) ";
    cin >> ans;
    cin.ignore();

    while (ans != 'R' && ans != 'L') {
        cout << "Please input a valid choice (R/L): ";
        cin >> ans;
        cin.ignore();
    }

    if (ans == 'R') {
        Register();
    } else if (ans == 'L') {
        Login();
    }

    return 0;
}
