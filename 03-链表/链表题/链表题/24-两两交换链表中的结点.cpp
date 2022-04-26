/*
    ����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣
    ������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //��2��ʹ�õݹ�
        /*
            �� head ��ʾԭʼ�����ͷ�ڵ㣬�µ�����ĵڶ����ڵ㣬
            �� newHead ��ʾ�µ������ͷ�ڵ㣬ԭʼ����ĵڶ����ڵ㣬
            ��ԭʼ�����е�����ڵ��ͷ�ڵ��� newHead.next���� head.next = swapPairs(newHead.next)��
            ��ʾ������ڵ����������������������µ�ͷ�ڵ�Ϊ head ����һ���ڵ㡣
            Ȼ���� newHead.next = head������������нڵ�Ľ�������󷵻��µ������ͷ�ڵ� newHead��

            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            ListNode* newHead = head->next;
            head->next = swapPairs(newHead->next);
            newHead->next = head;
            return newHead; 
        */
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* red = head;
        ListNode* green = head->next;
        red->next = green->next;
        green->next = red;
        red->next = swapPairs(red->next);
        return green;
        //��3��
        /*
            
        */
        /*ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;*/

        

        /*
            ������
        */
        //if (head == nullptr || head->next == nullptr) {
        //    return head;
        //}
        //ListNode* newHead = head->next; //��¼���ص�ͷ���
        //ListNode* prev = NULL;
        //ListNode* cur = head;
        //ListNode* next = head->next;
        //ListNode* nextnext = head->next->next;
        //while (cur && next) {
        //    // ���н���
        //    prev = cur;
        //    next->next = cur;
        //    cur->next = nextnext;

        //    //���¶�λ
        //    prev->next = next;
        //    cur = nextnext;
        //    if (cur) {
        //        next = cur->next;
        //    }
        //    if (next) {
        //        nextnext = next->next;
        //    }
        //}
        //return newHead;

        ListNode* dummyHead = new ListNode(0);  //�����ڱ��ڵ�
        ListNode* now = dummyHead;
        dummyHead->next = head;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        while (now->next != nullptr && now->next->next != nullptr) {
            ListNode* l = now->next;
            ListNode* r = now->next->next;
            now->next = r;
            l->next = r->next;
            r->next = l;
            now = l;
        }
        return dummyHead->next;
         //ListNode* dummyHead = new ListNode(0);  //�����ڱ��ڵ�
         //ListNode* newHead = dummyHead;
         //dummyHead->next = head;
         //if (head == nullptr || head->next == nullptr) {
         //    return head;
         //}
         //ListNode* cur = dummyHead;
         //ListNode* next = dummyHead->next;
         //ListNode* nextnext = dummyHead->next->next;
         //while (cur && next)
         //{
         //    dummyHead->next = next;
         //    cur->next = nextnext;
         //    next->next = cur;

         //    dummyHead = cur;
         //       if (dummyHead) {
         //           cur = dummyHead->next;
         //       }
         //       if (dummyHead->next) {
         //           nextnext = dummyHead->next->next;
         //       }


         //}
         //return newHead->next;
    }
};