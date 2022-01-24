#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief функция определения текущего элемента ряда.
 * param k - переменная для вычисления элемента ряда.
 * \return значение текущего элемент ряда.
*/
double getCurrent(const size_t k);
/**
 * \brief функция вычисления суммы первых n элементов ряда.
 * param n - количество элементов ряда.
 * param k - переменная для вычисления элемента ряда.
 * \return сумма первых n элементов ряда.
 */
double getSumm(const int n, size_t k);
/**
 * \brief вычисление суммы членов ряда не меньших числа e.
 * param e - константа по условию.
 * param k - переменная для вычисление элемента ряда.
 * \return сумма членов ряда не меньших числа e.
*/
double getSummE(const double e,  size_t k);
/**
 * \brief точка входа в программу.
 * return 0 в случае успеха.
*/
int main()
{
    int n;
    double e = 0.0;
    size_t k = 1;
    cout<<"Введите количество членов ряда"<< endl;
    cin >> n;
    cout<< "Введите e ";
    cin>>e;
    cout<< getSumm(n, k)<< endl;
    cout<< getSummE(e, k);
    return 0;
}
double getCurrent(const size_t k){
    return pow((-1.0),k) * (1.0 / pow((k + 1),2));
}
double getSumm(const int n, size_t k){
    double sum;
    for (int i = 1; i <=  n; i++){
        sum = sum + getCurrent(k);
        k=k+1;
    }
return sum;
}
double getSummE(const double e, size_t k){
    double cur, sum;
    cur = getCurrent(k);
    while (cur > e){
        sum = sum + cur;
        k++;
        cur = getCurrent(k);
    }
    return sum;
}