struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* minValueNode(TreeNode* root) {
    if (root == NULL) return NULL;

    if (root->left == NULL) return root;
    else return minValueNode(root->left);
}
    
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;
        
    if (root->val > key) root->left = deleteNode(root->left, key);
    else if (root->val < key) root->right = deleteNode(root->right, key);
    else  {
        if (root->right == NULL) {
            TreeNode* tmp = root->left;
            delete(root);
            return tmp;
        } else if (root->right->left == NULL) {
            TreeNode* tmp_r = root->right;
            TreeNode* tmp_l = root->left;
            delete(root);
            tmp_r->left = tmp_l;
            return tmp_r;
        } else {
            TreeNode* node = minValueNode(root->right);
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
        }
    }
    
    return root;
}

// Особые случаи:
// -- пустое дерево
// -- key за пределами дерева
// -- корень дерева
// -- освобождение памяти
