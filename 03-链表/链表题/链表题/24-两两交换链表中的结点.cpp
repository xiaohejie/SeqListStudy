/*
    给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
    你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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
        //法2：使用递归
        /*
            用 head 表示原始链表的头节点，新的链表的第二个节点，
            用 newHead 表示新的链表的头节点，原始链表的第二个节点，
            则原始链表中的其余节点的头节点是 newHead.next。令 head.next = swapPairs(newHead.next)，
            表示将其余节点进行两两交换，交换后的新的头节点为 head 的下一个节点。
            然后令 newHead.next = head，即完成了所有节点的交换。最后返回新的链表的头节点 newHead。

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
        //法3：
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
            有问题
        */
        //if (head == nullptr || head->next == nullptr) {
        //    return head;
        //}
        //ListNode* newHead = head->next; //记录返回的头结点
        //ListNode* prev = NULL;
        //ListNode* cur = head;
        //ListNode* next = head->next;
        //ListNode* nextnext = head->next->next;
        //while (cur && next) {
        //    // 进行交换
        //    prev = cur;
        //    next->next = cur;
        //    cur->next = nextnext;

        //    //重新定位
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

        ListNode* dummyHead = new ListNode(0);  //创建哨兵节点
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
         //ListNode* dummyHead = new ListNode(0);  //创建哨兵节点
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