#pragma once
#include <iostream>
using namespace std;

class User
{
public:
	User(string& login, string& password);
	User();
	string get_login();
	string get_password();
private:
	string _login;
	string _password;
};