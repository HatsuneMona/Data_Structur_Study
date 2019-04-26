#include "header.h"
using namespace std;

Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status AddElem(LinkList& L,string path) {
	int stat = 0;
	LNode* r = L;//r����ָʾ�������ĩβ�����︳ֵ��L����Ϊָ�������ı�ͷ��
	LNode* p;//p�����µ� �ڵ㡣
	ifstream file;
	ElemType temp;
	file.open(path, ios::in);
	if (file.is_open()) {
		while (!file.eof()) {//��������ļ���ĩβ
			try {//��ȡ�ļ��������ļ����ݴ����һ��ElemType
				file >> temp.coef;//ϵ��
				file >> temp.expn;//ָ��
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
	file.close();
	cout << "��ȡ�ɹ�������ȡ�� " << stat << " ������" << endl;
	return OK;
}

Status ShowPolynomial(LinkList L) {
	LNode* p;
	cout << "����ʽΪ��";
	if (!L->next) {
		cout << "0";
	}
	else {
		for (p = L->next; p; p = p->next) {
			cout << p->data.coef << "x^" << p->data.expn;
			if (p->next)cout << " + ";
		}
	}
	cout << endl;
	return OK;
}
//�����㷨 �ϲ�����ʽ
Status ProcessingPolynomial(LinkList &L) {
	Sort(L);                                     //����������
	LNode* r = L;                                //r�ĳ�ʼλ��������ͷ
	LNode* p;
	LNode* q;
	//�������ʽΪ��
	if (!r->next) {                
		cout << "����ʽΪ�գ�����ƭ�ҳ�BUG" << endl;
		return ERROR;
	}
	//�������ʽֻ��һ��
	else if (!r->next->next) {     
		p = r->next;                             //ָ��p�ĳ�ʼλ�ã���һ��
		if (p->data.coef == 0)                   //���ָ��Ϊ0
			RemoveNext(r);                       //ɾ��������õ�һ��������
	}
	//�������ʽ��>=����
	else {                        
		p = r->next;                             //ָ��p�ĳ�ʼλ�ã���һ��
		q = p->next;                             //ָ��q�ĳ�ʼλ�ã��ڶ���
		bool flog;                               //���ڼ�¼�Ƿ�����˺ϲ�����
		//��ʼѭ����ѭ���������������������ʽ��������ͷ�յ�data��
		while (p && q) {
			flog = 0;                            //����״̬��û�н��кϲ�������
			//ָ����ͬ������£��ص㣬��Ҫ�ϲ��ĵط���
			if (p->data.expn == q->data.expn) {
				p->data.coef += q->data.coef;    //ϵ�����
				RemoveNext(p);                   //ɾ������
				if (p->data.coef == 0)           //ָ����Ӻ�Ϊ0�����
					RemoveNext(r);               //ɾ��ָ��Ϊ0��һ��
				flog = 1;                        //�����˺ϲ�������flog = 1��
			}
			//ָ����ͬ�������
			if (!flog && r->next) r = r->next;   //���û�н��������ϲ���������r����һ������r
			if (r->next) p = r->next;            //���r���滹�����ֵp
			else p = NULL;                       //����pΪ��
			if (p && p->next) q = p->next;       //�������p������p���滹�����ֵq
			else q = NULL;                       //����qΪ��
		}
	}
	return OK;
}

LinkList SumPolynomial(LinkList L, LinkList M) {
	LNode* p = L;
	LinkList sum;
	InitList(sum);
	sum = p;//��L����ֱ�Ӹ���sum
	while (p->next) 
		p = p->next;
	p->next = M->next;
	return sum;
}

Status Swap(LNode* p, LNode* q) {
	ElemType dataTemp = p->data;
	p->data = q->data;
	q->data = dataTemp;
	return OK;
}

Status RemoveNext(LNode* p) {
	LNode* rm = p->next;//��ȡ��Ҫɾ���Ľ��
	p->next = rm->next;//����Ҫɾ���Ľ���Next�������һ�ڵ��Next
	delete rm;//ɾ��Ҫɾ���Ľ��
	return OK;
}

Status Sort(LinkList& L) {
	LNode* p;     //ָ��������λ��
	LNode* min;//ָ������С�Ľ��
	LNode* searchmin;//������Ѱ������С�Ľ�㣬�Ƚ��á�
	for (p = L->next; p; p = p->next) {//ѭ����ͷ��ʼ�����p���ڣ���ΪNull����ѭ������
		min = p;
		searchmin = p->next;
		for (; searchmin; searchmin = searchmin->next) 
			if (searchmin->data.expn <= min->data.expn) 
				min = searchmin;
		Swap(min, p);
	}
	return OK;
}

