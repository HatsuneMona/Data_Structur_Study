#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
	LinkList poly_A;          //����һԪ����ʽ��
	LinkList poly_B;
	//InitList(poly_A);         //��ʼ��һԪ����ʽ��
	InitList(poly_B);
	//AddElem(poly_A, "polynomial_A.txt");          //��һԪ����ʽ�������Ԫ��
	AddElem(poly_B, "polynomial_B.txt");
	//sort(poly_A);
	//Sort(poly_B);
	//ShowPolynamial(poly_A);   //��ʾһԪ����ʽ
	cout << "����ǰ��" << endl;
	ShowPolynomial(poly_B);   //��ʾһԪ����ʽ
	ProcessingPolynomial(poly_B);
	cout << "�����" << endl;
	ShowPolynomial(poly_B);   //��ʾһԪ����ʽ
	//cout << endl << "һԪ����ʽ�ĺ�Ϊ��" << SumPoly(poly_B) << endl;  //һԪ����ʽ���
	return 0;
}