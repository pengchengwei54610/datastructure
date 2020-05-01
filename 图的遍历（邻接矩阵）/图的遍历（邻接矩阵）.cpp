#include<iostream>
using namespace std;
#define MAX_VERTEX_NUM 50//最大顶点数
#define MAXQSIZE 1000
#define ok 1
#define error 0
#define overflow 0
typedef bool Status;

typedef int Adjmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	char vexs[MAX_VERTEX_NUM];
	Adjmatrix arcs;
	int vexnum;//顶点数
	int arcnum;//边数
}MGraph;
MGraph G1;

int visited[MAX_VERTEX_NUM];
typedef struct
{
	int *base;
	int S;//当前元素个数
	int MAXS;//最大能存储元素个数
	int front;//队头
	int rear;//队尾
}Squeue;

//顺序队列初始化
Status initqueue(Squeue &q)
{
	q.base = (int *)malloc(MAXQSIZE * sizeof(int));
	if (!q.base)
		return overflow;
	q.front = 0;
	q.rear= 0;
	q.MAXS = MAXQSIZE;
	q.S = 0;
	return ok;
}
void CreateMGraph(MGraph &g)
{
	int i, j, k;
	cin >> g.vexnum >> g.arcnum;
	for (i = 0; i < g.vexnum; i++)
		for (j = 0; j < g.vexnum; j++)
			g.arcs[i][j] = 0;
	for (k = 0; k < g.arcnum; k++)
	{
		cin >> i >> j;
		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;
	}
	return;
}
void DFS(MGraph G, int v)
{
	int p=0;
	cout<< v;
	visited[v] = 1;
	while (p != G.vexnum)
	{
		if (G.arcs[v][p] == 1)
		{
			if (!visited[p])
			{
				cout << ' ';
				DFS(G, p);
			}
		}
		p++;
	}
}
void DFSTraverse(MGraph G) 
{
	for (int v = 0; v < G.vexnum; ++v)
		visited[v] = 0;
	for (int v = 0; v < G.vexnum; ++v)
	{
		
		if (!visited[v])
		{
			cout << '{';
			DFS(G, v);
			cout << '}';
		}
		
	}
}

void BFS(MGraph G, int v)
{
	int p;
	Squeue Q;
	initqueue(Q);
	cout << '{';
	cout << v;
	visited[v] = 1;
	Q.base[Q.rear] = v;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	while (Q.front != Q.rear)
	{
		p = 0;
		v = Q.base[Q.front];
		Q.front = (Q.front + 1) % MAXQSIZE;
		while (p != G.vexnum)
		{
			if (G.arcs[v][p] == 1)
			{
				if (!visited[p])
				{
					cout << ' ';
					cout << p;
					visited[p] = 1;
					Q.base[Q.rear] = p;
					Q.rear = (Q.rear + 1) % MAXQSIZE;
				}
			}
			p++;

		}
	}
	cout << '}';
}

void BFSTraverse(MGraph G) {
	for (int v = 0; v < G.vexnum; ++v)
		visited[v] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v])
			BFS(G, v);
}



int main()
{
	CreateMGraph(G1);
	DFSTraverse(G1);
	cout << endl;
	BFSTraverse(G1);
	return 0;
}



//13 13 0 1 0 2 0 5 0 11 1 12 3 4 6 7 6 8 6 10 7 10 9 11 9 12 11 12