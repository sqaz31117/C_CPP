void swap(int* a, int* b) {
    if (*a == *b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void moveZeroes(int* nums, int numsSize) {
    for (int i = 0, pntToZero = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            swap(&nums[i], &nums[pntToZero++]);
        }
    }
}