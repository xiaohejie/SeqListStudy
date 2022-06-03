#include<iostream>
#include<vector>
using namespace std;
/*
	不同的二插搜索树：
		使用动态规划DP
*/
class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++) {		//假设i为根节点
			for (int j = i; j <= n; j++) {
				/*
					f(n)：表示长度为n的所有不同二插搜索树的个数
					F(i, n)：表示以i为根节点的所有二插搜索树的个数
					f(n) = (i从1到n求和)F(i, n)
					F(i, n) = f(i-1) * f(n-i);
					所以可得到下面的我公式
				*/
				f[i] += f[j - 1] * f[i - j];	//这个式子的推导，可以看官方解析
			}
		}
		return f[n];
	}
};