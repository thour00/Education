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
	void general(); //Главная функция
	void general_in_account();//Функция нахлждения в аккаунте
	int menu_account();//Выводит все доступыне чаты
	int registration();//Функция регистрации
	int enter_account();//Функция входа в аккаунт
	void set_user_in_account(string& login);
	string get_user_in_account();
	string get_message(int index);
	void cout_chat(string& user_1, string& user_2);
	void chat(string& user_1, string& user_2);
private:
	vector<User>accounts;//массив аккаунтов
	string user_in_account;//пользователь, который выполнил вход в аккаунт
	vector<Message>messages;//массив сообщений
};


