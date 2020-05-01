#include<iostream>
using namespace std;
#define MAX_VERTEX_NUM 50//最大顶点数
typedef int Adjmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	char vexs[MAX_VERTEX_NUM];
	Adjmatrix arcs;
	int vexnum;//顶点数
	int arcnum;//边数
}MGraph;
MGraph G1;

typedef struct ArcNode {
	int adjvex;//当前结点
	struct ArcNode  *nextarc;//下一结点
	int info;//权重
}ArcNode;  //边结点类型
typedef struct VNode {
	char data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM]; //表头结点
typedef struct {
	AdjList vertices;  //邻接表
	int vexnum;//顶点数
	int arcnum;//边数
}ALGraph;
ALGraph A2;

int parm_select()
{
	int parm;//1为有向图,2为有向网,3为无向图,4为无向网
	cin >> parm;
	return parm;
}

int LocateVex(MGraph G, char u)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (u == G.vexs[i])
			return i;
	}
	if (i == G.vexnum)
	{
		printf("Error u!\n");
		exit(1);
	}
	return 0;
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


void CreateMGraph1(MGraph &G, ALGraph &g)
{
	int i, j, k, I, J;
	char v1, v2;
	cin >> G.vexnum >> G.arcnum;
	cin >> G.vexs;
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	ArcNode *p;
	g.vexnum = G.vexnum;
	g.arcnum = G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		g.vertices[i].data = G.vexs[i];
		g.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		I = LocateVex(g, v1);
		J = LocateVex(g, v2);
		G.arcs[i][j] = 1;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = J;
		p->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p;
	}
	return;
}

void CreateMGraph2(MGraph &G, ALGraph &g)
{
	int i, j, k, w, I, J;
	char v1, v2;
	cin >> G.vexnum >> G.arcnum;
	cin >> G.vexs;
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	ArcNode *p;
	g.vexnum = G.vexnum;
	g.arcnum = G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		g.vertices[i].data = G.vexs[i];
		g.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		I = LocateVex(g, v1);
		J = LocateVex(g, v2);
		G.arcs[i][j] = w;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = J;
		p->nextarc = g.vertices[i].firstarc;
		p->info = w;
		g.vertices[i].firstarc = p;
	}
	return;
}

void CreateMGraph3(MGraph &G, ALGraph &g)
{
	int i, j, k, I, J;
	char v1, v2;
	cin >> G.vexnum >> G.arcnum;
	cin >> G.vexs;
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	ArcNode *p;
	ArcNode *l;
	g.vexnum = G.vexnum;
	g.arcnum = G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		g.vertices[i].data = G.vexs[i];
		g.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		I = LocateVex(g, v1);
		J = LocateVex(g, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = J;
		p->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p;
		l = (ArcNode*)malloc(sizeof(ArcNode));
		l->adjvex = I;
		l->nextarc = g.vertices[j].firstarc;
		g.vertices[j].firstarc = l;
	}
	return;
}

void CreateMGraph4(MGraph &G, ALGraph &g)
{
	int i, j, k, w, I, J;
	char v1, v2;
	cin >> G.vexnum >> G.arcnum;
	cin >> G.vexs;
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	ArcNode *p;
	ArcNode *l;
	g.vexnum = G.vexnum;
	g.arcnum = G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		g.vertices[i].data = G.vexs[i];
		g.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		I = LocateVex(g, v1);
		J = LocateVex(g, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = J;
		p->nextarc = g.vertices[i].firstarc;
		p->info = w;
		g.vertices[i].firstarc = p;
		l = (ArcNode*)malloc(sizeof(ArcNode));
		l->adjvex = I;
		l->nextarc = g.vertices[j].firstarc;
		l->info = w;
		g.vertices[j].firstarc = l;
	}
	return;
}

void PrintMGraph(MGraph G)
{
	int i, j;
	int no1 = 0;
	while (G.vexs[no1] != 0)
	{
		cout << G.vexs[no1] << ' ';
		no1++;
	}
	cout << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
			printf("%4d", G.arcs[i][j]);
		printf("\n");
	}
	return;
}

void PrintALGraph1(ALGraph g)
{
	int num1 = 0;
	ArcNode *k;
	for (; num1 < g.vexnum; num1++)
	{
		cout << g.vertices[num1].data;
		cout << "-->";
		if (g.vertices[num1].firstarc == NULL)
			;
		else
		{
			k = g.vertices[num1].firstarc;
			for (; k != NULL;)
			{
				cout << k->adjvex << ' ';
				k = k->nextarc;
			}
		}
		cout << endl;
	}
}

void PrintALGraph2(ALGraph g)
{
	int num1 = 0;
	ArcNode *k;
	for (; num1 < g.vexnum; num1++)
	{
		cout << g.vertices[num1].data;
		cout << "-->";
		if (g.vertices[num1].firstarc == NULL)
			;
		else
		{
			k = g.vertices[num1].firstarc;
			for (; k != NULL;)
			{
				cout << k->adjvex << ',' << k->info << ' ';
				k = k->nextarc;
			}
		}
		cout << endl;
	}
}


int main()
{
	int parm1;
	parm1 = parm_select();
	if (parm1 == 1)
	{
		CreateMGraph1(G1, A2);
		PrintMGraph(G1);
		PrintALGraph1(A2);
	}
	else if (parm1 == 2)
	{
		CreateMGraph2(G1, A2);
		PrintMGraph(G1);
		PrintALGraph2(A2);
	}
	else if (parm1 == 3)
	{
		CreateMGraph3(G1, A2);
		PrintMGraph(G1);
		PrintALGraph1(A2);
	}
	else if (parm1 == 4)
	{
		CreateMGraph4(G1, A2);
		PrintMGraph(G1);
		PrintALGraph2(A2);
	}

}



//1 4 4 abcd a b a c c d d a
//2 6 10 123456 1 2 5 1 4 7 2 3 4 3 1 8 3 6 9 4 3 5 4 6 6 5 4 5 6 1 3 6 5 1