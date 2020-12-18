#pragma once
#include "menu.h"
#include "carpark.h"

class Accounts {
protected:
	string login;
	string password;
	int role;
	int acess;
public:
	Accounts();
	string getLogin();
	string getPassword();
	int getRole();
	int getAcess();
	void updateLogin(string);
	void updatePassword(string);
	void updateRole(int);
	void updateAcess(int);
	friend ostream& operator<<(ostream&, Accounts&);
	friend ifstream& operator>>(ifstream&, Accounts&);
	friend ofstream& operator<<(ofstream&, Accounts&);
	~Accounts();
};

void writeFileAccounts(Accounts*, int);

void readFileAccounts(Accounts*, int&);

void showAccounts(Accounts*, int, int);

void addAccounts(Accounts*&, int&, int);

void delAccounts(Accounts*&, int&);

void delAccountsUser(Accounts*&, int&);

void updateAccounts(Accounts*&, int);

void updateAccountsUser(Accounts*&, int);

void workAccount(Accounts*&, int&, string&);

void workAccountUser(Accounts*&, int&, string&);

void workDataAdmin(Bus*, int, string);

void modulGlavnAdmin(Accounts*&, int&, Bus*&, int&, string);

void modulAdmin(Accounts*&, int&, Bus*&, int&, string);

void Registration(Accounts*&, int&, int);

void Authorization(Accounts*&, int&, Bus*, int&);

string isLoginUniq(Accounts*, int);