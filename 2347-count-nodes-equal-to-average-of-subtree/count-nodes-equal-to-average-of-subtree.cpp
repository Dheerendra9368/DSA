/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int,int> f(TreeNode* root,int &ans){
        if(root==NULL) return {0,0};
        else{
            auto lefttree=f(root->left,ans);
            auto righttree=f(root->right,ans);
            int n=1+lefttree.second+righttree.second;
            int sum=root->val+lefttree.first+righttree.first;
            if(sum/n==root->val) ans++;
            return {sum,n};
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};