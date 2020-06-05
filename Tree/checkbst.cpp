bool bst(Node* root,int l,int h){
    if(root == NULL)
        return true;
    else if(root->data > l && root->data < h){
        if(root->left != NULL && root->right != NULL){
            if(root->data > root->left->data && root->data < root->right->data)
                return bst(root->left,l,root->data) & bst(root->right,root->data,h);
            else
                return false;
        }else if(root->left != NULL){
            if(root->data > root->left->data)
                return bst(root->left,l,root->data);
            else
                return false;

        }else if(root->right != NULL){
            if(root->data < root->right->data)
                return bst(root->right,root->data,h);
            else
                return false;
        }else
            return true;


    }else{
        return false;
    }
}

bool isBST(Node* root) {
    // Your code here
    return bst(root,INT_MIN,INT_MAX);
}
