#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
typedef bool Status;
#define OK 1
#define ERROR 0


int count5=0;//记录第几个名字
#define name_max_num 1000
int pos1[name_max_num] = { 0 };
int sanlie[name_max_num] = { 0 };
#define name_max_length 100
//char a[name_max_length];
typedef struct
{
	char* data;
	int num;//散列次数
}hashnode;
typedef struct
{
	hashnode *firstarc;
	int num;//表内元素个数
	int num_max;//表长度
}hashlist;
hashlist a;
Status initial_hashlist(hashlist &a,int m)
{
	a.num_max=m;
	a.num = 0;
	a.firstarc = (hashnode*)malloc(sizeof(hashnode)*(a.num_max+1));
	if (a.firstarc == NULL)
		return ERROR;
	for (int i = 0; i <= a.num_max; i++)
	{
		a.firstarc[i].data = NULL;
	}
	return OK;
}
//小写字母转大写字母
void name_transfer(char *a)
{
	int count2=0;
	while (a[count2] != 0)
	{
		if (a[count2] <= 'z'&&a[count2] >= 'a')
			a[count2] =a[count2] - 'a' + 'A';
		count2++;
	}
}
int hash_transfer(hashlist a,int m)
{
	hashnode k;
	int count3 = 1;
	k.data = (char*)malloc(sizeof(char)*name_max_length);
	int count1 = 0;
	int length=0;
	int key=0;
	k.data[0] = 0;
	count1 = 0;
	cin >> k.data;
	name_transfer(k.data);
	while (k.data[count1] != 0)
	{
		length++;
		count1++;
	}
	count1--;
	int temp9;
	temp9 = 37 % m;
	while (count1>=0)
	{
		key =key+ ((k.data[count1]-'A'+1) * int(pow(temp9, length - count1 - 1))) % m;
		key = key % m;
		count1--;
	}
	key = key % m;
	while (a.firstarc[key].data != NULL)
	{
		if (key == a.num_max-1)
		{
			key = 0;
			count3++;
			continue;
		}
		key++;
		count3++;
	}
	a.firstarc[key].data = k.data;
	a.firstarc[key].num = count3;
	sanlie[count5] = count3;
	return key;
}
int main()
{
	int n;
	int m, length1;
	int count1=1;
	int count6=0;
	cin >> n;
	cin >> m >> length1;
	initial_hashlist(a,length1);
	while(n>count5)
	{
		pos1[count5]=hash_transfer(a,m);
		count5++;
	}
	while (count6<n)
	{
		cout << pos1[count6] << ' ';
		count6++;
	}
	cout << endl;
	count6 = 0;
	while (sanlie[count6]!=0)
	{
		cout << sanlie[count6] << ' ';
		count6++;
	}
	return 0;
}



/*
4 11 11
A B C L
4 11 11
aa ab ac ad
4 11 11
a b ac d
*/