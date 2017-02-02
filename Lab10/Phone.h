#ifndef PHONE_H
#define PHONE_H

#include "iostream"
#include <string.h>

using namespace std;

class Interface {
public:
	Interface();
	virtual void input();
	virtual void output();
	virtual void serialize() = NULL;
	virtual void deserialize(std::wifstream*) = NULL;
};

class Phone : public Interface{
	//Класс "Телефон"
public:
	int price;
	wstring* model;
	//Стандартные конструкторы 
	Phone(wstring, wstring);
	Phone(int, int, int);
	Phone(wstring, wstring, int, int, int);
	//Конструктор со значениями по умолчанию
	Phone();
	//Копирующий конструктор
	Phone(Phone*);
	//Дескриптор
	~Phone();

	bool checkFirm(wstring);
	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
	void setFirm(wstring);
	wstring* getFirm();
	int getPrice();
protected:
	int screenSize[2];
	double getDiagonal();
private:
	wstring* firm;
	int getDollarPrice();
};

class ButtonPhone : public Phone {
public:
	ButtonPhone();
	~ButtonPhone();
	int getButtonsNum();

	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
private:
	//Количество кнопок у кнопочного телефона
	int buttonsNum;
};

class SensorPhone : public Phone {
public:
	SensorPhone();
	~SensorPhone();
	bool checkSystem(wstring);
	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
protected:
	//Операционная система телефона
	wstring* OS;
};

class AndroidPhone : public SensorPhone {
public:
	//Версия операционной системы телефона
	wstring* version;
	AndroidPhone();
	AndroidPhone(wstring);
	~AndroidPhone();
	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
};
#endif