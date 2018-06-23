int singleNumber(int *nums, int numsSize) {
    int rv = 0;
    for (int i = 0; i < numsSize; ++i) {
        rv ^= nums[i];
    }
    return rv;
}