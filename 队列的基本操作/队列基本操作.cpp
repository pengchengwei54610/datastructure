#include<iostream>
#include<string>
using namespace std;
typedef bool Status;
typedef int QElemType;//元素数据类型
#define ok 1
#define error 0
#define overflow 0
typedef struct QNode
{
	QElemType data;
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
Status enqueue(linkqueue &q, QElemType e,int queue_max_length)
{
	QueuePtr p;
	if (queue_max_length == q.num)
		return error;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return overflow;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.num++;
	return ok;
}

//链队列的删除
Status dequeue(linkqueue &q, QElemType &e)
{
	QueuePtr p;
	if (q.front == q.rear)
		return error;
	p = q.front->next;
	e = p->data;
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


//取链队列第一个元素结点
Status gethead(linkqueue q, QElemType &e)
{
	if (queueempty(q))
		return error;
	e = q.front->next->data;
	return ok;
}

//遍历输出队列中所有元素
Status show_all(linkqueue q)
{
	QueuePtr k = q.front->next;
	while (k != NULL)
	{
		cout << k->data << ' ';
		k = k->next;
	}
	return ok;
}

int main()
{
	int queue_length;
	QElemType temp;
	string a;
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);
	cin >> queue_length;
	while (1)
	{
		cin >> a;
		if (a == "dequeue")
			if (dequeue(*q,temp))
				cout << temp << endl;
			else
				cout << "Queue is Empty" << endl;
		else if (a == "enqueue")
		{
			cin >> temp;
			if (enqueue(*q,temp,queue_length))
				;
			else
				cout << "Queue is Full" << endl;
		}
		else if (a == "quit")
		{
			show_all(*q);
			break;
		}
	}
	return 0;
}