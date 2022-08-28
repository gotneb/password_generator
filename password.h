#include <string>
#include <ctime>
#include <cstdlib>

class Password {
public:
    // TODO: Make user choose password length 
    enum class Type {
        Easy = 8, // means 8 digits
        Normal = 12, // means 12 digits
        Strong = 15, // means 15 digits
    };
    Password() { std::srand(time(nullptr)); }
    std::string CreatePassword();
    void GeneratePassword(Type &, std::string &);
    /*
     * So, I'm still learning C++ and at this point I weren't able to put the functions below in private mode.
     * Hence, I'll make them public and as soon as possible I'll learn how to put them as private.
     */
    void MakeEasyPassword(std::string &);
    void MakeNormalPassword(std::string &);
    void MakeStrongPassword(std::string &);
private:
    const std::string characters = "abcdefghijklmnopqrstuvwxyz";
    const std::string digits = "0123456789";
    const std::string special = "!@#$%_";
};