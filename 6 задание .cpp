﻿#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief проходит по каждому элементу массива arr.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @return sum
 */
int sumOfNegativesDivisibleByTen(const int arr[], const int n);

/**
 * @brief Функция изменяет порядок первых k элементов в массиве arr.
 * @param arr Указатель на массив целых чисел.
 * @param k Целое число, представляющее количество элементов, которые нужно обратить
 */
void reverseFirstKElements(int arr[], const int k);

/**
 * @brief Проверяет, есть ли в массиве пара соседних элементов с произведением, равным заданному числу.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @param product Заданное число для сравнения произведения.
 * @return true, если такая пара найдена, иначе false.
 */
bool hasAdjacentProduct(const int* arr, const int n, const int product);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, const int min, const int max);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();

    switch (choice)
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        delete[] arr;
        return -1;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    cout << "Сумма отрицательных элементов, значения которых кратны 10: " << sumOfNegativesDivisibleByTen(arr, n) << endl;

    int k; 
    cout << "Введите количество элементов для реверса: ";
    int k = getNumber();
    reverseFirstKElements(arr, k);
    cout << "Массив после реверса первых " << k << " элементов: ";
    printArray(arr, n);

    int product;
    cout << "Введите число для проверки произведения соседних элементов: ";
    int product = getNumber();

    if (hasAdjacentProduct(arr, n, product)) {
        cout << "Есть пара соседних элементов с произведением, равным " << product << endl;
    }
    else {
        cout << "Нет пары соседних элементов с произведением, равным " << product << endl;
    }
    cout << "Измененный массив: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    checkN(n);
    return static_cast<size_t>(n);
}

int getNumber()
{
    int number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных" << endl;
        cin.clear(); // Очистка флага ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование оставшегося ввода
        return getNumber(); // Рекурсивный вызов для повторного ввода
    }
    return number;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min >= max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int sumOfNegativesDivisibleByTen(const int arr[], const int n)
{
    int sum = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] < 0 && arr[i] % 10 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

void reverseFirstKElements(int arr[], const int k)
{
    int start = 0;
    int end = k - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

bool hasAdjacentProduct(const int* arr, const int n, const int product) 
{
    for (size_t i = 0; i < n - 1; ++i) 
    {
        if (arr[i] * arr[i + 1] == product) 
        {
            return true;
        }
    }
    return false;
}

void fillArray(int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
}
