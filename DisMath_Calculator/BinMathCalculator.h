#pragma once
#include "Multiply.h"

class BinMathCalculator
{
public:
	BinMathCalculator();
	void Menu();		//меню
	void Parse();		//парсинг строки и вычисление	//(A/B) * (A/C) | (A\B)Z(A\C) - пример
	


private:
	Multiply finalMultiply;
	Multiply aMultiply;
	Multiply bMultiply;
	Multiply cMultiply;
	int uMin, uMax;
	//методы для проверки
	bool CheckVecUsingTokens(std::vector<bool>);		//проверка при вычислении, что все символы использованы
	//проверка строки, что существуют все открывающие и закрвыающие скобки
	bool CheckStringForBrackets(std::string str) { return std::count(str.begin(), str.end(), '(') == std::count(str.begin(), str.end(), ')'); }

	void SetMultiple(Multiply& A, Multiply& B, Multiply& C);		//установка множеств, для тестов
	void SetUniversum();

};