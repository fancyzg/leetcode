//File Name  :Flatten Binary Tree .cpp 
//Author     : Avanty
//Date       : 2014/5/18  2:36PM
//Decription :
//Flatten Binary Tree to Linked List Total Accepted: 12359 Total Submissions: 45623 My Submissions
//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
//
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
	TreeNode *p;
	if(root == NULL) return;
	if(root->left != NULL) flatten(root->left);
	if(root->right != NULL) flatten(root->right);
	if(root->left != NULL){
	    if(root->right != NULL){
		p = root->left;
		while(p->right != NULL) p = p->right;
		p->right = root->right;
	    }
	    root->right = root->left;
	    root->left = NULL;
	}
    }
};
