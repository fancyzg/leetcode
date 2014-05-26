//File Name  : Polulating_Next_Right_Poniter_In_Each_Node_II.cpp
//Author     : Avanty
//Date       : 2014/5/18  12:32PM
//Decription :
//Populating Next Right Pointers in Each Node II Total Accepted: 9868 Total Submissions: 33524 My Submissions
//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree? Would your previous solution still work?
//
//Note:
//
//You may only use constant extra space.
//For example,
//Given the following binary tree,
//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL
//
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
	if(root == NULL) return;
	TreeLinkNode *p,*q,*r;
	p = root;
	while(p){
	    q = p;
	    while(q){
		if(q->left != NULL && q->right != NULL) q->left->next = q->right;
		else if( q->left == NULL && q->right == NULL){
		    q = q->next;
		    continue;
		}
		r = q->right;
		if(r == NULL) r = q->left;
		while(q->next != NULL){
		if(q->next->left == NULL && q->next->right == NULL) q = q->next;
		else{
		    r->next = q->next->left;
		    if(q->next->left == NULL) r->next = q->next->right;
		    break;
		}
		}
		q = q->next;
	    }
	    while(p){
		if(p->left == NULL && p->right == NULL) p = p->next;
		else{
		    if(p->left != NULL) p = p->left;
		    else p = p->right;
		    break;
		}
	    }
	}
    }
};
