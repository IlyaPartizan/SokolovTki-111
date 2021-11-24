#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение функции y
**/

double gety(const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double x = 1;
    const auto y = gety(x);
}

double gety(const double x)
{
    for (double x = 1; x <= 3; x = x + 0.2)
    {
        cout << "y = " << sin(log(x)) - cos(log(x)) + 2*(log(x)) << endl;
    }
    return 1;
}
