#include "Account.h"

const string& Account::getUsername() const {
    return username;
}

void Account::setUsername(const string& uname) {
    username = uname;
}

const string& Account::getPassword() const {
    return password;
}

void Account::setPassword(const string& pass) {
    password = pass;
}

const string& Account::getContactInfo() const {
    return contactInfo;
}

void Account::setContactInfo(const string& contact) {
    contactInfo = contact;
}
