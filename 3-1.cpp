#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y.
* \param x - константа
* \return Возвращает значение функции y.
**/
double getY(double x);

/**
* \brief Проверка y при заданном х
* \param x Значение x
* \return true, y существует при заданном х
*/
bool isCalculated(double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    double x = 1.0;
    const double step = 0.2;
    const double rightBorder = 3.0;
    
  while(x < rightBorder)
  {
        if (isCalculated(x))
        {
        const double y =  getY(x);
        std::cout << "x = " << std::setw(10) << std::left << std::setprecision(4) << x << " y = " << y << "\n";
        }
        else
        {
        cout << "При x = " << x << " y не существует" << "\n";
        }
        
        x+= step;
  }
return 0;
}

double getY(const double x)
{
    return sin(log(x)) - cos(log(x)) + 2.0 * (log(x));
}
bool isCalculated(const double x)
{
    return x >= 0;
}
