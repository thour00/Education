#include<iostream>
#include"Account.h"
#include<vector>
#include"Message.h"
#include<memory>
using namespace std;

void registration(string& login, string& password) {
    cout << "������� ����� (���� ���): ";
    std::cin >> login;
    cout << endl << "������� ������: ";
    std::cin >> password;
}

void menu() {
    cout << endl << "1. ���������������� �������" << endl <<
        "2. ����� � �������" << endl <<
        "3. ��������� ���������" << endl;
}
void acc_menu(Account& a, int size, int id) {
    if (size == 1) {
        cout <<endl<< "��� ������ ������������������ �������������!" << endl;
        cout << "��������������� ��� ��������!" << endl;
    }
    else {
        cout << endl<<"��� ��������� ����!" << endl;
        for (int i = 0; i < size; ++i) {
            cout << i+1<<". ";
            if (id == a.get_id()) {
            }
            else {
                cout << a.get_login()[i] << endl;
            }
        }
        cout << "���-�� ����� �� �������� ������� q";
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
    vector<Message>messages;

    while (programm) {
        
        srand(time(NULL));
        int a = rand()%16383;
        cout << a << endl;

        menu();
        short choice;
        std::cin >> choice;
        switch (choice) {
        case 1: {

            
            registration(login, password);
            Account* acc = new Account(login,password,id);
            accounts.push_back(*acc);
            delete acc;
            accounts[size].set_login(login);
            accounts[size].set_password(password);
            accounts[size].set_id(size);
            //foo(accounts[size]);
            size += 1;
            break;
        }
        case 2:
            cout << "�����: ";
            std::cin >> login;
            for (int i = 0; i < size; ++i) {
                if (accounts[i].get_login() == login) {
                    cout << "������: ";
                    std::cin >> password;
                    if (accounts[i].get_password() == password) {
                        id = accounts[i].get_id();


                        //���� �������� � ������� ������ ������������� ��� ��������� ���������
                        if (size == 1) {
                            cout << endl << "��� ������ ������������������ �������������!" << endl;
                            cout << "��������������� ��� ��������!" << endl;
                        }
                        else {
                            cout << endl << "��� ��������� ����!" << endl;
                            for (int i = 0; i < accounts.size()-1; ++i) {
                                cout << i + 1 << ". ";
                                if (id == accounts[i].get_id()) {
                                    cout << accounts[i+1].get_login() << endl;
                                }
                                else {
                                    cout << accounts[i].get_login() << endl;
                                }
                            }
                            cout << "���-�� ����� �� �������� ������� q";
                        }


                        if (size == 1) {
                            break;
                        }
                        
                        login = accounts[i].get_login();
                        password = accounts[i].get_password();
                        std::cin >> choice;
                        for(int j=0;j<accounts.size();++j){
                            
                        }
                            Message * messages = new Message();
                            cout << "���������: ";
                            std::cin >> message; 
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