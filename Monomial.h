#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;


class Monomial
{
	//��� ���� ������� ����������� �� ���������� � ��������� �������� �����. ������
	Monomial* next = nullptr;
	Monomial* prev = nullptr;

	double coefficient = 1;
	vector<int> powers; //������ ��� �������� ��������
	vector<char> variables; //������ ��� �������� ����������

	//�������, ������� ������������ ��� �������������(���������� �������)
	void obj_init(const char* value);
	
public:
	Monomial() = default;

	//����������� ����(�����������, �������, ����������)
	Monomial(double coeff, const vector<int>& powers, const vector<char>& variables)
	{
		coefficient = coeff;
		this->powers = powers;
		this->variables = variables;
	}

	//���������� ����(char* �5*x^2y^3z�)
	Monomial(const char* value)
	{
		obj_init(value);
	}

	//����������
	~Monomial() {}

	//���������� ��������/�������� �������� ������ ������
	double GetCoefficient()
	{
		return coefficient;
	}
	void SetCoefficient(double value)
	{
		this->coefficient = value;
	}
	vector<int>& GetPowers()
	{
		return powers;
	}
	void SetPowers(vector<int>& v)
	{
		this->powers = v;
	}
	vector<char>& GetVariables()
	{
		return variables;
	}
	Monomial& GetNext() const
	{
		return *next;
	}
	void SetNext(Monomial& obj)
	{
		next = &obj;
	}
	Monomial& GetPrev() const
	{
		return *prev;
	}
	void SetPrev(Monomial& obj)
	{
		prev = &obj;
	}

	//��������� ����������
	void operator=(const Monomial& obj);
	
	Monomial operator*(const Monomial& obj);
	
	Monomial operator/(const Monomial& obj);
	
	Monomial& operator*=(const Monomial& obj);
	
	Monomial& operator/=(const Monomial& obj);
	
	bool operator==(const Monomial& obj);
	
	bool operator!=(const Monomial& obj);
	

	friend ostream& operator<<(ostream& os, const Monomial& obj);
	friend istream& operator>>(istream& is, Monomial& obj);


};

