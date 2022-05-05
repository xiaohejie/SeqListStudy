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
	queue.push_back(s);			//����ʼ���s�Ž�����
	seen.insert(s);				//��ʾs�Ѿ����ʹ�
	while (queue.size() > 0)	//�����к���Ԫ�صĻ�
	{
		string vertex = queue.front();		//get��Ԫ��
		queue.pop_front();					//�����䵯��	
		nodes = graph[vertex];				//��vertex������Ԫ�أ�����BFS
		for (auto& w : nodes) {
			if (seen.find(w) == seen.end()) {
				queue.push_back(w);
				seen.insert(w);
			}
		}
		cout << vertex << " ";
	}
}

