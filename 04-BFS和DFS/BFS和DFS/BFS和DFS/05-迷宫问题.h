#pragma once
#include<iostream>
#include<queue>
using namespace std;
/*
	广度优先搜素：
		将队首节点可拓展的点入队，如果没有可拓展的点，将队首节点出队。
		重复以上步骤，直到到达目标位置或者队列为空。
		BFS搜索到的结果一定是最短的。BFS运用到了队列
	深度优先搜索：
		从某点出发，沿着一个方向往下试探，
		当找到目标位置，还需回溯，以便找到所有的路径，
		在比较最短的路径，效率没有BFS高。DFS运用到了栈
*/

struct point {
	int x;
	int y;
	int step;
};