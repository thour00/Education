#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Message // ����� �������� ������� �� ���� �������������(��� ��� ���������� � ��� ��� ��������) � ������ ������ ���������
{
public:
	Message(string& user_1, string& user_2, string& message);
	string get_mess();
	string get_user_1();
	string get_user_2();
private:
	string _messages;
	string _user_1;
	string _user_2;
};