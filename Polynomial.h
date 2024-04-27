#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
#include "Monomial.h"

using namespace std;

class Polynomial
{
	vector<char> operations; //������, � ������� �������� ����� �������
	Monomial* head = nullptr, * tail = nullptr; //��������� �� ������ � ����� �����. ������

	//��������� ��������� ��� �������� ������� � ���������
	Monomial* temp;
	Polynomial* temp_p;

	//�������, ������� ��������� ������(�����) � ����� �����. ������(�������)
	void push_back(Monomial& obj);

	//�������, ������� ������ �����. ������(������� ��������)
	void clear_s(Monomial* p)
	{
		while (p != nullptr)
		{
			Monomial* p_next = &p->GetNext();
			delete p;

			p = p_next;
		}
	}

	//�������, ������� ������������ ��� �������������(���������� �������)(�� ���������� ����� �������)
	void obj_init(const char* value);

public:
	Polynomial() = default;

	//�����������, �������� ���������� ����� �������
	Polynomial(const char* value)
	{
		this->obj_init(value);
	}

	//����������� �����������
	Polynomial(const Polynomial& obj1)
	{
		//��� �� �������� ������ �������� �� ������ ������� � ������
		this->operations = obj1.operations;

		//���� ���� ����������� �����. ������
		Monomial* p = obj1.head; //��������� �� ������ ��. ������
		Monomial* monom; //���������� ��� �������� ������
		while (p != nullptr)
		{
			monom = new Monomial(p->GetCoefficient(), p->GetPowers(), p->GetVariables());
			this->push_back(*monom);

			p = &p->GetNext();
		}


	}

	//����������
	~Polynomial()
	{
		Monomial* p = head;
		while (p != nullptr)
		{
			Monomial* p_next = &p->GetNext();
			delete p;

			p = p_next;
		}

		delete temp;
		delete temp_p;
	}

	//���������� ��������
	bool operator==(const Polynomial& obj);
	bool operator!=(const Polynomial& obj);
	Polynomial& operator=(const Polynomial& obj);
	Polynomial& operator+=(const Polynomial& obj);
	Polynomial& operator-=(const Polynomial& obj);
	Polynomial& operator*=(const Polynomial& obj);
	friend ostream& operator<<(ostream& os, const Polynomial& obj);
	friend istream& operator>>(istream& is, Polynomial& obj);

};