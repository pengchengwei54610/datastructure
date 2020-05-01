#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define stackincrement 10
#define overflow 0
#define error 0
#define ok 1
typedef  bool Status;
//数据类型定义
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}sqstack;
sqstack s;
//栈的初始化操作,栈的容量已给出
Status InitStack(sqstack &s, int num)
{
	s.base = (char *)malloc(num * sizeof(char));
	if (!s.base)
		return overflow;
	s.top = s.base;
	s.stacksize = num;
	return ok;
}
//取栈顶元素
Status gettop(sqstack s, char &e)
{
	if (s.top == s.base)
		return error;
	e = *(s.top - 1);
	return ok;
}
//进栈操作
Status push_stack(sqstack &s, char e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (char *)realloc(s.base, (s.stacksize + stackincrement) * sizeof(char));
		if (!s.base)
			return overflow;
		s.top = s.base + s.stacksize;
		s.stacksize += stackincrement;
	}
	*s.top++ = e;
	return ok;
}
//退栈操作
Status pop_stack(sqstack &s, char &e)
{
	if (s.top == s.base)
		return error;
	e = *--s.top;
	return ok;
}
//遍历输出
void show_all(sqstack &s)
{
	char content;
	while (s.top != s.base)
	{
		pop_stack(s, content);
		cout << content << ' ';
	}
}
int main()
{
	sqstack *s = (sqstack *)malloc(sizeof(sqstack));
	string a;
	char content1[1000];
	char content2[1000];
	cin >> content1;
	int length = strlen(content1);
	InitStack(*s, length+1);
	while (cin >> content2)
	{

		//每次输入时将栈清空
		s->stacksize = 0;
		s->top = s->base;


		int length2= strlen(content2);
		if ( length2!= length)
		{
			cout << "no" << endl;
			continue;
		}
		char ak;
		int no1 = 1;
		int num2 = 1;
		while (num2 <= length+1)
		{
			if (no1 == length2 + 1)
				break;
			if (num2 == 1)
			{
				push_stack(*s, content1[num2 - 1]);
				num2++;
			}
			if (*(s->top - 1) == content2[no1 - 1])
			{
				pop_stack(*s, ak);
				no1++;
			}
			else
			{
				push_stack(*s, content1[num2 - 1]);
				num2++;
			}
		}
		if (no1!= length2 + 1)
			cout << "no" << endl;
		else
			cout << "yes" << endl;

	}
	return 0;
}