#pragma once
#include "settings.h"

template<class T>
class Interface {
private:
	T data;
public:
	Interface() {
		data = 0;
	}
	Interface(T dat) {
		data = dat;
	}
	int menuMain();
	int menuSort();
	int menuSearch();
	int menuUpdate();
	int menuWorkData();
	int menuStatus();
	int menuAccount();
	int menuWorkAccount();
	int menuAdmin();
};

template<class T> int Interface<T>::menuMain() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {

		ViborPunktaMenu = (ViborPunktaMenu + 3) % 3;

		cout << "����� ����������\n";

		if (ViborPunktaMenu == 0) {
			setColor(9, 0);
			cout << "->�����������" << endl;
			setColor(15, 0);
		}
		else {
			cout << "�����������" << endl;
		}

		if (ViborPunktaMenu == 1) {
			setColor(9, 0);
			cout << "->�����������" << endl;
			setColor(15, 0);
		}
		else {
			cout << "�����������" << endl;
		}

		if (ViborPunktaMenu == 2) {
			setColor(9, 0);
			cout << "->�����" << endl;
			setColor(15, 0);
		}
		else {
			cout << "�����" << endl;
		}

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuSort() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 4) % 4;

		if (ViborPunktaMenu == 0) cout << "->���������� �� �����" << endl;
		else cout << "���������� �� �����" << endl;

		if (ViborPunktaMenu == 1) cout << "->���������� ���-�� ����" << endl;
		else cout << "���������� ���-�� ����" << endl;

		if (ViborPunktaMenu == 2) cout << "->���������� �� ���� �������" << endl;
		else cout << "���������� �� ���� �������" << endl;

		if (ViborPunktaMenu == 3) cout << "->����� � ���� ������ � �������" << endl;
		else cout << "����� � ���� ������ � �������" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuUpdate() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		cout << "�������������� " << data << "-��� ��������" << endl;
		ViborPunktaMenu = (ViborPunktaMenu + 10) % 10;

		if (ViborPunktaMenu == 0) cout << "->������" << endl;
		else cout << "������" << endl;

		if (ViborPunktaMenu == 1) cout << "->������� ��������" << endl;
		else cout << "������ ��������" << endl;

		if (ViborPunktaMenu == 2) cout << "->��� ��������" << endl;
		else cout << "��� ��������" << endl;

		if (ViborPunktaMenu == 3) cout << "->�������� ��������" << endl;
		else cout << "�������� ��������" << endl;

		if (ViborPunktaMenu == 4) cout << "->����� ��������" << endl;
		else cout << "����� ��������" << endl;

		if (ViborPunktaMenu == 5) cout << "->����� ��������" << endl;
		else cout << "����� ��������" << endl;

		if (ViborPunktaMenu == 6) cout << "->���-�� ����" << endl;
		else cout << "���-�� ����" << endl;

		if (ViborPunktaMenu == 7) cout << "->����" << endl;
		else cout << "����" << endl;

		if (ViborPunktaMenu == 8) cout << "->��� �������" << endl;
		else cout << "��� �������" << endl;

		if (ViborPunktaMenu == 9) cout << "->����� � ���� ������ � �������" << endl;
		else cout << "����� � ���� ������ � �������" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuSearch() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 4) % 4;

		if (ViborPunktaMenu == 0) cout << "->����� �� �������" << endl;
		else cout << "����� �� �������" << endl;

		if (ViborPunktaMenu == 1) cout << "->����� �� �����" << endl;
		else cout << "����� �� �����" << endl;

		if (ViborPunktaMenu == 2) cout << "->����� �� ���� �������" << endl;
		else cout << "����� �� ���� �������" << endl;

		if (ViborPunktaMenu == 3) cout << "->����� � ���� ������ � �������" << endl;
		else cout << "����� � ���� ������ � �������" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuWorkData() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 7) % 7;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->���������� ��������" << endl;
		else cout << "���������� ��������" << endl;

		if (ViborPunktaMenu == 1) cout << "->�������� ���������" << endl;
		else cout << "�������� ���������" << endl;

		if (ViborPunktaMenu == 2) cout << "->�������������� ������ ��������" << endl;
		else cout << "�������������� ������ ��������" << endl;

		if (ViborPunktaMenu == 3) cout << "->�������� ��������" << endl;
		else cout << "�������� ��������" << endl;

		if (ViborPunktaMenu == 4) cout << "->���������� ���������" << endl;
		else cout << "���������� ���������" << endl;

		if (ViborPunktaMenu == 5) cout << "->����� ���������" << endl;
		else cout << "����� ���������" << endl;

		if (ViborPunktaMenu == 6) cout << "->�����" << endl;
		else cout << "�����" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuStatus() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 3) % 3;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->�������" << endl;
		else cout << "�������" << endl;

		if (ViborPunktaMenu == 1) cout << "->��������" << endl;
		else cout << "��������" << endl;

		if (ViborPunktaMenu == 2) cout << "->������" << endl;
		else cout << "������" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuAccount() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 5) % 5;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->�������� �����" << endl;
		else cout << "�������� �����" << endl;

		if (ViborPunktaMenu == 1) cout << "->�������� ������" << endl;
		else cout << "�������� ������" << endl;

		if (ViborPunktaMenu == 2) cout << "->�������� ����" << endl;
		else cout << "�������� ����" << endl;

		if (ViborPunktaMenu == 3) cout << "->�������� ������" << endl;
		else cout << "�������� ������" << endl;

		if (ViborPunktaMenu == 4) cout << "->����� � ���� ������ � ����������" << endl;
		else cout << "����� � ���� ������ � ����������" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuWorkAccount() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 5) % 5;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->�������� ���������" << endl;
		else cout << "�������� ���������" << endl;

		if (ViborPunktaMenu == 1) cout << "->���������� ��������" << endl;
		else cout << "���������� ��������" << endl;

		if (ViborPunktaMenu == 2) cout << "->�������������� ������ ���������" << endl;
		else cout << "�������������� ������ ���������" << endl;

		if (ViborPunktaMenu == 3) cout << "->�������� ���������" << endl;
		else cout << "�������� ���������" << endl;

		if (ViborPunktaMenu == 4) cout << "->����� � ������ ��������������" << endl;
		else cout << "����� � ������ ��������������" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuAdmin() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 3) % 3;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->������ ������ � ����������" << endl;
		else cout << "������ ������ � ����������" << endl;

		if (ViborPunktaMenu == 1) cout << "->������ ������ � ������� ���������" << endl;
		else cout << "������ ������ � ������� ���������" << endl;

		if (ViborPunktaMenu == 2) cout << "->����� � ������� ����" << endl;
		else cout << "����� � ������� ����" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}