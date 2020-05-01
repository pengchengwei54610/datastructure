#include<iostream>
using namespace std;
typedef bool Status;
typedef char telemtype;
#define ok 1
#define error 0
#define overflow 0


typedef struct bitnode
{
	telemtype data;
	struct bitnode *lchild, *rchild;
}bitnode, *bitree;
typedef bitnode* elemtype;
typedef struct QNode
{
	bitnode data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
	int num;
}linkqueue;

//链队列初始化
Status initqueue(linkqueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front)
		return overflow;
	q.front->next = NULL;
	q.num = 0;
	return ok;
}

//链队列的销毁
Status destroyqueue(linkqueue &q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	q.num = 0;
	return ok;
}

//链队列的插入
Status enqueue(linkqueue &q, bitnode e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return overflow;
	p->data.data = e.data;
	p->data.lchild = e.lchild;
	p->data.rchild = e.rchild;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.num++;
	return ok;
}

//链队列的删除
Status dequeue(linkqueue &q, bitnode &e)
{
	QueuePtr p;
	if (q.front == q.rear)
		return error;
	p = q.front->next;
	e.data = p->data.data;
	e.lchild = p->data.lchild;
	e.rchild = p->data.rchild;
	q.front->next = p->next;
	if (q.rear == p)
		q.rear = q.front;
	free(p);
	q.num--;
	return ok;
}

//判断链队列是否为空
Status queueempty(linkqueue q)
{
	if (q.front == q.rear)
		return true;
	else
		return false;
}







//先序建立二叉树
Status createbitree(bitree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		if (!(t = (bitnode*)malloc(sizeof(bitnode))))
			return overflow;
		t->data = ch;
		createbitree(t->lchild);
		createbitree(t->rchild);
	}
	return ok;
}
//先序遍历二叉树
void preordertraverse(bitree t)
{
	if (t)
	{
		cout << t->data;
		preordertraverse(t->lchild);
		preordertraverse(t->rchild);
	}
}
//中序遍历二叉树
void inordertraverse(bitree t)
{
	if (t)
	{
		inordertraverse(t->lchild);
		cout << t->data;		
		inordertraverse(t->rchild);
	}
}
//后序遍历二叉树
void postordertraverse(bitree t)
{
	if (t)
	{
		postordertraverse(t->lchild);		
		postordertraverse(t->rchild);
		cout << t->data;
	}
}
//层次遍历二叉树（队列）
void levelordertraverse(bitree t)
{
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);
	bitnode a;
	if (t == NULL)
	{
		return;
	}
	enqueue(*q, *t);
	while (queueempty(*q)==error)
	{
		dequeue(*q,a);
		t = &a;
		cout << a.data;
		if (t->lchild != NULL)
		{
			enqueue(*q, *t->lchild);
		}
		if (t->rchild != NULL)
		{
			enqueue(*q, *t->rchild);
		}
	}

}
//树形输出二叉树（队列）（有错）
void treeordertraverse(bitree t)
{
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);
	bitnode b;
	b.data = NULL;
	b.lchild = NULL;
	b.rchild = NULL;
	bitnode a;
	if (t == NULL)
	{
		return;
	}
	enqueue(*q, *t);
	while (queueempty(*q) == error)
	{
		dequeue(*q, a);
		t = &a;
		if (t == NULL)
			cout << ' ';
		else
			cout << a.data;
		if (t!=NULL&&t->lchild != NULL)
		{
			enqueue(*q, *t->lchild);
		}
		else if(t != NULL && t->lchild == NULL)
		{
			enqueue(*q, b);
		}
		if (t != NULL && t->rchild != NULL)
		{
			enqueue(*q, *t->rchild);
		}
		else if (t != NULL && t->rchild == NULL)
		{
			enqueue(*q, b);
		}
	}

}
void PrintBiTree(bitree T, int n)
{
	int i;  
	char ch = ' ';
	if (T) {
		PrintBiTree(T->rchild, n + 1);
		for (i = 1; i <= n; ++i)
		{ 
			cout << "     ";
		}
		printf("%c\n", T->data);
		PrintBiTree(T->lchild, n + 1);
	}
}

int main()
{
	bitree t;
	t = (bitree)malloc(sizeof(bitnode));
	createbitree(t);
	preordertraverse(t);
	cout << endl;
	inordertraverse(t);
	cout << endl;
	postordertraverse(t);
	cout << endl;
	levelordertraverse(t);
	cout << endl;
//	treeordertraverse(t);
	PrintBiTree(t,0);
	cout << endl;
	return 0;
}
//abc##d##ef###