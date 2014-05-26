//File Name  :Balanced Binary Tree .cpp 
//Author     : Avanty
//Date       : 2014/5/18  2:36PM
//Balanced Binary Tree Total Accepted: 13915 Total Submissions: 43428 My Submissions
//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Have you been asked this question in an interview? 
/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int hightree(TreeNode *root, bool &balance){
	int hl,hr;
	if(root == NULL) return 0; 
	hl = hightree(root->left,balance);
	hr = hightree(root->right,balance);
	if(hl - hr >1 || hl - hr < -1) balance = false;
	return 1+max(hl,hr);
    }
    bool isBalanced(TreeNode *root) {
	bool balance;
	hightree(root, balance);
	return balance;
    }
};
