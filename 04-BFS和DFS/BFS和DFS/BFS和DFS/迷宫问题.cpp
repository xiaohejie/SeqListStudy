#include "05-�Թ�����.h"
int a[100][100], v[100][100];
//�������飺��������
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
//�������
queue<point> r;
int main2() {
	//����(m,n:�Թ��ж��      startx,starty:��ʼλ��      p,q:�Թ�����)
	int m, n, startx, starty, p, q;
	int flag = 0;
	cin >> m >> n;
	//�����Թ�ÿ���״̬���Ƿ����ϰ���
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	//ȷ����ʼλ��
	cin >> startx >> starty >> p >> q;

	/*
		BFS
	*/
	//�����������
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	//������,����״̬����Ϊ�ѷ���
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
		//�����ĸ�����
		for (int k = 0; k < 4; k++) {
			int tx, ty;
			tx = x + dx[k];
			ty = y + dy[k];
			//�ж���չ�ĵ�
			if (a[tx][ty] == 1 && v[tx][ty] == 0) {
				//���
				point temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = r.front().step + 1;
				r.push(temp);
				//����Ϊ�ѷ���
				v[tx][ty] = 1;
			}
		}
		//���ӣ���չ������Ҫ�����׳���
		r.pop();
	}
	if (flag == 0) {
		cout << "no answer��" << endl;
	}
	return 0;
}