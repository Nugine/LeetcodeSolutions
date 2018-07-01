/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    int s=0;
    if(root!=NULL){
        _soll(root,&s);
    }
    return s;
}

void _soll(struct TreeNode* root,int *s){
    if(root->left!=NULL){
        if(root->left->left==NULL&&root->left->right==NULL){
            (*s)+=root->left->val;
        }
        else{
            _soll(root->left,s);
        }
    }
    if(root->right!=NULL){
        _soll(root->right,s);
    }
}