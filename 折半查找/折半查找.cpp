#include<iostream>
using namespace std;
typedef bool Status;
#define OK 1
#define ERROR 0

typedef int KeyType;
typedef int ElemType;
typedef struct {
	ElemType  *elem;
	int length;
} SSTable;


Status initial_table(SSTable &a)
{
	int num1;
	int count1 = 1;
	cin >> num1;
	a.elem = (ElemType *)malloc(sizeof(ElemType)*(num1 + 1));
	if (a.elem == NULL)
		return ERROR;
	a.length = num1;
	while (count1 <= num1)
	{
		cin >> a.elem[count1];
		count1++;
	}
	return OK;
}

int EQ(int a, int b)
{
	if (a == b)
		return 1;
	else
		return 0;
}
int LT(int a, int b)
{
	if (a <= b)
		return 1;
	else
		return 0;
}
int Search_Bin(SSTable ST, KeyType key)
//ÕÛ°ë²éÕÒ 
{
	bool tag = 0;
	int low, high, mid,temp1;
	low = 1; high = ST.length;
	while (low <= high)
	{
		if (tag == 1 && low == high)
		{
			break;
		}
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid]))
		{
			tag = 1;
			temp1 = mid;
			high = mid;
		}
		else if (LT(key, ST.elem[mid]))
			high = mid - 1;
		else low = mid + 1;
	}
	if (tag == 0)
		return 0;
	else
		return temp1;
}


int main()
{
	int num2;
	int key;
	SSTable a1;
	initial_table(a1);
	cin >> num2;
	while (num2 != 0)
	{
		cin >> key;
		cout<<(Search_Bin(a1, key)-1);
		num2--;
		cout << endl;
	}
	return 0;
}

/*
10
1 2 2 3 3 4 5 5 5 5
1
5
*/