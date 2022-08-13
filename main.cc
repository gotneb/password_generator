/*
    Author: Gabriel Bento da Silva
    This a very simple program only to practice and learning how C++ works. 
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::cout;
using std::endl;
using std::string;

int main() 
{
    // Create a seed based on time
    std::srand(time(nullptr));

    // Base for generate password
    string characters = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    //string others = "!@#$%_";

    // input
    decltype(characters.size()) length_password;
    cout << "Please insert length password: ";
    cin >> length_password;
    while (length_password <= 0 || length_password >= 30) {
        cout << "Please insert a valid length!\nLength: ";
        cin >> length_password;
    }

    string password;

    for (decltype(digits.size()) i = 0; i != length_password; ++i) {
        if (rand()%3 <= 1) {
            password += rand()%2 == 0 ? characters.at(std::rand()%characters.size()) : toupper(characters.at(std::rand()%characters.size()));
        } else {
            password += digits.at(std::rand()%digits.size());
        }
    }   

    cout << "Password: " + password << endl;

    return 0;
}