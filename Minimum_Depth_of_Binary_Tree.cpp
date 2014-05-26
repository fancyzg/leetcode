//File Name  :Minimum Depth of Binary Tree.cpp 
//Author     : Avanty
//Date       : 2014/5/18  3:22PM
//Decription :
//

//Minimum Depth of Binary Tree Total Accepted: 13038 Total Submissions: 45023 My Submissions
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Have you been asked this question in an interview?  Yes
//Discuss

/**
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
    int minDepth(TreeNode *root) {
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
    if(root->left != NULL && root->right != NULL) return 1+min(minDepth(root->left), minDepth(root->right));
	else if(root->left != NULL) return 1+minDepth(root->left);
	else return 1+minDepth(root->right);
    }
};
