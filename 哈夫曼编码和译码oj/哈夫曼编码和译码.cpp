#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define char_num 127
typedef struct {
	char itself;
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char  **HuffmanCode;
int char_weight[char_num];
typedef struct
{
	char itself;
	int weight;
}tj_node;

//输入需要进行压缩的字符
int input_tj(char a)
{
	char_weight[a]++;
	if (char_weight[a] == 1)
		return 0;
	else
		return 1;
}

//选择霍夫曼树左右孩子结点
void Select(HuffmanTree a, int b, int &c, int &d)
{
	int k = 1;
	HuffmanTree e = a;
	int num1 = 0;
	while (num1 != 2)
	{
		if (e->parent == 0)
		{
			if (num1 == 0)
			{
				c = e - a;
			}
			else
			{
				d = e - a;
			}
			num1++;
		}
		e++;
	}
	while ((e - a) <= b)
	{
		if (e->parent == 0)
		{
			if (e->weight < (a + c)->weight || e->weight < (a + d)->weight)
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

//建立霍夫曼树
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, tj_node *w, int n)
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
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
	{
		p->weight = w->weight;
		p->itself = w->itself;
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
		//cout << HC[i] << endl;


	}
	free(cd);
}



int main()
{
	HuffmanTree a = (HuffmanTree)malloc(sizeof(HTNode));
	HuffmanCode c;
	cout << "请输入需要编码的字符串（以$结束，不超过1000个字符,可更改）" << endl;
	char k[1000];
	char code_1[1000] = { 0 };
	int num_k = 0;
	int num_l = 0;
	while (num_k < 1000)
	{
		cin >> k[num_k];
		if (k[num_k] == '$')
			break;
		if (input_tj(k[num_k]) == 0)
			num_l++;
		num_k++;
	}
	tj_node *w;
	w = (tj_node *)malloc((num_l) * sizeof(tj_node));
	int count1 = 0;//计数器1
	int count2 = 0;//计数器2
	while (count1 != num_l)
	{
		if (char_weight[count2] != 0)
		{
			w[count1].itself = count2;
			w[count1].weight = char_weight[count2];
			count1++;
		}
		count2++;
	}
	HuffmanCoding(a, c, w, num_l);
	count1 = 0;
	while (count1 < num_k)
	{
		count2 = 0;
		while (k[count1] != a[count2].itself)
		{
			count2++;
		}
				cout << c[count2] << ' ';//逐个输出压缩码
		strcat(code_1, c[count2]);
		count1++;
	}
	cout << code_1;
	cout << endl;

	cout << "解码结果如下" << endl;
	//解码
	count2 = 0;
	HuffmanTree temp;
	HuffmanTree temp2;
	temp = &a[2 * num_l - 1];
	temp2 = temp;
	while (code_1[count2] != 0)
	{
		if (temp2->lchild == 0 && temp2->rchild == 0)
		{
			cout << temp2->itself;
			temp2 = temp;
		}
		else
		{
			if (code_1[count2] == '0')
			{
				temp2 = (a + temp2->lchild);
				count2++;
			}
			else if (code_1[count2] == '1')
			{
				temp2 = (a + temp2->rchild);
				count2++;
			}
		}
	}
	cout << temp2->itself;



	return 0;
}