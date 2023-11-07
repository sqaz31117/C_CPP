int dfs(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == -1 || right == -1) return -1;
    if (abs(left-right) > 1) return -1;
    return left > right ? left+1 : right+1;
}

bool isBalanced(struct TreeNode* root) {
    return dfs(root) == -1 ? false : true;
}