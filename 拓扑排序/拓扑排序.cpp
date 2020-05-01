#include<iostream>
using namespace std;
typedef bool Status;
#define OK 1
#define ERROR 0



#define MAX_VERTEX_NUM 1000
typedef int VertexType;
typedef struct ArcNode 
{//图的邻接表的定义
	int adjvex;
	struct ArcNode *nextarc;
	int info;//权重
}ArcNode;
typedef struct VNode 
{
	VertexType data;
	int indegree;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;
int LocateVex(ALGraph G, char u)
{
	int i;
	for (i = 1; i < G.vexnum+1; i++)
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
	int v1, v2,weight;
	cin >> g.vexnum >> g.arcnum;
	ArcNode *p;
	for (i = 1; i < g.vexnum+1; i++)
	{
		g.vertices[i].data = i;
		g.vertices[i].firstarc = NULL;
		g.vertices[i].indegree = 0;
	}
	for (k = 0; k < g.arcnum; k++)
	{
		cin >> v1 >> v2>>weight;
		i = LocateVex(g, v1);
		j = LocateVex(g, v2);
		g.vertices[j].indegree++;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g.vertices[i].firstarc;
		p->info = weight;
		g.vertices[i].firstarc = p;
	}
	return;
}
Status ToplogicalSort(ALGraph G) 
{
	ArcNode *p;
	int k;
	int top = -1; //入度为零的顶点栈初始化
	for (int i = 1; i < G.vexnum; ++i)
		if (G.vertices[i].indegree == 0) {
			G.vertices[i].indegree = top;
			top = i; //入度为零顶点进栈
		}
	int count = 0;
	int i;
	while (top + 1)//说明栈非空
	{
		i = top;
		top = G.vertices[top].indegree;
		++count;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{//扫描该顶点的出边表
			k = p->adjvex; //边的另一顶点
			G.vertices[k].indegree--; //顶点入度减1
			if (G.vertices[k].indegree == 0)
			{
				G.vertices[k].indegree = top;
				top = k;
			}//入度为0入栈
		}
	}
	if (count < G.vexnum) 
		return ERROR;//有向环
	else return OK;
}


int main()
{
	ALGraph a1;
	CreateALGraph(a1);
	if (ToplogicalSort(a1) == ERROR)
		cout << 0;
	else
		cout << 1;
	return 0;
}