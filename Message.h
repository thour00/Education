#pragma once
#include<iostream>
#include "Account.h"
using namespace std;

class Message:public Account
{
private:
	string _message;
	int _chat = 0;
public:
	Message();
	Message(string& login, string& password, string& message, int _chat, int id);
	~Message();
	Message& operator=(Message&& other)noexcept;
};

