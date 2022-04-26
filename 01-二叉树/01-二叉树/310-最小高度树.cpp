#include <iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;
/*
	310-��С�߶�����˼·��ȷ�����������⣩
        �����Ľڵ�
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        int* degree = new int[n];       //ÿ���ڵ���ھ�����
        //unordered_map<int, vector<int>> map;    //ÿ���ڵ���ھ���
        vector<vector<int>> map(n);

        //��ʼ���ھ��������ھӵ�����
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            //������һ���ھ��ǶԷ�
            degree[a]++;
            degree[b]++;

            //key���ڵ�   value���ھ���
            map[a].push_back(b);
            map[b].push_back(a);
        }
        /*for (auto num : map) {
            for (auto n : num) {
                cout << n << " ";
            }
            cout << endl;
        }*/

        //��ʱ�˿�Ҷ�ӽڵ���
        queue<int> leafNodes;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leafNodes.push(i);
            }
        }
        //����ѭ��(��)
        while (leafNodes.size() > 0) {
            res.clear();

            int size = leafNodes.size();
            for (int i = 0; i < size; i++){
                int leaf = leafNodes.front();
                leafNodes.pop();
                res.push_back(leaf);

                vector<int> neighbors = map[leaf];      //ĳ��Ҷ�ӽڵ���ھ���
                for (auto& neighbour : neighbors) {
                    degree[neighbour]--;        //�ھӵ��ھ�������1

                    if (degree[neighbour] == 1) {
                        //��һ�ֵ�Ҷ�ӽ��
                        leafNodes.push(neighbour);
                    }
                }
            }
        }
        return res;
    }
};

