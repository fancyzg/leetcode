//File Name  : Implement strStr.cpp
//Author     : Avanty
//Date       : 2014/6/24/ 12:25AM
//Decription :
//Remove Nth Node From End of List Total Accepted: 14516 Total Submissions: 49264 My Submissions
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *p, *q, *r;
	int i;
	p = head;
	for(i = 0; i < n; i++) p = p->next;
	if(p == NULL){
	    p = head;
	    head = head->next;
	    delete p;
	}
	else{
	    q = head;
	    r = head->next;
	    while(p->next != NULL){
		p = p->next;
		q = r;
		r = r->next;
	    }
	    q->next = r->next;
	    delete r;
	}
	return head;
    }
};

int main(){
    Solution sl;
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next == NULL;
    head = sl.removeNthFromEnd(head,1);
    while(head != NULL) { cout<<head->val<<" "<<endl; head = head->next;}
    return 0;
}
