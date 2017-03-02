/*-----------------------------*/
/*-- Лабораторная работа №10 --*/
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
			cout << "Лабораторная работа №10" << endl << endl;
			cout << "Команды:" << endl
				<< "1. Вывод всей очереди на экран" << endl
				<< "2. Добавить элемент в очередь" << endl
				<< "3. Удалить элемент из очереди" << endl
				<< "4. Выйти" << endl << endl
				<< "Введите команду: ";
			wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));
			if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
				command = _wtoi(integerTest); //Переводим число из строки в int
				break;
			}
			else {
				cout << endl << "Неверная команда";
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
				cout << endl << "Элемент был удалён из очереди" << endl;
				element.output();
			}
			else {
				cout << endl << "Очередь пуста, невозможно удалить элемент";
			}
			wait();
			break;
		case 4: //Quit
			delete interfaceStructure;
			delete integerTest;
			return 0;
		default:
			cout << "Неверная команда. Попробуйте ещё раз." << endl;
			wait();
		}
	}
}

void wait() {
	cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
	_getch();
}

template<typename TYPE>
void outputDeque(deque<TYPE>* structure) {
	deque<Interface*>::iterator Iterator = structure->begin();

	if (structure->empty()) {
		cout << endl << "Очередь пуста";
	}
	else {
		for (; Iterator != deque<Interface>::end(); ++Iterator) {
			wcout << *Iterator << endl;
		}
	}
}

void outputDeque(deque<TEST>* structure) {
	if (structure->empty()) {
		cout << endl << "Очередь пуста";
	}
	else {
		for (unsigned int i = 0; i < structure->size(); i++) {
			cout << endl << "Элемент очереди №" << (i+1) << ":" << endl;
			//cout << structure->at(i);
			structure->at(i).output();
		}
	}
}