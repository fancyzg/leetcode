/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *p, *q, *p_pre;
        bool ifdel = false;
        p = head;
        while(p!=NULL && p->next != NULL){
            if(p->val == p->next->val) {
                q = p->next;
                p->next = p->next->next;
                delete q;
                ifdel = true;
                continue;
            }
            if(ifdel) {
                if(p == head){
                    head = p->next;
                    delete p;
                    p = head;
                }
                else{
                     p_pre->next = p->next;
                     delete p;
                     p = p_pre->next;
                }
                ifdel = false;
                continue;
            }
            p_pre = p;
            p = p->next;
        }
        
        if(ifdel && p != NULL){
	    delete p;
            if(p == head) return NULL;
	    p_pre->next = NULL;
	}
        return head;
    }
};
int main(){
    Solution sl;
    ListNode a(1),b(2),c(2);
    return 0;
}
