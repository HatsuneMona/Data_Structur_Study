#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define TRUE      1
#define FALSE     0
#define OK        1
#define ERROR     0
typedef int       Status;        //状态

typedef struct {
	string sno;
	string name;
	int age;
}ElemType;//元素结构

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;//节点结构

//初始化链表
Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

//创建单链表（使用“后插法”）（使用读取文件的方法进行创建）
Status AddElem(LinkList &L) {
	int stat = 0;
	LNode *r = L;//r用于指示单链表的末尾，这里赋值成L，意为指向空链表的表头。
	LNode *p;//p代表新的 节点。

	ifstream file;
	ElemType temp;
	file.open("students.txt", ios::in);
	if (file.is_open()) {
		while (!file.eof()) {//如果不是文件的末尾
			try {//读取文件，并将文件内容打包成一个ElemType
				file >> temp.sno;
				file >> temp.name;
				file >> temp.age;
			}
			catch (...) {
				cout << "文件读取错误，txt内容元素数量非法！" << endl;
			}
			//这里为后插法创建单链表的核心代码开始
			p = new LNode;       //新建一个LNode节点
			p->data = temp;      //将新LNode节点的data设置成 temp
			p->next = NULL;      //将新LNode节点的next设置成 NULL
			r->next = p;         //将单链表末尾的下一个节点“next”指向p
			r = p;               //移动单链表的末尾，移到p
			//后插法创建单链表的核心代码结束
			++stat;
		}
	}
	cout << "读取成功，共插入了 " << stat << " 条学生数据" << endl;
	return OK;
}


//输出所有学生信息
void ShowAllStudentInformation(LinkList L) {
	LNode *p = L;
	do {
		p = p->next;
		cout << p->data.sno << "     ";
		cout << p->data.age << "     ";
		cout << p->data.name << endl;
	} while (p->next != NULL);
}

//获取年龄最大的学生
void GettheOldestStudent(LinkList L) {
	LNode *p = L;
	LNode *oldestStudent = L;
	do {
		p = p->next;
		if (oldestStudent->data.age <= p->data.age)
			oldestStudent->data.age = p->data.age;
	} while (p->next != NULL);
	cout << "年龄最大的学生为：";
	cout << oldestStudent->data.sno << "     ";
	cout << oldestStudent->data.age << "     ";
	cout << oldestStudent->data.name << endl;
}

//逆转链表方向
void ReverseList(LinkList &L) {
	/*
	This Code Write&Design By 172054213 宋海禹
	时间复杂度：O(n)
	设计理念：
	我们需要三个指针：p、q、r（为了方便说明，我们假设三个指针指向的节点分别为1、2、3号节点）
	其中：          p、q是用于逆置用的；r是用于“防丢”的，因为p、q逆置后，2号节点所包含的“next”会被覆盖写成“1号节点”，如果没有r指针，我们将找不到3号节点。
	核心操作：       逆置循环的时候，我们仅需要改变二号节点中的指针，将其改变为指向“一号节点”。
	算法的结束：     while循环的时候我们要时刻保证三号节点不为空（否则r->next会无意义）所以，算法循环的结束条件是“三号节点为空”的时候。
	               三号节点变为空，意味着循环的结束，此时二号节点中的“next”少重指向了一次，所以需要在循环体外补上。
	最后：          我们修改头节点，将头结点指向新的队头，即一号节点。
	*/
	//逆转链表核心代码开始
	LNode *p, *q, *r;
	p = L->next;               //初始化一号节点
	q = p->next;               //初始化二号节点
	r = q->next;               //初始化三号节点
	p->next = NULL;            //逆转过后，仅有1号节点的“next”会指向空，即NULL
	while (r != NULL) {        //算法循环的结束条件是“三号节点为空”的时候。
		q->next = p;           //将二号节点的“next”重新指向到一号节点
		p = q;                 //移动指针位置，一号节点->向后移一个节点
		q = r;                 //移动指针位置，二号节点->向后移一个节点
		r = r->next;           //移动指针位置，三号节点->向后移一个节点
	}
	q->next = p;               //此时二号节点中的“next”少重指向了一次，补上
	L->next = q;               //修改头节点，将头结点指向新的队头，即一号节点
	//逆转链表核心代码结束
}


int main() {
	LinkList students;
	InitList(students);                      //初始化student链表
	AddElem(students);                       //使用后插法创建单链表
	ShowAllStudentInformation(students);     //显示学生信息
	cout << endl;
	GettheOldestStudent(students);           //遍历链表，找到年龄最大的学生（50）
	cout << endl;
	ReverseList(students);                   //逆转链表
	ShowAllStudentInformation(students);     //显示学生信息
	system("pause");
	return 0;
}