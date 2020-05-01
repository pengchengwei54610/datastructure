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
int LT(int a, int b)
{
	if (a < b)
		return 1;
	else
		return 0;
}
void InsertSort(int length)
{
	int j;
	for (int i = 2; i <= length; ++i)
		if (LT(elem1[i], elem1[i - 1]))
		{
			elem1[0] = elem1[i];  // L.r[0]Îª¼àÊÓÉÚ
			for (j = i - 1; LT(elem1[0], elem1[j]); --j)
			{
				elem1[j + 1] = elem1[j];
			}
			elem1[j + 1] = elem1[0];
		}
}

int main()
{
	int length;
	cin >> length;
	input_elem(length);
	InsertSort(length);
	output_elem(length);
	return 0;
}