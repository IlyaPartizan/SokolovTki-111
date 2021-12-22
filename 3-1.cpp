#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y.
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности.
* \return Возвращает значение функции y.
**/

double getY(const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double x = 0.0;
    const double step = 0.2;
    const double leftBorder = 1.0;
    const double rightBorder = 3.0;
    for (double x = leftBorder; x <= rightBorder; x+= step)
    {
        cout << "y = " << getY(x) << endl;
    }
    return 0;
}

double getY(const double x)
{
    return sin(log(x)) - cos(log(x)) + 2.0 * (log(x));
}
