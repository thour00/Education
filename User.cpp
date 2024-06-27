#include "User.h"
using namespace std;

User::User(string& login, string& password) : _login(login), _password(password) {

}
User::User() {

}
string User::get_login() {
	return _login;
}
string User::get_password() {
	return _password;
}