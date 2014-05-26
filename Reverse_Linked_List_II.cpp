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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int i,j,acc = 0;
        ListNode *p,*q,*r,*tail,*s;
        if(m == n) return head;
        p = head;
        if(m > 1){
            for(i = 1; i < m-1; i++) p=p->next;
            q = p->next;
        }
        else q = p;
        tail = q;
        r = q->next;
        q->next = NULL;
        for(i = 0; i < n-m; i++){
            s = r->next;
            r->next = q;
            q = r;
            r = s;
        }
        
        tail->next = r;
        if(m > 1){
            p->next = q;
            return head;
        } 
        else return q;
    }
};
int main(){
   Solution sl;
   ListNode a(3),b(5),c(1),d(2);
   a.next = &b;
   b.next = &c;
   c.next = &d;
   ListNode *p = &a;
   p = sl.reverseBetween(&a,3,4);
   while(p!=NULL){ cout<<p->val<<endl; p=p->next;}
   return 0;
}
