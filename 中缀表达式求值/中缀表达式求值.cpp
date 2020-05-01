#include<iostream>
using namespace std;
#define stack_init_size 100
#define stackincrement 10
#define overflow 0
#define error 0
#define ok 1
#define empty 1
#define n_empty 0
char a;
typedef bool Status;
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}numstack, *numstack1;
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}charstack, *charstack1;
//数字栈的初始化操作,栈的容量已给出
Status InitStack1(numstack &s)
{
	s.base = (int *)malloc(stack_init_size * sizeof(int));
	if (!s.base)
		return overflow;
	s.top = s.base;
	s.stacksize = stack_init_size;
	return ok;
}
//符号栈的初始化操作,栈的容量已给出
Status InitStack2(charstack &s)
{
	s.base = (char *)malloc(stack_init_size * sizeof(char));
	if (!s.base)
		return overflow;
	s.top = s.base;
	s.stacksize = stack_init_size;
	return ok;
}
//数字进栈操作
Status push_stack_num(numstack &s, int e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (int *)realloc(s.base, (s.stacksize + stackincrement) * sizeof(int));
		if (!s.base)
			return overflow;
		s.top = s.base + s.stacksize;
		s.stacksize += stackincrement;
	}
	*s.top++ = e;
	return ok;
}
//数字退栈操作
Status pop_stack_num(numstack &s, int &e)
{
	if (s.top == s.base)
		return error;
	e = *--s.top;
	return ok;
}
//数字栈判空操作
Status num_judge_empty(numstack &s)
{
	if (s.top == s.base)
		return empty;
	else
		return n_empty;
}
//符号进栈操作
Status push_stack_char(charstack &s, char e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (char *)realloc(s.base, (s.stacksize + stackincrement) * sizeof(int));
		if (!s.base)
			return overflow;
		s.top = s.base + s.stacksize;
		s.stacksize += stackincrement;
	}
	*s.top++ = e;
	return ok;
}
//符号退栈操作
Status pop_stack_char(charstack &s, char &e)
{
	if (s.top == s.base)
		return error;
	e = *--s.top;
	return ok;
}
//符号栈判空操作
Status char_judge_empty(charstack &s)
{
	if (s.top == s.base)
		return empty;
	else
		return n_empty;
}
//输入数字字符转为10进制数字
void convert(int &k, char e)
{
	k = k * 10 + (e - '0');
}
//输入判断是数字还是符号(1为符号，2为数字，3为非法字符)
int judge(charstack &s1, numstack &s2, char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '=')
	{
		return 1;
	}
	else if (a >= '0'&&a <= '9')
	{
		return 2;
	}
	else
		return 3;
}
int main()
{
	charstack *a1 = (charstack*)malloc(sizeof(charstack));
	numstack *b1 = (numstack*)malloc(sizeof(numstack));
	InitStack1(*b1);
	InitStack2(*a1);
	bool flag1 = 0;//1为数字，0为非数字
	bool flag2 = 1;
	int m = 0;
	int temp1, temp2, temp3;
	int result1 = 0;
	while (1)
	{
		int k;
		if (flag2 == 0)
		{
			while (char_judge_empty(*a1) == n_empty)
			{
				pop_stack_char(*a1, a);
				if (a == '+')
				{
					if (char_judge_empty(*a1) == empty)
					{
						pop_stack_num(*b1,temp1);
						pop_stack_num(*b1, temp2);
						temp1 += temp2;
						push_stack_num(*b1, temp1);
					}
					else
					{
						pop_stack_char(*a1, a);
						if (a == '+' || a == '-' || a == '(')
						{
							push_stack_char(*a1, a);
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							temp1 += temp2;
							push_stack_num(*b1, temp1);
						}
						else if (a == '*')
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							pop_stack_num(*b1, temp3);
							temp2 = temp3 * temp2;
							push_stack_num(*b1, temp2);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '+');
						}
						else
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							if (temp2 == 0)
							{
								cout << "ERROR";
								return 0;
							}
							pop_stack_num(*b1, temp3);

							temp3 = temp3 / temp2;
							push_stack_num(*b1, temp3);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '+');
						}
					}
				}
				else if (a == '-')
				{
					if (char_judge_empty(*a1) == empty)
					{
						pop_stack_num(*b1, temp1);
						pop_stack_num(*b1, temp2);
						temp2 -= temp1;
						push_stack_num(*b1, temp2);
					}
					
					else
					{
						pop_stack_char(*a1, a);
						if (a == '+' || a == '-' || a == '(')
						{
							push_stack_char(*a1, a);
							pop_stack_num(*b1, temp2);
							pop_stack_num(*b1, temp1);
							temp1 -= temp2;
							push_stack_num(*b1, temp1);
						}
						else if (a == '*')
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							pop_stack_num(*b1, temp3);
							temp2 = temp3 * temp2;
							push_stack_num(*b1, temp2);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '-');
						}
						else
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							if (temp2 == 0)
							{
								cout << "ERROR";
								return 0;
							}
							pop_stack_num(*b1, temp3);
							temp3 = temp3 / temp2;
							push_stack_num(*b1, temp3);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '-');
						}
					}
				}
				else if (a == '*')
				{
					pop_stack_num(*b1, temp2);
					pop_stack_num(*b1, temp1);
					temp1 *= temp2;
					push_stack_num(*b1, temp1);
				}
				else if (a == '/')
				{
					
					pop_stack_num(*b1, temp2);
					if (temp2 == 0)
					{
						cout << "ERROR";
						return 0;
					}
					pop_stack_num(*b1, temp1);
					temp1 /= temp2;
					push_stack_num(*b1, temp1);
				}
			}
			cout << *b1->base;
			return 0;
		}
		else if (flag2 == 1)
		{
			cin >> a;
			k = judge(*a1, *b1, a);
		}
		if (k == 1)
		{
			flag1 = 0;
			m = 0;
			if(flag2==1)
				push_stack_char(*a1, a);
			if (a == ')')
			{
				pop_stack_char(*a1, a);
				while (a != '(')
				{
					pop_stack_char(*a1, a);
					if (a == '*')
					{
						pop_stack_num(*b1, temp2);
						pop_stack_num(*b1, temp1);
						temp1 *= temp2;
						push_stack_num(*b1, temp1);
					}
					else if (a == '/')
					{
						pop_stack_num(*b1, temp1);
						if (temp1 == 0)
						{
							cout << "ERROR";
							return 0;
						}
						pop_stack_num(*b1, temp2);
						temp1 /= temp2;
						push_stack_num(*b1, temp1);
					}
					else if (a == '+')
					{
						pop_stack_char(*a1, a);
						if (a == '+' || a == '-' || a == '(')
						{
							push_stack_char(*a1, a);
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							temp1 += temp2;
							push_stack_num(*b1, temp1);
						}
						else if (a == '*')
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							pop_stack_num(*b1, temp3);
							temp2 = temp3 * temp2;
							push_stack_num(*b1, temp2);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '+');
						}
						else
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							if (temp2 == 0)
							{
								cout << "ERROR";
								return 0;
							}
							pop_stack_num(*b1, temp3);
							temp3 = temp3 / temp2;
							push_stack_num(*b1, temp3);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '+');
						}
					}
					else if (a == '-')
					{
						pop_stack_char(*a1, a);
						if (a == '+' || a == '-' || a == '(')
						{
							push_stack_char(*a1, a);
							pop_stack_num(*b1, temp2);
							pop_stack_num(*b1, temp1);
							temp1 -= temp2;
							push_stack_num(*b1, temp1);
						}
						else if (a == '*')
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							pop_stack_num(*b1, temp3);
							temp2 = temp3 * temp2;
							push_stack_num(*b1, temp2);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '-');
						}
						else
						{
							pop_stack_num(*b1, temp1);
							pop_stack_num(*b1, temp2);
							if (temp2 == 0)
							{
								cout << "ERROR";
								return 0;
							}
							pop_stack_num(*b1, temp3);
							temp3 = temp3 / temp2;
							push_stack_num(*b1, temp3);
							push_stack_num(*b1, temp1);
							push_stack_char(*a1, '-');
						}
					}
					/*else if (char_judge_empty(*a1) == empty)
					{

						pop_stack_char(*a1, a);
						if (a == '+')
						{
							pop_stack_char(*a1, a);
							if (a == '+' || a == '-' || a == '(')
							{
								push_stack_char(*a1, a);
								pop_stack_num(*b1, temp2);
								temp1 += temp2;
								push_stack_num(*b1, temp1);
							}
							else if (a == '*')
							{
								pop_stack_num(*b1, temp2);
								pop_stack_num(*b1, temp3);
								temp1 = temp3 * temp2 + temp1;
							}
							else
							{
								pop_stack_num(*b1, temp2);
								if (temp2 == 0)
								{
									cout << "ERROR";
									return 0;
								}
								pop_stack_num(*b1, temp3);
								temp1 = temp3 / temp2 + temp1;
							}
						}
						else if (a == '-')
						{
							pop_stack_char(*a1, a);
							if (a == '+' || a == '-' || a == '(')
							{
								push_stack_char(*a1, a);
								pop_stack_num(*b1, temp2);
								temp1 += temp2;
								push_stack_num(*b1, temp1);
							}
							else if (a == '*')
							{
								pop_stack_num(*b1, temp2);
								pop_stack_num(*b1, temp3);
								temp1 = temp3 * temp2 - temp1;
							}
							else
							{
								pop_stack_num(*b1, temp2);
								if (temp2 == 0)
								{
									cout << "ERROR";
									return 0;
								}
								pop_stack_num(*b1, temp3);
								temp1 = temp3 / temp2 - temp1;
							}
						}
						else if (a == '*')
						{
							pop_stack_num(*b1, temp2);
							temp1 *= temp2;
							push_stack_num(*b1, temp1);
						}
						else if (a == '/')
						{
							if (temp1 == 0)
							{
								cout << "ERROR";
								return 0;
							}
							pop_stack_num(*b1, temp2);
							temp1 /= temp2;
							push_stack_num(*b1, temp1);
						}
					}*/
				}
				if(a!='(')
					pop_stack_char(*a1, a);

			}
			else if (a=='+'||a == '-'|| a == '*'|| a == '/')
				;
			else if (a == '(')
				continue;
			else if (a == '=')
			{
				flag2 = 0;
				pop_stack_char(*a1, a);
				continue;
			}
			}
		
		else if (k == 2 && flag1 == 1 && flag2 == 1)
		{
			int e;
			pop_stack_num(*b1, e);
			e = e * 10 + a - '0';
			push_stack_num(*b1, e);
		}
		else if (k == 2 && flag1 == 0 && flag2 == 1)
		{
			push_stack_num(*b1, int(a - '0'));
			flag1 = 1;
		}
		else if (k == 3)
		{
			cout << "ERROR" << endl;
			return 0;
		}
	}
	return 0;
}