#include "BinMathCalculator.h"
#include <vector>
BinMathCalculator::BinMathCalculator()
{
	std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
	std::cout << "Добро пожаловать в калькулятор множеств, для начала работы необходимо ввести границы универсума.\n\n";
	std::cout << "Введите минимальную границу универсума: ";
	std::cin >> this->uMin;
	std::cout << "Введите максимальную границу универсума: ";
	std::cin >> this->uMax;
	if (this->uMin > this->uMax) std::swap(this->uMin, this->uMax);
	this->aMultiply.SetUniversum(this->uMin, this-> uMax);
	this->bMultiply.SetUniversum(this->uMin, this->uMax);
	this->cMultiply.SetUniversum(this->uMin, this->uMax);
	this->finalMultiply.SetUniversum(this->uMin, this->uMax);
}

void BinMathCalculator::Menu()			//меню калькулятора
{
	int menu, submenu;
	int multiplicity = 1, plusOrMinus = 0, parity = Multiply::parity::CLASSIC;

	do
	{
		std::cout << "\033[2J\033[1;1H";
		std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
		std::cout << "--------------------МЕНЮ--------------------\n\n";
		std::cout << " 1. Задать множества." << std::endl;
		std::cout << " 2. Ввести выражение." << std::endl;
		std::cout << " 3. Изменить универсум." << std::endl;
		std::cout << " 4. Посмотреть информацию." << std::endl;
		std::cout << " 0. Выход." << std::endl;

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
				std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
				std::cout << "--------------------МЕНЮ--------------------\n\n";
				std::cout << " 1. Задать множество в ручную." << std::endl;
				std::cout << " 2. Сгенерировать множество случайно." << std::endl;
				std::cout << " 0. Назад." << std::endl;

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
						std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
						std::cout << "--------------------МЕНЮ--------------------\n\n";
						std::cout << " 1. Ввести множество A." << std::endl;
						std::cout << " 2. Ввести множество B." << std::endl;
						std::cout << " 3. Ввести множество C." << std::endl;
						std::cout << " 4. Ввести все множества." << std::endl;
						std::cout << " 0. Назад." << std::endl;

						std::cout << "\n> ";
						std::cin >> submenu;

						switch (submenu)
						{
						case 0: 
							break;
						case 1:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\nЧисла вводить через пробел, для завершения ввода нажмите enter." << std::endl;
							std::cout << "Множество А: ";
							this->aMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						case 2:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\nЧисла вводить через пробел, для завершения ввода нажмите enter." << std::endl;
							std::cout << "Множество В: ";
							this->bMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						case 3:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\nЧисла вводить через пробел, для завершения ввода нажмите enter." << std::endl;
							std::cout << "Множество C: ";
							this->cMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						case 4:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "\nЧисла вводить через пробел, для завершения ввода нажмите enter." << std::endl;
							std::cout << "Множество А: ";
							this->aMultiply.HandWriteMultiple();
							system("pause");
							std::cout << "\033[2J\033[1;1H";
							std::cout << "Множество A: {" << this->aMultiply << std::endl;
							std::cout << "Множество B: ";
							this->bMultiply.HandWriteMultiple();
							system("pause");
							std::cout << "\033[2J\033[1;1H";
							std::cout << "Множество A: {" << this->aMultiply << std::endl;
							std::cout << "Множество B: {" << this->bMultiply << std::endl;
							std::cout << "Множество C: ";
							this->cMultiply.HandWriteMultiple();
							system("pause");
							break;
						}
						default:
							std::cout << "Ошибка ввода." << std::endl;
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
						std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
						std::cout << "--------------------МЕНЮ--------------------\n\n";
						std::cout << " 1. Установить кратность." << std::endl;
						std::cout << " 2. Установить четность / нечетность." << std::endl;
						std::cout << " 3. Установить знак генерируемых чисел." << std::endl;
						//std::cout << " 4. Генерировать только отрицательные числа." << std::endl;
						std::cout << " 4. Сброс настроек генерации." << std::endl;
						std::cout << " 5. Сгенерировать множество А." << std::endl;
						std::cout << " 6. Сгенерировать множество В." << std::endl;
						std::cout << " 7. Сгенерировать множество С." << std::endl;
						std::cout << " 8. Выполнить генерацию всех множеств." << std::endl;
						std::cout << " 0. Назад." << std::endl;

						std::cout << "\n> ";
						std::cin >> submenu;
						switch (submenu)
						{
						case 0:
							break;
						case 1:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							std::cout << "Кратность по умолчанию = 1." << std::endl;
							std::cout << "Текущая кратность = " << multiplicity << '.' << std::endl;
							std::cout << "Введите кратноcть: ";
							std::cin >> multiplicity;
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							std::cout << "Кратность по умолчанию = 1." << std::endl;
							std::cout << "Текущая кратность = " << multiplicity << '.' << std::endl;
							system("pause");
							break;
						}
						case 2:
						{
							int parityMenu = -1;
							do
							{
								std::cout << "\033[2J\033[1;1H";
								std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
								std::cout << "--------------------МЕНЮ--------------------\n\n";
								std::cout << " 1. Установить четность." << std::endl;
								std::cout << " 2. Установить нечетность." << std::endl;
								std::cout << " 3. Установить ни четность, ни нечетность." << std::endl;
								std::cout << "\n> ";
								std::cin >> parityMenu;
								if (parityMenu == 1)
								{
									std::cout << "Генерация четных чисел успешно установленна." << std::endl;
									parity = Multiply::EVEN;
								}
								else if (parityMenu == 2)
								{
									std::cout << "Генерация нечетных чисел успешно установленна." << std::endl;
									parity = Multiply::ODD;
								}
								else if (parityMenu == 3)
								{
									std::cout << "Генерация ни четных, ни нечетных чисел успешно установленна." << std::endl;
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
								std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
								std::cout << "--------------------МЕНЮ--------------------\n\n";
								std::cout << " 1. Установить только положительные числа \'+\'." << std::endl;
								std::cout << " 2. Установить только отрицательные числа \'-\'." << std::endl;
								std::cout << " 3. Установить весь диапазон чисел \'+\'/\'-\'." << std::endl;
								std::cout << "\n> ";
								std::cin >> plusOrMinusMenu;
								if (plusOrMinusMenu == 1)
								{
									std::cout << "Генерация положительных чисел успешно установленна." << std::endl;
									plusOrMinus = 1;
								}
								else if (plusOrMinusMenu == 2)
								{
									std::cout << "Генерация отрицательных чисел успешно установленна." << std::endl;
									plusOrMinus = -1;
								}
								else if (plusOrMinusMenu == 3)
								{
									std::cout << "Генерация положительных и отрицательных чисел успешно установленна." << std::endl;
									plusOrMinus = 0;
								}
							} while (plusOrMinusMenu > 3 && plusOrMinusMenu < 1);
							system("pause");
							break;
						}
						/*case 4:
						{
							std::cout << "Генерация только отрицательных чисел установленна." << std::endl;
							plusOrMinus = -1;
							system("pause");
							break;
						}*/
						case 4:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							std::cout << "Настройки генерации множеств успешно сброшены." << std::endl;
							std::cout << "Кратность = 1." << std::endl;
							std::cout << "Генерация положительных и отрицательных чисел восстановленна." << std::endl;
							std::cout << "Генерация ни четных, ни нечетных чисел восстановленна." << std::endl;
							multiplicity = 1;
							parity = Multiply::parity::CLASSIC;
							plusOrMinus = 0;
							system("pause");
							break;
						}
						case 5:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							this->aMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'A');
							std::cout << "Полученное множество А = { " << this->aMultiply;
							system("pause");
							break;
						}
						case 6:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							this->bMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'B');
							std::cout << "Полученное множество B = { " << this->bMultiply;
							system("pause");
							break;
						}
						case 7:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							this->cMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'C');
							std::cout << "Полученное множество C = { " << this->cMultiply;
							system("pause");
							break;
						}
						case 8:
						{
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							this->aMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'A');
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							std::cout << "Полученное множество А = { " << this->aMultiply;
							this->bMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'B');
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							std::cout << "Полученное множество А = { " << this->aMultiply;
							std::cout << "Полученное множество B = { " << this->bMultiply;
							this->cMultiply.RandomWriteMultiple(multiplicity, plusOrMinus, parity, 'C');
							std::cout << "\033[2J\033[1;1H";
							std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
							std::cout << "--------------------МЕНЮ--------------------\n\n";
							std::cout << "Полученное множество А = { " << this->aMultiply;
							std::cout << "Полученное множество B = { " << this->bMultiply;
							std::cout << "Полученное множество C = { " << this->cMultiply;
							system("pause");
							break;
						}
						default:
							std::cout << "Ошибка ввода.";
							system("pause");
							break;
						}
					}while (submenu);
					break;
				}
				
				default:
					std::cout << "Ошибка ввода." << std::endl;
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
			std::cout << "Полученное множество = { " << this->finalMultiply << std::endl;
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
			std::cout << "Универсум:" << std::endl;
			std::cout << "MIN = " << this->uMin << std::endl;
			std::cout << "MAX = " << this->uMax << std::endl << std::endl;
			std::cout << "Кратность = " << multiplicity << std::endl;
			if (plusOrMinus == 0)
				std::cout << "Генерация чисел со знаками \'+\' и \'-\'" << std::endl;
			else if (plusOrMinus > 0)
				std::cout << "Генерация чисел только со знаком \'+\'" << std::endl;
			else
				std::cout << "Генерация чисел только со знаком \'-\'" << std::endl;

			if (parity == Multiply::parity::CLASSIC)
				std::cout << "Генерация ни четных, ни нечетных чисел." << std::endl << std::endl;
			else if (parity == Multiply::parity::EVEN)
				std::cout << "Генерация четных чисел." << std::endl << std::endl;
			else
				std::cout << "Генерация нечетных чисел." << std::endl << std::endl;

			std::cout << "Множество А = { " << this->aMultiply << std::endl;
			std::cout << "Множество B = { " << this->bMultiply << std::endl;
			std::cout << "Множество C = { " << this->cMultiply << std::endl;
			system("pause");
			break;
		}
		default:
		{
			std::cout << "Ошибка ввода." << std::endl;
			system("pause");
			break;
		}
		}
	}while (menu);
}


// 'U' - объединение
// '^' - пересечение
// '\' - разность
// 'Z' - симетричная разность
// '-' - дополенние
void BinMathCalculator::Parse()
{
	std::string buffer;		//буфферная строка

	size_t startPosition = -1, endPosition = -1;
	size_t multLeftPosition = 0, multRightPosition = 0;		//переменные для вычисления


	std::cout << "Действия над множествами:" << std::endl;
	std::cout << " \'U\' - объединение" << std::endl;
	std::cout << " \'^\' - пересечение" << std::endl;
	std::cout << " \'\\\' - разность" << std::endl;
	std::cout << " \'Z\' - симетричная разность" << std::endl;
	std::cout << " \'-\' - дополенние" << std::endl << std::endl;

	std::cout << "A, B, С - множества." << std::endl << std::endl;
	std::cout << "Введите выражения в соответствии с легендой: " << std::endl;

	std::cin >> buffer;

	if (!this->CheckStringForBrackets(buffer))
	{
		std::cout << "Ошибка ввода строки, проверьте скобки." << std::endl;
		return;
	}

	buffer.erase(std::remove(buffer.begin(), buffer.end(), ' '));		//очищаем строку от пробелов
	std::vector<bool> usedTokens(buffer.size(), false);		//вектор для использованных переменных
	std::vector<Multiply> usedMultiplys(buffer.size());		//вектор для множеств
	std::vector<char> usedSigns(buffer.size(), ' ');		//вектор для знаков, которые используются
	for (size_t i = 0; i < buffer.length(); i++)		//парсинг строки и разбиение на вектора
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
			std::cout << "В введенном выражении допущена ошибка." << std::endl;
			return;
		}
	}
	while (!this->CheckVecUsingTokens(usedTokens))			//пока все токены строки не использованы
	{
		for (size_t i = 0; i < usedSigns.size(); i++)		//итерируемся по всему массиву
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
		if (startPosition != -1 && endPosition != -1)		//Если есть скобки, то выполняем между ними 
		{
			usedTokens[startPosition] = true;				//отмечаем использованные токены
			usedTokens[endPosition] = true;
			for (size_t i = startPosition + 1; i < endPosition; i++)	//выполняем действия, которые заключены в скобках
			{
				if (usedSigns[i] == '-' && usedTokens[i] == false)		//выполняем действия
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)	//поиск элемента с права для действия
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}

					usedMultiplys[i] = --usedMultiplys[multRightPosition];
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;
				}
				else if (usedSigns[i] == 'U' && usedTokens[i] == false)	//условие выполнения действия
				{
					for (size_t j = i + 1; j < usedMultiplys.size(); j++)	//поиск правого множества
						if (!usedMultiplys[j].Empty())
						{
							multRightPosition = j;
							break;
						}
					for (size_t j = i - 1; j >= 0; j--)						//поиск левого множества
						if (!usedMultiplys[j].Empty())
						{
							multLeftPosition = j;
							break;
						}
					usedMultiplys[i] = usedMultiplys[multLeftPosition] + usedMultiplys[multRightPosition];	//выполнение действия
					usedMultiplys[multLeftPosition].Clear();		//зануление старых значений
					usedMultiplys[multRightPosition].Clear();
					usedTokens[i] = true;							//отметка, что токен использован
				}
				else if (usedSigns[i] == '^' && usedTokens[i] == false)		//далее аналогично
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
		else				//если скобок не осталось, тут все аналогично, как со скобками, только итарации начинаются с первых элементов векторов.
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

void BinMathCalculator::SetMultiple(Multiply& A, Multiply& B, Multiply& C)		//установка множеств, //отладочное
{
	this->aMultiply = A;
	this->bMultiply = B;
	this->cMultiply = C;
}

bool BinMathCalculator::CheckVecUsingTokens(std::vector<bool> usedTokens)		//проверка, что все токены использованы
{
	for (size_t i = 0; i < usedTokens.size(); i++)
		if (!usedTokens[i])
			return false;
	return true;
}

void BinMathCalculator::SetUniversum()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << "------------КАЛЬКУЛЯТОР МНОЖЕСТВ------------\n\n";
	std::cout << "--------------------МЕНЮ--------------------\n\n";
	std::cout << "Введите минимальную границу универсума: ";
	std::cin >> this->uMin;
	std::cout << "Введите максимальную границу универсума: ";
	std::cin >> this->uMax;
	if (this->uMin > this->uMax) std::swap(this->uMin, this->uMax);
	this->aMultiply.SetUniversum(this->uMin, this->uMax);
	this->bMultiply.SetUniversum(this->uMin, this->uMax);
	this->cMultiply.SetUniversum(this->uMin, this->uMax);
	this->finalMultiply.SetUniversum(this->uMin, this->uMax);
}
