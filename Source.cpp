#include<iostream>
#include"Account.h"
#include<vector>
#include"Message.h"
#include<memory>
using namespace std;

void registration(string& login, string& password) {
    cout << "Введите логин (Ваше имя): ";
    std::cin >> login;
    cout << endl << "Введите пароль: ";
    std::cin >> password;
}

void menu() {
    cout << endl << "1. Зарегестрировать аккаунт" << endl <<
        "2. Войти в аккаунт" << endl <<
        "3. Завершить программу" << endl;
}
void acc_menu(Account& a, int size, int id) {
    if (size == 1) {
        cout <<endl<< "Нет других зарегестрированных пользователей!" << endl;
        cout << "Зарегестрируйте еще аккаунты!" << endl;
    }
    else {
        cout << endl<<"Все доступные чаты!" << endl;
        for (int i = 0; i < size; ++i) {
            cout << i<<". ";
            if (id == a.get_id()) {
                cout << a.get_login()[i + 1] << endl;
            }
            else {
                cout << a.get_login()[i] << endl;
            }
        }
        cout << "Что-бы выйти из аккаунта нажмите q";
    }
}
void foo(Account& acc) {
    cout << acc.get_login() << endl << acc.get_password() << endl << acc.get_id();

}

int main() {
    setlocale(LC_ALL, "ru");

    int size = 0;
    string login;
    string password;
    string message;
    int id = 0;
    bool programm = true;
    
    
    vector<Account>accounts;

    while (programm) {
        
        menu();
        short choice;
        std::cin >> choice;
        switch (choice) {
        case 1: {

            
            registration(login, password);
            Account* acc = new Account(login,password,id);
            accounts.push_back(*acc);
            accounts[size].set_login(login);
            accounts[size].set_password(password);
            accounts[size].set_id(size);
            foo(accounts[size]);
            size += 1;
            delete acc;
            break;
        }
        case 2:
            cout << "Логин: ";
            std::cin >> login;
            for (int i = 0; i < size; ++i) {
                if (accounts[i].get_login() == login) {
                    cout << "Пароль: ";
                    std::cin >> password;
                    if (accounts[i].get_password() == password) {
                        id = accounts[i].get_id();
                        acc_menu(accounts[i], size, id);
                        if (size == 1) {
                            break;
                        }
                        Message* messages = new Message[size];
                        login = accounts[i].get_login();
                        password = accounts[i].get_password();
                        std::cin >> choice;
                        switch (choice) {
                        case 1:
                            cout << "Сообщение: ";
                            std::cin >> message;
                            messages[size-1] = { login, password, message, size, id };

                            break;
                        }
                    }
                    else {

                    }
                }
                else {

                }
            }


            break;
        case 3:
            
            programm = false;
            break;
        }
    }
}














/*Account* acc = new Account[size];
acc = accounts;
delete[] accounts;
Account* accounts = new Account[size];
accounts = acc;
delete[]acc;*/