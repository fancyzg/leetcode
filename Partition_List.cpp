//File Name  : Partition List .cpp 
//Author     : Avanty
//Date       : 2014/5/23  10:08AM
//Description:
//Partition List Total Accepted: 10001 Total Submissions: 38075 My Submissions
//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.
//
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
    ListNode *partition(ListNode *head, int x) {
	ListNode *h1,*h2,*p,*q,*r;
	h1 = h2 = p = q = NULL;
	while(head!=NULL){
	    if(head->val < x){
		if(h1 == NULL){
		    h1 = head;
		    p = h1;
		}
		else{
		    p->next = head;
	            p = p->next;
		}
	    }
	    else{
		if(h2 == NULL){
		    h2 = head;
		    q = h2;
		}
		else{
		    q->next = head;
	            q = q->next;
		}
	    }
	    head = head->next;
	}
	if(p != NULL) p->next = h2;
	if(q != NULL) q->next = NULL;
	if(h1 == NULL) return h2;
	return h1;
    }
};

int main(){
    ListNode a(2),b(1);
    a.next = &b;
    Solution sl;
    ListNode *p, *q;
    p = sl.partition(&a,2);
    while(p!=NULL) {
	cout<<p->val;
	p=p->next;
    }
    return 0;
}
