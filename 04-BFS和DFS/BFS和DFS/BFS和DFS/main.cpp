#include"01-BFS.h"
#include"02-DFS.h"
#include"03-�������·��.h"
#include "04-Dijkstra�㷨.h"
int main() {
	unordered_map<string, vector<string>> praph = {
		{"A", {"B", "C"}},
		{"B", {"A", "C", "D"}},
		{"C", {"A", "B", "D", "E"}},
		{"D", {"B", "C", "E", "F"}},
		{"E", {"C", "D"}},
		{"F", {"D"}}
	};
	//DFS(praph, "E");
	unordered_map<string, string> parent;
	parent = BFS_rouetr(praph, "E");
	cout << endl;
	for (auto& p : parent) {
		cout << p.first << "  " << p.second << endl;
	}
	cout << endl;
	//Ҫ�ߵ�B��
	string v = "B";
	while (v != "")
	{
		cout << v << endl;
		//����v��������һ���ڵ㣬ֱ��vΪ��
		v = parent[v];
	}
	return 0;
}