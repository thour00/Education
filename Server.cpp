#include "Server.h"

void Server::general() {
	bool programm = true;
	while (programm) {

		cout << endl << "1. Зарегистрироваться" << endl <<
			"2. Войти" << endl <<
			"3. Закрыть программу" << endl;
		short choice;
		cin >> choice;

		if (choice == 1) {
			registration();
		}
		else if (choice == 2) {
			general_in_account();


		}
		else if (choice == 3) {
			break;
		}
	}
}
void Server::general_in_account() {
	h:
	string choice_acc;//ник пользователя, которому отправляем сообщение
	if (enter_account() == 0) {
		goto h;
	}
	while (choice_acc!="q") {
		if (menu_account()==0) {
			break;
		}

		
		cout << endl << "Введите имя пользователя которому хотите отправить сообщение: " << endl;
		cout << endl << "Что-бы выйти нажмите букву q" << endl;

		cin >> choice_acc;
		
		for (int i = 0; i < accounts.size(); ++i) {
			if (choice_acc == accounts[i].get_login()) {	
				cout_chat(user_in_account, choice_acc);
				chat(user_in_account, choice_acc);
				
			}
		}

	}

}
void Server::chat(string& user_1, string& user_2) {
	cout << "Что-бы выйти нажмите букву q" << endl;
		string mess;
		while (mess!="q") {
			cout << endl << user_1 << ": ";
			getline(cin, mess);
			Message message(user_1, user_2, mess);
			messages.push_back(message);
		}
}
void Server::cout_chat(string& user_1, string& user_2) {
	for (int i = 0; i < messages.size(); ++i) {
		
		if ((messages[i].get_user_1() == user_1 && messages[i].get_user_2() == user_2) ||(messages[i].get_user_1() == user_2 && messages[i].get_user_2() == user_1)) {
				cout << endl << messages[i].get_user_1() << ": " << messages[i].get_mess() << endl;
			
		}
		
	}
	
	cout << "Нет сообщений с этим пользователем!!!" << endl;
}
int Server::menu_account() {
	if (accounts.size() == 1) {
		cout << "                                                                                                                                           Нет доступных чатов!!!" << endl;
		return 0;
	}
	cout << "Чаты:" << endl;
	for (int i = 0; i < accounts.size(); ++i) {
		
		if (accounts[i].get_login() == user_in_account && i==0) {
			
		}
		else if (i != 0) {
			if (accounts[i - 1].get_login() == user_in_account) {
			cout << i << ". ";
			cout << accounts[i].get_login();
			}
		}
		else{
			cout << i+1 << ". ";
			cout << accounts[i].get_login();
		}
		
		
	}
	return 1;
}
int Server::registration() {
	string login;
	string password;

	cout << "                                                                                                                                               Регистрация!!!" << endl <<
		"Введите логин: ";
	cin >> login;
	cout << "Введите пароль: ";
	cin >> password;

	for (int i = 0; i < accounts.size(); ++i) {
		if (accounts[i].get_login() == login) {
			cout << "Логин уже занят!" << endl;
			return 0;
		}

	}
	User acc(login, password);
	accounts.push_back(acc);
	cout << "                                                                                                                                           Регистрация завершена!" << endl;
	return 1;
}
int Server::enter_account() {
	if (accounts.size() == 0) {
		cout << "Нет ниодного зарегистрированного аккаунта!!!" << endl;
		return 0;
	}
	string login;
	string password;

	cout << "Логин: ";
	cin >> login;
	cout  << "Пароль: ";
	cin >> password;

	for (int i = 0; i < accounts.size(); ++i) {
		if (accounts[i].get_login() == login) {
			if (accounts[i].get_password() == password) {

				set_user_in_account(login);
				cout << "                                                                                                                                              Приветствую, " << get_user_in_account() << endl;
				return 1;
			}
			break;
		}
	}
	cout << "Неверный логин иили пароль!!!" << endl;
	return 0;

}

void Server::set_user_in_account(string& login) {
	user_in_account = login;
}
string Server::get_user_in_account() {
	return user_in_account;
}
string Server::get_message(int index) {
	return messages[index].get_mess();
}

