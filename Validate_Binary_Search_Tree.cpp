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
    Solution(int x = numeric_limits<int>::min()){cmp_node = x;}
    bool isValidBST(TreeNode *root) {
        bool b1,b2;
        if(root == NULL) return true;
        b1 = isValidBST(root->left);
        if(root->val <= cmp_node) return false;
        cmp_node = root->val;
        b2 = isValidBST(root->right);
        return b1&&b2;
    }
private:
    int cmp_node;
};

int main(){
    TreeNode a(0),b(-1);
    a.left = &b;
    Solution sl;
    cout<<sl.isValidBST(&a)<<endl;
    return 0;
}
