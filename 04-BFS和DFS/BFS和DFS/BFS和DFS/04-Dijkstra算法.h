//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<map>
//using namespace std;
//#define N 110
//#define inf 0x3f3f3f3f
//struct Node  // 存点的信息，并将 < 号的重载
//{
//    char id; // 点的编号
//    int dis; // 点到源点的最短距离
//    Node(int a, int b) :id(a), dis(b) {}
//    friend bool operator < (const Node& a, const Node& b) {
//        return a.dis > b.dis;
//    }
//};
//map<char, vector<Node>>v;  // 邻接表
//map<char, char>p;    // 记录 BFS 树
//map<char, int>dis;    // 记录 点i 到源点的最短距离    
//vector<char>vis;    // 记录在 BFS 过程中 点i 有无被遍历过
//void BFS(char start)
//{
//    // 初始化
//    vis.clear();
//    p.clear();
//    for (auto i = v.begin(); i != v.end(); i++)
//        dis[(*i).first] = inf;
//
//    // 创建队列，并添加起点
//    priority_queue<Node>q;
//    q.push(Node(start, 0));
//    dis[start] = 0;
//    p[start] = 0;
//
//    while (q.size())
//    {
//        // 队首出队列
//        Node vertex = q.top();
//        q.pop();
//        vis.push_back(vertex.id);
//
//        // 取 vertex 的所有邻接点
//        vector<Node>vv = v[vertex.id];
//        for (int i = 0; i < vv.size(); i++)
//        {
//            Node next = { vv[i].id, vertex.dis + vv[i].dis };  // 注意：队列里面放的是点到源点的距离
//            auto ret = find(vis.begin(), vis.end(), next.id);
//            // 如果 next 没有遍历过的话, 并且该次遍历顺序的 点next 到源点的最短距离比原先还短。
//            if (ret == vis.end() && next.dis < dis[next.id])
//            {
//                p[next.id] = vertex.id;     // 记录路径
//                dis[next.id] = next.dis; // 记录距离 
//                q.push(next);
//            }
//        }
//    }
//}
//void find(char i)
//{
//    if (p[i] != 0)
//    {
//        find(p[i]);
//        printf("->%c", i);
//    }
//    else
//        printf("%c", i);
//}
//int main2(void)
//{
//    int n, m;
//    while (scanf("%d%d", &n, &m) != EOF)
//    {
//        v.clear();  // 清空邻接表
//
//        char s, s1, s2;
//        scanf("%c%c%c", &s1, &s, &s2);  // 起点
//        for (int i = 0; i < m; i++)
//        {
//            char t1, t2, t3, t4;
//            int w;
//            scanf("%c%c%c%d%c", &t1, &t3, &t2, &w, &t4);
//            vector<Node>vv = v[t1];        // 取出 t1 原来的所有邻接点
//            vv.push_back(Node(t2, w));    // 增加一个邻接点
//            v[t1] = vv;                    // 覆盖掉原来的邻接点
//            if (t1 != t2)    // 无向图
//            {
//                vv = v[t2];
//                vv.push_back(Node(t1, w));
//                v[t2] = vv;
//            }
//        }
//        BFS(s);
//
//        // 输出最短路径
//        for (auto i = v.begin(); i != v.end(); i++)
//        {
//            if ((*i).first == s)
//                continue;
//            printf("%c 到 %c 的最短距离为：%2d，最短路径为：", s, (*i).first, dis[(*i).first]);
//            find((*i).first);
//            puts("");
//        }
//    }
//    system("pause");
//    return 0;
//}