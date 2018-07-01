/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findBottomLeftValue(struct TreeNode* root) {
    int m=0,v=root->val;
    find(0,root,&m,&v);
    return v;
}

void find(int depth,struct TreeNode* root,int* maxdepth,int* val){
    if((root->left==NULL)&&(root->right==NULL)){
        if(depth>(*maxdepth)){
            *val=root->val;
            *maxdepth=depth;
        }
    }
    if(root->left!=NULL){
        find(depth+1,root->left,maxdepth,val);
    }
    if(root->right!=NULL){
        find(depth+1,root->right,maxdepth,val);
    }
}