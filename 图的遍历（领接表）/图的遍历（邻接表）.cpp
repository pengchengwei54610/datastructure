#include<iostream>
using namespace std;
#define MAX_VERTEX_NUM 50//最大顶点数
#define MAXQSIZE 1000
#define ok 1
#define error 0
#define overflow 0
typedef bool Status;
typedef struct ArcNode {
	int adjvex;//当前结点
	struct ArcNode  *nextarc;//下一结点
}ArcNode;  //边结点类型
typedef struct VNode {
	int data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM]; //表头结点
typedef struct {
	AdjList vertices;  //邻接表
	int vexnum;//顶点数
	int arcnum;//边数
}ALGraph;
ALGraph A2;
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
	q.rear = 0;
	q.MAXS = MAXQSIZE;
	q.S = 0;
	return ok;
}
int LocateVex(ALGraph G, char u)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	if (i == G.vexnum)
	{
		printf("Error u!\n");
		exit(1);
	}
	return 0;
}
void CreateALGraph(ALGraph &g)
{
	int i, j, k;
	int v1, v2;
	cin >> g.vexnum >> g.arcnum;
	ArcNode *p;
	ArcNode *l;
	for (i = 0; i < g.vexnum; i++)
	{
		g.vertices[i].data = i;
		g.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < g.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(g, v1);
		j = LocateVex(g, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p;
		l = (ArcNode*)malloc(sizeof(ArcNode));
		l->adjvex = i;
		l->nextarc = g.vertices[j].firstarc;
		g.vertices[j].firstarc = l;
	}
	return;
}
void DFS(ALGraph G, int v)
{
	ArcNode *p;
	cout << G.vertices[v].data;
	visited[v] = 1;
	p = G.vertices[v].firstarc;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			cout << ' ';
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}
void DFSTraverse(ALGraph G)
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

void BFS(ALGraph G, int v)
{
	ArcNode *p;
	Squeue Q;
	initqueue(Q);
	cout << '{';
	cout << G.vertices[v].data;
	visited[v] = 1;
	Q.base[Q.rear] = v;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	while (Q.front != Q.rear)
	{
		v = Q.base[Q.front];
		Q.front = (Q.front + 1) % MAXQSIZE;
		p = G.vertices[v].firstarc;
		while (p)
		{
			if (!visited[p->adjvex])
			{
				cout << ' ';
				cout << G.vertices[p->adjvex].data;
				visited[p->adjvex] = 1;
				Q.base[Q.rear] = p->adjvex;
				Q.rear = (Q.rear + 1) % MAXQSIZE;
			}
			p = p->nextarc;
		}
	}
	cout << '}';
}

void BFSTraverse(ALGraph G) {
	for (int v = 0; v < G.vexnum; ++v)
		visited[v] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v])
			BFS(G, v);
}



int main()
{
	CreateALGraph(A2);
	DFSTraverse(A2);
	cout << endl;
	BFSTraverse(A2);
	return 0;
}



//13 13 0 1 0 2 0 5 0 11 1 12 3 4 6 7 6 8 6 10 7 10 9 11 9 12 11 12