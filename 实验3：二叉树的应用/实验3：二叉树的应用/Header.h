#pragma once

//二叉树的存储结构
typedef char TElemType;

//节点结构
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;

typedef BiTree SElemType;

//构造空树
void 初始化空树(BiTree &T);

//创建树的定义
void 创建树(BiTree &T);

//输出二叉树的中序遍历结果
void 中序遍历(BiTree T);

//输出二叉树的前序遍历结果
void 前序遍历(BiTree T);

//输出二叉树的后序遍历结果
void 后序遍历(BiTree T);

//计算二叉树的深度
int 计算深度(BiTree T);

//统计二叉树的结点个数
int 结点个数统计(BiTree T);

//统计二叉树的叶节点个数
int 叶结点个数统计(BiTree T);
