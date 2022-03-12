#include <iostream>
#include <iomanip>
using namespace std;

#define MATRIX_ROW 4
#define MATRIX_COL 5

void initMatrix(int (*matrix)[MATRIX_COL]){
    for(int i = 0; i < MATRIX_ROW; ++i){
        for(int j = 0; j < MATRIX_COL; ++j){
            cin >> *(*(matrix + i) + j);
        }
    }
};
void printMatrix(int (*matrix)[MATRIX_COL]){
    for(int i = 0; i < MATRIX_ROW; ++i){
        for(int j = 0; j < MATRIX_COL; ++j){
            cout << setw(5) << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
};
void matrixPlus(int (*matrix1)[MATRIX_COL], int (*matrix2)[MATRIX_COL], int (*matrix3)[MATRIX_COL]){
    int **matrix = new int *[MATRIX_COL];
    for(int i = 0; i < MATRIX_ROW; ++i){
        for(int j = 0; j < MATRIX_COL; ++j){
            *(*(matrix3 + i) + j) = matrix1[i][j] + matrix2[i][j];
        }
    }
};
void matrixMinus(int (*matrix1)[MATRIX_COL], int (*matrix2)[MATRIX_COL], int (*matrix3)[MATRIX_COL]){
    int **matrix = new int *[MATRIX_COL];
    for(int i = 0; i < MATRIX_ROW; ++i){
        for(int j = 0; j < MATRIX_COL; ++j){
            *(*(matrix3 + i) + j) = *(matrix1 + i)[j] - matrix2[i][j];;
        }
    }
};
int main(){
    system("chcp 65001"); //解决输出中文乱码
    // 数组指针
    int (*matrix_A1)[MATRIX_COL] = new int [MATRIX_ROW][MATRIX_COL];
    int (*matrix_A2)[MATRIX_COL] = new int [MATRIX_ROW][MATRIX_COL];
    int (*matrix_A3)[MATRIX_COL] = new int [MATRIX_ROW][MATRIX_COL];
    cout << "请输入矩阵A1(4×5)的元素：" << endl;
    initMatrix(matrix_A1);
    cout << "请输入矩阵A2(4×5)的元素：" << endl;
    initMatrix(matrix_A2);
    cout << "矩阵A1(4×5)如下所示：" << endl;
    printMatrix(matrix_A1);
    cout << "矩阵A1(4×5)如下所示：" << endl;
    printMatrix(matrix_A2);
    cout << "矩阵A1和矩阵A2相加结果：" << endl;
    matrixPlus(matrix_A1, matrix_A2, matrix_A3);
    printMatrix(matrix_A3);
    cout << "矩阵A1和矩阵A2相减结果：" << endl;
    matrixMinus(matrix_A1, matrix_A2, matrix_A3);
    printMatrix(matrix_A3);
    delete matrix_A1;
    delete matrix_A2;
    delete matrix_A3;
    return 0;
}