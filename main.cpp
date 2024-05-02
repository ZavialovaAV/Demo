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
double calculateThirdSide(double side1, double side2, double angle); 
 
/** 
* @breef фунцция для вычисления площади треугольника 
* @param side1 - первая сторона треугольника 
* @param side2 - вторая сторона треугольника 
* @param angle - угол в треугольнике 
* @return результат вычисления результата 
*/ 
double calculateTriangleArea(double side1, double side2, double angle); 
 
/** 
* @breef фунцция для вычисления радиуса описанной окружности 
* @param side1 - первая сторона треугольника 
* @param side2 - вторая сторона треугольника 
* @param angle - угол в треугольнике 
* @return результат вычисления результата 
*/ 
double calculateCircumcircleRadius(double side1, double side2, double angle); 
 
/** 
* @brief Считывает значения с клавиатуры с проверкой ввода 
*/ 
double getValue(); 
 
/** 
* @brief Функция для конвертации радиан в градусы. 
* 
* @param radians Значение в радианах, которое нужно сконвертировать. 
* @return double Значение в градусах после конвертации. 
*/ 
double convertRadiansToDegrees(double radians); 
 
/** 
* @breef получает значение с клавиатуры 
* @return вычисления третьей стороны треугольника, вычисления площади треугольника, вычисления радиуса описанной окружности 
*/ 
int main() 
 
{ 
 
 cout << "Введите длину первой стороны треугольника: "; 
 double side1 = getValue(); 
 cout << "Введите длину второй стороны треугольника: "; 
 double side2 = getValue(); 
 cout << "Введите величину угла между сторонами в радианах: "; 
 double angle = getValue(), convertRadiansToDegrees(double radians);
 
 cout << "Третья сторона треугольника: " << calculateThirdSide(side1, side2, angle)<< endl; 
 cout << "Площадь треугольника: " <<calculateTriangleArea(side1, side2, angle)<< endl; 
 cout << "Радиус описанной окружности: " <<calculateCircumcircleRadius(side1, side2, angle)<< endl; 
 
 return 0; 
} 
 
double getValue() 
{ 
 double value; 
 cin>>value; 
 if (cin.fail()) 
 { 
 cout<<"Incorrect value "<< endl; 
 abort(); 
 } 
 return value; 
} 
 
 
double calculateThirdSide(double side1, double side2, double angle) 
{ 
 return sqrt(side1 * side1 + side2 * side2 - 2 * side1 * side2 * cos(angle)); 
} 
 
 
double calculateTriangleArea(double side1, double side2, double angle) 
{ 
 double thirdSide = calculateThirdSide(side1, side2, angle); 
 return 0.5 * side1 * side2 * sin(angle); 
} 
 
 
double calculateCircumcircleRadius(const double side1, const double side2, const double angle) 
{ 
 double thirdSide = calculateThirdSide(side1, side2, angle); 
 return (side1 * side2 * thirdSide) / (4 * sqrt((side1 + side2 + thirdSide) * (side1 + side2 - thirdSide) * (side2 + thirdSide - side1) * (side1 + thirdSide - side2))); 
} 
 
double convertRadiansToDegrees(double radians) 
{ 
 return radians * 180.0 / 3.1415; 
}