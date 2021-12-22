#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

/**
* \brief вычисление переменной y по заданному x
* \param сonst double x - переменная, которую вводит пользователь
* \param сonst double y - искомая переменная
* \param const double a - переменная, данная по условию
* \return - значение y
*/
double getY(const double x, const double a);

/**
 * \brief функция, выводящая ошибку.
*/
void ERROR();

/**
 *\brief точка входа в программу.
 *\return 0 в случае успеха.
*/
int main()
{
    const double a=1.65;
    double x=0.0;
    double y=0.0;
    cout<<"Введите значение переменной x"<<endl;
    cin>>x;
    y=getY(x,a);
    cout<<"Y = " << y <<endl;
    return 0;
}
double getY(const double x, const double a)
{
    double e = 0.001;
    const double border1 = 1.34;
    const double border2 = 1.4;
    if (x < border1)
      return M_PI * x * x - (7.0 / (x * x));
    if (x - border2 <= e || x > border2) 
      return log(x + 7 * sqrt(x+a));
    else
      ERROR();
}

void ERROR()
{
    cout<<"Ошибка! Диапазон ввода х: (-inf,1.34) or [1.4,+inf).";
}
