#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

sing namespace std;

/**
* \brief Математическая функция, рассчитывающая сумму
* \param const double first - константа
* \param const double second - константа
* \return Возвращает сумму чисел
**/
double getSum(const double first, const double second);

/**
* \brief Математическая функция, рассчитывающая разность
* \param const double first - константа
* \param const double second - константа
* \return Возвращает разность  чисел
**/
double getSubstraction(const double first, const double second);

/**
* \brief Математическая функция, рассчитывающая произведение
* \param const double first - константа
* \param const double second - константа
* \return Возвращает произведение чисел
**/
double getMultiplcation(const double first, const double second);

/**
* \brief Математическая функция, рассчитывающая частное
* \param const double first - константа
* \param const double second - константа
* \return Возвращает частное чисел
**/
double getDivide(const double first, const double second);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
  double first, second;  
  cout << "Введите два числа и нажмите Enter: \n";
  cin >> first >> second;

	const auto a = getSum(first, second);
	const auto b = getSubstraction(first, second);
	const auto c = getMultiplcation(first, second);
	const auto d = getDivide(first, second);

	cout << "First = " << first << "\nSecond = " << second << "\nСумма чисел = " << a << "\nРазность чисел = " << b << "\nПроизведение чисел = " << c << "\nЧастное чисел = " << d;
	return 0;
}

double getSum(const double first, const double second) { return first + second; }
double getSubstraction(const double first, const double second) { return first - second; } 
double getMultiplcation(const double first, const double second) { return first * second; } 
double getDivide(const double first, const double second) { return first / second; } 