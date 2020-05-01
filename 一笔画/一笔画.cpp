#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX_NUM 100

typedef struct {
	int Matrix[MAX_NUM][MAX_NUM];
	int vexnum, arcnum;//vex顶点，arc边数
} GMatrix;
int num = 0;
int No = 0;
void dfs_draw(GMatrix M, int s[100], int n)
{
	if (No == 0 && n != 0)
		return;
	s[No] = n + 1;
	No++;
	int i;
	for (i = 0; i < M.vexnum; i++) {
		if (M.Matrix[n][i] != 0) {
			M.Matrix[n][i] = 0;
			M.Matrix[i][n] = 0;
			dfs_draw(M, s, i);
			M.Matrix[n][i] = 1;
			M.Matrix[i][n] = 1;
		}
	}
	if (No == M.arcnum) {
		cout << "第" << ++num << "种走法" << endl;
		for (i = 0; i < M.arcnum; i++)
			cout << i + 1 << ':' << s[i] << "->" << s[i + 1] << endl;
		cout << endl;
	}
	No--;
	return;
}
int main()
{
	GMatrix M;
	cout << "输入顶点数和边数" << endl;
	cin >> M.vexnum >> M.arcnum;
	int i, j, m, n;
	int	s[100] = { 0 };
	for (i = 0; i < M.vexnum; i++)
		for (j = 0; j < M.vexnum; j++)
			M.Matrix[i][j] = 0;
	cout << "输入边之间的连接" << endl;
	for (i = 0; i < M.arcnum; i++)
	{
		cin >> m >> n;
		M.Matrix[m - 1][n - 1] = 1;
		M.Matrix[n - 1][m - 1] = 1;
	}
	for (i = 0; i < M.vexnum; i++)
		dfs_draw(M, s, i);
	return 0;
}
//5 8 1 2 1 3 1 5 2 3 2 5 3 4 3 5 4 5