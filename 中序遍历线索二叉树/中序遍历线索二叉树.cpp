//Paste your code here
//NOTE: If you use java, your Main class must be named solution
//Paste your code here
//NOTE: If you use java, your Main class must be named solution
#include<iostream>
using namespace std;
typedef bool Status;
typedef char telemtype;
#define ok 1
#define error 0
#define overflow 0
bool tag1 = false;
typedef enum { Link, Thread }PointerTag;
//Link==0：指针，指向孩子结点
//Thread==1：线索，指向前驱或后继结点
typedef struct bithrnode {
	char data;
	struct bithrnode *lchild, *rchild;
	PointerTag LTag, RTag;
}bithrnode, *bithrtree;
bithrtree T;
bithrnode *pre = NULL;

//遍历先序线索二叉树（不带头结点）
void preorder_Thr(bithrtree T)
{
	bithrtree p = T;
	cout << p->data;
	while (p->rchild)
	{
		if (p->LTag == Link)
			p = p->lchild;
		else
			p = p->rchild;
		cout << p->data;
	}
}

//遍历中序线索二叉树（不带头结点）
void inorder1_Thr(bithrtree T)
{
	bithrtree p = T;
	while (p->LTag == Link)
		p = p->lchild;
	printf("%c", p->data);
	while (p->rchild)
	{
		if (p->RTag == Link)
		{
			p = p->rchild;
			while (p->LTag == Link) p = p->lchild;
		}
		else p = p->rchild;
		printf("%c", p->data);
	}
}


//先序建立二叉树
Status createbithrtree(bithrtree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		if (!(t = (bithrnode*)malloc(sizeof(bithrnode))))
			return overflow;
		t->data = ch;
		t->LTag = Link;
		t->RTag = Link;
		createbithrtree(t->lchild);
		createbithrtree(t->rchild);
	}
	return ok;
}

//先序线索化
void PreThreading(bithrtree P)
{
	if (P)
	{
		if (!P->lchild)
		{
			P->LTag = Thread;
			P->lchild = pre;
		}
		if (!P->rchild)
			P->RTag = Thread;
		if (pre && pre->RTag == Thread)
			pre->rchild = P;
		pre = P;
		if (P->LTag == Link)
			PreThreading(P->lchild);
		if (P->RTag == Link)
			PreThreading(P->rchild);
	}
}

//中序线索化
void InThreading(bithrtree P)
{
	if (P)
	{
		InThreading(P->lchild);
		if (!P->lchild)
		{
			P->LTag = Thread;
			P->lchild = pre;
		}
		if (pre && !pre->rchild) pre->RTag = Thread;
		if (pre && pre->RTag == Thread) pre->rchild = P;
		pre = P;
		InThreading(P->rchild);
	}
}

//查找结点字符的前驱和后继结点元素
void searchbithrtree(bithrtree T, char k)
{
	bithrtree a;
	bithrtree p = T;
	while (p->LTag == Link)
		p = p->lchild;
	if (p->data == k)
	{
		tag1 = true;
		cout << "succ is ";
		if (p->rchild == NULL)
			cout << "NULL" << endl;
		else if (p->RTag == 1)
			cout << p->rchild->data << p->rchild->RTag << endl;
		else
		{
			a = p;
			a = a->rchild;
			while (a->LTag == 0)
				a = a->lchild;
			cout << a->data << a->RTag << endl;
		}
		cout << "prev is ";
		if (p->lchild == NULL)
			cout << "NULL" << endl;
		else if (p->LTag == 1)
			cout << p->lchild->data << p->lchild->LTag << endl;
		else
		{
			a = p;
			a = a->lchild;
			while (a->RTag == 0)
				a = a->rchild;

			cout << a->data << a->LTag << endl;
		}
		return;
	}
	while (p->rchild)
	{
		if (p->RTag == Link)
		{
			p = p->rchild;
			///


			if (p->data == k)
			{
				tag1 = true;
				cout << "succ is ";
				if (p->rchild == NULL)
					cout << "NULL" << endl;
				else if (p->RTag == 1)
					cout << p->rchild->data << p->rchild->RTag << endl;
				else
				{
					a = p;
					a = a->rchild;
					while (a->LTag == 0)
						a = a->lchild;
					cout << a->data << a->RTag << endl;
				}
				cout << "prev is ";
				if (p->lchild == NULL)
					cout << "NULL" << endl;
				else if (p->LTag == 1)
					cout << p->lchild->data << p->lchild->LTag << endl;
				else
				{
					a = p;
					a = a->lchild;
					while (a->RTag == 0)
						a = a->rchild;

					cout << a->data << a->LTag << endl;
				}
				return;
			}


			///
			while (p->LTag == Link)
			{
				p = p->lchild;
				///


				if (p->data == k)
				{
					tag1 = true;
					cout << "succ is ";
					if (p->rchild == NULL)
						cout << "NULL" << endl;
					else if (p->RTag == 1)
						cout << p->rchild->data << p->rchild->RTag << endl;
					else
					{
						a = p;
						a = a->rchild;
						while (a->LTag == 0)
							a = a->lchild;
						cout << a->data << a->RTag << endl;
					}
					cout << "prev is ";
					if (p->lchild == NULL)
						cout << "NULL" << endl;
					else if (p->LTag == 1)
						cout << p->lchild->data << p->lchild->LTag << endl;
					else
					{
						a = p;
						a = a->lchild;
						while (a->RTag == 0)
							a = a->rchild;

						cout << a->data << a->LTag << endl;
					}
					return;
				}

				///
			}
		}
		else
		{
			p = p->rchild;
			///


			if (p->data == k)
			{
				tag1 = true;
				cout << "succ is ";
				if (p->rchild == NULL)
					cout << "NULL" << endl;
				else if (p->RTag == 1)
					cout << p->rchild->data << p->rchild->RTag << endl;
				else
				{
					a = p;
					a = a->rchild;
					while (a->LTag == 0)
						a = a->lchild;
					cout << a->data << a->RTag << endl;
				}
				cout << "prev is ";
				if (p->lchild == NULL)
					cout << "NULL" << endl;
				else if (p->LTag == 1)
					cout << p->lchild->data << p->lchild->LTag << endl;
				else
				{
					a = p;
					a = a->lchild;
					while (a->RTag == 0)
						a = a->rchild;

					cout << a->data << a->LTag << endl;
				}
				return;
			}

			////
		}
	}
}


//树形打印线索二叉树
void PrintBithrTree(bithrtree T, int n)
{
	int i;
	char ch = ' ';
	if (T) {
		if (T->RTag == Link)
			PrintBithrTree(T->rchild, n + 1);
		for (i = 1; i <= n; ++i)
		{
			cout << "     ";
		}
		cout << T->data << T->LTag << T->RTag << endl;
		if (T->LTag == Link)
			PrintBithrTree(T->lchild, n + 1);
	}
}
int main()
{
	bithrtree t;
	t = (bithrtree)malloc(sizeof(bithrnode));
	createbithrtree(t);
	InThreading(t);
	char k;
	inorder1_Thr(t);
	cout << endl;
	cin >> k;
	searchbithrtree(t, k);
	if (tag1 == false)
		cout << "Not found" << endl;
	return 0;
}
//abc##d##ef###
//abd##eg#j###c#fh#kl###i##
//ab#c#de###fg##hik##j###
//a#b#c#d##
//abcd#####
//abc##def##hj##kl#####
//abc##de#g##f###