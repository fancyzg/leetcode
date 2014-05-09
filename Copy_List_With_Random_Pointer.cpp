//File Name  : COpy_List_With_R.cpp
//Author     : Avanty
//Date       : 2014/5/8  3:10PM
//Decription :
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

//Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//TLE
/*
RandomListNode *addrRandom(RandomListNode *head, int pos_id){
    while(pos_id-- > 0) head = head->next;
    return head;
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
	unordered_map<RandomListNode* ,int> pos;
	unordered_map<RandomListNode* ,int>:: iterator iter;
	RandomListNode *p = head;
	RandomListNode *chead = NULL;
	RandomListNode *cp = NULL;
	int i = 0;
	int pos_id;
	while(p!=NULL){
	    pos[p] = i++;
	    if(chead == NULL){
		chead = new RandomListNode(p->label);
		cp = chead;
	    }
	    else{
		cp->next = new RandomListNode(p->label);
	        cp = cp->next;
	    }
	    p = p->next;
	}
	p = head;
	cp = chead;
	while(p!=NULL){
	    iter = pos.find(p->random);
	    if(iter != pos.end()) cp->random = addrRandom(chead,iter->second);
	    cp = cp->next;
	    p = p->next;
	}
	return chead;
    }
};
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
	unordered_map<RandomListNode * ,RandomListNode *> pos;
	unordered_map<RandomListNode * ,RandomListNode *>:: iterator iter;
	RandomListNode *p = head;
	RandomListNode *chead = NULL;
	RandomListNode *cp = NULL;
	while(p!=NULL){
	    if(chead == NULL){
		chead = new RandomListNode(p->label);
		cp = chead;
		pos[p] = cp;
	    }
	    else{
		cp->next = new RandomListNode(p->label);
	        cp = cp->next;
		pos[p] = cp;
	    }
	    p = p->next;
	}
	p = head;
	cp = chead;
	while(p!=NULL){
	    iter = pos.find(p->random);
	    if(iter != pos.end()) cp->random = iter->second;
	    cp = cp->next;
	    p = p->next;
	}
	return chead;
    }
};
int main(){
    RandomListNode a(1),b(2),c(3),d(4),e(5),f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    a.random = &c;
    b.random = NULL;
    c.random = &e;
    d.random = &f;
    e.random = &b;

    Solution sl;
    RandomListNode * head = sl.copyRandomList(&a);
    RandomListNode *p = head;
    while(p != NULL){
	cout<<p->label<<endl;
	p = p->random;
    }
    return 0;
}
