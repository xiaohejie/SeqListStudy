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
	queue.push_back(s);			//将开始结点s放进队列
	seen.insert(s);				//表示s已经访问过
	while (queue.size() > 0)	//队列中含有元素的话
	{
		string vertex = queue.front();		//get首元素
		queue.pop_front();					//并将其弹出	
		nodes = graph[vertex];				//与vertex相连的元素，进行BFS
		for (auto& w : nodes) {
			if (seen.find(w) == seen.end()) {
				queue.push_back(w);
				seen.insert(w);
			}
		}
		cout << vertex << " ";
	}
}

