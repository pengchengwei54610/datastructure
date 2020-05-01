//#include<iostream>
//using namespace std;
//typedef struct
//{
//	int key;
//}node;
//typedef struct
//{
//	node* r;
//	int length;
//}SqList;
//int input_elem(SqList &elem1, int num)
//{
//	int count1;
//	for (count1 = 1; count1 <= num; count1++)
//	{
//		cin >> elem1.r[count1].key;
//	}
//	return num;
//}
//void output_elem(SqList a, int num)
//{
//	int count1 = 1;
//	for (; count1 <= num; count1++)
//	{
//		cout << a.r[count1].key << ' ';
//	}
//	cout << endl;
//}
//int Partition(SqList &L, int low, int high)
//{
//	L.r[0] = L.r[low];
//	int pivotkey = L.r[low].key;
//	while (low < high)
//	{
//		while (low < high && L.r[high].key >= pivotkey)
//		{
//			--high;
//		}
//		L.r[low] = L.r[high];
//		while (low < high && L.r[low].key <= pivotkey)
//		{
//			++low;
//		}
//		L.r[high] = L.r[low];
//	}
//	L.r[low] = L.r[0];
//	return low;
//}
//void QSort(SqList &L, int low, int high) {
//	if (low < high)
//	{
//		int pivotloc = Partition(L, low, high);
//		QSort(L, low, pivotloc - 1);
//		QSort(L, pivotloc + 1, high);
//	}
//}
//void QuickSort(SqList &L)
//{
//	QSort(L, 1, L.length);
//}
//
//
//
//int main()
//{
//	SqList a;
//	cin >> a.length;
//	a.r = (node*)malloc(sizeof(node)*(a.length + 1));
//	input_elem(a, a.length);
//	QuickSort(a);
//	output_elem(a, a.length);
//	return 0;
//}

#include<iostream>
using namespace std;
#define elem_nummax 100005
int elem1[elem_nummax];
int input_elem(int num)
{
	int count1;
	for (count1 = 1; count1 <= num; count1++)
	{
		cin >> elem1[count1];
	}
	return num;
}
void output_elem(int num)
{
	int count1 = 1;
	for (; count1 <= num; count1++)
	{
		cout << elem1[count1] << ' ';
	}
	cout << endl;
}
int Partition(int low, int high)
{
	elem1[0] = elem1[low];
	int pivotkey = elem1[low];
	while (low < high)
	{
		while (low < high && elem1[high] >= pivotkey)
		{
			--high;
		}
		elem1[low] = elem1[high];
		while (low < high &&elem1[low] <= pivotkey)
		{
			++low;
		}
		elem1[high] =elem1[low];
	}
	elem1[low] = elem1[0];
	return low;
}
void QSort( int low, int high) {
	if (low < high)
	{
		int pivotloc = Partition(low, high);
		QSort( low, pivotloc - 1);
		QSort( pivotloc + 1, high);
	}
}
void QuickSort(int length)
{
	QSort(1, length);
}



int main()
{
	int length;
	cin >>length;
	input_elem(length);
	QuickSort(length);
	output_elem(length);
	return 0;
}





/*
6
23 46 0 8 11 18
13
81 68 33 40 89 72 75 21 75 3 63 15 54
*/