#include "05-迷宫问题.h"
int a[100][100], v[100][100];
//方向数组：右下左上
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
//申请队列
queue<point> r;
int main2() {
	//输入(m,n:迷宫有多大      startx,starty:起始位置      p,q:迷宫出口)
	int m, n, startx, starty, p, q;
	int flag = 0;
	cin >> m >> n;
	//输入迷宫每块的状态（是否有障碍）
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	//确定起始位置
	cin >> startx >> starty >> p >> q;

	/*
		BFS
	*/
	//将起点进行入队
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	//起点入队,并将状态设置为已访问
	r.push(start);
	v[startx][starty] = 1;

	while (!r.empty()) {
		int x = r.front().x;
		int y = r.front().y;
		if (x == p && y == q) {
			flag = 1;
			cout << r.front().step << endl;
			break;
		}
		//遍历四个方向
		for (int k = 0; k < 4; k++) {
			int tx, ty;
			tx = x + dx[k];
			ty = y + dy[k];
			//判断拓展的点
			if (a[tx][ty] == 1 && v[tx][ty] == 0) {
				//入队
				point temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = r.front().step + 1;
				r.push(temp);
				//设置为已访问
				v[tx][ty] = 1;
			}
		}
		//出队：拓展完了需要将队首出队
		r.pop();
	}
	if (flag == 0) {
		cout << "no answer！" << endl;
	}
	return 0;
}