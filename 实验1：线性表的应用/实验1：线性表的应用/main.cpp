#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
	LinkList poly_A;          //声明一元多项式表
	LinkList poly_B;
	//InitList(poly_A);         //初始化一元多项式表
	InitList(poly_B);
	//AddElem(poly_A, "polynomial_A.txt");          //向一元多项式表中添加元素
	AddElem(poly_B, "polynomial_B.txt");
	//sort(poly_A);
	//Sort(poly_B);
	//ShowPolynamial(poly_A);   //显示一元多项式
	cout << "整理前：" << endl;
	ShowPolynomial(poly_B);   //显示一元多项式
	ProcessingPolynomial(poly_B);
	cout << "整理后：" << endl;
	ShowPolynomial(poly_B);   //显示一元多项式
	//cout << endl << "一元多项式的和为：" << SumPoly(poly_B) << endl;  //一元多项式求和
	return 0;
}