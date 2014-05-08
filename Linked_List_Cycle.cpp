//File Name  : Binary_Tree_Postorder_Travelsal.cpp
//Author     : Avanty
//Date       : 2014/5/8  10:29PM
//Decription :
//Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
	ListNode * fast, *slow;
	fast = slow = head;
	bool flag = true;
	if(head == NULL) return NULL;
	while(flag == true || fast != slow){
	    if(flag == true) flag = false;
	    if(fast->next != NULL && fast->next->next != NULL) fast = fast->next->next;
	    else return false;
	    slow = slow->next;
	}
	return true;
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
//    f.next = &f;
    Solution sl;
    cout<< sl.hasCycle(&a)<<endl;
    return 0;
}
