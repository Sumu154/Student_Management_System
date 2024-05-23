
#include <iostream>
#include <string>

using namespace std;
class Account {
protected:
    string username;
    string password;
    string contactInfo;

public:
    virtual void login() = 0;

    const string& getUsername() const;
    void setUsername(const string& uname);

    const string& getPassword() const;
    void setPassword(const string& pass);

    const string& getContactInfo() const;
    void setContactInfo(const string& contact);
};

