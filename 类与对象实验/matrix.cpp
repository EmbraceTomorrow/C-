#include <iostream>
#include <iomanip>
using namespace std;
class Matrix{
    public:
        Matrix(int row, int col, int *matrix);
        Matrix(Matrix& m);
        Matrix operator=(const Matrix &m);
        Matrix operator+(Matrix &m);
        Matrix operator-(Matrix &m);
        ~ Matrix();
        int getRow();
        int getCol();
        void initMatrix();
        Matrix matrixPlus(Matrix m);
        Matrix matrixMinus(Matrix m);
        void printMatrix();
    private:
        int row;
        int col;
        int *matrix;
};
Matrix::Matrix(int row = 0, int col = 0, int *matrix = nullptr){
    this->row = row;
    this->col = col;
    this->matrix = new int[row*col];
    if(matrix != nullptr){
        for(int i=0;i<row*col;++i){
            this->matrix[i] = matrix[i];
        }
    }
}
Matrix::Matrix(Matrix& m){
    row = m.row;
    col = m.col;
    matrix = new int[row*col];
    for(int i=0;i<row*col;++i){
        matrix[i] = m.matrix[i];
    }
}
Matrix Matrix::operator=(const Matrix &m){
    if(this == &m){
        return *this; //自赋值
    }
    delete[] this->matrix; //释放“旧元素”
    this->row = m.row;
    this->col = m.col;
    this->matrix = new int[this->row*this->col];
    for(int i=0;i<row*col;++i){
        matrix[i] = m.matrix[i];
    }
    return *this;
}
Matrix::~Matrix(){
    delete[] matrix;
}
int Matrix::getRow(){
    return row;
}
int Matrix::getCol(){
    return col;
}
void Matrix::initMatrix(){
    cout << "请输入矩阵的行数和列数：" << endl;
    cin >> row;
    cin >> col;
    delete[] this->matrix;
    matrix = new int[row*col];
    cout << "请输入矩阵"<<row<<"×"<<col<<"的元素：" << endl;
    for(int i=0;i<row*col;++i){
        cin >> matrix[i];
    }
    
}
Matrix Matrix::operator + (Matrix& m){
    if(row != m.row || col != m.col){
        cout<< "矩阵大小不相同，无法进行计算！" <<endl;
        return m;
    }
    Matrix res(row,col);
    for(int i=0;i<row*col;++i){
        res.matrix[i] = matrix[i] + m.matrix[i];
    }
    return res;
}
Matrix Matrix::operator - (Matrix& m){
    if(row != m.row || col != m.col){
        cout<< "矩阵大小不相同，无法进行计算！" <<endl;
        return m;
    }
    Matrix res(row,col);
    for(int i=0;i<row*col;++i){
        res.matrix[i] = matrix[i] - m.matrix[i];
    }
    return res;
}
void Matrix::printMatrix(){
    for(int i = 0; i <row; ++i){
        for(int j = 0; j < col; ++j){
            cout << setw(5) << matrix[i*col+j]<< " ";
        }
        cout << endl;
    }
};

int main()
{
    system("chcp 65001"); //解决输出中文乱码
    Matrix A1,A2,A3;
    A1.initMatrix();//初始化
    A2.initMatrix();
    cout << "矩阵A1("<<A1.getRow()<<"×"<<A1.getCol()<<")如下所示：" << endl;
    A1.printMatrix();
    cout << "矩阵A2("<<A2.getRow()<<"×"<<A2.getCol()<<")如下所示：" << endl;
    A2.printMatrix();
    A3 = A1 + A2;
    cout << "矩阵A1和矩阵A2相加结果：" << endl;
    A3.printMatrix();
    A3 = A1 - A2;
    cout << "矩阵A1和矩阵A2相减结果：" << endl;
    A3.printMatrix();

    Matrix* pA1 = new Matrix();
    Matrix* pA2 = new Matrix();
    Matrix* pA3 = new Matrix();
    pA1->initMatrix();
    (*pA2).initMatrix();
    cout << "矩阵pA1("<<(*pA1).getRow()<<"×"<<(*pA1).getCol()<<")如下所示：" << endl;
    (*pA1).printMatrix();
    cout << "矩阵pA2("<<(*pA2).getRow()<<"×"<<(*pA2).getCol()<<")如下所示：" << endl;
    (*pA2).printMatrix();
    (*pA3)=(*pA1)+(*pA2);
    cout << "矩阵pA1和矩阵pA2相加结果：" << endl;
    (*pA3).printMatrix();
    (*pA3)=(*pA1)-(*pA2);
    cout << "矩阵pA1和矩阵pA2相减结果：" << endl;
    (*pA3).printMatrix();
    delete pA1;
    delete pA2;
    delete pA3;
    return 0;
}
// 4 5 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 -19 4 5 20 19 18 17 16 15 14 13 12 11 10 1 2 3 4 5 6 7 8 -9 5 4 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 5 4 20 19 18 17 16 15 14 13 12 11 10 1 2 3 4 5 6 7 8 9
