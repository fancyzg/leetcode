//File Name  :Convert Sorted List to BST .cpp 
//Author     : Avanty
//Date       : 2014/5/18  4:50PM
//Description:
//Convert Sorted List to Binary Search Tree Total Accepted: 10719 Total Submissions: 39921 My Submissions
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *ToBST(ListNode *head, int number){
	ListNode *p, *q;
	TreeNode *tp;
	int i, ln, rn;
	if(head == NULL) return NULL;
	if(number == 1){
	    tp = new TreeNode(head->val);
	    return tp;
	}
	ln = number/2;
	rn = number - ln -1;
	p = head;
	for(i = 0; i < ln; i++){
	    q = p;
	    p = p->next;
	}
	q->next = NULL;
	tp = new TreeNode(p->val);
	tp->left = ToBST(head,ln);
	tp->right = ToBST(p->next, rn);
	q->next = p;
	return tp;
    }
	
    TreeNode *sortedListToBST(ListNode *head) {
	int number = 0;
	ListNode *p;
	if(head == NULL) return NULL;
	p = head;
	while(p){
	    number++;
	    p = p->next;
	}
	return ToBST(head,number);
    }
};
