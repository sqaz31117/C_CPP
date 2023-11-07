int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        int mid = l + (r-l)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return -1;
}