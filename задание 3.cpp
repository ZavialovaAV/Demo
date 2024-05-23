#include <iostream>
#include <cmath>

using namespace std;

struct Point 
{
double x;
double y;
};

/**
* @brief Функция для получения корректного числового значения.
* @return double Корректное числовое значение.
*/
double getValue(); 


/**
* @brief Вычисляет расстояние между двумя точками.
* @param p1 Первая точка.
* @param p2 Вторая точка.
* @return double Расстояние между точками.
*/
double distance(Point p1, Point p2);


/**
* @brief Проверяет, лежат ли три точки на одной прямой.
* @param A Первая точка.
* @param B Вторая точка.
* @param C Третья точка.
* @return true Если точки лежат на одной прямой.
* @return false Если точки не лежат на одной прямой.
*/
bool arePointsCollinear(Point A, Point B, Point C);


/**
* @brief Вычисляет угол между двумя отрезками.
* @param A Первая точка отрезка.
* @param B Общая точка между отрезками.
* @param C Вторая точка отрезка.
* @return double Угол между отрезками в радианах.
*/
double angleBetweenSegments(Point A, Point B, Point C);

/**
* @breef получает значение с клавиатуры
* @return определение будут ли точки A, B, C лежать ли на одной прямой, если нет, то вычислить угол
*/
int main() {
setlocale(LC_ALL, "rus");

Point A, B, C;

cout << "Введите координаты точки A (x y): ";
A.x = getValue();
A.y = getValue();

cout << "Введите координаты точки B (x y): ";
B.x = getValue();
B.y = getValue();

cout << "Введите координаты точки C (x y): ";
C.x = getValue();
C.y = getValue();

if (arePointsCollinear(A, B, C)) {
cout << "Точки находятся на одной прямой." << endl;
}
else {
cout << "Точки не находятся на одной прямой." << endl;
double angle = angleBetweenSegments(A, B, C);
angle = angle * 180.0 / 3.14; // Перевод из радиан в градусы
cout << "Угол между отрезками AB и BC: " << angle << " градусов." << endl;
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

bool arePointsCollinear(Point A, Point B, Point C) 
{
return ((B.y - A.y) * (C.x - B.x) == (C.y - B.y) * (B.x - A.x));
}

double angleBetweenSegments(Point A, Point B, Point C) 
{
double AB = distance(A, B);
double BC = distance(B, C);
double AC = distance(A, C);
return acos((AB * AB + BC * BC - AC * AC) / (2 * AB * BC));
}

