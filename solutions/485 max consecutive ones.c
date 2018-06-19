#define max(a, b) (((a) > (b)) ? (a) : (b))
int findMaxConsecutiveOnes(int *nums, int numsSize) {
    int i, j, max_len = 0;
    for (i = 0; nums[i] == 0 && i < numsSize; ++i) {
    }
    while (i < numsSize) {
        for (j = i + 1; j < numsSize;) {
            if (nums[j] == 0) {
                break;
            } else {
                ++j;
            }
        }
        max_len = max(j - i, max_len);
        for (i = j; i < numsSize;) {
            if (nums[i] == 0) {
                ++i;
            } else {
                break;
            }
        }
    }
    return max_len;
}
