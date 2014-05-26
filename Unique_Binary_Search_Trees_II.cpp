//File Name  : Unique_BInary_Search_Trees_II.cpp 
//Author     : Avanty
//Date       : 2014/5/20  10:56AM
//Description:
//Unique Binary Search Trees II Total Accepted: 7649 Total Submissions: 28723 My Submissions
//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<TreeNode *> gen(int start, int end){
	int i,j,k;
	TreeNode *root;
	vector<TreeNode *> ret,vecleft,vecright;
	if(start > end) return vector<TreeNode *>(1,nullptr);
	for(i = start; i <= end; i++){
	    vecleft = gen(start, i-1);
	    vecright = gen(i+1, end);
	    for(j = 0; j < vecleft.size(); j++){
		for(k = 0; k < vecright.size(); k++){
		    root = new TreeNode(i);
		    root->left = vecleft[j];
		    root->right = vecright[k];
		    ret.push_back(root);
		}
	    }
	}
	return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
       return gen(1,n); 
    }
};

int main(){

    return 0;
}
