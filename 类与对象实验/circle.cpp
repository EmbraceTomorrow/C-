#include <iostream>
#include <math.h>
using namespace std;
class Point{
    public:
        Point();
        Point(int x, int y);
        Point(const Point& p);
        ~ Point();
        double distance(Point p);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
    private:
        int x;
        int y;
};
Point::Point(){
    x = 0;
    y = 0;
    cout << "调用无参构造函数Point()"<<endl;
    // cout << "调用无参构造函数Point()"<< x << y <<endl;
    system("pause");
}
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
    cout << "调用构造函数Point(double x, double y)"<<endl;
    // cout << "调用构造函数Point(double x, double y)"<< x << y <<endl;
    system("pause");
}
Point::Point(const Point& p){
    x = p.x;
    y = p.y;
    cout << "调用拷贝构造函数Point(Point& p)" <<endl;
    // cout << "调用拷贝构造函数Point(Point& p)" << x << y <<endl;
    system("pause");
}
Point::~Point(){
    cout << "调用析构函数~Point()" <<endl;
    // cout << "调用析构函数~Point()" << x << y <<endl;
    system("pause");
}
double Point::distance(Point p){
    return sqrt( pow(p.x - x, 2) + pow(p.y - y, 2) );
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
void Point::setX(int x){
    this->x = x;
}
void Point::setY(int y){
    this->y = y;
}
class Circle{
    public:
        Circle();
        Circle(Point center, int redius);
        Circle(const Circle & c);
        ~Circle();
        Point* getCenter();
        int getRadius();
        void setRadius(int radius);
    private:
        Point center;
        int radius;
};
Circle::Circle(){
    center = Point();
    // center = Point(1,1);
    radius = 0;
    cout << "调用无参构造函数Circle()" <<endl;
    system("pause");
}
Circle::Circle(Point center, int radius):center(center){
    radius = radius;
    cout << "调用构造函数Circle(Point center, double redius)" <<endl;
    system("pause");
}
Circle::Circle(const Circle & c){
    center = c.center;
    radius = c.radius;
    cout << "调用拷贝构造函数Circle(Circle & c)" <<endl;
    system("pause");
}
Circle::~Circle(){
    cout << "调用析构函数~Circle()" <<endl;
    system("pause");
}
Point* Circle::getCenter(){
    return &center;
}
int Circle::getRadius(){
    return radius;
}
void Circle::setRadius(int radius){
    this->radius = radius;
}
int main()
{
    system("chcp 65001"); //解决输出中文乱码
    cout<< "开始创建c1" <<endl;
    Circle c1;
    cout<< "开始创建c2" <<endl;
    Circle c2;
    Point *c1Center = c1.getCenter();
    Point *c2Center = c2.getCenter();
    int tempX, tempY, tempR;
    cout<< "请输入c1的圆心和半径：" <<endl;
    cin>> tempX >> tempY >> tempR;
    (*c1Center).setX(tempX);
    (*c1Center).setY(tempY);
    c1.setRadius(tempR);
    cout<< "请输入c2的圆心和半径：" <<endl;
    cin>> tempX >> tempY >> tempR;
    (*c2Center).setX(tempX);
    (*c2Center).setY(tempY);
    c2.setRadius(tempR);
    bool intersect = (*c1Center).distance(*c2Center) <= c1.getRadius() + c2.getRadius();
    if(intersect){
        cout<<"两圆相交！"<<endl;
    }else{
        cout<<"两圆不相交！"<<endl;
    }
    return 0;
}
