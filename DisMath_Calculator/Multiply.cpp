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
	//std::cout << "���������� ���������: { ";
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
	//std::cout << "���������� ���������: { ";
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
	//std::cout << "���������� ���������: { ";
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
	//std::cout << "���������� ���������: { ";
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
	//std::cout << "���������� ���������: { ";
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


//��������� ������ 1
//��������� ������� 1
// 
//��������� + 1
//��������� - 1
//��������� ������� + 1
//��������� ������� - 1
// 
//��������� ������ + 
//��������� ������ - 
//��������� ������ ������� + 
//��������� ������ ������� -
// 
//��������� ������
//��������� ��������
//��������� ������ ������� 
//��������� �������� ������� 

void Multiply::HandWriteMultiple()
{
	this->multiply.clear();
	std::string buffer;
	//std::cout << "����� ������� ����� ������, ��� ���������� ����� ������� enter." << std::endl;
	std::cin.get();
	std::getline(std::cin, buffer);
	std::list<std::pair<std::string, int>> bufferForVariable;	//����� ���  �����
	std::list<int> bufferForDeleteNumber;						//����� ��� �����, ������� �� �������� ��� ���������
	std::pair<std::string, int> tempPair("", 0);				//������ ���� ��� ������� ������

	for (size_t i = 0; i < buffer.length(); i++)				//����� ����� � ������
	{
		if (buffer[i] == ' ')
		{
			tempPair.first.erase(std::remove(tempPair.first.begin(), tempPair.first.end(), ' '));
			if (tempPair.first.length() != 0)
				bufferForVariable.push_back(tempPair);			//���� ��������� ������� �����
			tempPair.first.clear();
		}
		else
		{
			tempPair.first += buffer[i];						//���������������� ������, ��� ����������� � �����
		}
	}
	if (tempPair.first.length() != 0)
		bufferForVariable.push_back(tempPair);
	for (auto& i : bufferForVariable)
		i.second = std::stoi(i.first);		//������� ������ � �����
	bool catchRecurring = true;
	for (auto& i : bufferForVariable)		//���������� ���� ���������� ��� ������
	{
		if (i.second >= this->uMin && i.second <= this->uMax)			//��������� ������ �� � ���������
			catchRecurring = this->multiply.insert(i.second).second;	//���� �� ����� � ����
		else
			bufferForDeleteNumber.push_back(i.second);					//������ ������� �� �������� � ���������
		if (!catchRecurring)											//������ ������� �� �����, ��� ��� �����������
			bufferForDeleteNumber.push_back(i.second);
		catchRecurring = true;
	}
	if (bufferForDeleteNumber.size())
	{
		std::cout << "������ ����� �� ����������, ��� ��� �� ������ � ��������� ��� ��� ������� �� ���������: ";
		for (auto& i : bufferForDeleteNumber)
			std::cout << i << ", ";
		std::cout << "\b\b." << std::endl;
	}
	else
		std::cout << "��� ����� ���������." << std::endl; 
}


void Multiply::createSet(const std::vector<int>& vecForAvaibleElem, const char& literall)
{
	int amountElem;
	do
	{
		std::cout << "������� ���������� ��������� ��� ��������� ��������� " << literall << " : ";
		std::cin >> amountElem;
	} while (amountElem > vecForAvaibleElem.size() || amountElem < 0);     //���� ��� ����, ����� ������������� �� ������� ���������� ���������.

	while (this->multiply.size() != amountElem)				//��������� ����� � ��������� ����������� �� �������
		this->multiply.insert(vecForAvaibleElem[rand() % vecForAvaibleElem.size()]);
}


void Multiply::RandomWriteMultiple(const int &multiplicity, const int &minusOrPlus, const int& parity, const char &literall)
{
	int amountElem;
	std::vector<int> vecForAvaibleElem;
	vecForAvaibleElem.reserve(this->uMax - this->uMin);			//������ ��� ���� �����, ������� �������� ��� ���� ���������
	this->multiply.clear();

	if (minusOrPlus == 0 && parity == parity::CLASSIC)		//��������� ������� ����� � ���� ��������� ������
	{
		for (int i = this->uMin; i <= this->uMax; i++)		//����� ���� �����, ������� �������� ��� ���������
			if (i % multiplicity == 0)
				vecForAvaibleElem.push_back(i);				
	}
	else if (minusOrPlus != 0 && parity == parity::CLASSIC)					//����� ��������� ���� �����������
	{
		if (minusOrPlus > 0)		//������ ������������� �����
		{
			if (this->uMax < 0)
			{
				std::cout << "������ ��������� �� ����� ������������, ��� ��� ��������� �� �������� ������ �����.";
				return;
			}
			for (int i = this->uMin; i <= this->uMax; i++)		//������� ���� ��������� ���������
				if (i % multiplicity == 0 && i >= 0)
					vecForAvaibleElem.push_back(i);
		}
		else
		{
			if (this->uMin >= 0)	//������ ������������� �����  
			{
				std::cout << "������ ��������� �� ����� ������������, ��� ��� ��������� �� �������� ������ �����.";
				return;
			}
			for (int i = this->uMin; i <= this->uMax; i++)		
				if (i % multiplicity == 0 && i < 0)
					vecForAvaibleElem.push_back(i);
		}
	}
	else // ��������� ����� ��������� �� ��������, ����� ����������� ���������
	{
		if (minusOrPlus == 0 && parity == Multiply::EVEN)							//������ ����� � + � -
		{
			for (int i = this->uMin; i <= this->uMax; i++)		
				if (i % multiplicity == 0 && i % 2 == 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus == 0 && parity == Multiply::ODD)							//�������� ����� � + � -
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && (i % 2 == 1 || i%2 == -1))
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus > 0 && parity == Multiply::EVEN)						//������ ����� ������ +
		{
			for (int i = this->uMin; i <= this->uMax; i++)		
				if (i % multiplicity == 0 && i % 2 == 0 && i >= 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus > 0 && parity == Multiply::ODD)							//�������� ����� ������ +
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && (i % 2 == 1 || i % 2 == -1) && i >= 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus < 0 && parity == Multiply::EVEN)											//������ ����� ������ -
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && i % 2 == 0 && i < 0)
					vecForAvaibleElem.push_back(i);
		}
		else if (minusOrPlus < 0 && parity == Multiply::ODD)							//�������� ����� ������ +
		{
			for (int i = this->uMin; i <= this->uMax; i++)
				if (i % multiplicity == 0 && (i % 2 == 1 || i % 2 == -1) && i < 0)
					vecForAvaibleElem.push_back(i);
		}


	} 
	createSet(vecForAvaibleElem, literall);				//��������� ����������� ����� ����, ��� ��������� ��������� �����, ������� ������� �� ���������� �������
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
	//os << "���������: { ";
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
