#include <iostream>
using namespace std;
//计算prefix_table：最长公共前后缀表
/*
	思路：
		最好画个图
		prefix[0] = 0;
		当i < n{
			如果pattern[i] == pattern[len]{
				len就要加1；
				第i个prefix等于len
				然后i++
			}
			否则{
				if(len > 0){
				
				}
			}
		}
*/
void prifix_table(char pattern[], int prefix[] ,int n) {
	prefix[0] = 0;
	int len = 0;	//最长公共前后缀长度
	int i = 1;
	while (i < n) {
		if (pattern[i] == pattern[len]) {
			len++;
			prefix[i] = len;
			i++;
		}
		else {
			if (len > 0) {
				len = prefix[len - 1];
			}
			else {
				prefix[i] = len;
				i++;
			}
		}
	}
}

//对最长公共前后缀表进行移位
void move_Prefix_table(int prefix[], int n) {
	int i = 0;
	for (int i = n - 1; i > 0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}

//实现kmp算法
void kmpSearch(char text[], char pattern[]) {
	int i = 0, j = 0;
	int m = strlen(text);
	int n = strlen(pattern);
	//cout << m << n << endl;
	int* prefix = (int*)malloc(sizeof(int) * n);
	//寻找最长公共前后缀
	prifix_table(pattern, prefix, n);
	move_Prefix_table(prefix, n);
	/*for (int i = 0; i < n; i++) {
		cout << prefix[i] << endl;
	}*/
	//进行KMP搜索
	/*
		text[i]	    ,len(text)    = m;
		pattern[j]  ,len(pattern) = n;
	*/
	while (i < m) {
		if(j == n - 1 && text[i] == pattern[j]){
			cout << "Found pattern at " << i - j << endl;
			//继续往下寻找
			j = prefix[j];
		}
		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			j = prefix[j];
			if (j == -1) {
				i++;
				j++;
			}
		}
	}
}

int main() {
	char text[] = "ABABCABAAABABCABAAABABCABAA";
	char pattern[] = "ABABCABAA";
	kmpSearch(text, pattern);
	/*int n = 9;
	int prefix[9];
	prifix_table(pattern, prefix, n);
	move_Prefix_table(prefix, n);
	for (int i = 0; i < n; i++) {
		cout << prefix[i] << endl;
	}*/
	return 0;
}