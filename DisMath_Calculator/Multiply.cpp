#include "Multiply.h"

Multiply::Multiply()
{
	this->uMin = INT_MIN;
	this->uMax = INT_MAX;
}

Multiply::Multiply(int uMin, int uMax)
{
	this->uMin = uMin;
	this->uMax = uMax;
}

Multiply::Multiply(const Multiply& copy)
{
	this->multiply = copy.multiply;
	this->uMin = copy.uMin;
	this->uMax = copy.uMax;
}


Multiply Multiply::operator+(const Multiply& other)
{
	Multiply temp(this->uMin, this->uMax);
	temp.multiply.insert(this->multiply.begin(), this->multiply.end());
	temp.multiply.insert(other.multiply.begin(), other.multiply.end());

	//// OUTPUT
	//std::cout << "Полученное множество: { ";
	//for (auto& i : temp.multiply)
	//	std::cout << i << ", ";
	//if (temp.multiply.size())
	//	std::cout << "\b\b }" << std::endl;
	//else
	//	std::cout << " }" << std::endl;
	return temp;
}

Multiply Multiply::operator-(const Multiply& other)
{
	Multiply temp(this->uMin, this->uMax);
	for (auto& i : this->multiply)
		if (other.multiply.find(i) != other.multiply.end())
			temp.multiply.insert(i);

	//// OUTPUT
	//std::cout << "Полученное множество: { ";
	//for (auto& i : temp.multiply)
	//	std::cout << i << ", ";
	//if (temp.multiply.size())
	//	std::cout << "\b\b }" << std::endl;
	//else
	//	std::cout << " }" << std::endl;
	return temp;

}

Multiply Multiply::operator/(const Multiply& other)
{
	Multiply temp(this->uMin, this->uMax);
	for (auto& i : this->multiply)
		if (other.multiply.find(i) == other.multiply.end())
			temp.multiply.insert(i);
	//// OUTPUT
	//std::cout << "Полученное множество: { ";
	//for (auto& i : temp.multiply)
	//	std::cout << i << ", ";
	//if (temp.multiply.size())
	//	std::cout << "\b\b }" << std::endl;
	//else
	//	std::cout << " }" << std::endl;
	return temp;
}

Multiply Multiply::operator*(const Multiply& other)
{
	Multiply temp(this->uMin, this->uMax);
	for (auto& i : this->multiply)
		if (other.multiply.find(i) == other.multiply.end())
			temp.multiply.insert(i);

	for (auto& i : other.multiply)
		if (this->multiply.find(i) == this->multiply.end())
			temp.multiply.insert(i);

	// //OUTPUT
	//std::cout << "Полученное множество: { ";
	//for (auto& i : temp.multiply)
	//	std::cout << i << ", ";
	//if (temp.multiply.size())
	//	std::cout << "\b\b }" << std::endl;
	//else
	//	std::cout << " }" << std::endl;
	return temp;
}

Multiply Multiply::operator--()
{
	Multiply temp(this->uMin, this->uMax);
	for (int i = this->uMin; i <= uMax; i++)
		temp.multiply.insert(i);
	for (auto& i : this->multiply)
		temp.multiply.erase(i);
	// //OUTPUT
	//std::cout << "Полученное множество: { ";
	//for (auto& i : temp.multiply)
	//	std::cout << i << ", ";
	//if (temp.multiply.size())
	//	std::cout << "\b\b }" << std::endl;
	//else
	//	std::cout << " }" << std::endl;
	return temp;
}

Multiply& Multiply::operator=(const Multiply& other)
{
	this->multiply = other.multiply;
	this->uMin = other.uMin;
	this->uMax = other.uMax;
	return *this;
}


//генерация просто 1
//генерация кратных 1
// 
//генерация + 1
//генерация - 1
//генерация кратных + 1
//генерация кратных - 1
// 
//генерация четных + 
//генерация четных - 
//генерация четных кратных + 
//генерация четных кратных -
// 
//генерация четных
//генерация нечетных
//генерация четных кратных 
//генерация нечетных кратных 

void Multiply::HandWriteMultiple()
{
	this->multiply.clear();
	std::string buffer;
	//std::cout << "Числа вводить через пробел, для завершения ввода нажмите enter." << std::endl;
	std::cin.get();
	std::getline(std::cin, buffer);
	std::list<std::pair<std::string, int>> bufferForVariable;	//буфер для  числа
	std::list<int> bufferForDeleteNumber;						//буфер для чисел, которые не подходят под универсум
	std::pair<std::string, int> tempPair("", 0);				//просто пара для удобной рабоыт

	for (size_t i = 0; i < buffer.length(); i++)				//поиск чисел в строке
	{
		if (buffer[i] == ' ')
		{
			tempPair.first.erase(std::remove(tempPair.first.begin(), tempPair.first.end(), ' '));
			if (tempPair.first.length() != 0)
				bufferForVariable.push_back(tempPair);			//если полностью заисали число
			tempPair.first.clear();
		}
		else
		{
			tempPair.first += buffer[i];						//конкотанирование строки, для превращения в число
		}
	}
	if (tempPair.first.length() != 0)
		bufferForVariable.push_back(tempPair);
	for (auto& i : bufferForVariable)
		i.second = std::stoi(i.first);		//перевод строки в число
	bool catchRecurring = true;
	for (auto& i : bufferForVariable)		//заполнения сета происходит вот отсюда
	{
		if (i.second >= this->uMin && i.second <= this->uMax)			//проверяем входит ли в универсум
			catchRecurring = this->multiply.insert(i.second).second;	//есть ли число в сете
		else
			bufferForDeleteNumber.push_back(i.second);					//данные которые не попадают в универсум
		if (!catchRecurring)											//данные которые не вошли, так как повторяются
			bufferForDeleteNumber.push_back(i.second);
		catchRecurring = true;
	}
	if (bufferForDeleteNumber.size())
	{
		std::cout << "Данные числа не добавленны, так как не входят в универсум или уже имеются во множестве: ";
		for (auto& i : bufferForDeleteNumber)
			std::cout << i << ", ";
		std::cout << "\b\b." << std::endl;
	}
	else
		std::cout << "Все числа добавлены." << std::endl; 
}


void Multiply::createSet(const std::vector<int>& vecForAvaibleElem, const char& literall)
{
	int amountElem;
	do
	{
		std::cout << "Введите количество элементов для генерации множества " << literall << " : ";
		std::cin >> amountElem;
	} while (amountElem > vecForAvaibleElem.size() || amountElem < 0);     //блок для того, чтобы сгенерировать не большее количетсво элементов.

	while (this->multiply.size() != amountElem)				//генерация чисел и случайное длобавление из массива
		this->multiply.insert(vecForAvaibleElem[rand() % vecForAvaibleElem.size()]);
}


void Multiply::RandomWriteMultiple(const int &multiplicity, const int &minusOrPlus, const int& parity, const char &literall)
{
	int amountElem;
	std::vector<int> vecForAvaibleElem;
	vecForAvaibleElem.reserve(this->uMax - this->uMin);			//вектор для всех чисел, которые подходят под наши параметры
	this->multiply.clear();

	if (minusOrPlus == 0 && parity == parity::CLASSIC)		//генерация кратных чисел и всех остальных подряд
	{
		for (int i = this->uMin; i <= this->uMax; i++)		//отбор всех чисел, которые подходят под параметры
			if (i % multiplicity == 0)
				vecForAvaibleElem.push_back(i);				
	}
	else if (minusOrPlus != 0 && parity == parity::CLASSIC)					//далее структура идет аналогичная
	{
		if (minusOrPlus > 0)		//только положительные числа
		{
			if (this->uMax < 0)
			{
				std::cout << "Такого множества не может существовать, так как универсум не включает данные числа.";
				return;
			}
			for (int i = this->uMin; i <= this->uMax; i++)		//выборка всех доступных элементов
				if (i % multiplicity == 0 && i >= 0)
					vecForAvaibleElem.push_back(i);
		}
		else
		{
			if (this->uMin >= 0)	//только отрицательные числа  
			{
				std::cout << "Такого множества не может существовать, так как универсум не включает данные числа.";
				return;
			}
			for (int i = this->uMin; i <= this->uMax; i++)		
				if (i % multiplicity == 0 && i < 0)
					vecForAvaibleElem.push_back(i);
		}
	}
	else // генерация чисел зависящая от четности, также учитывается кратность
	{
		if (minusOrPlus == 0 && parity == Multiply::EVEN)							//четные числа и + и -
		{
			for (int i = this->uMin; i <= this->uMax; i++)		
				if (i % multiplicity == 0 && i % 2 == 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus == 0 && parity == Multiply::ODD)							//нечетные числа и + и -
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && (i % 2 == 1 || i%2 == -1))
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus > 0 && parity == Multiply::EVEN)						//четные числа только +
		{
			for (int i = this->uMin; i <= this->uMax; i++)		
				if (i % multiplicity == 0 && i % 2 == 0 && i >= 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus > 0 && parity == Multiply::ODD)							//нечетные числа только +
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && (i % 2 == 1 || i % 2 == -1) && i >= 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus < 0 && parity == Multiply::EVEN)											//четные числа только -
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && i % 2 == 0 && i < 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus < 0 && parity == Multiply::ODD)							//нечетные числа только +
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && (i % 2 == 1 || i % 2 == -1) && i < 0)
					vecForAvaibleElem.push_back(i);
		}


	} 
	createSet(vecForAvaibleElem, literall);				//замещение одинакового блока кода, для генерации случайных чисел, которые берутся из собранного вектора
}

void Multiply::SetUniversum(int uMin, int uMax)
{
	this->uMin = uMin;
	this->uMax = uMax;
	std::vector<int> buffer;
	buffer.reserve(this->multiply.size());
	for (auto& i : this->multiply)
		if (i < uMin || i > uMax)
			buffer.push_back(i);
	for (size_t i = 0; i < buffer.size(); i++)
		this->multiply.erase(buffer[i]);

}

bool Multiply::Empty()
{
	if (this->uMin == INT_MIN && this->uMax == INT_MAX && this->multiply.empty())
		return true;
	return false;
}

void Multiply::Clear()
{
	this->uMax = INT_MAX;
	this->uMin = INT_MIN;
	this->multiply.clear();
}

std::ostream& operator<<(std::ostream& os, const Multiply& obj)
{
	//os << "Множество: { ";
	if (!obj.multiply.size())
		std::cout << "}" << std::endl;
	else
	{
		for (auto& i : obj.multiply)
			std::cout << i << ", ";
		std::cout << "\b\b }" << std::endl;
	}
	return os;
}
