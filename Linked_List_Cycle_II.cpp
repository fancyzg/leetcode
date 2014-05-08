//File Name  : Binary_Tree_Postorder_Travelsal.cpp
//Author     : Avanty
//Date       : 2014/5/8  9:31PM
//Decription :
//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

//Follow up:
//Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
	ListNode *fast, *slow;
	ListNode *cmp1, *cmp2;
	int flag = 0;
	slow = head;
	fast = head;
	if (head == NULL) return NULL;
	while(fast != slow || flag == 0){
	    if(flag == 0) flag = 1;
	    if( fast->next != NULL && fast->next->next != NULL) fast = fast->next->next;
	    else return NULL;
	    slow = slow->next;
	}

	cmp1 = head;
	cmp2 = slow;
	while(cmp1 != cmp2){
	    cmp1 = cmp1->next;
	    cmp2 = cmp2->next;
	}
	return cmp1;
    }
};

int main(){

    ListNode a(1),b(2),c(3),d(4),e(5),f(6);
    ListNode *p;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &f;
    Solution sl;
    p = sl.detectCycle(&a);
    if(p!=NULL)cout<<p->val<<endl;
    return 0;
}
