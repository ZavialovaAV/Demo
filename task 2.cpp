#include <iostream>
#include <cmath>
using namespace std;
/**
 * @breef фунцция для вычисления третьей стороны треугольника
 * @param side1 - первая сторона треугольника
 * @param side2 - вторая сторона треугольника
 * @param angle - угол в треугольнике
 * @return результат вычисления результата 
 */
double calculateThirdSide(double side1, double side2, double angle) {
return sqrt(side1 * side1 + side2 * side2 - 2 * side1 * side2 * cos(angle));
}
/**
 * @breef фунцция для вычисления площади треугольника
 * @param side1 - первая сторона треугольника
 * @param side2 - вторая сторона треугольника
 * @param angle - угол в треугольнике
 * @return результат вычисления результата 
 */
double calculateTriangleArea(double side1, double side2, double angle) {
double thirdSide = calculateThirdSide(side1, side2, angle);
return 0.5 * side1 * side2 * sin(angle);
}
/**
 * @breef фунцция для вычисления радиуса описанной окружности
 * @param side1 - первая сторона треугольника
 * @param side2 - вторая сторона треугольника
 * @param angle - угол в треугольнике
 * @return результат вычисления результата 
 */
double calculateCircumcircleRadius(double side1, double side2, double angle) {
double thirdSide = calculateThirdSide(side1, side2, angle);
return (side1 * side2 * thirdSide) / (4 * sqrt((side1 + side2 + thirdSide) * (side1 + side2 - thirdSide) * (side2 + thirdSide - side1) * (side1 + thirdSide - side2)));
}
/**
 * @breef получает значение с клавиатуры
 * @return  вычисления третьей стороны треугольника, вычисления площади треугольника, вычисления радиуса описанной окружности
 */
int main() {
double side1, side2, angle;
cout << "Введите длину первой стороны треугольника: ";
cin >> side1;
cout << "Введите длину второй стороны треугольника: ";
cin >> side2;
cout << "Введите величину угла между сторонами в радианах: ";
cin >> angle;
double thirdSide = calculateThirdSide(side1, side2, angle);
double area = calculateTriangleArea(side1, side2, angle);
double radius = calculateCircumcircleRadius(side1, side2, angle);

cout << "Третья сторона треугольника: " << thirdSide << endl;
cout << "Площадь треугольника: " << area << endl;
cout << "Радиус описанной окружности: " << radius << endl;

return 0;
} 
