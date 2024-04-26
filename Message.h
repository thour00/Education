#pragma once
#include<iostream>
#include "Account.h"
#include<vector>
using namespace std;

class Message
{
private:
	Account _a;
	Account _b;
	string _message;
public:
	Message();
	Message(Account _a, string& message);
	~Message();
	Message& operator=(Message&& other)noexcept;
};

