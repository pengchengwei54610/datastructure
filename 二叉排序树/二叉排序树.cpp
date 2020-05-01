#include<iostream>
#include<iomanip>
using namespace std;
typedef bool Status;
#define OK 1
#define ERROR 0

int length_sum=0;
int node_num = 0;
typedef struct
{
	int key;
}ElemType;
typedef  struct  BiTNode {
	ElemType  data;
	struct  BiTNode  *lchild, *rchild;
} BiTNode, *BiTree;

void Insert_BST(BiTree &T, BiTree S)
{
	BiTree  p, q;
	if (!T)
		T = S;
	else {
		p = T;
		q = p;
		while (p)
		{
			q = p;
			if (S->data.key < p->data.key)
				p = p->lchild;
			else p = p->rchild;
		}
		if (S->data.key < q->data.key)
			q->lchild = S;
		else q->rchild = S;
	}
	return;
}
void Creat_BST(BiTree &T)
{
	int x;
	BiTree S;
	T = NULL;
	int num1;
	cin >> num1;
	while (num1 > 0)
	{
		cin >> x;
		S = (BiTNode *)malloc(sizeof(BiTNode));
		S->data.key = x;
		S->lchild = NULL;
		S->rchild = NULL;
		Insert_BST(T, S);
		num1--;
	}	
	return;
}
//返回值0表示未找到，1表示找到，未找到时已将需查找的元素进行了插入
int  Searh_BST(BiTree &T, int key)
{
	BiTree  p, q, S;
	p = T;
	q = NULL;
	while (p)
	{
		if (p->data.key == key)
			return 1;
		else if (p->data.key > key)
		{
			q = p;
			p = p->lchild;
		}
		else
		{
			q = p;
			p = p->rchild;
		}
	}
	S = (BiTNode *)malloc(sizeof(BiTNode));
	S->data.key = key;
	S->lchild = S->rchild = NULL;
	if (!T)
		T = S;
	else  if (q->data.key > key)
		q->lchild = S;
	else q->rchild = S;
	return 0;
}

void delNode(BiTree &T, BiTree p, BiTree f)
{
	BiTree s, q;
	int tag;
	tag = 0;
	if (!p->lchild)
		s = p->rchild; //左孩子不存在
	else if (!p->rchild)
		s = p->lchild; //右孩子不存在
	else {
		q = p;
		s = p->lchild;
		while (s->rchild)//找到左子树最大结点
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q == p)
			q->lchild = s->lchild;
		else
			q->rchild = s->lchild;
		free(s);
		tag = 1;
	} //左右孩子都存在
	if (!tag)
	{
		if (!f)
			T = s;
		else if (f->lchild == p)
			f->lchild = s;
		else
			f->rchild = s;
		free(p);
		return;
	}
}


int Delete_BST(BiTree &T, int key)
{
	BiTree p, f;
	p = T;
	f = NULL;
	while (p)
	{
		if (p->data.key == key)
		{
			delNode(T, p, f);
			return 1;
		}
		else if (p->data.key > key)
		{
			f = p;
			p = p->lchild;
		}
		else
		{
			f = p;
			p = p->rchild;
		}
	}
	return 0;
}

void preordertraverse(BiTree t,int depth)
{
	if (t)
	{
		cout << t->data.key<<' ';
		length_sum += depth;
		node_num++;
		preordertraverse(t->lchild,depth+1);
		preordertraverse(t->rchild, depth + 1);
	}
}


int main()
{
	BiTree a1;
	Creat_BST(a1);
	int key1;
	cin >> key1;
	cout << Delete_BST(a1, key1)<<endl;
	cout << Searh_BST(a1, key1)<<endl;
	preordertraverse(a1,1);
	cout << endl;
	double ASL;
	ASL = double(length_sum) / node_num;
	cout<<setiosflags(ios::fixed) << setprecision(2) << ASL;
	return 0;
}