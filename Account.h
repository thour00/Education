#pragma once
#include<iostream>

using namespace std;

class Account {
protected:
    string _login;
    string _password;
    int _id=0;
public:
    Account(string login, string password, int id);
    Account();
    /*~Account();
    Account(Account&& other);
    Account& operator=(Account&& other)noexcept;*/
    Account foo(Account&& other);
    void foo(string& login, string& password);
    void set_login(string& login);
    void set_password(string& password);
    void set_id(int size);
    string get_login();
    string get_password();
    bool check_data(Account& a, string& login, string& password);
    int& get_id();
};
