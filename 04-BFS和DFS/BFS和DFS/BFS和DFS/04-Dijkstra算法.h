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
//struct Node  // ������Ϣ������ < �ŵ�����
//{
//    char id; // ��ı��
//    int dis; // �㵽Դ�����̾���
//    Node(int a, int b) :id(a), dis(b) {}
//    friend bool operator < (const Node& a, const Node& b) {
//        return a.dis > b.dis;
//    }
//};
//map<char, vector<Node>>v;  // �ڽӱ�
//map<char, char>p;    // ��¼ BFS ��
//map<char, int>dis;    // ��¼ ��i ��Դ�����̾���    
//vector<char>vis;    // ��¼�� BFS ������ ��i ���ޱ�������
//void BFS(char start)
//{
//    // ��ʼ��
//    vis.clear();
//    p.clear();
//    for (auto i = v.begin(); i != v.end(); i++)
//        dis[(*i).first] = inf;
//
//    // �������У���������
//    priority_queue<Node>q;
//    q.push(Node(start, 0));
//    dis[start] = 0;
//    p[start] = 0;
//
//    while (q.size())
//    {
//        // ���׳�����
//        Node vertex = q.top();
//        q.pop();
//        vis.push_back(vertex.id);
//
//        // ȡ vertex �������ڽӵ�
//        vector<Node>vv = v[vertex.id];
//        for (int i = 0; i < vv.size(); i++)
//        {
//            Node next = { vv[i].id, vertex.dis + vv[i].dis };  // ע�⣺��������ŵ��ǵ㵽Դ��ľ���
//            auto ret = find(vis.begin(), vis.end(), next.id);
//            // ��� next û�б������Ļ�, ���Ҹôα���˳��� ��next ��Դ�����̾����ԭ�Ȼ��̡�
//            if (ret == vis.end() && next.dis < dis[next.id])
//            {
//                p[next.id] = vertex.id;     // ��¼·��
//                dis[next.id] = next.dis; // ��¼���� 
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
//        v.clear();  // ����ڽӱ�
//
//        char s, s1, s2;
//        scanf("%c%c%c", &s1, &s, &s2);  // ���
//        for (int i = 0; i < m; i++)
//        {
//            char t1, t2, t3, t4;
//            int w;
//            scanf("%c%c%c%d%c", &t1, &t3, &t2, &w, &t4);
//            vector<Node>vv = v[t1];        // ȡ�� t1 ԭ���������ڽӵ�
//            vv.push_back(Node(t2, w));    // ����һ���ڽӵ�
//            v[t1] = vv;                    // ���ǵ�ԭ�����ڽӵ�
//            if (t1 != t2)    // ����ͼ
//            {
//                vv = v[t2];
//                vv.push_back(Node(t1, w));
//                v[t2] = vv;
//            }
//        }
//        BFS(s);
//
//        // ������·��
//        for (auto i = v.begin(); i != v.end(); i++)
//        {
//            if ((*i).first == s)
//                continue;
//            printf("%c �� %c ����̾���Ϊ��%2d�����·��Ϊ��", s, (*i).first, dis[(*i).first]);
//            find((*i).first);
//            puts("");
//        }
//    }
//    system("pause");
//    return 0;
//}