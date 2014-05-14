//File Name  : Sum_Root_to_Leaf.cpp
//Author     : Avanty
//Date       : 2014/5/12  4:19PM
//Decription :
//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void cal_sumnumber(TreeNode *root, int p_sum, int &sum){
	if(root->left == NULL && root->right == NULL){
	    sum = sum + p_sum * 10 + root->val;
	}
	else{
	    if(root->left != NULL)  cal_sumnumber(root->left, p_sum*10 + root->val, sum);
	    if(root->right != NULL) cal_sumnumber(root->right, p_sum*10 + root->val, sum);
	}
    }
    int sumNumbers(TreeNode *root) {
	int sum = 0;
	int p_sum = 0;
	if(root == NULL) return 0;
	cal_sumnumber(root,p_sum,sum);
	return sum;
    }
};

int main(){
    TreeNode a(1),b(2),c(3);
    a.right = &b;
    a.left = &c;
    Solution sl;
    cout<<sl.sumNumbers(&a)<<endl;
    return 0;
}
