#include "Message.h"

Message::Message() {

}
Message::Message(Account a, string& message) {
    _message = message;
}
Message::~Message() {
}
Message& Message::operator=(Message&& other)noexcept {
    _message = other._message;
    return *this;
}
