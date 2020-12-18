#include "accounts.h"
#include "carpark.h"
#include "defence.h"

Accounts::Accounts()
{
	role = 0;
	acess = 0;
}

string Accounts::getLogin()
{
	return login;
}

string Accounts::getPassword()
{
	return password;
}

int Accounts::getRole()
{
	return role;
}

int Accounts::getAcess()
{
	return acess;
}

void Accounts::updateLogin(string log)
{
	login = log;
}

void Accounts::updatePassword(string pas)
{
	password = pas;
}

void Accounts::updateRole(int rol)
{
	role = rol;
}

void Accounts::updateAcess(int ac)
{
	acess = ac;
}

Accounts::~Accounts()
{

}

ostream& operator<<(ostream& out, Accounts& account) {
	out << "Логин: " << account.getLogin() << endl;
	out << "Пароль: " << account.getPassword() << endl;
	out << "Состояние: ";
	if (account.getAcess() == 0) {
		out << "не подтвержден" << endl;
	}
	else out << "подтвержден" << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Accounts& account)
{
	string s;
	getline(fin, account.login);
	getline(fin, s);
	account.password = deencryptionPassword(s);
	getline(fin, s);
	account.role = stoi(s);
	getline(fin, s);
	account.acess = stoi(s);
	return fin;
}

ofstream& operator<<(ofstream& fout, Accounts& account)
{
	fout << account.login << endl;
	fout << encryptionPassword(account.password) << endl;
	fout << account.role << endl;
	fout << account.acess << endl;
	return fout;
}

void writeFileAccounts(Accounts* mas_of_accounts, int number_of_accounts) {
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (int i = 0; i < number_of_accounts; i++) {
		fout << mas_of_accounts[i];
	}
	fout.close();
}

void readFileAccounts(Accounts* mas_of_accounts, int& number_of_accounts) {
	if (number_of_accounts != 0) {
		ifstream fin(FILE_OF_ACCOUNTS, ios::in);
		int i = 0;
		while (fin.peek() != EOF) {
			fin >> mas_of_accounts[i];
			i++;
		}
		number_of_accounts = i;
		fin.close();
	}
}

void showAccounts(Accounts* mas_of_accounts, int number_of_accounts, int r)
{
	int nAdmin = 1, nUser = 1;
	for (int i = 0; i < number_of_accounts; i++) {
		if (r == 2) {
			if (mas_of_accounts[i].getRole() == 2) cout << "\tГлавный администратор" << endl;
			else if (mas_of_accounts[i].getRole() == 1) {
				cout << "\tАдминистратор " << "№ " << nAdmin << endl;
				nAdmin++;
			}
			else {
				cout << "\tПользователь " << "№ " << nUser << endl;
				nUser++;
			}
		}
		else {
			cout << "\tПользователь " << "№ " << nUser << endl;
			nUser++;
		}
		cout << mas_of_accounts[i];
		Sleep(500);
	}
	if (nUser - 1 == 0 && r!= 2) cout << "Нет пользователей" << endl;
}

void addAccounts(Accounts*& mas_of_accounts, int& number_of_accounts, int r)
{
	string log, pass;
	int role, kol = 0;
	if (number_of_accounts - 1 == 0) {
		cout << "Первый аккаунт должен быть главным администратором!" << endl;
		cout << "Логин(не менее 3 символов): "; log = vvodLogin();
		mas_of_accounts[number_of_accounts - 1].updateLogin(log);
		cout << "Пароль(не менее 5 символов): "; pass = vvodPassword();
		mas_of_accounts[number_of_accounts - 1].updatePassword(pass);
		mas_of_accounts[number_of_accounts - 1].updateRole(2);
		mas_of_accounts[number_of_accounts - 1].updateAcess(1);
		cout << "Вы успешно зарегистрированы" << endl;
	}
	else {
		cout << "Логин(не менее 3 символов): ";
		log = vvodLogin(); 
		for (int i = 0; i < number_of_accounts; i++) {
			if (mas_of_accounts[i].getLogin() == log) kol++;
		}
		if (kol != 0) {
			cout << "Аккаунт с таким логином уже существует!" << endl;
			number_of_accounts--;
		}
		else {
			mas_of_accounts[number_of_accounts - 1].updateLogin(log);
			cout << "Пароль(не менее 5 символов): ";
			pass = vvodPassword();
			mas_of_accounts[number_of_accounts - 1].updatePassword(pass);
			cout << "Права доступа(1 - админ, 0 - пользователь): ";
			role = vvodRole();
			mas_of_accounts[number_of_accounts - 1].updateRole(role);
			if (r != 2) {
				mas_of_accounts[number_of_accounts - 1].updateAcess(0);
				cout << "Вы успешно зарегистрированы, дождитесь подтверждения аккаунта для входа в систему" << endl;
				system("pause");
			}
			else {
				mas_of_accounts[number_of_accounts - 1].updateAcess(1);
				cout << "Аккаунт добавлен" << endl;
			}
		}
	}
}

void delAccounts(Accounts*& mas_of_accounts, int& number_of_accounts) {
	showAccounts(mas_of_accounts, number_of_accounts, 2);
	string log;
	int number = 0, q = 0;
	if (number_of_accounts > 0) {
		cout << "Введите логин аккаунта, который хотите удалить: ";
		log = vvodLogin();
		if (log == mas_of_accounts[0].getLogin()) cout << "Нельзя удалить собственный аккаунт" << endl;
		else {
			for (int i = 1; i < number_of_accounts; i++) {
				if (log == mas_of_accounts[i].getLogin()) {
					q++;
					number = i;
					break;
				}
			}
			if (q == 0) {
				cout << "Пользователей с логином " << log << " нет" << endl;
			}
			else {
				if (mas_of_accounts[number].getRole() == 1) {
					for (int i = number; i < number_of_accounts - 1; i++) {
						mas_of_accounts[i] = mas_of_accounts[i + 1];
					}
					cout << "Администратор удален!" << endl;
					number_of_accounts--;
				}
				else {
					for (int i = number; i < number_of_accounts - 1; i++) {
						mas_of_accounts[i] = mas_of_accounts[i + 1];
					}
					cout << "Пользователь удален!" << endl;
					number_of_accounts--;
				}
			}
		}
	}
	writeFileAccounts(mas_of_accounts, number_of_accounts);
}

void delAccountsUser(Accounts*& mas_of_accounts, int& number_of_accounts) {
	showAccounts(mas_of_accounts, number_of_accounts, 1);
	string log;
	int number = 0, q = 0;
	if (number_of_accounts > 0) {
		if (number_of_accounts > 0) {
			cout << "Введите логин пользователя, который хотите удалить: ";
			log = vvodLogin();
			for (int i = 1; i < number_of_accounts; i++) {
				if (log == mas_of_accounts[i].getLogin() && mas_of_accounts[i].getRole() == 0) {
					q++;
					number = i;
					break;
				}
			}
			if (q == 0) {
				cout << "Пользователей с логином " << log << " нет" << endl;
			}
			else {
				if (mas_of_accounts[number].getRole() == 0) {
					for (int i = number; i < number_of_accounts - 1; i++) {
						mas_of_accounts[i] = mas_of_accounts[i + 1];
					}
					cout << "Пользователь удален!" << endl;
					number_of_accounts--;
				}
			}
		}
		writeFileAccounts(mas_of_accounts, number_of_accounts);
	}
}

void updateAccounts(Accounts*& mas_of_accounts, int number_of_accounts) {
	showAccounts(mas_of_accounts, number_of_accounts, 2);
	string login, password;
	int role = 0, acess = 0, update = 0, q = 0, number = 0;
	bool quit = true;
	cout << "Введите логин аккаунта, который хотите изменить: ";
	login = vvodLogin();
	for (int i = 0; i < number_of_accounts; i++) {
		if (login == mas_of_accounts[i].getLogin()) {
			q++;
			number = i;
			break;
		}
	}
	if (q == 0) {
		cout << "Аккаунтов с логином " << login << " нет" << endl;
	}
	else {
		Interface<string> b("Редактирование аккаунта с логином " + login);
		while (quit) {
			system("cls");
			switch (b.menuAccount()) {
			case 0:
				cout << "Текущий логин: ";
				cout << mas_of_accounts[number].getLogin();
				cout << endl;
				cout << "Введите новый логин(не менее 3 символов): ";
				login = isLoginUniq(mas_of_accounts, number_of_accounts);
				mas_of_accounts[number].updateLogin(login);
				break;
			case 1:
				cout << "Текущий пароль: ";
				cout << mas_of_accounts[number].getPassword();
				cout << endl;
				cout << "Введите новый пароль(не менее 5 символов): ";
				password = vvodPassword();
				mas_of_accounts[number].updatePassword(password);
				break;
			case 2:
				cout << "Текущее право доступа(2 - главный администратор, 1 - администратор, 0 - пользователь): ";
				cout << mas_of_accounts[number].getRole();
				cout << endl;
				if (login == mas_of_accounts[0].getLogin()) {
					cout << "Нельзя изменить собственную роль" << endl;
					system("pause");
				}
				else {
					if (mas_of_accounts[number].getRole() == 1) mas_of_accounts[number].updateRole(0);
					else mas_of_accounts[number].updateRole(1);
					cout << "Роль изменена" << endl;
					system("pause");
				}
				break;
			case 3:
				cout << "Текущее состояние(1 - аккаунт подтвержден, 0 - аккаунт не подтвержден): ";
				cout << mas_of_accounts[number].getAcess();
				cout << endl;
				if (login == mas_of_accounts[0].getLogin()) {
					cout << "Нельзя изменить собственный статус" << endl;
					system("pause");
				}
				else {
					if (mas_of_accounts[number].getAcess() == 1) mas_of_accounts[number].updateAcess(0);
					else mas_of_accounts[number].updateAcess(1);
					cout << "Статус изменен" << endl;
					system("pause");
				}
				break;
			case 4:
				quit = false;
				break;
			}
		}
	}
	writeFileAccounts(mas_of_accounts, number_of_accounts);
}

void updateAccountsUser(Accounts*& mas_of_accounts, int number_of_accounts) {
	showAccounts(mas_of_accounts, number_of_accounts, 1);
	if (number_of_accounts > 0) {
		string login, password;
		int role = 0, acess = 0, update = 0, q = 0, number = 0;
		bool quit = true;
		cout << "Введите логин пользователя, который хотите изменить: ";
		login = vvodLogin();
		for (int i = 1; i < number_of_accounts; i++) {
			if (login == mas_of_accounts[i].getLogin() && mas_of_accounts[i].getRole() == 0) {
				q++;
				number = i;
				break;
			}
		}
		if (q == 0) {
			cout << "Пользователей с логином " << login << " нет" << endl;
		}
		else {
			Interface<string> b("Редактирование аккаунта с логином " + login);
			while (quit) {
				system("cls");
				switch (b.menuAccount()) {
				case 0:
					cout << "Текущий логин: ";
					cout << mas_of_accounts[number].getLogin();
					cout << endl;
					cout << "Введите новый логин(не менее 3 символов): ";
					login = isLoginUniq(mas_of_accounts, number_of_accounts);
					mas_of_accounts[number].updateLogin(login);
					break;
				case 1:
					cout << "Текущий пароль: ";
					cout << mas_of_accounts[number].getPassword();
					cout << endl;
					cout << "Введите новый пароль(не менее 5 символов): ";
					password = vvodPassword();
					mas_of_accounts[number].updatePassword(password);
					break;
				case 2:
					cout << "Текущее право доступа(1 - администратор, 0 - пользователь): ";
					cout << mas_of_accounts[number].getRole();
					cout << endl;
					if (mas_of_accounts[number].getRole() == 1) mas_of_accounts[number].updateRole(0);
					else mas_of_accounts[number].updateRole(1);
					break;
				case 3:
					cout << "Текущее состояние(1 - аккаунт подтвержден, 0 - аккаунт не подтвержден): ";
					cout << mas_of_accounts[number].getAcess();
					cout << endl;
					if (mas_of_accounts[number].getAcess() == 1) mas_of_accounts[number].updateAcess(0);
					else mas_of_accounts[number].updateAcess(1);
					break;
				case 4:
					quit = false;
					break;
				}
			}
		}
		writeFileAccounts(mas_of_accounts, number_of_accounts);
	}
}

void workAccount(Accounts*& mas_of_accounts, int& number_of_accounts, string& login) {
	int n = 0;
	Interface<string> b("Модуль работы с аккаунтами главного администратора " + login);
	while (n != 5) {
		system("cls");
		n = b.menuWorkAccount();
		switch (n) {
		case 0:
			showAccounts(mas_of_accounts, number_of_accounts, 2);
			system("pause");
			break;
		case 1:
			Registration(mas_of_accounts, number_of_accounts, 2);
			system("pause");
			break;
		case 2:
			updateAccounts(mas_of_accounts, number_of_accounts);
			system("pause");
			break;
		case 3:
			delAccounts(mas_of_accounts, number_of_accounts);
			system("pause");
			break;
		case 4:
			n = 5;
			break;
		}
	}
}

void workAccountUser(Accounts*& mas_of_accounts, int& number_of_accounts, string& login) {
	int n = 0;
	Interface<string> b("Модуль работы с аккаунтами администратора " + login);
	while (n != 4) {
		system("cls");
		n = b.menuWorkAccount();
		switch (n) {
		case 0:
			showAccounts(mas_of_accounts, number_of_accounts, 1);
			system("pause");
			break;
		case 1:
			updateAccountsUser(mas_of_accounts, number_of_accounts);
			system("pause");
			break;
		case 2:
			delAccountsUser(mas_of_accounts, number_of_accounts);
			system("pause");
			break;
		case 3:
			n = 4;
			break;
		}
	}
}

void workDataAdmin(Bus* mas_of_bus, int number_of_bus, string login) {
	int data = 0;
	Interface<string> b("Модуль работы с данными автопарка администратора " + login);
	while (data != 7) {
		system("cls");
		data = b.menuWorkData();
		switch (data) {
		case 0:
			addBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 1:
			showBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 2:
			updateBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 3:
			delBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 4:
			sortBus(mas_of_bus, number_of_bus);
			system("cls");
			break;
		case 5:
			searchBus(mas_of_bus, number_of_bus);
			system("cls");
			break;
		case 6:
			data = 7;
			break;
		}
	}
}

void modulGlavnAdmin(Accounts*& mas_of_accounts, int& number_of_accounts, Bus*& mas_of_bus, int& number_of_bus, string login) {
	int m = 0;
	Interface<string> b("Модуль главного администратора " + login);
	while (m != 3) {
		system("cls");
		m = b.menuAdmin();
		switch (m) {
		case 0:
			workAccount(mas_of_accounts, number_of_accounts, login);
			break;
		case 1:
			workDataAdmin(mas_of_bus, number_of_bus, login);
			break;
		case 2:
			m = 3;
			break;
		}
	}
}

void modulAdmin(Accounts*& mas_of_accounts, int& number_of_accounts, Bus*& mas_of_bus, int& number_of_bus, string login) {
	int m = 0;
	Interface<string> b("Модуль администратора " + login);
	while (m != 3) {
		system("cls");
		m = b.menuAdmin();
		switch (m) {
		case 0:
			workAccountUser(mas_of_accounts, number_of_accounts, login);
			break;
		case 1:
			workData(mas_of_bus, number_of_bus, login);
			break;
		case 2:
			m = 3;
			break;
		}
	}
}

void Registration(Accounts*& mas_of_accounts, int& number_of_accounts, int r) {
	number_of_accounts++;
	Accounts* ptr = new Accounts[number_of_accounts];
	copy(mas_of_accounts, mas_of_accounts + number_of_accounts - 1, ptr);
	mas_of_accounts = ptr;
	ptr = NULL;
	delete[]ptr;
	addAccounts(mas_of_accounts, number_of_accounts, r);
	writeFileAccounts(mas_of_accounts, number_of_accounts);
}

void Authorization(Accounts*& mas_of_accounts, int& number_of_accounts, Bus* mas_of_bus, int& number_of_bus)
{
	if (number_of_accounts != 0) {
		bool power = true;
		string log, pass;
		int exit, quit;
		while (power)
		{
			exit = 0, quit = 0;
			cout << "Логин: ";
			log = vvodLogin();
			cout << "Пароль: ";
			pass = vvodPassword();
			for (int i = 0; i < number_of_accounts; i++) {
				if (log == mas_of_accounts[i].getLogin() && pass == mas_of_accounts[i].getPassword()) {
					exit++;
					if (mas_of_accounts[i].getRole() == 2 && mas_of_accounts[i].getAcess() == 1) {
						quit++;
						cout << "Вы вошли в систему как главный администратор " << mas_of_accounts[i].getLogin() << endl;
						system("pause");
						modulGlavnAdmin(mas_of_accounts, number_of_accounts, mas_of_bus, number_of_bus, mas_of_accounts[i].getLogin());
						power = false;
					}
					if (mas_of_accounts[i].getRole() == 1 && mas_of_accounts[i].getAcess() == 1) {
						quit++;
						cout << "Вы вошли в систему как администратор " << mas_of_accounts[i].getLogin() << endl;
						system("pause");
						modulAdmin(mas_of_accounts, number_of_accounts, mas_of_bus, number_of_bus, mas_of_accounts[i].getLogin());
						power = false;
					}
					if (mas_of_accounts[i].getRole() == 0 && mas_of_accounts[i].getAcess() == 1) {
						quit++;
						cout << "Вы вошли в систему как пользователь " << mas_of_accounts[i].getLogin() << endl;
						system("pause");
						workData(mas_of_bus, number_of_bus, mas_of_accounts[i].getLogin());
						power = false;
					}
				}
			}
			if (exit == 0) {
				cout << "Неправильно введен логин или пароль\n";
				break;
			}
			else if (exit != 0 && quit == 0) {
				cout << "Аккаунт не подтвержден\n";
				break;
			}
		}
	}
	else cout << "Аккаунтов нет!" << endl;
	system("pause");
}

string isLoginUniq(Accounts* mas_of_accounts, int number_of_accounts) {
	string login;
	int exit;
	while (1)
	{
		exit = 0;
		login = vvodLogin();
		for (int i = 0; i < number_of_accounts; i++) {
			if (mas_of_accounts[i].getLogin() == login) {
				cout << "Аккаунт с таким логином уже существует, выберите другой!" << endl;
				exit++;
				break;
			}

		}
		if (exit == 0) return login;
	}
}