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
};

class Phone : public Interface{
	//����� "�������"
public:
	int price;
	wstring* model;
	//����������� ������������ 
	Phone(wstring, wstring);
	Phone(int, int, int);
	Phone(wstring, wstring, int, int, int);
	//����������� �� ���������� �� ���������
	Phone();
	//���������� �����������
	Phone(Phone*);
	Phone(Phone const&);
	//����������
	~Phone();

	bool checkFirm(wstring);
	void input();
	void output();
	void setFirm(wstring);
	wstring* getFirm();
	int getPrice();
	//operator= (Phone, Phone);
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
private:
	//���������� ������ � ���������� ��������
	int buttonsNum;
};

class SensorPhone : public Phone {
public:
	SensorPhone();
	~SensorPhone();
	bool checkSystem(wstring);
	void input();
	void output();
protected:
	//������������ ������� ��������
	wstring* OS;
};

class AndroidPhone : public SensorPhone {
public:
	//������ ������������ ������� ��������
	wstring* version;
	AndroidPhone();
	AndroidPhone(wstring);
	~AndroidPhone();
	void input();
	void output();
};
#endif