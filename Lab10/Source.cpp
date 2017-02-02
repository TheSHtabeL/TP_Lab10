/*----------------------------*/
/*-- ������������ ������ �10 --*/
/*----------------------------*/
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <wchar.h>
#include "Phone.h"
#include "deque"

using namespace std;

void wait();
template <typename TYPE>
void outputDeque(deque<TYPE*>* structure);
void outputDeque(deque<Interface*>* structure);

int main()
{
	locale::global(std::locale("Russian"));
	setlocale(LC_ALL, "Russian");
	std::wcin.imbue(std::locale("rus_rus.866"));
	deque<Interface*>* interfaceStructure = new deque<Interface*>();
	Interface* interfaceElement;
	bool dequeType = true; //true: Object; false: standard
	int command;

	while (true) {
		wchar_t* integerTest = new wchar_t[100];
		while (true) {
			system("cls");
			cout << "������������ ������ �9" << endl << endl;

			cout << "�������:" << endl
				<< "1. ����� ���� ������� �� �����" << endl
				<< "2. �������� ������� � �������" << endl
				<< "3. ������� ������� �� �������" << endl
				<< "4. ������������ ���������" << endl
				<< "5. �������������� ���������" << endl
				<< "6. �����" << endl << endl
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
		delete integerTest;
		integerTest = new wchar_t[100];
		switch (command) {
		case 1:
			outputDeque(interfaceStructure); //Output case
			wait();
			break;
		case 2: //Push
			while (true) {
				system("cls");
				cout << "�������� ��� ��������, ������� �� �������� � �������:" << endl
					<< "1. Phone" << endl
					<< "2. ButtonPhone" << endl
					<< "3. SensorPhone" << endl
					<< "4. AndroidPhone" << endl << endl
					<< "������� �������: ";
				wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));

				if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
					command = _wtoi(integerTest); //��������� ����� �� ������ � int
					if ((command > 0) && (command < 5)) {
						break;
					}
					else {
						cout << endl << "�������� �������";
						wait();
					}
				}
				else {
					cout << endl << "�������� �������";
					wait();
				}
			}
			switch (command) {
			case 1:
				cout << endl << "������ Phone: " << endl;
				interfaceElement = new Phone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			case 2:
				cout << endl << "������ ButtonPhone: " << endl;
				interfaceElement = new ButtonPhone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			case 3:
				cout << endl << "������ SensorPhone: " << endl;
				interfaceElement = new SensorPhone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			case 4:
				cout << endl << "������ AndroidPhone: " << endl;
				interfaceElement = new AndroidPhone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			}
			break;
		case 3: //Pop
			if (interfaceStructure->size() != 0) {
				interfaceElement = interfaceStructure->back();
				interfaceStructure->pop_back();
				cout << endl << "������� ��� ����� �� �������" << endl;
				interfaceElement->output();
				delete interfaceElement;
			}
			else {
				cout << endl << "������� �����, ���������� ������� �������";
			}
			wait();
			break;
		case 4:
			cout << endl << "������������ ���������" << endl;
			//structure->serialize();
			cout << endl << "� ������ ������������ ������ ������� ���������" << endl;
			wait();
			break;
		case 5:
			cout << endl << "�������������� ���������" << endl;
			//delete structure; //��������������� ������ ���������
			//structure = new Structure();
			//structure->deserialize();
			cout << endl << "� ������ ������������ ������ ������� ���������" << endl;
			wait();
			break;
		case 6: //Quit
			delete interfaceStructure;
			delete integerTest;
			return 0;
		default:
			cout << "�������� �������. ���������� ��� ���." << endl;
			wait();
			delete integerTest;
		}
	}
}

void wait() {
	cout << endl << "������� ����� ������� ��� �����������..." << endl;
	_getch();
}

template<typename TYPE>
void outputDeque(deque<TYPE*>* structure) {
	if (structure->empty()) {
		cout << endl << "������� �����";
	}
	else {
		for (unsigned int i = 0; i < structure->size(); i++) {
			cout << endl << "������� ������� �" << (i+1) << ":" << endl;
			cout << structure->at(i);
		}
	}
}

void outputDeque(deque<Interface*>* structure) {
	if (structure->empty()) {
		cout << endl << "������� �����";
	}
	else {
		for (unsigned int i = 0; i < structure->size(); i++) {
			cout << endl << "������� ������� �" << (i+1) << ":" << endl;
			structure->at(i)->output();
		}
	}
}