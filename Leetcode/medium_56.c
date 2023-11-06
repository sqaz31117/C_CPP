int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int** ans = (int**)malloc(sizeof(int*)*intervalsSize);
    ans[0] = intervals[0];
    int Size = 1;

    for (int i = 1; i < intervalsSize; i++) {
        if (ans[Size-1][1] >= intervals[i][0]) {
            ans[Size-1][1] = ans[Size-1][1] > intervals[i][1] ? ans[Size-1][1] : intervals[i][1];
        }
        else {
            ans[Size++] = intervals[i];
        }
    }

    *returnSize = Size;
    // *returnColumnSizes -> point to an (int*)array
    *returnColumnSizes = (int*)malloc(sizeof(int)*Size);
    for (int i = 0; i < Size; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}