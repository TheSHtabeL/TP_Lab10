#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Phone.h"

#define dollarCourse 63;
using namespace std;

//Абстрактный класс "Интерфейс"
Interface::Interface()
{

}
void Interface::input()
{

}
void Interface::output()
{

}
void Interface::serialize() {

}
void Interface::deserialize(wifstream* file) {

}

Phone::Phone(wstring model, wstring firm) {
	price = -1;
	this->model = new wstring(model);
	//wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), model);
	this->firm = new wstring(firm);
	//wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), firm);
	screenSize[0] = -1;
	screenSize[1] = -1;
}
Phone::Phone(int price, int screenLength, int screenHeight) {
	model = new wstring(L"none");
	//wcscpy_s(model, (_msize(this->model) / sizeof(wchar_t)), L"none");
	firm = new wstring(L"none");
	//wcscpy_s(firm, (_msize(this->firm) / sizeof(wchar_t)), L"none");
	this->price = price;
	screenSize[0] = screenLength;
	screenSize[1] = screenHeight;
}
Phone::Phone(wstring model, wstring firm, int price, int screenLength, int screenHeight) {
	this->model = new wstring(model);
	//wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), model);
	this->firm = new wstring(firm);
	//wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), firm);
	this->price = price;
	screenSize[0] = screenLength;
	screenSize[1] = screenHeight;
}
Phone::Phone(){
	price = -1;
	this->model = new wstring(L"none");
	//wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), L"default");
	screenSize[0] = -1;
	screenSize[1] = -1;
	this->firm = new wstring(L"none");
	//wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), L"default");
}
Phone::Phone(Phone* original) {
	this->model = new wstring(original->model->data());
	this->firm = new wstring(original->firm->data());
	this->price = original->price;
	//this->model = new string(original->model); TO DO
	//wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), original->model);
	this->screenSize[0] = original->screenSize[0];
	this->screenSize[1] = original->screenSize[1];
	//this->firm = new string(original->firm); TO DO
 	//wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), original->firm);
}
Phone::~Phone() {
	delete firm;
	delete model;
}
bool Phone::checkFirm(wstring firm) {
	//Метод сообщает, был ли выпущен телефон указанным производителем
	return this->firm->compare(firm) == 0 ? true : false;
}
int Phone::getPrice() {
	return price;
}
void Phone::input() {
	//Метод для ручного ввода значений для переменных класса
	wchar_t* integerTest = new wchar_t[100];
	wstring readFromStream;

	cout << "Введите фирму-производителя телефона: ";
	//wcin.getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	//firm->assign(integerTest);
	getline(wcin, readFromStream);
	firm->assign(readFromStream);
	cout << "Введите модель телефона: ";
	//wcin.getline(model, (_msize(model) / sizeof(wchar_t)));
	getline(wcin, readFromStream);
	model->assign(readFromStream);
	_flushall();
	while (true) {
		cout << "Введите цену телефона: ";
		wcin >> integerTest;
		//Чистим поток ввода
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
			price = _wtoi(integerTest); //Переводим число из строки в int
			if (price < 0) {
				cout << "Цена телефона должна быль положительным значением или нулём. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "Введите ширину экрана телефона в сантиметрах: ";
		wcin >> integerTest;
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) {
			screenSize[0] = _wtoi(integerTest);
			if (screenSize[0] <= 0) {
				cout << "Получено некорректное значение. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "Введите длину экрана телефона в сантиметрах: ";
		wcin >> integerTest;
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) {
			screenSize[1] = _wtoi(integerTest);
			if (screenSize[1] <= 0) {
				cout << "Было получено некорректное значение. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	delete integerTest;
}
void Phone::output() {
	cout << "Фирма: ";
	wcout << firm->data() << endl;
	cout << "Модель телефона: ";
	wcout << model->data() << endl;
	cout << "Цена: " << endl;
	cout << price << " в рублях" << endl;
	cout << getDollarPrice() << " в долларах" << endl;
	cout << "Разрешение экрана: " << screenSize[0] << "см x " << screenSize[1] << "см" << endl;
	cout << "Диагональ: " << getDiagonal() << " дюйм." << endl;
}
double Phone::getDiagonal() {
	//Метод возвращает диагональ экрана телефона в дюймах
	if ((screenSize[0] > 0) && (screenSize[1] > 0)) {
		return sqrt((screenSize[0] / 2.54)*(screenSize[0] / 2.54) + (screenSize[1] / 2.54)*(screenSize[1] / 2.54));
	}
	else {
		return -1;
	}
}
int Phone::getDollarPrice() {
	//Метод возвращает цену телефона, конвертированную в доллары
	return (int)price / dollarCourse;
}
void Phone::serialize() {
	//Метод отвечает за сериализацию элемента структуры
	//В файл записываются все данные элемента, а его тип обозначается идентификатором
	/*wofstream file("Saved Structure.txt", ios_base::app);
	file << "#Phone" << endl; //Идентификатор для упрощения считывания данных из файла
	file << model << endl;
	file << firm << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file.close();*/
}
void Phone::deserialize(wifstream* file) {
	//Метод, отвечающий за десериализацию элемента структуры
	wchar_t* integerTest = new wchar_t[100];

	/*file->getline(model, (_msize(model)/sizeof(wchar_t)) );
	file->getline(firm, (_msize(firm) / sizeof(wchar_t)) );
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);
	delete integerTest;*/
}
wstring* Phone::getFirm() {
	return firm;
}
void Phone::setFirm(wstring firm){
	this->firm->assign(firm);
}

/*ButtonPhone::ButtonPhone() : Phone() {
	buttonsNum = -1;
}
ButtonPhone::~ButtonPhone() {
}
int ButtonPhone::getButtonsNum() {
	//Метод возвращает количество кнопок телефона
	return (buttonsNum == NULL) ? -1 : buttonsNum;
}
void ButtonPhone::input() {
	//Метод для ручного ввода значений для переменных класса
	Phone::input();
	wchar_t* integerTest = new wchar_t[100];

	while (true) {
		cout << "Введите количество кнопок у телефона: ";
		wcin >> integerTest;
		//Чистим поток ввода
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
			buttonsNum = _wtoi(integerTest); //Переводим число из строки в int
			if (buttonsNum < 0) {
				cout << "Количество кнопок должно быть положительным значением или нулём. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	delete integerTest;
}
void ButtonPhone::output() {
	//Метод вывода данных
	Phone::output();
	cout << "Количество кнопок у телефона: " << buttonsNum << endl;
}
void ButtonPhone::serialize() {
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#ButtonPhone" << endl;
	file << model << endl;
	file << Phone::getFirm() << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file << buttonsNum << endl;
	file.close();
}
void ButtonPhone::deserialize(wifstream* file) {
	//Метод, отвечающий за десериализацию элемента структуры
	wchar_t* integerTest = new wchar_t[100];
	
	file->getline(model, (_msize(model) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	setFirm(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	buttonsNum = _wtoi(integerTest);
	
	delete integerTest;
}

SensorPhone::SensorPhone() : Phone() {
	this->OS = new wchar_t[100];
	wcscpy_s(this->OS, (_msize(this->OS)) / sizeof(wchar_t), L"default");
}
SensorPhone::~SensorPhone() {
	delete OS;
}
bool SensorPhone::checkSystem(wchar_t testOS[]) {
	//Метод принимает на вход название операционной системы и возвращает ответ на вопрос
	//"Имеет ли телефон данную операционную систему?"
	return wcscmp(OS, testOS) ? true : false;
}
void SensorPhone::input() {
	//Метод для ручного ввода значений для переменных класса
	Phone::input();
	cout << "Введите название операционной системы телефона: ";
	wcin.getline(OS, (_msize(OS) / sizeof(wchar_t)));
}
void SensorPhone::output() {
	//Метод вывода данных
	Phone::output();
}
void SensorPhone::serialize() {
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#SensorPhone" << endl;
	file << model << endl;
	file << Phone::getFirm() << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file << OS << endl;
	file.close();
}
void SensorPhone::deserialize(wifstream* file) {
	//Метод, отвечающий за десериализацию элемента структуры
	wchar_t* integerTest = new wchar_t[100];

	file->getline(model, (_msize(model) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	setFirm(integerTest);
	file->getline(OS, (_msize(OS) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);
	
	delete integerTest;
}

AndroidPhone::AndroidPhone() : SensorPhone(){
	this->version = new wchar_t[100];
	wcscpy_s(this->version, _msize(this->version) / sizeof(wchar_t), L"none");
}
AndroidPhone::AndroidPhone(wchar_t version[] = L"default") : SensorPhone() {
	this->version = new wchar_t[100];
	wcscpy_s(this->version, _msize(this->version) / sizeof(wchar_t), version);
}
AndroidPhone::~AndroidPhone() {
	delete version;
}
void AndroidPhone::input() {
	//Метод для ручного ввода значений для переменных класса
	SensorPhone::input();

	cout << "Введите версию Android: ";
	wcin.getline(version, _msize(version) / sizeof(wchar_t));
}
void AndroidPhone::serialize() {
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#AndroidPhone" << endl;
	file << model << endl;
	file << Phone::getFirm() << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file << OS << endl;
	file << version << endl;
	file.close();
}
void AndroidPhone::deserialize(wifstream* file) {
	//Метод, отвечающий за десериализацию элемента структуры
	wchar_t* integerTest = new wchar_t[100];

	file->getline(model, (_msize(model) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	setFirm(integerTest);
	file->getline(OS, (_msize(OS) / sizeof(wchar_t)));
	file->getline(version, (_msize(version) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);

	delete integerTest;
}

void AndroidPhone::output() {
	//Метод вывода данных
	cout << "Версия операционной системы: ";
	wcout << version << endl;
	SensorPhone::output();
}*/