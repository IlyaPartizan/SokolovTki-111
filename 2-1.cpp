#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
*\brief Математическая функция, расчитывающая сумму двух чисел
*\ а - число 1, имеющие тип данных с плавающей точкойдвойной точности
*\ b - число 2, имеющие тип данных с плавающей точкойдвойной точности
**/

double Summ(double a, double b);

/**
*\brief Математическая функция, расчитывающая разность двух чисел
*\ а - число 1, имеющие тип данных с плавающей точкойдвойной точности
*\ b - число 2, имеющие тип данных с плавающей точкойдвойной точности
**/

double Subtr(double a, double b);

/**
*\brief Математическая функция, расчитывающая произведение двух чисел
*\ а - число 1, имеющие тип данных с плавающей точкой двойной точности
*\ b - число 2, имеющие тип данных с плавающей точкой двойной точности
**/

double Mult(double a, double b);

/**
*\brief Математическая функция, расчитывающая частное двух чисел
*\ а - число 1, имеющие тип данных с плавающей точкой двойной точности
*\ b - число 2, имеющие тип данных с плавающей точкой двойной точности
**/

double Div(double a, double b);

/**
*\точка входа в программу
*\ return возвращает - в случае успешного выолнения программы
**/

int main(){
	setlocale(LC_ALL, "Russian");
	double a;
	double b;
	cout<<"Введите a"<<endl;
	cin>>a;
	cout<<"Введите b"<<endl;
	cin>>b;
	int i;//переменная для выбора функций программы в консоли
	cout<<"Введите 1, чтобы сложить чила"<<endl;
	cout<<"Введите 2, чтобы вычесть"<<endl;
	cout<<"Введите 3, чтобы умножить"<<endl;
	cout<<"Введите 4, чтобы разделить"<<endl;
	cout<<"Любой другой символ для выхода из программы"<<endl;
	cin>>i;
	switch(i){
		case 1:
			cout<<Summ(a,b);
		case 2:
			cout<<Subtr(a,b);
		case 3:
			cout<<Mult(a,b);
		case 4:
			cout<<Div(a,b);
		default:
			break;
	}
	
	
}
	double Summ(double a, double b){
		return a+b;
	}
	double Subtr(double a, double b){
		return a-b;
	}
	double Mult(double a, double b){
		return a*b;
	}
	double Div(double a, double b){
		return a/b;
	}