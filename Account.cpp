#include "Account.h"
using namespace std;

Account::Account(string login, string password,int id) : _login(login), _password(password), _id(id) {
    _login = login;
    _password = password;
}
Account::Account() {
}
/*Account::~Account() {
    _login = nullptr;
    _password = nullptr;
}
Account::Account(Account&& other) {
    _login = other._login;
    _password = other._password;
    _login = nullptr;
    _password = nullptr;
}
Account& Account::operator=(Account&& other)noexcept {
    _login = other._login;
    _password = other._password;
    _login = nullptr;
    _password = nullptr;
    return *this;
}*/
void Account::foo(string& login, string& password) {
    _login = login;
    _password = password;
}
void Account::set_login(string& login) {
    _login = login;
}
void Account::set_password(string& password) {
    _password = password;
}
void Account::set_id(int size) {
    _id = 1000 + size;
}
string Account::get_login() {
    return _login;
}
string Account::get_password() {
    return _password;
}
bool Account::check_data(Account& a, string& login, string& password) {
    if (login == a._login && password == a._password) {
        return true;
    }
    else {
        return false;
    }
}
int& Account::get_id() {
    return _id;
}