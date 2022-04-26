#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include <set>
#include <stack>
using namespace std;
void DFS(unordered_map<string, vector<string>> graph, string s) {
	stack<string> queue;
	set<string> seen;
	vector<string> nodes;
	queue.push(s);
	seen.insert(s);
	while (queue.size() > 0)
	{
		string vertex = queue.top();
		queue.pop();
		nodes = graph[vertex];
		for (auto& w : nodes) {
			if (seen.find(w) == seen.end()) {
				queue.push(w);
				seen.insert(w);
			}
		}
		cout << vertex << " ";
	}
}
