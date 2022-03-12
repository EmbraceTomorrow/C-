#include <iostream>
using namespace std;

# define PI 3.14159
class Shape{
    public:
        Shape();
        virtual double area();
};
Shape::Shape(){
    
}
double Shape::area(){
    cout<<"调用基函数的面积计算方法！"<<endl;
    return 0;
}
class Rectangle : public Shape{
    public:
        Rectangle();
        Rectangle(int l, int w);
        ~Rectangle();
        virtual double area();
    private:
        int length;
        int width;
};
Rectangle::Rectangle(){
    cout << "调用无参构造函数Rectangle()"<<endl;
    system("pause");
}
Rectangle::Rectangle(int l, int w){
    length = l;
    width = w;
    cout << "调用构造函数Rectangle(int l, int w)"<<endl;
    system("pause");
}
Rectangle::~Rectangle(){
    cout << "调用析构函数~Rectangle()" <<endl;
    system("pause");
}
double Rectangle::area(){
    cout << "长方形的长和宽分别为：" << length << "," << width << "。" <<endl;
    cout << "长方形的面积为：" << length * width <<endl;
    return length * width;
}
class Circle : public Shape{
    public:
        Circle();
        Circle(int r);
        ~Circle();
        virtual double area();
    private:
        int radius;
};
Circle::Circle(){
    cout << "调用无参构造函数Circle()"<<endl;
    system("pause");
}
Circle::Circle(int r){
    radius = r;
    cout << "调用构造函数Circle(int r)"<<endl;
    system("pause");
    
}
Circle::~Circle(){
    cout << "调用析构函数~Circle()" <<endl;
    system("pause");
}
double Circle::area(){
    cout << "圆形的半径为：" << radius <<endl;
    cout << "圆形的面积为：" << PI * radius * radius <<endl;
    return PI * radius * radius;
}
class Square : public Rectangle{
    public:
        Square();
        Square(int l);
        ~Square();
        virtual double area();
    private:
        int length;
};
Square::Square(){
    cout << "调用无参构造函数Square()"<<endl;
    system("pause");
}
Square::Square(int l){
    length = l;
    cout << "调用构造函数Square(int l)"<<endl;
    system("pause");
}
Square::~Square(){
    cout << "调用析构函数~Square()" <<endl;
    system("pause");
}
double Square::area(){
    cout << "正方形的边长为：" << length <<endl;
    cout << "正方形的面积为：" << length * length <<endl;
    return length * length;
}

int main(){
    system("chcp 65001"); //解决输出中文乱码
    Rectangle r(10,5);
    Circle c(5);
    Square s(7);
    // Shape shape; //不是抽象类，只实现了虚函数，可以创建对象。
    Shape &sh = s;  
    sh.area();  //此处Shape的对象sh调用的是Square类中的area(),实现了动态联编
    r.area();
    c.area();
    s.area();
    return 0;
}