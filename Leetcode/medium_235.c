struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == p || root == q || root == NULL) return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left == NULL && right != NULL) return right;
    if (left != NULL && right == NULL) return left;
    if (left != NULL && right != NULL) return root;
    return NULL;
}