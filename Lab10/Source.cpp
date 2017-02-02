/*----------------------------*/
/*-- Лабораторная работа №10 --*/
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
			cout << "Лабораторная работа №9" << endl << endl;

			cout << "Команды:" << endl
				<< "1. Вывод всей очереди на экран" << endl
				<< "2. Добавить элемент в очередь" << endl
				<< "3. Удалить элемент из очереди" << endl
				<< "4. Сериализация структуры" << endl
				<< "5. Десериализация структуры" << endl
				<< "6. Выйти" << endl << endl
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
				cout << "Выберите тип элемента, который вы добавите в очередь:" << endl
					<< "1. Phone" << endl
					<< "2. ButtonPhone" << endl
					<< "3. SensorPhone" << endl
					<< "4. AndroidPhone" << endl << endl
					<< "Введите команду: ";
				wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));

				if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
					command = _wtoi(integerTest); //Переводим число из строки в int
					if ((command > 0) && (command < 5)) {
						break;
					}
					else {
						cout << endl << "Неверная команда";
						wait();
					}
				}
				else {
					cout << endl << "Неверная команда";
					wait();
				}
			}
			switch (command) {
			case 1:
				cout << endl << "Объект Phone: " << endl;
				interfaceElement = new Phone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			case 2:
				cout << endl << "Объект ButtonPhone: " << endl;
				interfaceElement = new ButtonPhone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			case 3:
				cout << endl << "Объект SensorPhone: " << endl;
				interfaceElement = new SensorPhone();
				interfaceElement->input();
				interfaceStructure->push_front(interfaceElement);
				interfaceElement = NULL;
				break;
			case 4:
				cout << endl << "Объект AndroidPhone: " << endl;
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
				cout << endl << "Элемент был удалён из очереди" << endl;
				interfaceElement->output();
				delete interfaceElement;
			}
			else {
				cout << endl << "Очередь пуста, невозможно удалить элемент";
			}
			wait();
			break;
		case 4:
			cout << endl << "Сериализация структуры" << endl;
			//structure->serialize();
			cout << endl << "В данной лабораторной работе функция отключена" << endl;
			wait();
			break;
		case 5:
			cout << endl << "Десериализация структуры" << endl;
			//delete structure; //Перезаписывание старой структуры
			//structure = new Structure();
			//structure->deserialize();
			cout << endl << "В данной лабораторной работе функция отключена" << endl;
			wait();
			break;
		case 6: //Quit
			delete interfaceStructure;
			delete integerTest;
			return 0;
		default:
			cout << "Неверная команда. Попробуйте ещё раз." << endl;
			wait();
			delete integerTest;
		}
	}
}

void wait() {
	cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
	_getch();
}

template<typename TYPE>
void outputDeque(deque<TYPE*>* structure) {
	if (structure->empty()) {
		cout << endl << "Очередь пуста";
	}
	else {
		for (unsigned int i = 0; i < structure->size(); i++) {
			cout << endl << "Элемент очереди №" << (i+1) << ":" << endl;
			cout << structure->at(i);
		}
	}
}

void outputDeque(deque<Interface*>* structure) {
	if (structure->empty()) {
		cout << endl << "Очередь пуста";
	}
	else {
		for (unsigned int i = 0; i < structure->size(); i++) {
			cout << endl << "Элемент очереди №" << (i+1) << ":" << endl;
			structure->at(i)->output();
		}
	}
}