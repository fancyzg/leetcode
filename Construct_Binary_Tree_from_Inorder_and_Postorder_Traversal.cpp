//File Name  : Construct Binary Tree from Inorder and Postorder Traversal.cpp 
//Author     : Avanty
//Date       : 2014/5/18  9:14PM
//Given inorder and postorder traversal of a tree, construct the binary tree.

//Note:
//You may assume that duplicates do not exist in the tree.
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


TreeNode *build(vector<int> &inorder, int pos1, vector<int> &postorder, int pos2, int num){
    int i,pos,val;
    TreeNode *p;
    if(num == 0) return NULL;
    val = postorder[pos2+num-1];
    p = new TreeNode(val);
    for(i = 0; i < num; i++){
	if(inorder[pos1+i] == val) {
	    pos = pos1 + i;
	    break;
	}
    }
    p->left = build(inorder,pos1,postorder,pos2,pos-pos1);
    p->right = build(inorder,pos+1,postorder, pos2+(pos-pos1), num - (pos-pos1) -1);
    return p;
}

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
	if(inorder.empty()) return NULL;
	return build(inorder,0,postorder,0,inorder.size());
    }
};
