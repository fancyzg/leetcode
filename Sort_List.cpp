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
	    ListNode *merge(ListNode *p, ListNode *q, int num)
	    {
		ListNode *head, *r;
		if(p == NULL) return q;
		if(q == NULL) return p;
		if(p->val < q->val) 
		{
		    head = p;
		    r = p;
		    p = p->next;
		}
		else 
		{
		    head = q;
		    r = p;
		    p = p->next;
		}
		while(p && q) 
		{
		    if(p->val < q->val)
		    {
			r->next = p;
			p = p->next;
		    }
		    else
		    {
			r->next = q;
			q =q->next;
		    }
		    r = r->next;
		}
		if(p != NULL)
		    r->next = p;
		if(q != NULL) 
		    r->next = q;
		return head;
	    }
	    ListNode *sortList(ListNode *head) {
		int num, k, len = 0, i = 0, j = 0;
		ListNode * search, p,q,r,tail;
		search = head;
		while(search != NULL)
		{
		    search = search->next;
		    len++;
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
		    for(j = 0; j < num; j = j + 2^(i+1))
		    {
			p = head;
			ihead = tail;
			for(k = 0; k < 2^i-1; k++)
			{
			    p = p->next;
			}
			q = p->next;
			p ->next = NULL;
			r = q;
			for(k = 0; k < 2^i-1; k++)
			{
			    r = r->next;
			}
			tail = r->next;
			r->next = NULL;
			if (j = 0) head = merge(p,q);
			else
			{
			    ihead->next = merge(p,q);


			}

			

		    }

		}


		        
		    }
};
