#include <iostream>
using namespace std;

# define PI 3.14159
class Shape{
    public:
        virtual double area()=0;
};
class Rectangle : public Shape{
    public:
        Rectangle();
        Rectangle(int l, int w);
        ~Rectangle();
        double area();
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
        double area();
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
        double area();
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
    // Shape shape; //抽象类不可以实例化, 编译不通过，会报错。
    Shape &sh = s;  //抽象类不可以实例化，但可以创建指针或引用。抽象类的引用可以访问派生类的虚函数
    sh.area();
    r.area();
    c.area();
    s.area();
    return 0;
}