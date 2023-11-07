void dfs(int** image, int rows, int cols, int row, int col, int org_color, int color) {
    // left, up, right, down
    if (image[row][col] == color) return;
    image[row][col] = color;

    int r[4] = {0, -1, 0, 1};
    int c[4] = {-1, 0, 1, 0};
    for (int i = 0; i < 4; i++) {
        int m = row + r[i];
        int n = col + c[i];
        if (m >= 0 && m < rows && n >= 0 && n < cols && image[m][n] == org_color) {
            dfs(image, rows, cols, m, n, org_color, color);
        }
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    // imageSize -> rows
    // imageColSize -> cols
    dfs(image, imageSize, *imageColSize, sr, sc, image[sr][sc], color);

    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    return image;
}