#include<iostream>
using namespace std;
typedef struct
{
	int key;
}ElemType;
typedef struct
{
	ElemType* r;
	int num;
}HeapType;
int input_elem(HeapType &elem)
{
	int count1;
	for (count1 = 1; count1 <= elem.num; count1++)
	{
		cin >> elem.r[count1].key;
	}
	return elem.num;
}
void output_elem_sp(HeapType elem, int num)
{
	int count1 = elem.num;
	for (; count1 >elem.num-num; count1--)
	{
		cout << elem.r[count1].key << ' ';
	}
	cout << endl;
}
int LT(int a, int b)
{
	if (a < b)
		return 1;
	else
		return 0;
}
void HeapAdjust(HeapType &H, int s, int m)
{
	ElemType rc = H.r[s];
	for (int j = 2 * s; j <= m; j *= 2)
	{
		if ((j < m) && (LT(H.r[j].key, H.r[j + 1].key))) ++j;
		if (!(LT(rc.key, H.r[j].key))) break;
		H.r[s].key = H.r[j].key;  s = j;
	}
	H.r[s] = rc;
}
void HeapSort(HeapType &H)
{
	ElemType temp;
	for (int i = H.num / 2; i > 0; --i)
		HeapAdjust(H, i, H.num);
	for (int i = H.num; i > 1; --i)
	{
		temp = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = temp;
		HeapAdjust(H, 1, i - 1);
	}
}

int main()
{
	int num;
	HeapType a;
	cin >> a.num>>num;
	a.r = (ElemType*)malloc(sizeof(ElemType)*(a.num + 1));
	input_elem(a);
	HeapSort(a);
	output_elem_sp(a,num);
	return 0;
}
/*
6
23 46 0 8 11 18
13
81 68 33 40 89 72 75 21 75 3 63 15 54
*/