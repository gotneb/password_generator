/*
    Author: Gabriel Bento da Silva
    This a very simple program only to practice and learning how C++ works. 
*/
#include <iostream>
#include <string>

#include "password.h"

using std::cin;
using std::cout;
using std::cout;
using std::endl;
using std::string;

int main() 
{
    Password generator;
    string answer = "s"; 

    while (tolower(answer[0]) != 'n') {
        system("clear");
        auto my_password = generator.CreatePassword();
        cout << "Password: " << my_password << endl;
        cout << "----------------------\n" 
        << "Deseja criar uma nova senha? [S/N]: ";
        cin >> answer;
    }
    
    cout << ";-; BYE BYE! s2" << endl;
}