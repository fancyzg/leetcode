//File Name  :Convert Sorted Array to BST.cpp 
//Author     : Avanty
//Date       : 2014/5/18  5:29PM
//Description:
//Binary Tree Level Order Traversal II Total Accepted: 10277 Total Submissions: 33192 My Submissions
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
//  [15,7]
//  [9,20],
//  [3],
//]
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//
//
//OJ's Binary Tree Serialization:
//The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
//
//Here's an example:
//   1
//  / \
// 2   3
//    /
//   4
//    \
//     5
//The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
//Have you been asked this question in an interview?  Yes
//Discuss
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
#include<algorithm>
using namespace std;
class Solution{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<int> vec;
	vector<vector<int> > matrix;
	vector<TreeNode *> vecnode;
	TreeNode *p;
	if(root == NULL) return matrix;
	vecnode.push_back(root);
	vecnode.push_back(NULL);
	while(!vecnode.empty()){
	    p = vecnode.front();
	    vecnode.erase(vecnode.begin());
	    if(p != NULL){
		vec.push_back(p->val);
		if(p->left != NULL) vecnode.push_back(p->left);
		if(p->right != NULL) vecnode.push_back(p->right);
	    }
	    else{
		matrix.push_back(vec);
		vec.clear();
		if(!vecnode.empty())
		vecnode.push_back(NULL);
	    }
	}
	reverse(matrix.begin(),matrix.end());
    }
};
