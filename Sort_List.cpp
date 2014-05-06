/**
 *File name:Sort_List.cpp
 *Author:Avanty
 *Date:2014-3-21
 *Descriptions:
 *Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
	    ListNode *merge(ListNode *p, ListNode *q,ListNode *& w)
	    {
		ListNode *head, *r;
		if(p == NULL)
		{
		    r = q;
		    while(r->next != NULL) r = r->next;
		    w = r;
		    return q;
		}
		if(q == NULL)
		{
		    r = p;
		    while(r->next != NULL) r = r->next;
		    w = r;
		    return p;
		}

		if(p->val <= q->val) 
		{
		    head = p;
		    r = p;
		    p = p->next;
		}
		else 
		{
		    head = q;
		    r = q;
		    q = q->next;
		}
		while(p && q) 
		{
		    if(p->val <= q->val)
		    {
			r->next = p;
			p = p->next;
		    }
		    else
		    {
			r->next = q;
			q = q->next;
		    }
		    r = r->next;
		}
		if(p != NULL)
		    r->next = p;
		if(q != NULL) 
		    r->next = q;
		while(r->next != NULL) r = r->next;
		w = r;
		ListNode * test = head;
		return head;
	    }

	    ListNode *sortList(ListNode *head) {
		int num, k, len = 0, i = 0, j = 0;
		ListNode * search, *p,*q,*r,*tail,*ihead,*w;
		search = head;
		while(search != NULL)
		{
		    len++;
		    search = search->next;
		}
		i = len;
		while(i != 0)
		{
		    i>>=1;
		    j++;
		}
		num = j;
		for(i = 0; i < num; i++)
		{
		    p = head;
		    for(j = 0; j <= len; j = j + pow(2,i+1))
		    {
			q = p;
			for(k = 0; k < pow(2,i) -1; k++)
			{
			    if(q != NULL) q = q->next;
			}
			if(q == NULL) 
			{
			    tail = NULL;
			    goto Label;
			}
			r = q->next;
			q ->next = NULL;
			q = r;
			for(k = 0; k < pow(2,i) -1; k++)
			{
			   if(r != NULL) r = r->next;
			}
			if(r != NULL)
			{
			   tail = r->next;
			   r->next = NULL;
			}
			else
			{
			  tail = NULL;
			}
                Label:  if (j == 0) 
			{
			    head = merge(p,q,w);
			    ihead = w;
			}
			else
			{
			    ihead->next = merge(p,q,w);
			    ihead = w;
			}
			p = tail;
			if(tail == NULL) break;
		    }
		}
		return head;
	}
};

int main(){
    ListNode a(4),b(19),c(5),d(14),e(-3),f(1),g(5),h(8),i(11),j(15);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    h.next = &i;
    i.next = &j;
    ListNode *p = &a;
    while(p != NULL ){
	cout<<p->val<<endl;
	p = p->next;
    }
    Solution sl;
//    ListNode *w;
//    p = sl.merge(&a,NULL,w);
    p = sl.sortList(&a);
   // cout<<w->val<<endl;
    while(p != NULL ){
	cout<<p->val<<endl;
	p = p->next;
    }
    return 0;
}
