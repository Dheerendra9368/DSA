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
    int tchild(TreeNode* root){
        if(root==NULL) return 0;
        else return tchild(root->left)+tchild(root->right)+1;
    }

    int Sum(TreeNode* root,int &ans){
        if(root==NULL) return 0;
        else{
            int leftsum=Sum(root->left,ans);
            int rightsum=Sum(root->right,ans);
            int n=tchild(root);
            if((root->val+leftsum+rightsum)/n==root->val) ans++;
            return root->val+leftsum+rightsum;
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        Sum(root,ans);
        return ans;
    }
};