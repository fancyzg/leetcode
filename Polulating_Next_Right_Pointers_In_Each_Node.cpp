//File Name  : Polulating_Next_right_Pointers_In_Each_Node.cpp
//Author     : Avanty
//Date       : 2014/5/16  7:23PM
//Decription :
//Populating Next Right Pointers in Each Node
//Total Accepted: 13837 Total Submissions: 40062
//
//Given a binary tree
//
//    struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//    }
//
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//    You may only use constant extra space.
//    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//
//For example,
//Given the following perfect binary tree,
//
//         1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
//
//After calling your function, the tree should look like:
//
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL
//
//Have you been asked this question in an interview?

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
	TreeLinkNode *p,q,r;
	p = root;
	while(p->left != NULL){
	    q = p;
	    p->left->next = p->right;
	    while(p->next != NULL){
		r = p;
		p = p->next;
		r->right->next = p->left;
		p->left->next = p->right;
	    }
	    p = q;
	    p = p->left;
	}
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL || root->left == NULL || root->right == NULL) return;
        root->left->next = root->right;
        if(root->next != NULL && root->right != NULL){
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
