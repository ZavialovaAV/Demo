#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief Функция для получения корректного числового значения от пользователя.
 *        Программа будет просить пользователя ввести значение, пока он не введет корректное число.
 * @return double Корректное числовое значение.
 */
double getValue();

/**
 * @brief Функция для проверки области определения функции y = 3x - 4ln(x) - 5.
 * 
 * @param x Значение аргумента x.
 * @return bool Возвращает true, если x находится в области определения, иначе false.
 */
bool isInDomain(const double x);

/**
 * @brief Функция для вычисления значения y = 3x - 4ln(x) - 5 при заданном x.
 * 
 * @param x Значение аргумента x.
 * @return double Значение функции y.
 */
double computeY(const double x);

/**
 * @brief Основная функция программы. Вычисляет значения функции y = 3x - 4ln(x) - 5
 *        для x в промежутке [1, 2] с шагом 0.2 и выводит результаты на экран.
 */
int main() {
    setlocale(LC_ALL, "rus");


    cout << "Введите начальное значение x: ";
    double x_start = getValue();
    cout << "Введите конечное значение x: ";
    double x_end = getValue();
    cout << "Введите шаг delta x: ";
    double delta_x = getValue();

    
    cout << " x       | y" << endl;
    cout << "----------------" << endl;

   
    for (double x = x_start; x < x_end + delta_x) {
        if (isInDomain(x)) {
            double y = computeY(x); 
            cout << fixed << setprecision(4) << x << " | " << y << endl; 
        } else {
            cout << fixed << setprecision(4) << x << " | Вне области определения" << endl; 
            break;
        }
    }

    return 0;
}

double getValue() 
{
    double value;
    bool inputSuccess = false;

    do {
        if (!(cin >> value)) {
            cout << "Некорректное значение. Пожалуйста, введите число." << endl;
            cin.clear();
            // Очистка буфера ввода до символа новой строки, чтобы избежать зацикливания
            while (cin.get() != '\n');
        } else {
            inputSuccess = true;
        }
    } while (!inputSuccess);

    return value;
}

bool isInDomain(const double x) 
{
    return x > 0;
}

double computeY(const double x) 
{
    return 3 * x - 4 * log(x) - 5;
}
