#include<iostream>
#include<fstream>
using namespace std;

#define TRUE      1
#define FALSE     0
#define OK        1
#define ERROR     0
typedef int       Status;        //״̬
typedef int       elemType;      //���Ա�����

#define MAXSIZE            100            //���Ա������
//#define LIST_INIT_SIZE     100            //���Ա�洢�ռ�ĳ�ʼ������
//#define LISTINCREMENT      10             //���Ա�洢�ռ�ķ�������

typedef struct {
	elemType *elem;//Ԫ�ؼ�
	int last = -1;//����List���һ��Ԫ�ص�λ��
}SqList;

/*
Ϊ�˷������ֺ�����Work_1()��Work_2())�Ⱥ��������У����ڴ�ʹ����ȫ�ֱ�����
�����ڡ��½��������Ԫ�ء�������Ԫ�ء�����ȡԪ���������Ȼ���������
�ϸ��������ϵѡ�����á��򡰲����á�
*/
SqList class1, class2, result;


//�½���
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

//��ձ�
Status CleanList(SqList &L) {
	L.last = -1;//λ��=0����ĵ�һ��Ԫ�أ�λ��Ϊ-1����û��Ԫ�ء�
	return OK;
}

//���Ԫ��
Status Addelem(SqList &L, elemType data) {
	if (L.last + 1 <= MAXSIZE) {//���û�г���MAXSIZE
		L.elem[++L.last] = data;
		return OK;
	}
	else {//����MAXSIZE
		cout << "�������Χ" << endl;
		return ERROR;
	}
}

//����Ԫ��
Status Swapelem(elemType &data_a, elemType &data_b) {
	elemType temp;//����ֻʹ����һ�����ӵĹ�����Ԫ
	temp = data_a;
	data_a = data_b;
	data_b = temp;
	return OK;
}

//��ȡԪ������
int Length(SqList L) {
	return L.last++;
}

//��ʾ������
void Show(SqList L) {
	for (int i = 0; i <= L.last; i++) {
		cout << L.elem[i] << "  ";
	}
	cout << endl;
}

//��ȡ�ļ�
Status LoadFile() {
	cout << "�ļ���ʼ��ȡ" << endl;
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
		cout << "�ļ���ȡ����" << endl;
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
		cout << "�ļ���ȡ����" << endl;
		return ERROR;
	}
	file.close();
	cout << "�ļ���ȡ����" << endl;
	return OK;
}

//������ʾ
void Show() {
	cout << "�༶һ��";
	Show(class1);
	cout << "�༶����";
	Show(class2);
	cout << "���  ��";
	Show(result);
}

//����һ��1���2��һ���Ŷӡ��鲢������������Ԫ�ذ�ֵ�ǵݼ��������С���������˳���ʵ�֣���
void Work_1() {
	cout << "ִ������һ��1���2��һ���Ŷӡ��鲢������������Ԫ�ذ�ֵ�ǵݼ��������С���������˳���ʵ�֣�" << endl;
	int i = 0;
	int j = 0;
	int k = 0;
	//��һ���������ĸ�ֵ��
	if (class1.elem[i] <= class2.elem[j]) 
		Addelem(result, class1.elem[i++]);
	else 
		Addelem(result, class1.elem[j++]);
	//�в��������ĸ�ֵ������ĳһ�������жϺ�ֹͣ����
	while (i <= class1.last && j <= class2.last) 
		if (class1.elem[i] <= class2.elem[j]) 
			Addelem(result, class1.elem[i++]);
		else 
			Addelem(result, class1.elem[j++]);
	//����ĳһ�������жϺ�,ʣ�������Ԫ���ճ���һ��û��������顣
	if (i > class1.last) 
		while (j <= class2.last) 
			Addelem(result, class2.elem[j++]);
	else if (j > class2.last) 
		while (i <= class1.last) 
			Addelem(result, class1.elem[i++]);
}
//�������ͷβ���������Ŷӡ���˳���A���ã�ֻ������ԭ��Ĵ洢�ռ���������һ�����ӵĹ�����Ԫ��
void Work_2() {
	cout << "ִ���������ͷβ���������Ŷӡ���˳���A���ã�ֻ������ԭ��Ĵ洢�ռ���������һ�����ӵĹ�����Ԫ��" << endl;
	for (int i = 0; i <= result.last / 2; i++) {
		Swapelem(result.elem[i], result.elem[result.last - i]);//elemSwap�ڽ���һ�����ӵĹ�����Ԫ
	}
}

//������������˳���A��ʹ����ߵ�����Ԫ�ؾ�С��18��ʹ���ұߵ�����Ԫ�ؾ�����18�������������������һ��˳���A������n������Ԫ�ء�
void Work_3() {
	cout << "ִ��������������˳���A��ʹ����ߵ�����Ԫ�ؾ�С��18��ʹ���ұߵ�����Ԫ�ؾ�����18�������������������һ��˳���A������n������Ԫ�ء�" << endl;
	//��ע�������A��˳��ģ���δ���Ӧ������ȷ��
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
	Show();//�ڿձ��������������
	LoadFile();//��TXT�ĵ��ж�ȡ����
	Show();//��ʾ��ȡ����ԭʼ����
	Work_1();//��������һ
	Show();
	Work_2();//���������
	Show();
	Work_3();//����������
	Show();
	system("pause");
}