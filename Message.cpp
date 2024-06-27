#include "Message.h"

Message::Message(string& user_1, string& user_2, string& message) {
	this->_user_1 = user_1;
	this->_user_2 = user_2;
	this->_messages = message;
}
string Message::get_mess() {
	return _messages;
}
string Message::get_user_1() {
	return _user_1;
}
string Message::get_user_2() {
	return _user_2;
}
