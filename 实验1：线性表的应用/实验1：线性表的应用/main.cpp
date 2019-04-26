#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
	LinkList poly_A;                              //声明一元多项式表
	LinkList poly_B;
	LinkList result;
	InitList(poly_A);                             //初始化一元多项式表
	InitList(poly_B);
	AddElem(poly_A, "polynomial_A.txt");          //向一元多项式表中添加元素
	AddElem(poly_B, "polynomial_B.txt");
	cout << "整理前：" << endl;
	ShowPolynomial(poly_A);                       //显示一元多项式
	ShowPolynomial(poly_B);                       
	result = SumPolynomial(poly_A, poly_B);       //多项式A、B相加
	ProcessingPolynomial(result);                 //整理多项式
	cout << "多项式A、B相加后：" << endl;
	ShowPolynomial(result);                       //显示一元多项式

	////以下测试
	//InitList(result);
	//AddElem(result, "test.txt");                  //测试用
	//cout << "整理前：" << endl;
	//ShowPolynomial(result);                       //显示一元多项式
	//ProcessingPolynomial(result);                 //整理多项式
	//cout << "多项式A、B相加后：" << endl;
	//ShowPolynomial(result);                       //显示一元多项式
	return 0;
}