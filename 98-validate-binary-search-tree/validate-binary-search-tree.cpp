class Solution {
public:
    void helper(TreeNode* root,TreeNode* &prev,bool &flag){
        if(root==NULL) return;
        helper(root->left,prev,flag);
        if(prev!=NULL){
            if(prev->val>=root->val){
                flag=false;
                return;
            }
        }
        prev=root;
        helper(root->right,prev,flag);
    }

    bool isValidBST(TreeNode* root) {
        bool flag=true;
        TreeNode* prev=NULL;
        helper(root,prev,flag);
        return flag;
    }
};