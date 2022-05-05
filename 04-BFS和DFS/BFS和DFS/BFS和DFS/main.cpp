#include"01-BFS.h"
#include"02-DFS.h"
#include"03-计算最短路径.h"
#include "04-Dijkstra算法.h"
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
	//要走到B点
	string v = "B";
	while (v != "")
	{
		cout << v << endl;
		//根据v找他的上一个节点，直到v为空
		v = parent[v];
	}
	return 0;
}