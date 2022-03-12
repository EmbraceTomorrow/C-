#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    system("chcp 65001"); //解决输出中文乱码
    srand(time(0));
    int price = rand()%1000 + 1;
    int guess = 0;
    int low = 0;
    int high = 1000;
    while(true){
        cout << "请输入猜测的价格(" << low << "~" << high <<"):" <<endl;
        cin >> guess;
        if(guess > price){
            cout << "猜测的价格高了！" <<endl;
            high = guess;
        }else if (guess < price)
        {
            cout << "猜测的价格低了！" <<endl;
            low = guess;
        }else{
            cout << "猜对了！" <<endl;
            break;
        }
        
    }
    system("pause");
    return 0;
}