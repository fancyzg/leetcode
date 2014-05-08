//File Name  : Binary_Tree_Postorder_Travelsal.cpp
//Author     : Avanty
//Date       : 2014/5/8 3:39PM
//Decription :
//Binary Tree Preorder Traversal Total Accepted: 17511 Total Submissions: 50419 My Submissions
//Given a binary tree, return the preorder traversal of its nodes' values.

//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [1,2,3].

#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
	vector<int> preoder;
	vector<TreeNode *> stk;
	TreeNode * cur;
	if(root == NULL) return preoder;
	stk.push_back(root);
	while(stk.size() != 0){
	    cur = stk.back();
	    preoder.push_back(cur->val);
	    stk.pop_back();
	    if(cur->right != NULL) stk.push_back(cur->right);
	    if(cur->left != NULL) stk.push_back(cur->left);
	}
	return preoder;
    }
};

int main(){
    TreeNode a(1),b(2),c(3);
    a.right = &b;
    b.left = &c;
    Solution sl;
    vector<int> vec = sl.preorderTraversal(&a);
    vector<int>:: iterator iter;
    for(iter= vec.begin(); iter != vec.end();iter++){
	cout<<*iter<<endl;
    }
    return 0;
}
