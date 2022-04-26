#include <iostream>
using namespace std;
//����prefix_table�������ǰ��׺��
/*
	˼·��
		��û���ͼ
		prefix[0] = 0;
		��i < n{
			���pattern[i] == pattern[len]{
				len��Ҫ��1��
				��i��prefix����len
				Ȼ��i++
			}
			����{
				if(len > 0){
				
				}
			}
		}
*/
void prifix_table(char pattern[], int prefix[] ,int n) {
	prefix[0] = 0;
	int len = 0;	//�����ǰ��׺����
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

//�������ǰ��׺�������λ
void move_Prefix_table(int prefix[], int n) {
	int i = 0;
	for (int i = n - 1; i > 0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}

//ʵ��kmp�㷨
void kmpSearch(char text[], char pattern[]) {
	int i = 0, j = 0;
	int m = strlen(text);
	int n = strlen(pattern);
	//cout << m << n << endl;
	int* prefix = (int*)malloc(sizeof(int) * n);
	//Ѱ�������ǰ��׺
	prifix_table(pattern, prefix, n);
	move_Prefix_table(prefix, n);
	/*for (int i = 0; i < n; i++) {
		cout << prefix[i] << endl;
	}*/
	//����KMP����
	/*
		text[i]	    ,len(text)    = m;
		pattern[j]  ,len(pattern) = n;
	*/
	while (i < m) {
		if(j == n - 1 && text[i] == pattern[j]){
			cout << "Found pattern at " << i - j << endl;
			//��������Ѱ��
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