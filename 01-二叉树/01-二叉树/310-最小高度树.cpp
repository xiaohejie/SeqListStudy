#include <iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
/*
	310-最小高度树（思路正确，代码有问题）
        找中心节点
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        int* degree = new int[n];       //每个节点的邻居数量
        //unordered_map<int, vector<int>> map;    //每个节点的邻居们
        vector<vector<int>> map(n);

        //初始化邻居数量和邻居的名字
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            //至少有一个邻居是对方
            degree[a]++;
            degree[b]++;

            //key：节点   value：邻居们
            map[a].push_back(b);
            map[b].push_back(a);
        }
        /*for (auto num : map) {
            for (auto n : num) {
                cout << n << " ";
            }
            cout << endl;
        }*/

        //此时此刻叶子节点们
        queue<int> leafNodes;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leafNodes.push(i);
            }
        }
        //遍历循环(减)
        while (leafNodes.size() > 0) {
            res.clear();

            int size = leafNodes.size();
            for (int i = 0; i < size; i++){
                int leaf = leafNodes.front();
                leafNodes.pop();
                res.push_back(leaf);

                vector<int> neighbors = map[leaf];      //某个叶子节点的邻居们
                for (auto& neighbour : neighbors) {
                    degree[neighbour]--;        //邻居的邻居数量减1

                    if (degree[neighbour] == 1) {
                        //新一轮的叶子结点
                        leafNodes.push(neighbour);
                    }
                }
            }
        }
        return res;
    }
};

