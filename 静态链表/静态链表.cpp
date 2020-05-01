#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;
#define elem_max_num 200
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct {
	string data;
	int cur;
}node1;
//创建备用链表
void reserveArr(node1 *array,int maxSize) 
{
	for (int i = 1; i < maxSize-1; i++) 
	{
		array[i].cur = i + 1;//将每个数组分量链接到一起
	}
	array[maxSize - 1].cur = -1;//链表最后一个结点的游标值为-1
}
//提取分配空间,若备用链表非空，则返回分配的结点下标，否则返回-1（当分配最后一个结点时，该结点的游标值为-1）
int mallocArr(node1 * array) 
{	
	return array[1].cur;
}
//初始化静态链表
void initArr(node1 *array,int maxSize)
{
	reserveArr(array,maxSize);
	array[0].cur = -1;
	int body = mallocArr(array);
	for (int i = 0; i <maxSize; i++) 
	{
		array[i].data = "N/A";
	}
}
//向链表中指定位置插入数据，add表示插入元素的位置，a表示要插入的数据
Status insertArr(node1 * array, int add, string a)
{
	int tempBody= 0;
	int insert = mallocArr(array);
	if (insert == -1)
	{
		cout << "FULL" << endl;
		return ERROR;
	}
	if (array[0].cur == -1)
	{
		if (add > 0)
		{
			cout << "-1" << endl;
			return ERROR;
		}
		array[0].cur = array[1].cur;
		array[1].cur = array[array[1].cur].cur;
		array[array[0].cur].data = a;
		array[array[0].cur].cur = -1;
	}
	else
	{
		for (int i = 1; i < add; i++)
		{
			tempBody = array[tempBody].cur;
			if (array[tempBody].cur == -1)
			{
				cout << "-1" << endl;
				return ERROR;
			}
		}
	}	
	array[1].cur= array[insert].cur;
	array[insert].cur = array[tempBody].cur;
	array[insert].data = a;
	array[tempBody].cur = insert;
	return OK;
}
//向链表表尾插入数据，a表示要插入的数据
Status insertArr_tail(node1 * array, string a)
{
	if (array[1].cur == -1)
	{
		cout << "FULL"<<endl;
		return ERROR;
	}
	int temp1=array[0].cur;
	int temp2;
	if (temp1 == -1)
	{
		temp2 = array[1].cur;
		array[0].cur = array[1].cur;
		array[array[1].cur].data = a;
		array[1].cur = array[array[1].cur].cur;
		array[temp2].cur = -1;
	}
	else
	{
		temp2 = array[1].cur;
		while (array[temp1].cur != -1)
		{
			temp1 = array[temp1].cur;
		}
		array[array[1].cur].data = a;
		array[temp1].cur = array[1].cur;
		array[1].cur = array[array[1].cur].cur;
		array[temp2].cur = -1;
	}
	return OK;
}
//查找数据域为elem的结点在数组中的位置
int selectElem(node1 * array, string elem) 
{
	int tempBody =array[0].cur;
	//当游标值为0时，表示链表结束
	while (array[tempBody].cur != -1) 
	{
		if (array[tempBody].data == elem) {
			return tempBody;
		}
		tempBody = array[tempBody].cur;
	}
	return -1;//返回-1，表示在链表中没有找到该元素
}
// 查找数据域为elem的结点在元素中的位置
int selectElem1(node1 * array, string elem)
{
	int count1 = 1;
	int tempBody = array[0].cur;
	if (tempBody == -1)
		return -1;
	//当游标值为0时，表示链表结束
	while (array[tempBody].cur != -1)
	{
		if (array[tempBody].data == elem)
		{
			return count1;
		}
		count1++;
		tempBody = array[tempBody].cur;
	}
	if (array[tempBody].data == elem)
	{
		return count1;
	}
	return -1;//返回-1，表示在链表中没有找到该元素
}
//删除结点函数，body表示第几个元素
Status deletArr_pos(node1 * array, int body,string &k) 
{
	if (array[0].cur == -1)
	{
		cout << "EMPTY" << endl;
		return ERROR;
	}
	if (body <= 0)
	{
		cout << "-1" << endl;
		return ERROR;
	}
	int count1 = 1;
	int tempBody =0;
	int temp2;
	while (count1 <= body)
	{
		if (array[tempBody].cur == -1)
		{
			cout << "-1" << endl;
			return ERROR;
		}
		temp2 = tempBody;
		tempBody = array[tempBody].cur;
		count1++;
	}
	//将被删除结点的游标直接给被删除结点的上一个结点
	array[temp2].cur = array[tempBody].cur;
	k = array[tempBody].data;
	array[tempBody].data = "N/A";
	array[tempBody].cur = array[1].cur;
	array[1].cur = tempBody;
	return OK;
}
//遍历输出静态链表
void displayArr(node1 * array) {
	int tempBody=array[0].cur;//tempBody准备做遍历使用
	while (array[tempBody].cur!=-1) 
	{
		cout << array[tempBody].data << ' ';
		tempBody = array[tempBody].cur;
	}
	cout << array[tempBody].data << ' ';
}
//遍历输出内存情况
void displaymem(node1 * array,int num)
{
	int count1 = 0;
	while (count1<num)
	{
		cout << count1 << " : " << array[count1].data << " : " << array[count1].cur << "\t\t";
		count1++;
		if (count1 % 3 == 0)
			cout << endl;
	}
	if (count1 % 3 != 0)
		cout << endl;
}

int main() 
{
	int temp1,i,j;
	string buffer2;
	node1 array[elem_max_num];
	string buffer;
	int maxsize;
	cin >> maxsize;
	initArr(array,maxsize);
	int num1;
	cin >> num1;
	temp1 =1;
	/*if (temp1 > maxsize - 2)
		temp1 = maxsize - 2;*/
	while (temp1 <= num1&&temp1 <=maxsize-2)
	{
		cin >> buffer;
		insertArr_tail(array, buffer);
		temp1++;
	}
	while (temp1 <= num1&&temp1 <= maxsize)
	{
		cin >> buffer;
		temp1++;
	}
	displaymem(array, maxsize);
	cin >> i >> buffer;
	if (insertArr(array, i, buffer) == ERROR)
		;
	else
	{
		displayArr(array);
		cout << endl;
	}
	cin >> j;
	if (deletArr_pos(array, j,buffer2)==ERROR)
		;
	else
	{
		cout << buffer2<<endl;
	}
	cin >> buffer;
	cout<<selectElem1(array, buffer)<<endl;
	cin >> buffer;
	if(insertArr_tail(array, buffer)==ERROR)
		;
	else
	{
		displayArr(array);
		cout << endl;
	}
	displaymem(array, maxsize);
	return 0;
}

/*
2 2
Jan Feb
1 Jun
7
May
Oct

9 5
Jan Feb Mar Apr May
7 Jun
1
Mar
Oct

9 0
7 Jun
1
Mar
Oct

9 2
Mar jam
7 Jun
1
jam
Oct

10 2
Mar jam
7 Jun
1
jam
Oct
*/