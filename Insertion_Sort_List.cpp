/**
 *File Name: Insertion_Sort_List.cpp
 *Author:Avanty
 *Date:2014-3-23
 *Descriptions:
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
	    ListNode *insertionSortList(ListNode *head) {
		ListNode *p,*l_p,*n_p,*q,*r;
		ListNode *m,*n;
		p = head;
		l_p = p;
		while(p)
		{
		    n_p = p->next;
		    q = head;
		    r = q;
		    while(p->val > q->val)
		    {
			r = q;
			q = q->next;
		    }
		    if(p == q)	
		    {
		        l_p = p;
			p = n_p;
			continue;
		    }
		    l_p->next = n_p;
		    if(q == head)
		    {
			head = p;
			p->next = r;
		    }
		    else
		    {
			p->next = r->next;
			r->next = p;
		    }
		    p = n_p;
		}
		return head;
		    }
};

int main()
{
    ListNode *head,*p,*q;
    p = new ListNode(11);
    int i = 0;
    head = p;
    q = p;
    while(i < 10)
    {

	p = new ListNode(i);
	q->next = p;
	q = p;
	p = p->next;
	i++;
    }
    Solution sl;
    head =  sl.insertionSortList(head);
    p = head;
    while(p)
    {
	cout<<p->val<<" "<<endl;
	p = p->next;
    }
    return 0;
}
