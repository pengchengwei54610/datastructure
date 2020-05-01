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
//计算元素个数
int linklength(linklist l)
{
	int j = 0;
	linklist p;
	p = l->next;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}
//查找（按值查找）
int locate_elem(linklist &l, int i)
{
	int j = 1;
	linklist p;
	p = l->next;
	while (p != NULL && p->no != i)
	{
		p = p->next;
		j++;;
	}
	if (p == NULL)
		return -1;
	else
		return j;
}
//返回第i个元素前一个结点地址
linklist locate_el(linklist &l, int i)
{
	linklist p = l;
	while (i != 1)
	{
		p = p->next;
		i--;
	}
	return p;
}
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
//在第i个元素前插入元素
Status linkinsert_before(linklist &l, int i, ElemType e)
{
	if (linklength(l) < i||i==0)
		return ERROR;
	linklist p, s;
	p=locate_el(l, i);
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
//头插法建立链表(确定的元素个数)
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
//去重算法
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
//链表逆置
void list_inversion(linklist &l)
{
	linklist p, q;
	p = l->next;
	l->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = l->next;
		l->next = q;
	}
}
//保留元素中3的倍数
void third_removal(linklist &l)
{
	linklist p, j;
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
//删除第i个元素
Status delete_elem(linklist &l, int i)
{
	if (i == 0||linklength(l) < i)
		return ERROR;
	linklist p, s;
	p=locate_el(l, i);
	s = p->next;
	p->next = s->next;
	delete(s);
	return OK;
}
//遍历显示所有元素
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
//链表的摧毁
int Destory_List(linklist* L) {
	linklist q, p = *L; //指向首元

	/* 整个链表(含头结点)依次释放 */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		free(p);
		p = q;
	}

	*L = NULL;    //头指针置NULL
	return OK;
}
int main()
{
	linklist l;
	l = (linklist)malloc(sizeof(data1));
	l->next = NULL;
	int num;
	int pos;
	cout << "请输入创建的单链表元素个数"<<endl;
	cin >> num;
	cout << "请依次输入各元素，以空格分隔(头插法）" << endl;
	create_list_headinsert(l, num);
	cout << "下为链表内元素" << endl;
	show_all(l);
	cout << endl;
	cout << "请输入插入位置及元素" << endl;
	cin >> pos >> buffer1.no;
	if (linkinsert_before(l, pos, buffer1) == ERROR)
		cout << "插入位置非法";
	else
	{
		cout << "下为链表内元素" << endl;
		show_all(l);
	}
	cout << endl;
	cout << "请输入删除元素位置" << endl;
	cin >> pos;
	if (delete_elem(l, pos) == ERROR)
	{
		cout << "删除位置非法";
	}
	else
	{
		cout << "下为链表内元素" << endl;
		show_all(l);
	}
	cout << endl;
	int numb;
	cout << "请输入查找元素" << endl;
	cin >> numb;
	int temp;
	if ((temp=locate_elem(l, numb) )>= 1)
	{
		cout << "查找元素位置为" << endl;
		cout << temp << endl;
	}
	else
		cout << "未找到该元素" << endl;;
	cout << "链表长度为" << endl;
	cout << linklength(l);
	return 0;
}