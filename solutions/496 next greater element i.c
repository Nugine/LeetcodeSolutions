/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
int *nextGreaterElement(int *findNums, int findNumsSize, int *nums,
                        int numsSize, int *returnSize) {
    int i, j, n, m;
    n = sizeof(int) * findNumsSize;
    int *rv = (int *)malloc(n);

    for (i = 0; i < findNumsSize; ++i) {
        n = findNums[i];
        for (j = 0; j < numsSize; ++j) {
            if (nums[j] == n) {
                break;
            }
        }
        m = -1;
        for (; j < numsSize; ++j) {
            if (nums[j] > n) {
                m = nums[j];
                break;
            }
        }
        rv[i] = m;
    }
    *returnSize = findNumsSize;
    return rv;
}