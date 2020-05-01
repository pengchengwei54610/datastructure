#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
#define char_num 8
typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char  **HuffmanCode;

void Select(HuffmanTree a, int b, int &c, int &d)
{
	int k=1;
	HuffmanTree e=a;
	int num1 = 0;
	while (num1!=2)
	{
		if (e->parent == 0)
		{
			if (num1 == 0)
			{
				c = e-a;
			}
			else
			{
				d = e-a;
			}
			num1++;
		}
		e++;
	}
	while ((e-a) <= b)
	{
		if (e->parent == 0)
		{
			if (e->weight < (a + c)->weight|| e->weight < (a + d)->weight)
				if ((a + c)->weight <= (a + d)->weight)
				{
					d = e - a;
				}
				else
				{
					c = d;
					d = e - a;
				}
		}
		e++;
	}
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	HuffmanTree p;
	char *cd;
	int i, s1, s2, start;
	unsigned int c, f;
	if (n <= 1)
		return;      // n为字符数目，m为结点数目
	int m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号单元未用
	p = HT;
	p->weight = -1;
	p->parent = -1;
	p->lchild = -1;
	p->rchild = -1;
	for (p = HT+1, i = 1; i <= n; ++i, ++p, ++w)
	{
		p->weight = *w; 
		p->parent = 0; 
		p->lchild = 0;
		p->rchild = 0;
	}
	// *W={5,29,7,8,14,23,3,11}
	// *p = { *w,0,0,0 };	
	for (; i <= m; ++i, ++p)
	{
		p->weight = 0;
		p->parent = 0; 
		p->lchild = 0;
		p->rchild = 0;
	}
	//*p={ 0,0,0,0 };
	for (i = n + 1; i <= m; ++i)    //  建赫夫曼树
	{
		Select(HT, i - 1, s1, s2); //已被选择过的节点不能再选
		HT[s1].parent = i;   
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	//  0号单元未用
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		for (c = i, f = HT[c].parent; f != 0; c = f, f = HT[f].parent)
			if (HT[f].lchild == c) 
				cd[--start] = '0';
			else cd[--start] = '1';
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
		cout << HC[i] << endl;
	}
	free(cd);
}



int main()
{
	HuffmanTree a = (HuffmanTree)malloc(sizeof(HTNode));
	HuffmanCode c;
	int k[char_num] = { 5,29,7,8,14,23,3,11 };
	int *w=k;
	HuffmanCoding(a, c, w, char_num);
	return 0;
}