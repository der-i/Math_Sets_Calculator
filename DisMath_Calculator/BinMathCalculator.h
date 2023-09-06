#pragma once
#include "Multiply.h"

class BinMathCalculator
{
public:
	BinMathCalculator();
	void Menu();		//����
	void Parse();		//������� ������ � ����������	//(A/B) * (A/C) | (A\B)Z(A\C) - ������
	


private:
	Multiply finalMultiply;
	Multiply aMultiply;
	Multiply bMultiply;
	Multiply cMultiply;
	int uMin, uMax;
	//������ ��� ��������
	bool CheckVecUsingTokens(std::vector<bool>);		//�������� ��� ����������, ��� ��� ������� ������������
	//�������� ������, ��� ���������� ��� ����������� � ����������� ������
	bool CheckStringForBrackets(std::string str) { return std::count(str.begin(), str.end(), '(') == std::count(str.begin(), str.end(), ')'); }

	void SetMultiple(Multiply& A, Multiply& B, Multiply& C);		//��������� ��������, ��� ������
	void SetUniversum();

};