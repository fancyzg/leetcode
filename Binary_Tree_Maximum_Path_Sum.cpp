//File Name  : Binary_Tree_Maxmium_Path_Sum.cpp
//Author     : Avanty
//Date       : 2014/5/12  2:23PM
//Decription :
//Binary Tree Maximum Path Sum Total Accepted: 10498 Total Submissions: 53586 My Submissions
//Given a binary tree, find the maximum path sum.
//
//The path may start and end at any node in the tree.
//
//For example:
//Given the below binary tree,
//
//       1
//      / \
//     2   3
//Return 6.
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
#include<limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void maxpath(TreeNode *root, int &max, int &cmax){
	if(root->left == NULL && root->right == NULL){
	    max = root->val;
	    cmax = root->val;
	    return;
	}
	int lmax,rmax,lcmax,rcmax;
	lmax = rcmax = lcmax = rcmax = numeric_limits<int>::min();
	if(root->left != NULL) maxpath(root->left,lmax,lcmax);
	if(root->right != NULL) maxpath(root->right,rmax,rcmax);
	if(lcmax < 0 && rcmax < 0) cmax = root->val;
	else if(lcmax > rcmax) cmax = root->val + lcmax;
	else cmax = root->val + rcmax;
	max = root->val;
	if(lcmax > 0) max = max+lcmax;
	if(rcmax > 0) max = max+rcmax;
	if(max < lmax) max = lmax;
	if(max < rmax) max = rmax;
	return;
    }
    int maxPathSum(TreeNode *root) {
	int max,cmax;
	maxpath(root, max, cmax);
	return max;
    }
};

int main(){
    TreeNode a(1),b(2),c(3);
    a.left = &b;
    //b.right = &c;
    Solution sl;
    cout<<sl.maxPathSum(&a)<<endl;

}
