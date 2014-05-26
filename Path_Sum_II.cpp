//File Name  :Path Sum II.cpp 
//Author     : Avanty
//Date       : 2014/5/18  2:59PM
//Decription :
//
//Path Sum II Total Accepted: 11454 Total Submissions: 41897 My Submissions
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]
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

class Solution {
public:
    void haspathsum(TreeNode *root, int sum, vector<vector<int> > &m, vector<int> &v){
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL && sum == root->val){ 
	    v.push_back(sum);
	    m.push_back(v);
	    v.pop_back();
	}
	else{
		v.push_back(root->val);
		haspathsum(root->left, sum - root->val, m, v);
		haspathsum(root->right, sum - root->val, m, v);
		v.pop_back();
	}
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > matrix;
	vector<int> vec;
	haspathsum(root,sum,matrix,vec);
	return matrix;
    }
};
