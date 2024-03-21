#include <iostream>
#include <cmath>
using namespace std;
/**
* @breef - функция, для вычисления значения переменных a по заданным константам.
* @param x- значение константы x.
* @param y- значение константы y.
* @param z- значение константы z.
* @return результат вычисления результата a.
**/
double calculateA(const double x,const double y,const double z);
/**
* @breef - функция, для вычисления значения переменных b по заданным константам.
* @param x- значение константы x.
* @param y- значение константы y.
* @param z- значение константы z.
* @return результат вычисления результата b.
**/
double calculateB(const double x,const double y,const double z);
int main()
{
const double x=0.5;
const double y=0.05;
const double z=0.7;
cout<<"x="<<x<<endl;
cout<<"y="<<y<<endl;
cout<<"z="<<z<<endl;
cout<<"a="<<calculateA(x,y,z)<<endl;
cout<<"b="<<calculateB(x,y,z)<<endl;
return 0;
}
double calculateA(const double x,const double y,const double z)
{
    return (pow(x,2)*(x+1.0))/(y-pow(sin(x+z),2));
}
double calculateB(const double x,const double y,const double z)
{
    return sqrt((x*y)/z)+pow(cos(pow((x+y),2)),2);
}

