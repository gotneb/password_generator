#include <iostream>
#include "password.h"

std::string Password::CreatePassword() {
    Password::Type type;
    std::string password;
    short option = 0;
    // Selection input
    while (option < 1 || option > 3) {
        std::cout << "Please choose one type of password showed below:\n";
        std::cout << "=============================\n[1] - Easy Password\n[2] - Normal password\n[3] - Strong Password\n=============================\nSelection: ";
        std::cin >> option;
    }

    switch (option) {
        case 1:
            type = Password::Type::Easy;
            break;
        case 2:
            type = Password::Type::Normal;
            break;
        case 3:
            type = Password::Type::Strong;
            break;
    }
    
    GeneratePassword(type, password);
    return password;
}

void Password::GeneratePassword(Password::Type &type, std::string &password) {
    switch (type) {
        case Type::Easy:
            MakeEasyPassword(password);
            break;
        case Type::Normal:
            MakeNormalPassword(password);
            break;
        case Type::Strong:
            MakeStrongPassword(password);
            break;
    }
}

void Password::MakeEasyPassword(std::string &password) {
    for (decltype(digits.size()) i = 0; i != static_cast<int>(Password::Type::Easy); ++i) {
        if (rand()%3 <= 1) {
            char c = characters.at(std::rand()%characters.size());
            password += rand() % 2 == 0 ?  c : toupper(c);
        } else {
            password += digits.at(std::rand()%digits.size());
        }
    } 
}

void Password::MakeNormalPassword(std::string &password) {
    for (decltype(digits.size()) i = 0; i != static_cast<int>(Password::Type::Normal); ++i) {
        short random = 1 + rand()%10; 
        if (random <= 6) {
            char c = characters.at(std::rand()%characters.size());
            password += rand() % 2 == 0 ?  c : toupper(c);
        } else {
            password += digits.at(std::rand()%digits.size());
        }
    } 
}

void Password::MakeStrongPassword(std::string &password) {
    for (decltype(digits.size()) i = 0; i != static_cast<int>(Password::Type::Strong); ++i) {
        short random = 1 + rand()%10; 
        // 50% chance to be a letter
        if (random <= 5) { 
            char c = characters.at(std::rand()%characters.size());
            password += rand() % 2 == 0 ?  c : toupper(c);
        } 
        // 30% chance to be a digit
        else if (random <= 8) {
            password += digits.at(std::rand()%digits.size());
        } 
        // 20% chance to be a special character
        else { 
            password += special.at(std::rand()%special.size());
        }
    } 
}