#include<iostream>
#include<fstream>
using namespace std;

#define TRUE      1
#define FALSE     0
#define OK        1
#define ERROR     0
typedef int       Status;        //状态
typedef int       elemType;      //线性表类型

#define MAXSIZE            100            //线性表最长长度
//#define LIST_INIT_SIZE     100            //线性表存储空间的初始分配量
//#define LISTINCREMENT      10             //线性表存储空间的分配增量

typedef struct {
	elemType *elem;//元素集
	int last = -1;//代表List最后一个元素的位置
}SqList;

/*
为了方便程序分函数（Work_1()、Work_2())等函数的运行，故在此使用了全局变量，
但对于“新建表”“添加元素”“交换元素”“获取元素数量”等基础函数，
严格按照需求关系选择“引用”或“不引用”
*/
SqList class1, class2, result;


//新建表
Status CreateList(SqList &L) {
	L.elem = new elemType[MAXSIZE];
	if (!L.elem) {
		exit(ERROR);
	}
	else {
		L.last = -1;
		return OK;
	}
}

//清空表
Status CleanList(SqList &L) {
	L.last = -1;//位置=0代表的第一个元素，位置为-1代表没有元素。
	return OK;
}

//添加元素
Status Addelem(SqList &L, elemType data) {
	if (L.last + 1 <= MAXSIZE) {//如果没有超出MAXSIZE
		L.elem[++L.last] = data;
		return OK;
	}
	else {//超出MAXSIZE
		cout << "超出最大范围" << endl;
		return ERROR;
	}
}

//交换元素
Status Swapelem(elemType &data_a, elemType &data_b) {
	elemType temp;//这里只使用了一个附加的工作单元
	temp = data_a;
	data_a = data_b;
	data_b = temp;
	return OK;
}

//获取元素数量
int Length(SqList L) {
	return L.last++;
}

//显示表内容
void Show(SqList L) {
	for (int i = 0; i <= L.last; i++) {
		cout << L.elem[i] << "  ";
	}
	cout << endl;
}

//读取文件
Status LoadFile() {
	cout << "文件开始读取" << endl;
	ifstream file;
	elemType temp;
	file.open("class1.txt", ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			file >> temp;
			Addelem(class1, temp);
		}
	}
	else {
		cout << "文件读取错误" << endl;
		return ERROR;
	}
	file.close();
	file.open("class2.txt", ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			file >> temp;
			Addelem(class2, temp);
		}
	}
	else {
		cout << "文件读取错误" << endl;
		return ERROR;
	}
	file.close();
	cout << "文件读取结束" << endl;
	return OK;
}

//批量显示
void Show() {
	cout << "班级一：";
	Show(class1);
	cout << "班级二：";
	Show(class2);
	cout << "结果  ：";
	Show(result);
}

//任务一：1班和2班一起排队。归并两个“其数据元素按值非递减有序排列”的有序（用顺序表实现）。
void Work_1() {
	cout << "执行任务一：1班和2班一起排队。归并两个“其数据元素按值非递减有序排列”的有序（用顺序表实现）" << endl;
	int i = 0;
	int j = 0;
	int k = 0;
	//第一个排序结果的赋值。
	if (class1.elem[i] <= class2.elem[j]) 
		Addelem(result, class1.elem[i++]);
	else 
		Addelem(result, class1.elem[j++]);
	//中部排序结果的赋值（遇到某一个数组中断后停止）。
	while (i <= class1.last && j <= class2.last) 
		if (class1.elem[i] <= class2.elem[j]) 
			Addelem(result, class1.elem[i++]);
		else 
			Addelem(result, class1.elem[j++]);
	//遇到某一个数组中断后,剩余的数组元素照抄另一个没有完的数组。
	if (i > class1.last) 
		while (j <= class2.last) 
			Addelem(result, class2.elem[j++]);
	else if (j > class2.last) 
		while (i <= class1.last) 
			Addelem(result, class1.elem[i++]);
}
//任务二：头尾交换重新排队。将顺序表A逆置，只允许在原表的存储空间外再增加一个附加的工作单元。
void Work_2() {
	cout << "执行任务二：头尾交换重新排队。将顺序表A逆置，只允许在原表的存储空间外再增加一个附加的工作单元。" << endl;
	for (int i = 0; i <= result.last / 2; i++) {
		Swapelem(result.elem[i], result.elem[result.last - i]);//elemSwap内仅含一个附加的工作单元
	}
}

//任务三：调整顺序表A，使其左边的所有元素均小于18，使其右边的所有元素均大于18。按照年龄调整。设有一个顺序表A，包含n个数据元素。
void Work_3() {
	cout << "执行任务三：调整顺序表A，使其左边的所有元素均小于18，使其右边的所有元素均大于18。按照年龄调整。设有一个顺序表A，包含n个数据元素。" << endl;
	//备注：如果表A是顺序的，这段代码应该是正确的
	int temp;
	for (int i = 0; i <= result.last; i++) {
		if (result.elem[i] <= 18) {
			Swapelem(result.elem[i], result.elem[result.last - i]);
		}
	}
}

int main() {
	CreateList(class1);
	CreateList(class2);
	CreateList(result);
	Show();//在空表的情况下输出数据
	LoadFile();//从TXT文档中读取数据
	Show();//显示读取到的原始数据
	Work_1();//进行任务一
	Show();
	Work_2();//进行任务二
	Show();
	Work_3();//进行任务三
	Show();
	system("pause");
}