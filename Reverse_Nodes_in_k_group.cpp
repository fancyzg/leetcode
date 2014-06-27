//File Name  : Reverse Nodes in k-Group.cpp
//Author     : Avanty
//Date       : 2014/6/25/ 3:37PM
//Decription :
//Reverse Nodes in k-Group Total Accepted: 9712 Total Submissions: 39043 My Submissions
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k){
	int i;
        if(k == 1 || head == NULL) return head;
	ListNode *p,*q,*r,*thead,*ttail,*oldhead, *oldtail;
	thead = ttail =oldtail= oldhead= NULL;
	p = head;
	head = NULL;
	while(p != NULL){
	    oldtail = ttail;
	    ttail = p;
	    i = 1;
	    while(i < k && p->next != NULL){
		p = p->next;
		i++;
	    }
	    if(i < k) break;
	    p = ttail;
	    q = p->next;
	    r = q->next;
	    i = 1;
	    while(i < k){
		q->next = p;
		p = q;
		q = r;
		if(r != NULL) r = r->next;
		i++;
	    }
	    if(head == NULL) head = p;
	    else oldtail->next = p;
	    p = q;
	}
	if(i ==k ){
	    ttail->next = NULL;
	}
	else{ 
	    if(head == NULL) head = ttail;
	    else oldtail->next = ttail;
	}
	return head;
    }
};

int main(){
    Solution sl;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    ListNode *head = sl.reverseKGroup(&a,2);
    while(head != NULL) {
	cout<<head->val<<endl;
	head = head->next;
    }
    return 0;
}
