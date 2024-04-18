#include "Message.h"

Message::Message() {

}
Message::Message(string& login, string& password, string& message, int chat, int id) : _message(message), _chat(chat), Account(login, password, id) {
    _message = message;
    _chat = chat;
}
Message::~Message() {
	_message = nullptr;
	_chat = 0;
}
Message& Message::operator=(Message&& other)noexcept {
    _login = other._login;
    _password = other._password;
    _login = nullptr;
    _password = nullptr;
    return *this;
}
