/*-----------------------------*/
/*-- ������������ ������ �10 --*/
/*-----------------------------*/
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <wchar.h>
#include <deque>
#include "Phone.h"

using namespace std;

typedef Phone TEST;

void wait();
template <typename TYPE>
void outputDeque(deque<TYPE>* structure);
void outputDeque(deque<TEST>* structure);

int main()
{
	locale::global(locale("Russian"));
	setlocale(LC_ALL, "Russian");
	wcin.imbue(locale("rus_rus.866"));

	deque<TEST>* interfaceStructure = new deque<TEST>();
	TEST element;
	int command;
	wchar_t* integerTest = new wchar_t[100];

	while (true) {
		while (true) {
			system("cls");
			cout << "������������ ������ �10" << endl << endl;
			cout << "�������:" << endl
				<< "1. ����� ���� ������� �� �����" << endl
				<< "2. �������� ������� � �������" << endl
				<< "3. ������� ������� �� �������" << endl
				<< "4. �����" << endl << endl
				<< "������� �������: ";
			wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));
			if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
				command = _wtoi(integerTest); //��������� ����� �� ������ � int
				break;
			}
			else {
				cout << endl << "�������� �������";
				wait();
			}
		}
		switch (command) {
		case 1:
			outputDeque(interfaceStructure); //Output case
			wait();
			break;
		case 2: //Push
			element.input();
			interfaceStructure->push_front(element);
			break;
		case 3: //Pop
			if (interfaceStructure->size() != 0) {
				element = interfaceStructure->back();
				interfaceStructure->pop_back();
				cout << endl << "������� ��� ����� �� �������" << endl;
				element.output();
			}
			else {
				cout << endl << "������� �����, ���������� ������� �������";
			}
			wait();
			break;
		case 4: //Quit
			delete interfaceStructure;
			delete integerTest;
			return 0;
		default:
			cout << "�������� �������. ���������� ��� ���." << endl;
			wait();
		}
	}
}

void wait() {
	cout << endl << "������� ����� ������� ��� �����������..." << endl;
	_getch();
}

template<typename TYPE>
void outputDeque(deque<TYPE>* structure) {
	deque<Interface*>::iterator Iterator = structure->begin();

	if (structure->empty()) {
		cout << endl << "������� �����";
	}
	else {
		for (; Iterator != deque<Interface>::end(); ++Iterator) {
			wcout << *Iterator << endl;
		}
	}
}

void outputDeque(deque<TEST>* structure) {
	if (structure->empty()) {
		cout << endl << "������� �����";
	}
	else {
		for (unsigned int i = 0; i < structure->size(); i++) {
			cout << endl << "������� ������� �" << (i+1) << ":" << endl;
			//cout << structure->at(i);
			structure->at(i).output();
		}
	}
}