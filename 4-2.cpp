#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 *\brief Вычисление нового размера массива.
 *\param size размер массива.
 *\return Размер нового массива.
*/
size_t NewSize(const int* myArray, size_t size, const int a, const int b);

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* myArray, size_t size);

/**
 * \brief Удаление элементов, принадлежащих отрезку [a,b] и кратных 7.
 * \param myArray массив.
 * \param size размер массива.
 * \return изменённый массив.
 */
int* IsBelongABAndMulpiples7(int* myArray, size_t size, const int a, const int b);

/**
 * \brief Создание нового массива по заданным формулам.
 * \param myArray массив.
 * \param size размер массива.
 * \return изменённый массив.
 */
int* ArrayChange(int* myArray, size_t size);

/**
 * \brief Замена первого отрицательного элемента массива на первый положительный.
 * \param myArray массив.
 * \param size размер массива.
 * \param maxValue максимальное значение, которое может принимать элемент массива.
 */
int* NegativeToPositiveChange(int* myArray, const size_t size);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size);

/**
 * \brief Варианы ввода массива.
 */
enum class ArrayInputWay
{
    random,
    keyboard
};

/**
 * \brief Точка входа в программу.
 * \return 0, в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    size_t size = GetSize();

    if (size == 0)
        return 1;

    cout << "Как вы хотите заполнить массив?\n";
    cout << static_cast<int>(ArrayInputWay::random) << " - random,\n";
    cout << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;

    const auto chosen = static_cast<ArrayInputWay>(choice);
    int* myArray = nullptr;

    auto minValue = 0;
    auto maxValue = 0;
    cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl;
    cin >> minValue >> maxValue;
    if (maxValue <= minValue)
    {
        cout << "Введен неправильный диапазон!" << endl;
    }

    switch (chosen)
    {
    case ArrayInputWay::random:
    {
        myArray = FillRandomArray(size, minValue, maxValue);
        break;
    }
    case ArrayInputWay::keyboard:
    {
        myArray = FillUserArray(size);
        break;
    }
    }

    cout << "Массив с заменённым отрицательным элементом: " << endl;

    myArray = NegativeToPositiveChange(myArray, size);
    ArrayPrint(myArray, size);

    int a,b;
    cout<<"Введите промежуток (a и b): ";
    cin>>a>>b;
    
    int* newArray2 = new int[NewSize(myArray, size, a, b)];
    cout << "Массив с удалёнными элементами принадлежащими [a,b], кратными 7" << endl;
    newArray2 = IsBelongABAndMulpiples7(myArray, size, a, b);
    ArrayPrint(newArray2, NewSize(myArray, size, a, b));

    if (newArray2 != nullptr) {

        delete[] newArray2;
        newArray2 = nullptr;

    }

    cout << "Заменённый массив по формулам A[i] = D[i]^2 + i и A[i] = D[i] * i" << endl;
    newArray2 = ArrayChange(myArray, size);
    ArrayPrint(newArray2, size);

    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}

size_t GetSize() 
{
    int size = 0;
    cout << "Введите размер массива" << endl;
    cin >> size;
    if (size <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size;
};

size_t NewSize(const int* myArray, size_t size, const int a, const int b) 
{
    size_t count = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 7 == 0 && (a-1) <= index && index <= (b-1)) {
            count++;
        }
    }
    size = size - count;
    return size;
}

int* NegativeToPositiveChange(int* myArray, const size_t size)
{
    int temprary = 0;

    auto firstNegativeArrayValue = 0;
    size_t firstNegativeElementIndex = 0;
    auto firstPositiveArrayValue = -1;
    size_t firstPositiveElementIndex = 0;
    size_t index = 0;

    while (firstNegativeArrayValue == 0) {
        if (myArray[index] < 0) {
            firstNegativeArrayValue = myArray[index];
            firstNegativeElementIndex = index;
        }
        index++;
    }
    
    while (firstPositiveArrayValue == -1) {
        if (myArray[index] >= 0) {
            firstPositiveArrayValue = myArray[index];
            firstPositiveElementIndex = index;
        }
        index++;
    }

    temprary = myArray[firstNegativeElementIndex];
    myArray[firstNegativeElementIndex] = myArray[firstPositiveElementIndex];
    myArray[firstPositiveElementIndex] = temprary;

    return myArray;
}

int* ArrayChange(int* myArray, size_t size)
{
    int temprary = 0;
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    int* newArray = new int[size];
    for (size_t index = 0, newindex = 0; index < size; index++) {
        if (myArray[index] % 2 == 1) {
            newArray[newindex] = myArray[index] * index;
        }
        else {
            newArray[newindex] = myArray[index] * myArray[index] + index;
        }
        newindex++;
    }

    return newArray;
}

int* IsBelongABAndMulpiples7(int* myArray, size_t size, const int a, const int b)
{
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }
    
    size_t count = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 7 == 0 && (a-1) <= index && index <= (b-1)) {
            count++;
        }
    }

    int* newArray = new int[size - count];
    for (size_t index = 0, newindex = 0; index < size; index++) {
        if (!(myArray[index] % 7 == 0 && (a-1) <= index && index <= (b-1))) {
            newArray[newindex] = myArray[index];
            newindex++;
        }
    }
    return newArray;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "Массив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    const auto area = abs(minValue) + abs(maxValue) + 1;
    auto* myArray = new int[size];
    for (size_t index = 0; index < size; index++) {
        myArray[index] = rand() % area + minValue;
        cout << myArray[index] << endl;
    }
    return myArray;
}

int* FillUserArray(const size_t size)
{
    auto* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}