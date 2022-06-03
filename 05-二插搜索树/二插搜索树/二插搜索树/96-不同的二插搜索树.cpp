#include<iostream>
#include<vector>
using namespace std;
/*
	��ͬ�Ķ�����������
		ʹ�ö�̬�滮DP
*/
class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++) {		//����iΪ���ڵ�
			for (int j = i; j <= n; j++) {
				/*
					f(n)����ʾ����Ϊn�����в�ͬ�����������ĸ���
					F(i, n)����ʾ��iΪ���ڵ�����ж����������ĸ���
					f(n) = (i��1��n���)F(i, n)
					F(i, n) = f(i-1) * f(n-i);
					���Կɵõ�������ҹ�ʽ
				*/
				f[i] += f[j - 1] * f[i - j];	//���ʽ�ӵ��Ƶ������Կ��ٷ�����
			}
		}
		return f[n];
	}
};