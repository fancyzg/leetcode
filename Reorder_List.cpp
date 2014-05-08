//File Name  : Binary_Tree_Postorder_Travelsal.cpp
//Author     : Avanty
//Date       : 2014/5/8  3:55PM
//Decription :
//Given a singly linked list L: L0→ L1→ …→ Ln-1 → Ln,
//reorder it to: L0 → Ln→ L1→ Ln-1→ L2→ Ln-2→ …
//You must do this in-place without altering the nodes' values.
//For example, //Given {1,2,3,4}, reorder it to {1,4,2,3}.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//method:from n/2+n%2+1 - n reverse, and merge

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int list_len(ListNode * head){
    int len = 0;
    while(head){
	len++;
	head = head->next;
    }
    return len;
}

ListNode * reverseList(ListNode * head){
    ListNode *p,*q,*r;
    if(head == NULL) return NULL;
    p = head;
    q = p->next;
    head->next = NULL;
    while(q != NULL){
	r = q->next;
	q->next = p;
	p = q;
	q = r;
    }
    return p;
}

ListNode * mergeList(ListNode *first, ListNode *second){
    ListNode *head,*p,*q;
    bool mset = false;
    if(first == NULL ) return NULL;
    head = first;
    p = head;
    first = first->next;
    while(first != NULL || second != NULL){
	if(mset){
	    p->next = first;
	    p = p->next;
	    first = first->next;
	    mset = false;
	}
	else{
	    p->next = second;
	    p = p->next;
	    second = second->next;
	    mset = true;
	}
    }
}


class Solution {
public:
    void reorderList(ListNode *head) {
       int i,len,mid;
       ListNode *p,*q,*second;
       len = list_len(head);
       mid = len/2 + len%2;
       p = head;
       i = 0;
       while(p){
	   q = p;
	   p=p->next;
	   if(++i == mid){
	       q->next = NULL;
	       break;
	   }
       }
       second = reverseList(p);
       mergeList(head,second);
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
    Solution sl;
    sl.reorderList(&a);
    p = &a; 
    while(p != NULL ){
	cout<<p->val<<endl;
	p = p->next;
    }
    return 0;
}
