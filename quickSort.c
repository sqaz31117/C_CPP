#include <stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    if (*a == *b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int partition(int* nums, int l, int r) {
    int pivot = nums[r];
    int j = l;
    for (int i = l; i < r; i++) {
        if (nums[i] < pivot) {
            swap(&nums[i], &nums[j++]);
        }
    }
    swap(&nums[j], &nums[r]);
    return j;
}

void quickSort(int* nums, int l, int r) {
    if (l < r) {
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot-1);
        quickSort(nums, pivot+1, r);
    }
}

int main() {
    int nums[] = {-2, 0, -10, 7, 9, 20, -5};
    int len = sizeof(nums) / sizeof(int);
    quickSort(nums, 0, len-1);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}