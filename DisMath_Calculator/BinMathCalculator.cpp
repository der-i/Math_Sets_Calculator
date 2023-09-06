#include "BinMathCalculator.h"
#include <vector>
BinMathCalculator::BinMathCalculator()
{
	std::cout << "------------����������� ��������------------\n\n";
	std::cout << "����� ���������� � ����������� ��������, ��� ������ ������ ���������� ������ ������� ����������.\n\n";
	std::cout << "������� ����������� ������� ����������: ";
	std::cin >> this->uMin;
	std::cout << "������� ������������ ������� ����������: ";
	std::cin >> this->uMax;
	if (this->uMin > this->uMax) std::swap(this->uMin, this->uMax);
	this->aMultiply.SetUniversum(this->uMin, this-> uMax);
	this->bMultiply.SetUniversum(this->uMin, this->uMax);
	this->cMultiply.SetUniversum(this->uMin, this->uMax);
	this->finalMultiply.SetUniversum(this->uMin, this->uMax);
}

void BinMathCalculator::Menu()			//���� ������������
{
	int menu, submenu;
	int multiplicity = 1, plusOrMinus = 0, parity = Multiply::parity::CLASSIC;

	do
	{
		std::cout << "\033[2J\033[1;1H";
		std::cout << "------------����������� ��������------------\n\n";
		std::cout << "--------------------����--------------------\n\n";
		std::cout << " 1. ������ ���������." << std::endl;
		std::cout << " 2. ������ ���������." << std::endl;
		std::cout << " 3. �������� ���������." << std::endl;
		std::cout << " 4. ���������� ����������." << std::endl;
		std::cout << " 0. �����." << std::endl;

		std::cout << "\n> ";
		std::cin >> menu;

		switch (menu)
		{
		case 0:
			break;
		case 1:
		{
			do
			{
				std::cout << "\033[2J\033[1;1H";
				std::cout << "------------����������� ��������------------\n\n";
				std::cout << "--------------------����--------------------\n\n";
				std::cout << " 1. ������ ��������� � ������." << std::endl;
				std::cout << " 2. ������������� ��������� ��������." << std::endl;
				std::cout << " 0. �����." << std::endl;

				std::cout << "\n> ";
				std::cin >> submenu;

				switch (submenu)
				{
				case 0:
				{
					//submenu = -5;
					break;
				}
				case 1:
				{
					do
					{
						std::cout << "\033[2J\033[1;1H";
						std::cout << "------------����������� ��������------------\n\n";
						std::cout << "--------------------����--------------------\n\n";
						std::cout << " 1. ������ ��������� A." << std::endl;
						std::cout << " 2. ������ ��������� B." << std::endl;
						std::cout << " 3. ������ ��������� C." << std::endl;
						std::cout << " 4. ������ ��� ���������." << std::endl;
						std::cout << " 0. �����." << std::endl;

						std::cout << "\n> ";
						std::cin >> submenu;

						switch (submenu)
						{
						case 0: 
							break;
						case 1:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\n����� ������� ����� ������, ��� ���������� ����� ������� enter." << std::endl;
							std::cout << "��������� �: ";
							this->aMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						case 2:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\n����� ������� ����� ������, ��� ���������� ����� ������� enter." << std::endl;
							std::cout << "��������� �: ";
							this->bMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						case 3:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\n����� ������� ����� ������, ��� ���������� ����� ������� enter." << std::endl;
							std::cout << "��������� C: ";
							this->cMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						case 4:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\n����� ������� ����� ������, ��� ���������� ����� ������� enter." << std::endl;
							std::cout << "��������� �: ";
							this->aMultiply.HandWriteMultiple();
							system("pause");
							std::cout << "\033[2J\033[1;1H";
							std::cout << "��������� A: {" << this->aMultiply << std::endl;
							std::cout << "��������� B: ";
							this->bMultiply.HandWriteMultiple();
							system("pause");
							std::cout << "\033[2J\033[1;1H";
							std::cout << "��������� A: {" << this->aMultiply << std::endl;
							std::cout << "��������� B: {" << this->bMultiply << std::endl;
							std::cout << "��������� C: ";
							this->cMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						default:
							std::cout << "������ �����." << std::endl;
							system("pause");
							break;
						}
					} while (submenu);
					break;
				}
				case 2:
				{
					do					
					{
						std::cout << "\033[2J\033[1;1H";
						std::cout << "------------����������� ��������------------\n\n";
						std::cout << "--------------------����--------------------\n\n";
						std::cout << " 1. ���������� ���������." << std::endl;
						std::cout << " 2. ���������� �������� / ����������." << std::endl;
						std::cout << " 3. ���������� ���� ������������ �����." << std::endl;
						//std::cout << " 4. ������������ ������ ������������� �����." << std::endl;
						std::cout << " 4. ����� �������� ���������." << std::endl;
						std::cout << " 5. ������������� ��������� �." << std::endl;
						std::cout << " 6. ������������� ��������� �." << std::endl;
						std::cout << " 7. ������������� ��������� �." << std::endl;
						std::cout << " 8. ��������� ��������� ���� ��������." << std::endl;
						std::cout << " 0. �����." << std::endl;

						std::cout << "\n> ";
						std::cin >> submenu;
						switch (submenu)
						{
						case 0:
							break;
						case 1:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							std::cout << "��������� �� ��������� = 1." << std::endl;
							std::cout << "������� ��������� = " << multiplicity << '.' << std::endl;
							std::cout << "������� ������c��: ";
							std::cin >> multiplicity;
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							std::cout << "��������� �� ��������� = 1." << std::endl;
							std::cout << "������� ��������� = " << multiplicity << '.' << std::endl;
							system("pause");
							break;
						}
						case 2:
						{
							int parityMenu = -1;
							do
							{
								std::cout << "\033[2J\033[1;1H";
								std::cout << "------------����������� ��������------------\n\n";
								std::cout << "--------------------����--------------------\n\n";
								std::cout << " 1. ���������� ��������." << std::endl;
								std::cout << " 2. ���������� ����������." << std::endl;
								std::cout << " 3. ���������� �� ��������, �� ����������." << std::endl;
								std::cout << "\n> ";
								std::cin >> parityMenu;
								if (parityMenu == 1)
								{
									std::cout << "��������� ������ ����� ������� ������������." << std::endl;
									parity = Multiply::EVEN;
								}
								else if (parityMenu == 2)
								{
									std::cout << "��������� �������� ����� ������� ������������." << std::endl;
									parity = Multiply::ODD;
								}
								else if (parityMenu == 3)
								{
									std::cout << "��������� �� ������, �� �������� ����� ������� ������������." << std::endl;
									parity = Multiply::CLASSIC;
								}
							} while (parityMenu > 3 && parityMenu < 1);
							system("pause");
							break;
						}
						case 3:
						{
							int plusOrMinusMenu = -1;
							do
							{
								std::cout << "\033[2J\033[1;1H";
								std::cout << "------------����������� ��������------------\n\n";
								std::cout << "--------------------����--------------------\n\n";
								std::cout << " 1. ���������� ������ ������������� ����� \'+\'." << std::endl;
								std::cout << " 2. ���������� ������ ������������� ����� \'-\'." << std::endl;
								std::cout << " 3. ���������� ���� �������� ����� \'+\'/\'-\'." << std::endl;
								std::cout << "\n> ";
								std::cin >> plusOrMinusMenu;
								if (plusOrMinusMenu == 1)
								{
									std::cout << "��������� ������������� ����� ������� ������������." << std::endl;
									plusOrMinus = 1;
								}
								else if (plusOrMinusMenu == 2)
								{
									std::cout << "��������� ������������� ����� ������� ������������." << std::endl;
									plusOrMinus = -1;
								}
								else if (plusOrMinusMenu == 3)
								{
									std::cout << "��������� ������������� � ������������� ����� ������� ������������." << std::endl;
									plusOrMinus = 0;
								}
							} while (plusOrMinusMenu > 3 && plusOrMinusMenu < 1);
							system("pause");
							break;
						}
						/*case 4:
						{
							std::cout << "��������� ������ ������������� ����� ������������." << std::endl;
							plusOrMinus = -1;
							system("pause");
							break;
						}*/
						case 4:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							std::cout << "��������� ��������� �������� ������� ��������." << std::endl;
							std::cout << "��������� = 1." << std::endl;
							std::cout << "��������� ������������� � ������������� ����� ��������������." << std::endl;
							std::cout << "��������� �� ������, �� �������� ����� ��������������." << std::endl;
							multiplicity = 1;
							parity = Multiply::parity::CLASSIC;
							plusOrMinus = 0;
							system("pause");
							break;
						}
						case 5:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							this->aMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'A');
							std::cout << "���������� ��������� � = { " << this->aMultiply;
							system("pause");
							break;
						}
						case 6:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							this->bMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'B');
							std::cout << "���������� ��������� B = { " << this->bMultiply;
							system("pause");
							break;
						}
						case 7:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							this->cMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'C');
							std::cout << "���������� ��������� C = { " << this->cMultiply;
							system("pause");
							break;
						}
						case 8:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							this->aMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'A');
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							std::cout << "���������� ��������� � = { " << this->aMultiply;
							this->bMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'B');
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							std::cout << "���������� ��������� � = { " << this->aMultiply;
							std::cout << "���������� ��������� B = { " << this->bMultiply;
							this->cMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'C');
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------����������� ��������------------\n\n";
							std::cout << "--------------------����--------------------\n\n";
							std::cout << "���������� ��������� � = { " << this->aMultiply;
							std::cout << "���������� ��������� B = { " << this->bMultiply;
							std::cout << "���������� ��������� C = { " << this->cMultiply;
							system("pause");
							break;
						}
						default:
							std::cout << "������ �����.";
							system("pause");
							break;
						}
					}while (submenu);
					break;
				}
				
				default:
					std::cout << "������ �����." << std::endl;
					system("pause");
					break;
				}
			} while (submenu /*== -5*/);
			break;
		}
		case 2:
		{
			std::cout << "\033[2J\033[1;1H";
			this->Parse();
			std::cout << "���������� ��������� = { " << this->finalMultiply << std::endl;
			system("pause");
			break;
		}
		case 3:
		{
			this->SetUniversum();
			system("pause");
			break;
		}
		case 4:
		{
			std::cout << "���������:" << std::endl;
			std::cout << "MIN = " << this->uMin << std::endl;
			std::cout << "MAX = " << this->uMax << std::endl << std::endl;
			std::cout << "��������� = " << multiplicity << std::endl;
			if (plusOrMinus == 0)
				std::cout << "��������� ����� �� ������� \'+\' � \'-\'" << std::endl;
			else if (plusOrMinus > 0)
				std::cout << "��������� ����� ������ �� ������ \'+\'" << std::endl;
			else
				std::cout << "��������� ����� ������ �� ������ \'-\'" << std::endl;

			if (parity == Multiply::parity::CLASSIC)
				std::cout << "��������� �� ������, �� �������� �����." << std::endl << std::endl;
			else if (parity == Multiply::parity::EVEN)
				std::cout << "��������� ������ �����." << std::endl << std::endl;
			else
				std::cout << "��������� �������� �����." << std::endl << std::endl;

			std::cout << "��������� � = { " << this->aMultiply << std::endl;
			std::cout << "��������� B = { " << this->bMultiply << std::endl;
			std::cout << "��������� C = { " << this->cMultiply << std::endl;
			system("pause");
			break;
		}
		default:
		{
			std::cout << "������ �����." << std::endl;
			system("pause");
			break;
		}
		}
	}while (menu);
}


// 'U' - �����������
// '^' - �����������
// '\' - ��������
// 'Z' - ����������� ��������
// '-' - ����������
void BinMathCalculator::Parse()
{
	std::string buffer;		//��������� ������

	size_t startPosition = -1, endPosition = -1;
	size_t multLeftPosition = 0, multRightPosition = 0;		//���������� ��� ����������


	std::cout << "�������� ��� �����������:" << std::endl;
	std::cout << " \'U\' - �����������" << std::endl;
	std::cout << " \'^\' - �����������" << std::endl;
	std::cout << " \'\\\' - ��������" << std::endl;
	std::cout << " \'Z\' - ����������� ��������" << std::endl;
	std::cout << " \'-\' - ����������" << std::endl << std::endl;

	std::cout << "A, B, � - ���������." << std::endl << std::endl;
	std::cout << "������� ��������� � ������������ � ��������: " << std::endl;

	std::cin >> buffer;

	if (!this->CheckStringForBrackets(buffer))
	{
		std::cout << "������ ����� ������, ��������� ������." << std::endl;
		return;
	}

	buffer.erase(std::remove(buffer.begin(), buffer.end(), ' '));		//������� ������ �� ��������
	std::vector<bool> usedTokens(buffer.size(), false);		//������ ��� �������������� ����������
	std::vector<Multiply> usedMultiplys(buffer.size());		//������ ��� ��������
	std::vector<char> usedSigns(buffer.size(), ' ');		//������ ��� ������, ������� ������������
	for (size_t i = 0; i < buffer.length(); i++)		//������� ������ � ��������� �� �������
	{
		switch (buffer[i])
		{
		case'(':
		{
			usedSigns[i] = '(';
			break;
		}
		case')':
		{
			usedSigns[i] = ')';
			break;
		}
		case'U':
		{
			usedSigns[i] = 'U';
			break;
		}
		case'^':
		{
			usedSigns[i] = '^';
			break;
		}
		case'\\':
		{
			usedSigns[i] = '\\';
			break;
		}
		case'Z':
		{
			usedSigns[i] = 'Z';
			break;
		}
		case'-':
		{
			usedSigns[i] = '-';
			break;
		}
		case'A':
		{
			usedMultiplys[i] = this->aMultiply;
			usedTokens[i] = true;
			break;
		}
		case'B':
		{
			usedMultiplys[i] = this->bMultiply;
			usedTokens[i] = true;
			break;
		}
		case'C':
		{
			usedMultiplys[i] = this->cMultiply;
			usedTokens[i] = true;
			break;
		}
		default:
			std::cout << "� ��������� ��������� �������� ������." << std::endl;
			return;
		}
	}
	while (!this->CheckVecUsingTokens(usedTokens))			//���� ��� ������ ������ �� ������������
	{
		for (size_t i = 0; i < usedSigns.size(); i++)		//����������� �� ����� �������
		{
			if (usedSigns[i] == '(' && usedTokens[i] == false)
			{
				startPosition = i;
			}
			if (usedSigns[i] == ')' && usedTokens[i] == false)
			{
				endPosition = i;
				break;
			}
		}
		if (startPosition != -1 && endPosition != -1)		//���� ���� ������, �� ��������� ����� ���� 
		{
			usedTokens[startPosition] = true;				//�������� �������������� ������
			usedTokens[endPosition] = true;
			for (size_t i = startPosition + 1; i < endPosition; i++)	//��������� ��������, ������� ��������� � �������
			{
				if (usedSigns[i] == '-' && usedTokens[i] == false)		//��������� ��������
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)	//����� �������� � ����� ��� ��������
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}

					usedMultiplys[i] = --usedMultiplys[multRightPosition];
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == 'U' && usedTokens[i] == false)	//������� ���������� ��������
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)	//����� ������� ���������
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)						//����� ������ ���������
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] + usedMultiplys[multRightPosition];	//���������� ��������
					usedMultiplys[multLeftPosition].Clear();		//��������� ������ ��������
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;							//�������, ��� ����� �����������
				}
				else if (usedSigns[i] == '^' && usedTokens[i] == false)		//����� ����������
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] - usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == '\\' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!(usedMultiplys[j].Empty()))
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] / usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == 'Z' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] * usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
			}
		}
		else				//���� ������ �� ��������, ��� ��� ����������, ��� �� ��������, ������ �������� ���������� � ������ ��������� ��������.
		{
			for (size_t i = 0; i < usedSigns.size(); i++)
			{
				if (usedSigns[i] == '-' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}

					usedMultiplys[i] = --usedMultiplys[multRightPosition];
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == 'U' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] + usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == '^' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] - usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == '\\' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!(usedMultiplys[j].Empty()))
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] / usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == 'Z' && usedTokens[i] == false)
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] * usedMultiplys[multRightPosition];
					usedMultiplys[multLeftPosition].Clear();
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
			}
		}
		startPosition = -1;
		endPosition = -1;
	}
	for (size_t i = 0; i < usedMultiplys.size(); i++)
		if (!usedMultiplys[i].Empty())
			this->finalMultiply = usedMultiplys[i];
}

void BinMathCalculator::SetMultiple(Multiply& A, Multiply& B, Multiply& C)		//��������� ��������, //����������
{
	this->aMultiply = A;
	this->bMultiply = B;
	this->cMultiply = C;
}

bool BinMathCalculator::CheckVecUsingTokens(std::vector<bool> usedTokens)		//��������, ��� ��� ������ ������������
{
	for (size_t i = 0; i < usedTokens.size(); i++)
		if (!usedTokens[i])
			return false;
	return true;
}

void BinMathCalculator::SetUniversum()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << "------------����������� ��������------------\n\n";
	std::cout << "--------------------����--------------------\n\n";
	std::cout << "������� ����������� ������� ����������: ";
	std::cin >> this->uMin;
	std::cout << "������� ������������ ������� ����������: ";
	std::cin >> this->uMax;
	if (this->uMin > this->uMax) std::swap(this->uMin, this->uMax);
	this->aMultiply.SetUniversum(this->uMin, this->uMax);
	this->bMultiply.SetUniversum(this->uMin, this->uMax);
	this->cMultiply.SetUniversum(this->uMin, this->uMax);
	this->finalMultiply.SetUniversum(this->uMin, this->uMax);
}
