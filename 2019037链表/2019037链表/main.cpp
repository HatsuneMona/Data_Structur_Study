#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define TRUE      1
#define FALSE     0
#define OK        1
#define ERROR     0
typedef int       Status;        //״̬

typedef struct {
	string sno;
	string name;
	int age;
}ElemType;//Ԫ�ؽṹ

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;//�ڵ�ṹ

//��ʼ������
Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

//����������ʹ�á���巨������ʹ�ö�ȡ�ļ��ķ������д�����
Status AddElem(LinkList &L) {
	int stat = 0;
	LNode *r = L;//r����ָʾ�������ĩβ�����︳ֵ��L����Ϊָ�������ı�ͷ��
	LNode *p;//p�����µ� �ڵ㡣

	ifstream file;
	ElemType temp;
	file.open("students.txt", ios::in);
	if (file.is_open()) {
		while (!file.eof()) {//��������ļ���ĩβ
			try {//��ȡ�ļ��������ļ����ݴ����һ��ElemType
				file >> temp.sno;
				file >> temp.name;
				file >> temp.age;
			}
			catch (...) {
				cout << "�ļ���ȡ����txt����Ԫ�������Ƿ���" << endl;
			}
			//����Ϊ��巨����������ĺ��Ĵ��뿪ʼ
			p = new LNode;       //�½�һ��LNode�ڵ�
			p->data = temp;      //����LNode�ڵ��data���ó� temp
			p->next = NULL;      //����LNode�ڵ��next���ó� NULL
			r->next = p;         //��������ĩβ����һ���ڵ㡰next��ָ��p
			r = p;               //�ƶ��������ĩβ���Ƶ�p
			//��巨����������ĺ��Ĵ������
			++stat;
		}
	}
	cout << "��ȡ�ɹ����������� " << stat << " ��ѧ������" << endl;
	return OK;
}


//�������ѧ����Ϣ
void ShowAllStudentInformation(LinkList L) {
	LNode *p = L;
	do {
		p = p->next;
		cout << p->data.sno << "     ";
		cout << p->data.age << "     ";
		cout << p->data.name << endl;
	} while (p->next != NULL);
}

//��ȡ��������ѧ��
void GettheOldestStudent(LinkList L) {
	LNode *p = L;
	LNode *oldestStudent = L;
	do {
		p = p->next;
		if (oldestStudent->data.age <= p->data.age)
			oldestStudent->data.age = p->data.age;
	} while (p->next != NULL);
	cout << "��������ѧ��Ϊ��";
	cout << oldestStudent->data.sno << "     ";
	cout << oldestStudent->data.age << "     ";
	cout << oldestStudent->data.name << endl;
}

//��ת������
void ReverseList(LinkList &L) {
	/*
	This Code Write&Design By 172054213 �κ���
	ʱ�临�Ӷȣ�O(n)
	������
	������Ҫ����ָ�룺p��q��r��Ϊ�˷���˵�������Ǽ�������ָ��ָ��Ľڵ�ֱ�Ϊ1��2��3�Žڵ㣩
	���У�          p��q�����������õģ�r�����ڡ��������ģ���Ϊp��q���ú�2�Žڵ��������ġ�next���ᱻ����д�ɡ�1�Žڵ㡱�����û��rָ�룬���ǽ��Ҳ���3�Žڵ㡣
	���Ĳ�����       ����ѭ����ʱ�����ǽ���Ҫ�ı���Žڵ��е�ָ�룬����ı�Ϊָ��һ�Žڵ㡱��
	�㷨�Ľ�����     whileѭ����ʱ������Ҫʱ�̱�֤���Žڵ㲻Ϊ�գ�����r->next�������壩���ԣ��㷨ѭ���Ľ��������ǡ����Žڵ�Ϊ�ա���ʱ��
	               ���Žڵ��Ϊ�գ���ζ��ѭ���Ľ�������ʱ���Žڵ��еġ�next������ָ����һ�Σ�������Ҫ��ѭ�����ⲹ�ϡ�
	���          �����޸�ͷ�ڵ㣬��ͷ���ָ���µĶ�ͷ����һ�Žڵ㡣
	*/
	//��ת������Ĵ��뿪ʼ
	LNode *p, *q, *r;
	p = L->next;               //��ʼ��һ�Žڵ�
	q = p->next;               //��ʼ�����Žڵ�
	r = q->next;               //��ʼ�����Žڵ�
	p->next = NULL;            //��ת���󣬽���1�Žڵ�ġ�next����ָ��գ���NULL
	while (r != NULL) {        //�㷨ѭ���Ľ��������ǡ����Žڵ�Ϊ�ա���ʱ��
		q->next = p;           //�����Žڵ�ġ�next������ָ��һ�Žڵ�
		p = q;                 //�ƶ�ָ��λ�ã�һ�Žڵ�->�����һ���ڵ�
		q = r;                 //�ƶ�ָ��λ�ã����Žڵ�->�����һ���ڵ�
		r = r->next;           //�ƶ�ָ��λ�ã����Žڵ�->�����һ���ڵ�
	}
	q->next = p;               //��ʱ���Žڵ��еġ�next������ָ����һ�Σ�����
	L->next = q;               //�޸�ͷ�ڵ㣬��ͷ���ָ���µĶ�ͷ����һ�Žڵ�
	//��ת������Ĵ������
}


int main() {
	LinkList students;
	InitList(students);                      //��ʼ��student����
	AddElem(students);                       //ʹ�ú�巨����������
	ShowAllStudentInformation(students);     //��ʾѧ����Ϣ
	cout << endl;
	GettheOldestStudent(students);           //���������ҵ���������ѧ����50��
	cout << endl;
	ReverseList(students);                   //��ת����
	ShowAllStudentInformation(students);     //��ʾѧ����Ϣ
	system("pause");
	return 0;
}