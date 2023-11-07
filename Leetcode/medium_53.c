int maxSubArray(int* nums, int numsSize) {
    int maxVal = nums[0];
    int curVal = nums[0];

    for (int i = 1; i < numsSize; i++) {
        curVal = curVal + nums[i] > nums[i] ? curVal + nums[i] : nums[i];
        maxVal = maxVal > curVal ? maxVal : curVal;
    }
    return maxVal;
}