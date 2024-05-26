#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

/**
 * @brief Функция для проверки ввода корректного числового значения.
 * @return double Корректное числовое значение.
 */
double getValue();

/**
 * @brief Функция для вычисления расстояния между двумя точками.
 * @param p1 Первая точка.
 * @param p2 Вторая точка.
 * @return double Расстояние между точками.
 */
double distance(const Point p1, const Point p2);

/**
* @breef получает значение с клавиатуры
* @return нахождение расстояния между двумя точками
*/
int main() {
    setlocale(LC_ALL, "rus");

    Point point1, point2;

    cout << "Введите координаты первой точки (x y): ";
    point1.x = getValue();
    point1.y = getValue();

    cout << "Введите координаты второй точки (x y): ";
    point2.x = getValue();
    point2.y = getValue();

    double dist = distance(point1, point2);
    cout << "Расстояние между точками: " << dist << endl;

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
            while (cin.get() != '\n');
        } else {
            inputSuccess = true;
        }
    } while (!inputSuccess);

    return value;
}

double distance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}