#include <iostream>
#include <cmath>

using namespace std;

/**
* @brief Функция для получения корректного числового значения.
* @return double Корректное числовое значение.
*/
double getValue();

/**
 * @brief Функция для вычисления факториала числа.
 * @param n Число, для которого нужно вычислить факториал.
 * @return long long Факториал числа n.
 */
long long factorial(int n);

/**
 * @brief Функция для вычисления суммы первых n членов последовательности.
 * @param n Количество членов последовательности.
 * @return double Сумма первых n членов.
 */
double computeSumFirstN(int n);

/**
 * @brief Функция для вычисления суммы членов последовательности по модулю не меньших заданного числа epsilon.
 * @param epsilon Заданное число для сравнения по модулю.
 * @return double Сумма членов последовательности по модулю не меньших epsilon.
 */
double computeSumGreaterThanEpsilon(double epsilon);

/**
 * @brief Основная функция программы.
 */
int main() {
    setlocale(LC_ALL, "rus");

    int n;
    double epsilon;

    cout << "Введите количество членов последовательности (n): ";
    n = static_cast<int>(getValue());
    cout << "Введите значение epsilon: ";
    epsilon = getValue();

    double sumFirstN = computeSumFirstN(n);
    cout << "Сумма первых " << n << " членов последовательности: " << sumFirstN << endl;

 
    double sumGreaterThanEpsilon = computeSumGreaterThanEpsilon(epsilon);
    cout << "Сумма членов последовательности по модулю не меньших " << epsilon << ": " << sumGreaterThanEpsilon << endl;

    return 0;
}

double getValue() {
    double value;
    bool inputSuccess = false;

    do {
        if (!(cin >> value)) {
            cout << "Некорректное значение. Пожалуйста, введите число." << endl;
            cin.clear();
            while (cin.get() != '\n');
        } else {
            inputSuccess = true;
        }
    } while (!inputSuccess);

    return value;
}

long long factorial(int n) 
{
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double computeSumFirstN(int n) 
{
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {
        double term = pow(-1, k) * factorial(k) / factorial(4 + k);
        sum += term;
    }
    return sum;
}

double computeSumGreaterThanEpsilon(double epsilon) {
    double sum = 0.0;
    int k = 1;
    while (true) {
        double term = pow(-1, k) * factorial(k) / factorial(4 + k);
        if (fabs(term) < epsilon) {
            break;
        }
        sum += term;
        ++k;
    }
    return sum;
}