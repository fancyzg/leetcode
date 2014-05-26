//File Name  :Convert Sorted Array to BST.cpp 
//Author     : Avanty
//Date       : 2014/5/18  5:29PM
//Description:
//Convert Sorted Array to Binary Search Tree Total Accepted: 12003 Total Submissions: 37721 My Submissions
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
class Solution {
public:
    TreeNode *ToBST(vector<int> &num, int pos, int number){
	TreeNode *tp;
	int newpos;
	if(number == 0) return NULL;
	if(number == 1){
	    tp = new TreeNode(num[pos]);
	    return tp;
	}
	newpos = pos + number/2;
	tp = new TreeNode(num[newpos]);
	tp->left  = ToBST(num, pos, number/2); 
	tp->right = ToBST(num, newpos+1, number - number/2 -1);
	return tp;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
	int number;
	number = num.size();
	return ToBST(num,0, number);
    }
};
