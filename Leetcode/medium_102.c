int dfs(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    int tmp = left > right ? left : right;
    return tmp+1;
}

void traversal(struct TreeNode* root, int** ans, int* arr, int depth) {
    if (root == NULL) return;
    if (!arr[depth]) {
        ans[depth] = (int*)malloc((depth > 10 ? 1024 : 1 << depth)*sizeof(int));
    }
    ans[depth][arr[depth]++] = root->val;
    traversal(root->left, ans, arr, depth+1);
    traversal(root->right, ans, arr, depth+1);
}

// returnSize -> levels
// returnColumnSizes -> # of nodes in each level
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = dfs(root);
    int** ans = (int**)malloc((*returnSize)*sizeof(int*));
    *returnColumnSizes = (int*)calloc(*returnSize, sizeof(int));
    traversal(root, ans, *returnColumnSizes, 0);
    return ans;
}