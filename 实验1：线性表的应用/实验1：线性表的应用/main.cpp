#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
	LinkList poly_A;                              //����һԪ����ʽ��
	LinkList poly_B;
	LinkList result;
	InitList(poly_A);                             //��ʼ��һԪ����ʽ��
	InitList(poly_B);
	AddElem(poly_A, "polynomial_A.txt");          //��һԪ����ʽ�������Ԫ��
	AddElem(poly_B, "polynomial_B.txt");
	cout << "����ǰ��" << endl;
	ShowPolynomial(poly_A);                       //��ʾһԪ����ʽ
	ShowPolynomial(poly_B);                       
	result = SumPolynomial(poly_A, poly_B);       //����ʽA��B���
	ProcessingPolynomial(result);                 //�������ʽ
	cout << "����ʽA��B��Ӻ�" << endl;
	ShowPolynomial(result);                       //��ʾһԪ����ʽ

	////���²���
	//InitList(result);
	//AddElem(result, "test.txt");                  //������
	//cout << "����ǰ��" << endl;
	//ShowPolynomial(result);                       //��ʾһԪ����ʽ
	//ProcessingPolynomial(result);                 //�������ʽ
	//cout << "����ʽA��B��Ӻ�" << endl;
	//ShowPolynomial(result);                       //��ʾһԪ����ʽ
	return 0;
}