#pragma once
#include"User.h"
#include<iostream>
#include<vector>
#include"Message.h"
#include<string>

using namespace std;


class Server
{
public:
	void general(); //������� �������
	void general_in_account();//������� ���������� � ��������
	int menu_account();//������� ��� ��������� ����
	int registration();//������� �����������
	int enter_account();//������� ����� � �������
	void set_user_in_account(string& login);
	string get_user_in_account();
	string get_message(int index);
	void cout_chat(string& user_1, string& user_2);
	void chat(string& user_1, string& user_2);
private:
	vector<User>accounts;//������ ���������
	string user_in_account;//������������, ������� �������� ���� � �������
	vector<Message>messages;//������ ���������
};


