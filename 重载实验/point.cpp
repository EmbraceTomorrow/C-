#include <iostream>
#include <math.h>
using namespace std;
class Point{
    public:
        Point();
        Point(int x, int y);
        Point(const Point& p);
        Point operator ++(); //前置“++”重载,++point
        Point operator ++(int); //后置“++”重载,point++
        Point operator --(); //前置“--”重载,--point
        Point operator --(int); //后置“--”重载,point--
        void print();
    private:
        int x;
        int y;
};
Point::Point(){
    x = 0;
    y = 0;
}
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}
Point::Point(const Point& p){
    x = p.x;
    y = p.y;
}
Point Point::operator ++(){
    x++;
    y++;
    return *this;
}
Point Point::operator ++(int){
    Point temp(*this);
    x++;
    y++;
    return temp;
}
Point Point::operator --(){
    x--;
    y--;
    return *this;
}
Point Point::operator --(int){
    Point temp(*this);
    x--;
    y--;
    return temp;
}
void Point::print(){
    cout<<"圆心:("<< x <<","<< y << ")" <<endl;
}
int main()
{
    system("chcp 65001"); //解决输出中文乱码
    Point p(5,6);
    Point p2;
    cout<<"p的";
    p.print();
    p2 = ++p;
    cout<<"++p的";
    p.print();
    cout<<"p2 = ++p的";
    p2.print();
    p2 = p++;
    cout<<"p++的";
    p.print();
    cout<<"p2 = p++的";
    p2.print();
    p2 = --p;
    cout<<"--p的";
    p.print();
    cout<<"p2 = --p的";
    p2.print();
    p2 = p--;
    cout<<"p--的";
    p.print();
    cout<<"p2 = p--的";
    p2.print();
    return 0;
}
