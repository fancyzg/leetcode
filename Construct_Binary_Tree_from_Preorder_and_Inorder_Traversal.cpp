//File Name  : Construct Binary Tree from Inorder and Postorder Traversal.cpp 
//Author     : Avanty
//Date       : 2014/5/18  10:53PM
//Description:
//Construct Binary Tree from Preorder and Inorder Traversal Total Accepted: 8479 Total Submissions: 33176 My Submissions
//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
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
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *build(vector<int> &preorder, int pos1, vector<int> &inorder, int pos2, int num){
    int i, pos, val;
    TreeNode *p;
    if(num == 0) return NULL;
    val = preorder[pos1];
    for(i = 0; i < num; i++){
	if(inorder[pos2+i] == val){
	    pos = pos2+i;
	    break;
	}
    }
    p = new TreeNode(val);
    p->left =  build(preorder, pos1+1, inorder,pos2, pos-pos2);
    p->right = build(preorder, pos1+(pos-pos2)+1, inorder,pos+1, num - 1 - (pos-pos2));
    return p;
}

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return build(preorder,0,inorder,0,preorder.size());
    }
};
