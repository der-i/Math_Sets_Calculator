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
		EVEN = 2,	//четный
		ODD = 1,	//нечетный
		CLASSIC = 0	//ни четный, ни нечетный
	};
	Multiply();
	Multiply(int uMin, int uMax);		
	Multiply(const Multiply& copy);
	
	void HandWriteMultiple();		//заполнение данных в ручную
	void RandomWriteMultiple(const int &multiplicity = 1, const int &minusOrPlus = 0,const int &parity = parity::CLASSIC, const char &literal = ' '); //заполнение данных рандомно
	//кратность (число), "-" (0>) или + (0<), четность из енама, и литерал множества, для более красивого вывода
	
	void SetUniversum(int uMin, int uMax); //установка универсума
	bool Empty();		//пустое множество универсум от INT_MAX, до INT_MIN и пустое множество
	void Clear();		//очистка


	//Operations
	Multiply operator +(const Multiply& other);	// 'U' - Union - объединение
	Multiply operator -(const Multiply& other); // '^' - intersection - пересечение
	Multiply operator /(const Multiply& other); // '\' - difference - разность
	Multiply operator *(const Multiply& other); // 'Z' - simetrical defference - симитричная разность
	Multiply operator --();						// '-' - complement - дополнение
	Multiply& operator = (const Multiply& other);
	friend std::ostream& operator<<(std::ostream& os, const Multiply& obj);
private:
	inline void createSet(const std::vector<int>&, const char&);



	std::set<int> multiply;		//контейнер для множества
	int uMin, uMax;				//универсум
};

