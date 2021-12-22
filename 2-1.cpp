#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
*\brief Математическая функция, расчитывающая сумму двух чисел.
*\ param а - число 1, имеющие тип данных с плавающей точкойдвойной точности.
*\ param b - число 2, имеющие тип данных с плавающей точкойдвойной точности.
**/

double Summ(const double a, const double b);

/**
*\brief Математическая функция, расчитывающая разность двух чисел.
*\ param а - число 1, имеющие тип данных с плавающей точкойдвойной точности.
*\ param b - число 2, имеющие тип данных с плавающей точкойдвойной точности.
**/

double Difference(const double a, const double b);

/**
*\brief Математическая функция, расчитывающая произведение двух чисел.
*\ param а - число 1, имеющие тип данных с плавающей точкой двойной точности.
*\ param b - число 2, имеющие тип данных с плавающей точкой двойной точности.
**/

double Composition(const double a, const double b);

/**
*\brief Математическая функция, расчитывающая частное двух чисел.
*\ param а - число 1, имеющие тип данных с плавающей точкой двойной точности.
*\ param b - число 2, имеющие тип данных с плавающей точкой двойной точности.
**/

double Quotient(double a, double b);

/**
 * \brief Математические операции.
 */
enum class MathOperations
{
    /**
     * \brief Сумма.
     */
    Sum,

    /**
     * \brief Разность.
     */
     Difference,

     /**
      * \brief Произведение.
      */
      Composition,
      /**
        * \brief Частное.
        */
        Quotient
};

/**
*\точка входа в программу.
*\ return возвращает - в случае успешного выолнения программы.
**/

int main(){
	setlocale(LC_ALL, "Russian");
    cout << "Введите математическую операцию "
        << "\nСумма - " << static_cast<int>(MathOperations::Sum)
        << "\nРазность - " << static_cast<int>(MathOperations::Difference)
        << "\nПроизведение - " << static_cast<int>(MathOperations::Composition)
        << "\nЧастное - " << static_cast<int>(MathOperations::Quotient);

    int choose;
    cin >> choose;
    
    double a = 0.0;
    double b = 0.0;
    double output = 0.0;
    
    cout<< "Введите 2 числа ";
    cin >> a >> b;
    const auto choice = static_cast<MathOperations>(choose);
    
    switch (choice)
    {
    case MathOperations::Sum:
        output = Summ(a,b); 
        cout << "Сумма = " << output ;
        break;
    case MathOperations::Difference:
        output = Difference(a,b);
        cout << "Разность = "<<  output;
        break;
    case MathOperations::Composition:
        output = Composition(a,b);
        cout << "Произведение = "<< output;
        break;
    case MathOperations::Quotient:
        output = Quotient(a,b);
        cout << "Частное = "<< output;
        break;
    }
    return 0;
}

double Summ(double a, double b){
		return a+b;
	}
	
double Difference(double a, double b){
	return a-b;
}

double Composition(double a, double b){
	return a*b;
}

double Quotient(double a, double b){
	return a/b;
}
