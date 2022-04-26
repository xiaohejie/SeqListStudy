#pragma once
#include<iostream>
#include<unordered_map>
#include<deque>
#include<vector>
#include <set>
using namespace std;
void BFS(unordered_map<string, vector<string>> graph, string s) {
	deque<string> queue;
	set<string> seen;
	vector<string> nodes;
	queue.push_back(s);
	seen.insert(s);
	while (queue.size() > 0)
	{
		string vertex = queue.front();
		queue.pop_front();
		nodes = graph[vertex];
		for (auto& w : nodes) {
			if (seen.find(w) == seen.end()) {
				queue.push_back(w);
				seen.insert(w);
			}
		}
		cout << vertex << " ";
	}
}

