#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int l, int mid, int r) {
    const int lens = r-l+1;
    int* tmp = (int*)malloc(sizeof(int) * lens);
    int ll = l;
    int rl = mid+1;
    int cur = 0;

    while (ll <= mid && rl <= r) {
        if (nums[ll] < nums[rl]) {
            tmp[cur++] = nums[ll++];
        }
        else {
            tmp[cur++] = nums[rl++];
        }
    }

    while (ll <= mid) {
        tmp[cur++] = nums[ll++];
    }

    while (rl <= r) {
        tmp[cur++] = nums[rl++];
    }

    ll = l;
    for (int i = 0; i < cur; i++) {
        nums[ll++] = tmp[i];
    }
    free(tmp);
}

void mergeSort(int* nums, int l, int r) {
    if (l < r) {
        int mid = l + (r-l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
}

int main() {
    int nums[] = {-2, 0, -10, 7, 9, 20, -5};
    int len = sizeof(nums) / sizeof(int);
    mergeSort(nums, 0, len-1);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}