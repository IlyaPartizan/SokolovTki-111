#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Функция вычисляющая температуру, на котору. остыла ложка
* \param const double a - константа, масса ложки
* \param const double b - константа, количество теплоты
* \param const double c - константа, удельная теплоемкость
* \return Возвращает частное чисел
**/
double getT(const double a, const double c, const double b);


/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
  double a, b, c;  
  cout << "Введите массу ложки в грамма: \n";
  cin >> a;
  cout << "Введите количество энергии, которое она отдала: \n";
  cin >> b;
  cout << "Введите удельную теплоемкость ложки (Дж/г • °C) : \n";
  cin >> c;
  cout << "Формула, по которые будет делаться подсчет - Q = a*c*(t1 - t0) \n";

	const auto difT = getT(a, c, b);

	cout << "M = " << a << "\nQ = " << b << "\nC = " << c << "\nНа сколько изменилась температура ложки = " << difT;
	return 0;
}

double getT(const double a, const double c, const double b) { return b / (a * c); } 