#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <algorithm>

class Multiply
{
public:
	enum parity
	{
		EVEN = 2,	//������
		ODD = 1,	//��������
		CLASSIC = 0	//�� ������, �� ��������
	};
	Multiply();
	Multiply(int uMin, int uMax);		
	Multiply(const Multiply& copy);
	
	void HandWriteMultiple();		//���������� ������ � ������
	void RandomWriteMultiple(const int &multiplicity = 1, const int &minusOrPlus = 0,const int &parity = parity::CLASSIC, const char &literal = ' '); //���������� ������ ��������
	//��������� (�����), "-" (0>) ��� + (0<), �������� �� �����, � ������� ���������, ��� ����� ��������� ������
	
	void SetUniversum(int uMin, int uMax); //��������� ����������
	bool Empty();		//������ ��������� ��������� �� INT_MAX, �� INT_MIN � ������ ���������
	void Clear();		//�������


	//Operations
	Multiply operator +(const Multiply& other);	// 'U' - Union - �����������
	Multiply operator -(const Multiply& other); // '^' - intersection - �����������
	Multiply operator /(const Multiply& other); // '\' - difference - ��������
	Multiply operator *(const Multiply& other); // 'Z' - simetrical defference - ����������� ��������
	Multiply operator --();						// '-' - complement - ����������
	Multiply& operator = (const Multiply& other);
	friend std::ostream& operator<<(std::ostream& os, const Multiply& obj);
private:
	inline void createSet(const std::vector<int>&, const char&);



	std::set<int> multiply;		//��������� ��� ���������
	int uMin, uMax;				//���������
};

