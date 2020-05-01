#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;
#define elem_max_num 1000
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct
{
	string data;
	int cur;
}node1;
//创建备用链表
void reserveArr(node1 *array, int maxSize)
{
	for (int i = 1; i < maxSize - 1; i++)
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
void initArr(node1 *array, int maxSize)
{
	reserveArr(array, maxSize);
	array[0].cur = -1;
	int body = mallocArr(array);
	for (int i = 0; i < maxSize; i++)
	{
		array[i].data = "N/A";
	}
}


int main()
{
	node1 array1[elem_max_num];
	string buffer;
	int maxsize;
	cin >> maxsize;
	initArr(array1, maxsize);
	int num1;
	cin >> num1;
	while (num1 > 0)
	{
		cin >> buffer;
		num1--;
	}
	return 0;
}