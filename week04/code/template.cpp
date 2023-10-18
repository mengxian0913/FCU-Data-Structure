#define MAX 100

struct polynomial{
    int coef ; //多項式的係數
    int expon ; //多項式的指數
};

struct MyPoly{
    polynomial terms[MAX] ; //多項式陣列
    int size ; //多項式大小
    MyPoly(); //建構子 初始化 size = 0
    MyPoly(char*); //建構子 讀入檔案
    void ShowPoly( ) ; //印出多項式內容
    MyPoly Add(MyPoly) ; //多項式相加
    void SingleMult(int) ; //將多項式乘上一係數
    int Lead_Exp() ; //回傳多項式中最大指數的次方
    void Attach(float, int) ; //新增 1 個項式到多項式中
    void Remove(int); //刪除多項式中的某一指數
    MyPoly Mult(MyPoly); //多項式相乘
};