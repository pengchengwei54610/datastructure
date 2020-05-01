#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct data1
{
	int no;
	data1* next;
}data1, *linklist;
data1 buffer1;
typedef data1 ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}Sqlist;
ElemType a;
//输入元素
int input_stu()
{
	cin >> buffer1.no;
	return buffer1.no;
}
//在第i个元素后插入元素
Status linkinsert(linklist &l, int i, ElemType e)
{

	linklist p, s;
	p = l;
	int j = 0;
	while (j != i)
	{
		p = p->next;
		++j;
	}
	s = (linklist)malloc(sizeof(data1));
	s->no = e.no;
	s->next = p->next;
	p->next = s;
	return OK;
}
//找出不比当前元素大的最大元素序号
int getelem_notless(linklist l, int e)
{
	linklist p;
	p = l->next;
	int j = 0;
	if (!p)
		return j;
	while (p && (p->no <= e))
	{
		p = p->next;
		j++;
	}
	return j;
}
//以0结束建立链表
void create_list(linklist &l)
{
	int k;
	while (input_stu() != 0)
	{
		k = getelem_notless(l, buffer1.no);
		linkinsert(l, k, buffer1);
	}
}
//以确定的元素个数建立链表
void create_list_num(linklist &l, int a)
{
	int k = 0;
	while (a != 0)
	{
		input_stu();
		linkinsert(l, k, buffer1);
		k++;
		a--;
	}
}
//头插法建立链表(确定的元素个数
void create_list_headinsert(linklist &l, int a)
{
	int k = 0;
	while (a != 0)
	{
		input_stu();
		linkinsert(l, 0, buffer1);
		a--;
	}
}
void Duplicate_removal_1(linklist &l, int a)
{
	linklist p, k, j;
	p = l->next;
	while (p)
	{
		k = p;
		while (k->next)
		{
			if (k->next->no == p->no&&k->next != p)
			{
				j = k->next;
				k->next = k->next->next;
				delete(j);
			}
			else
				k = k->next;
		}
		p = p->next;
	}
}
void list_inversion(linklist &l)
{
	linklist p, q;
	p = l->next;
	l->next = NULL;
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		q->next = l->next;
		l->next = q;
	}
}
void third_removal(linklist &l)
{
	linklist p,j;
	p = l;
	while (p->next)
	{
		if (p->next->no % 3 != 0)
		{
			j = p->next;
			p->next = p->next->next;
			free(j);
		}
		else
			p = p->next;
	}
}
void show_all(linklist &l)
{
	linklist p;
	p = l->next;
	while (p)
	{
		cout << p->no << ' ';
		p = p->next;
	}
}
int main()
{
	linklist l;
	l = (linklist)malloc(sizeof(data1));
	l->next = NULL;
	int num;
	cin >> num;
	create_list_headinsert(l, num);
	show_all(l);
	cout << endl;
	list_inversion(l);
	third_removal(l);
	show_all(l);
	return 0;
}