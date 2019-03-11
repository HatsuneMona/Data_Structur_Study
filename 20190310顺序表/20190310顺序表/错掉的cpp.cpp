//错的↓

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
//void Loadfile();//读取文件
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
//	work_1();//1班和2班一起排队。归并两个“其数据元素按值非递减有序排列”的有序（用顺序表实现）。
//	show();
//	work_2();//头尾交换重新排队。将顺序表A逆置，只允许在原表的存储空间外再增加一个附加的工作单元。
//	show();
//	work_3();//调整顺序表A，使其左边的所有元素均小于18，使其右边的所有元素均大于18。按照年龄调整。设有一个顺序表A，包含n个数据元素。
//	show();
//	system("pause");
//}
//
//void Loadfile() {
//	cout << "文件开始读取" << endl;
//	ifstream file;
//	file.open("class1.txt", ios::in);
//	if (file.is_open()) {
//		while (!file.eof()) {
//			file >> age_1[size_1++];
//		}
//	}
//	else {
//		cout << "文件读取错误" << endl;
//	}
//	file.close();
//	file.open("class2.txt", ios::in);
//	if (file.is_open()) {
//		while (!file.eof()) {
//			file >> age_2[size_2++];
//		}
//	}
//	else {
//		cout << "文件读取错误" << endl;
//	}
//	file.close();
//	size_1--;
//	size_2--;
//	cout << "文件读取结束" << endl;
//}
//
//void work_1() {
//	cout << "执行任务一：1班和2班一起排队。归并两个“其数据元素按值非递减有序排列”的有序（用顺序表实现）" << endl;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	//第一个排序结果的赋值。
//	if (age_1[i] <= age_2[j]) {
//		result[k] = age_1[i++];
//	}
//	else {
//		result[k] = age_2[j++];
//	}
//	//中部排序结果的赋值（遇到某一个数组中断后停止）。
//	while (i < size_1 && j < size_2) {
//		if (age_1[i] <= age_2[j]) {
//			result[++k] = age_1[i++];
//		}
//		else {
//			result[++k] = age_2[j++];
//		}
//	}
//	//遇到某一个数组中断后,剩余的数组元素照抄另一个没有完的数组。
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
//	cout << "执行任务二：头尾交换重新排队。将顺序表A逆置，只允许在原表的存储空间外再增加一个附加的工作单元。" << endl;
//	int temp;//附加的工作单元
//	for (int i = 0; i < size_r / 2; i++) {
//		temp = result[i];
//		result[i] = result[size_r - i - 1];
//		result[size_r - i - 1] = temp;
//	}
//}
//
//void work_3() {
//	cout << "执行任务三：调整顺序表A，使其左边的所有元素均小于18，使其右边的所有元素均大于18。按照年龄调整。设有一个顺序表A，包含n个数据元素。" << endl;
//	//备注：如果表A是顺序的，这段代码应该是正确的
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
//	cout << "一班的年龄数组：";
//	for (int i = 0; i < size_1; i++) {
//		cout << age_1[i] << " ";
//	}
//	cout << endl << "二班的年龄数组：";
//	for (int i = 0; i < size_2; i++) {
//		cout << age_2[i] << " ";
//	}
//	cout << endl << "结果数组：";
//	for (int i = 0; i < size_r; i++) {
//		cout << result[i] << " ";
//	}
//	cout << endl;
//}
