#include<iostream>
#include<cstring>
using namespace std;
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2
typedef int Status;
struct data1
{
	string month;
	int cur;
};
typedef struct
{
	struct data1 *elem;
}sllist;
//表初始化
Status InitList(sllist &l, int num)
{
	l.elem = (data1 *)malloc((num+2) * sizeof(data1));
	if (!l.elem)return(OVERFLOW);
	l.elem[0].cur = -1;
	l.elem[1].cur = 2;
	for (int i = 2; i <= num + 1; i++)
		l.elem[i].cur = i + 1;
}
//尾部追加元素
Status AddElem(sllist &l,string a)
{
	int num;
	num = l.elem[1].cur;
	if (l.elem[num-1].cur==-1)
		return ERROR;
	else
	{
//		l.elem[num].cur = -1;
		l.elem[num].month = a;
		l.elem[1].cur = l.elem[num].cur;
		l.elem[num].cur = -1;
		l.elem[1].cur++;
	}
	return OK;
}
//第i个元素位置前插入一个新的元素
Status InsertElem(sllist &l,int i, string a)
{
	int num;
	num = l.elem[1].cur;
	if (l.elem[num - 1].cur == -1)
		return ERROR;
	else
	{
		int k;
		for (k = num; k > i+1; k--)
			l.elem[k].month=l.elem[k-1].month;
		l.elem[k].month = a;
		l.elem[1].cur++;
	}
	return OK;
}
//删除第i个元素
//查找某元素
//判表空
//判表满
//表的遍历

int main()
{
	int m, n;
	cin >> m >> n;//m表示数组的容量,n表示首次追加到表中的元素个数
	return 0;
}