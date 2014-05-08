//File Name  : Binary_Tree_Postorder_Travelsal.cpp
//Author     : Avanty
//Date       : 2014/5/7 12:00AM
//Decription :
//Given a binary tree, return the postorder traversal of its nodes' values.
//For example:
//Given binary tree {1,#,2,3},
//         1
//	    \
//	     2
//	    /
//         3
//return [3,2,1].

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
/*
class Solution {
    public:
	    vector<int> postorderTraversal(TreeNode *root) {
		if(root->left  != NULL) postorderTraversal(root->left); 
		if(root->right != NULL) postorderTraversal(root->right); 
		porder.push_back(root->val);
		return porder;
	    }
    private:
	vector<int> porder;
};
*/
class Solution {
    public:
	    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> porder;
		vector<TreeNode*> stk;
		TreeNode *tmp,*pre;
		if(root == NULL) return porder;
		stk.push_back(root);
		while(stk.size() != 0){
		    tmp = stk[stk.size()-1];
		    if((tmp->left == NULL && tmp->right == NULL) || ( pre == tmp->left|| pre == tmp->right)){
			porder.push_back(tmp->val);
			stk.pop_back();
			pre = tmp;
		    }
		    else{
			if(tmp->right != NULL) stk.push_back(tmp->right);
			if(tmp->left != NULL) stk.push_back(tmp->left);
		    }
		}
		return porder;
	    }
};

int main(){
    TreeNode a(1),b(2),c(3);
    a.right = &b;
    b.left = &c;
    Solution sl;
    vector<int> vec = sl.postorderTraversal(&a);
    vector<int>:: iterator iter;
    for(iter= vec.begin(); iter != vec.end();iter++){
	cout<<*iter<<endl;
    }
    return 0;
}
