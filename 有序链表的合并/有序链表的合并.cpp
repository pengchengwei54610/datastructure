#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct data1
{
	int no;
	data1* next;
}data1,*linklist;
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
	while (j!=i)
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
int getelem_notless(linklist l,int e)
{
	linklist p;
	p = l->next;	
	int j = 0;
	if (!p)
		return j;	
	while (p&&(p->no<=e))
	{
		p = p->next;
		j++;
	}
	return j;
}
void create_list(linklist &l)
{
	int k;
	while(input_stu() != 0)
	{
		k=getelem_notless(l, buffer1.no);
		linkinsert(l, k, buffer1);
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
	create_list(l);
	create_list(l);
	show_all(l);
	return 0;
}