//��ġ�

//#include <iostream>
//#include <fstream>
//using namespace std;
//
//#define MAXSIZE 100
//
//int result[MAXSIZE];
//int age_1[MAXSIZE];
//int age_2[MAXSIZE];
//int size_1;
//int size_2;
//int size_r = 0;
//
//void Loadfile();//��ȡ�ļ�
////void sort(); 
////void swap(int &a, int &b);
//void work_1();
//void work_2();
//void work_3();
//void show();
//
//int main() {
//	Loadfile();
//	show();
//	work_1();//1���2��һ���Ŷӡ��鲢������������Ԫ�ذ�ֵ�ǵݼ��������С���������˳���ʵ�֣���
//	show();
//	work_2();//ͷβ���������Ŷӡ���˳���A���ã�ֻ������ԭ��Ĵ洢�ռ���������һ�����ӵĹ�����Ԫ��
//	show();
//	work_3();//����˳���A��ʹ����ߵ�����Ԫ�ؾ�С��18��ʹ���ұߵ�����Ԫ�ؾ�����18�������������������һ��˳���A������n������Ԫ�ء�
//	show();
//	system("pause");
//}
//
//void Loadfile() {
//	cout << "�ļ���ʼ��ȡ" << endl;
//	ifstream file;
//	file.open("class1.txt", ios::in);
//	if (file.is_open()) {
//		while (!file.eof()) {
//			file >> age_1[size_1++];
//		}
//	}
//	else {
//		cout << "�ļ���ȡ����" << endl;
//	}
//	file.close();
//	file.open("class2.txt", ios::in);
//	if (file.is_open()) {
//		while (!file.eof()) {
//			file >> age_2[size_2++];
//		}
//	}
//	else {
//		cout << "�ļ���ȡ����" << endl;
//	}
//	file.close();
//	size_1--;
//	size_2--;
//	cout << "�ļ���ȡ����" << endl;
//}
//
//void work_1() {
//	cout << "ִ������һ��1���2��һ���Ŷӡ��鲢������������Ԫ�ذ�ֵ�ǵݼ��������С���������˳���ʵ�֣�" << endl;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	//��һ���������ĸ�ֵ��
//	if (age_1[i] <= age_2[j]) {
//		result[k] = age_1[i++];
//	}
//	else {
//		result[k] = age_2[j++];
//	}
//	//�в��������ĸ�ֵ������ĳһ�������жϺ�ֹͣ����
//	while (i < size_1 && j < size_2) {
//		if (age_1[i] <= age_2[j]) {
//			result[++k] = age_1[i++];
//		}
//		else {
//			result[++k] = age_2[j++];
//		}
//	}
//	//����ĳһ�������жϺ�,ʣ�������Ԫ���ճ���һ��û��������顣
//	if (i == size_1) {
//		while (j < size_2) {
//			result[++k] = age_2[j++];
//		}
//	}
//	else if (j == size_2) {
//		while (i < size_1) {
//			result[++k] = age_1[i++];
//		}
//	}
//	size_r = ++k;
//}
//
//void work_2() {
//	cout << "ִ���������ͷβ���������Ŷӡ���˳���A���ã�ֻ������ԭ��Ĵ洢�ռ���������һ�����ӵĹ�����Ԫ��" << endl;
//	int temp;//���ӵĹ�����Ԫ
//	for (int i = 0; i < size_r / 2; i++) {
//		temp = result[i];
//		result[i] = result[size_r - i - 1];
//		result[size_r - i - 1] = temp;
//	}
//}
//
//void work_3() {
//	cout << "ִ��������������˳���A��ʹ����ߵ�����Ԫ�ؾ�С��18��ʹ���ұߵ�����Ԫ�ؾ�����18�������������������һ��˳���A������n������Ԫ�ء�" << endl;
//	//��ע�������A��˳��ģ���δ���Ӧ������ȷ��
//	int temp;
//	for (int i = 0; i < size_r; i++) {
//		if (result[i] <= 18) {
//			temp = result[i];
//			result[i] = result[size_r - i - 1];
//			result[size_r - i - 1] = temp;
//		}
//	}
//}
//
//void show() {
//	cout << "һ����������飺";
//	for (int i = 0; i < size_1; i++) {
//		cout << age_1[i] << " ";
//	}
//	cout << endl << "������������飺";
//	for (int i = 0; i < size_2; i++) {
//		cout << age_2[i] << " ";
//	}
//	cout << endl << "������飺";
//	for (int i = 0; i < size_r; i++) {
//		cout << result[i] << " ";
//	}
//	cout << endl;
//}
