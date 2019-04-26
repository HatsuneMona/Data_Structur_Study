#include "header.h"
using namespace std;

Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status AddElem(LinkList& L,string path) {
	int stat = 0;
	LNode* r = L;//r用于指示单链表的末尾，这里赋值成L，意为指向空链表的表头。
	LNode* p;//p代表新的 节点。
	ifstream file;
	ElemType temp;
	file.open(path, ios::in);
	if (file.is_open()) {
		while (!file.eof()) {//如果不是文件的末尾
			try {//读取文件，并将文件内容打包成一个ElemType
				file >> temp.coef;//系数
				file >> temp.expn;//指数
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
	file.close();
	cout << "读取成功，共读取了 " << stat << " 项数据" << endl;
	return OK;
}

Status ShowPolynomial(LinkList L) {
	LNode* p;
	cout << "多项式为：";
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
//核心算法 合并多项式
Status ProcessingPolynomial(LinkList &L) {
	Sort(L);                                     //先排序数组
	LNode* r = L;                                //r的初始位置在链表头
	LNode* p;
	LNode* q;
	//如果多项式为空
	if (!r->next) {                
		cout << "多项式为空，别想骗我出BUG" << endl;
		return ERROR;
	}
	//如果多项式只有一项
	else if (!r->next->next) {     
		p = r->next;                             //指定p的初始位置：第一项
		if (p->data.coef == 0)                   //如果指数为0
			RemoveNext(r);                       //删除该项，并得到一个空数组
	}
	//如果多项式有>=两项
	else {                        
		p = r->next;                             //指定p的初始位置：第一项
		q = p->next;                             //指定q的初始位置：第二项
		bool flog;                               //用于记录是否进行了合并操作
		//开始循环，循环条件：至少有两项多项式（包括表头空的data）
		while (p && q) {
			flog = 0;                            //重置状态（没有进行合并操作）
			//指数相同的情况下（重点，需要合并的地方）
			if (p->data.expn == q->data.expn) {
				p->data.coef += q->data.coef;    //系数相加
				RemoveNext(p);                   //删除后者
				if (p->data.coef == 0)           //指数相加后为0的情况
					RemoveNext(r);               //删除指数为0的一项
				flog = 1;                        //进行了合并操作（flog = 1）
			}
			//指数不同的情况下
			if (!flog && r->next) r = r->next;   //如果没有进行项数合并操作，且r有下一项，则后移r
			if (r->next) p = r->next;            //如果r后面还有项，则赋值p
			else p = NULL;                       //否则p为空
			if (p && p->next) q = p->next;       //如果存在p，并且p后面还有项，则赋值q
			else q = NULL;                       //否则q为空
		}
	}
	return OK;
}

LinkList SumPolynomial(LinkList L, LinkList M) {
	LNode* p = L;
	LinkList sum;
	InitList(sum);
	sum = p;//将L链表直接赋给sum
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
	LNode* rm = p->next;//获取将要删除的结点
	p->next = rm->next;//将将要删除的结点的Next赋予给上一节点的Next
	delete rm;//删除要删除的结点
	return OK;
}

Status Sort(LinkList& L) {
	LNode* p;     //指向待排序的位置
	LNode* min;//指向本轮最小的结点
	LNode* searchmin;//用于搜寻本轮最小的结点，比较用。
	for (p = L->next; p; p = p->next) {//循环从头开始，如果p存在（不为Null）则循环结束
		min = p;
		searchmin = p->next;
		for (; searchmin; searchmin = searchmin->next) 
			if (searchmin->data.expn <= min->data.expn) 
				min = searchmin;
		Swap(min, p);
	}
	return OK;
}

