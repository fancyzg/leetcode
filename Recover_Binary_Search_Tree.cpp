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
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void recover(TreeNode *root){
        if(root == NULL) return;
        recover(root->left);
        if(cmp != NULL && cmp->val > root->val){
            vec.push_back(cmp);
            vec.push_back(root);
        }
        cmp = root;
        recover(root->right);
    }
    void recoverTree(TreeNode *root) {
        cmp = NULL;
        recover(root);
        if(vec.size() == 2){
            swap(vec[0]->val,vec[1]->val);
        }
        if(vec.size() == 4){
            swap(vec[0]->val,vec[3]->val);
        }
	vec.clear();
	cmp = NULL;
    }
private:
    vector<TreeNode *> vec;
    TreeNode *cmp;
};

int main(){
    TreeNode a(2),b(3),c(1);
    a.left = &b;
    a.right = &c;
    Solution sl;
    sl.recoverTree(&a);
    cout<<a.val<<" "<<b.val<<" "<<c.val<<endl;
    return 0;
}
