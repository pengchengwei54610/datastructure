#include<iostream>
#include<string>
using namespace std;
#define queue_initial_num 1000
typedef bool Status;
typedef int QElemType;//元素数据类型
#define ok 1
#define error 0
#define overflow 0
typedef struct DATA
{
	QElemType requests_num;
}DATA, *DATAPtr;
typedef struct
{
	DATA *e;
	int S;//当前元素个数
	int MAXS;//最大能存储元素个数
	int head;//队头
	int tail;//队尾
}queue;

//顺序队列初始化
Status initqueue(queue &q)
{
	 q.e = (DATAPtr)malloc(queue_initial_num*sizeof(DATA));
	if (!q.e)
		return overflow;
	q.head = 0;
	q.tail = 0;
	q.MAXS = queue_initial_num;
	q.S = 0;
	return ok;
}

//顺序队列的销毁
Status destroyqueue(queue &q)
{
	free(q.e);
	q.head= 0;
	q.tail = 0;
	q.MAXS = 0;
	q.S = 0;
	return ok;
}

//顺序队列清空
Status clearqueue(queue &q)
{
	q.S = 0;
	q.tail = 0;
	q.head = 0;
	return 0;
}

//顺序队列的插入
Status enqueue(queue &q, DATA e)
{
	if (q.MAXS == q.S)
		return error;
	q.S++;
	q.e[q.tail].requests_num = e.requests_num;
	if (q.tail != q.MAXS-1)
	{		
		q.tail++;
	}
	else
	{
		q.tail = 0;
	}
	return ok;
}

//顺序队列的元素出队
Status dequeue(queue &q, DATA &e)
{
	if (q.S == 0)
		return error;
	q.S--;
	e.requests_num = q.e[q.head].requests_num;
	if (q.head != q.MAXS-1)
	{
		q.head++;
	}
	else
	{
		q.head = 0;
	}
	return ok;
}

//判断顺序队列是否为空（空为true，非空为false）
Status queueempty(queue q)
{
	if (q.S==0)
		return true;
	else
		return false;
}

//返回队列内元素个数
int elem_num(queue q)
{
	return q.S;
}

//取顺序队列第一个元素结点
Status gethead(queue q, DATA &e)
{
	if (queueempty(q))
		return error;
	e.requests_num = q.e[q.head].requests_num;
	return ok;
}

//遍历输出队列中所有元素
Status show_all(queue q)
{
	if (q.S == 0)
	{
		cout << "no elem in the queue" << endl;
		return 0;
	}
	int k=q.head;
	while (k != q.tail)
	{		
		cout << q.e[k].requests_num << ' ';
		if (k == q.MAXS - 1)
			k = 0;
		else
			k++;
	}
	cout << endl;
	return ok;
}

int main()
{
	DATA temp;
	queue *q = (queue *)malloc(sizeof(queue));
	initqueue(*q);
	string a;
	while (1)
	{
		cin >> a;
		if (a == "dequeue")
			if (dequeue(*q, temp))
				cout << temp.requests_num << endl;
			else
				cout << "Queue is Empty" << endl;
		else if (a == "enqueue")
		{
			cin >> temp.requests_num;
			enqueue(*q, temp);
		}
		else if (a == "whether_empty")
		{
			if (queueempty(*q) == true)
				cout << "queue is empty" << endl;
			else
				cout << "queue is not empty" << endl;
		}
		else if (a == "count_elem")
		{
			cout << elem_num(*q) << endl;
		}
		else if (a == "show_queue")
		{
			show_all(*q);
		}
		else if (a == "clear_queue")
		{
			clearqueue(*q);
			show_all(*q);
		}
		else if (a == "quit")
		{
			break;
		}		
	}	
	destroyqueue(*q);
	return 0;
}