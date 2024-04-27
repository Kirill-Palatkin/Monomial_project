#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
#include "Monomial.h"
#include "Polynomial.h"

using namespace std;

void passByValue(Monomial monomial);
void passByReference(Monomial& monomial);
Monomial returnObject(void);


int main()
{
	setlocale(0, "");

	//����� ���������� ��������� �����
	ifstream input_file;
	input_file.open("input_file.txt");

	string line;
	vector<Polynomial*> arr_obj;
	Polynomial* temp_obj1;

	while (getline(input_file, line))
	{
		char operation[3];
		char polynomial[75];

		int size_line = line.size();
		int begin_polyn;

		for (int i = 0; i < size_line; ++i)
		{
			int counter = 0;
			temp_obj1 = nullptr;

			if (line[i] == '<')
			{
				begin_polyn = i + 1;
				while (line[begin_polyn] != '>')
					polynomial[counter++] = line[begin_polyn++];

				polynomial[counter] = '\0';

				temp_obj1 = new Polynomial(polynomial);
				arr_obj.push_back(temp_obj1);

				counter = 0;
				int j = begin_polyn + 1; //��� ������ ���� ��������

				//���� �����������
				if (line[j] == ';') continue;
				while (j < size_line - 2 && line[j] != '<')
					operation[counter++] = line[j++];

				operation[counter] = '\0';

				i = j - 1; //����� ���������� i ����� <
			}
		}

		cout << "���������: (" << *arr_obj[0] << ") " << operation << " (" << *arr_obj[1] << ")" << endl;

		string operat(operation);

		bool res, flag = false;

		if (operat == "+")
		{
			(*arr_obj[0] += *arr_obj[1]);
			cout << "\t��������� " << operat << ": " << *arr_obj[0] << endl;
		}
		else if (operat == "-")
		{
			(*arr_obj[0] -= *arr_obj[1]);
			cout << "\t��������� " << operat << ": " << *arr_obj[0] << endl;
		}
		else if (operat == "*")
		{
			(*arr_obj[0] *= *arr_obj[1]);
			cout << "\t��������� " << operat << ": " << *arr_obj[0] << endl;
		}
		else if (operat == "==") cout << "\t��������� " << operat << ": " << (*arr_obj[0] == *arr_obj[1]) << endl;
		else if (operat == "!=") cout << "\t��������� " << operat << ": " << (*arr_obj[0] != *arr_obj[1]) << endl;


		arr_obj.clear();
		flag = false;

	}

	cout << endl << endl << endl;


	Monomial m1(3, { 2, 1, 3 }, { 'x', 'z', 'h' }); // ������� ������ Monomial
	Monomial m2(4, { 1, 2, 3 }, { 'x', 'y', 'z' });

	// �������� ��������� �� ��������
	cout << "�������� ��������� �� ��������:" << endl;
	passByValue(m1);
	cout << "�������� ������� ����� ��������: " << m1 << endl;

	// �������� ��������� �� ������
	cout << "\n�������� ��������� �� ������:" << endl;
	passByReference(m2);
	cout << "�������� ������� ����� ��������: " << m2 << endl;

	// ������� ������� �� �������
	cout << "\n������� ������� �� �������:" << endl;
	Monomial returnedObject = returnObject();
	cout << "������������ ������: " << returnedObject << endl;

	return 0;
}

//������� ��� �������� ��������� �� ��������
void passByValue(Monomial monomial) {
	cout << "�������� ��������� �� ���������: " << monomial << endl;

	// �������� �������� ���������
	monomial.SetCoefficient(10);

	cout << "�������� ��������� ����� ���������: " << monomial << endl;
}

//������� ��� �������� ��������� �� ������
void passByReference(Monomial& monomial) {
	cout << "�������� ��������� �� ���������: " << monomial << endl;

	// �������� �������� ���������
	monomial.SetCoefficient(20);

	cout << "�������� ��������� ����� ���������: " << monomial << endl;
}

//������� ��� �������� �������
Monomial returnObject(void)
{
	Monomial monomial(5, { 2, 3, 1 }, { 'x', 'y', 'z' }); // ������� ������ Monomial

	// ��������� ��������� �������� � ��������
	monomial.SetCoefficient(15);

	vector<int> a = { 1, 2, 1 };
	monomial.SetPowers(a);

	return monomial; // ���������� ������
}