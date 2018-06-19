/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
int *shortestToChar(char *S, char C, int *returnSize) {
    int sl = strlen(S);
    *returnSize = sl;
    int *tmp = (int *)malloc(sizeof(int) * sl);
    int *rv = (int *)malloc(sizeof(int) * sl);
    int i, j, k = 0, l, h, m;

    for (i = 0; i < sl; ++i) {
        if (S[i] == C) {
            tmp[k] = i;
            ++k;
        }
    }
    i = tmp[0];
    for (j = 0; j <= i; ++j) {
        rv[j] = i - j;
    }
    i = tmp[k - 1];
    for (j = i; j < sl; ++j) {
        rv[j] = j - i;
    }
    for (l = 0; l < k - 1; ++l) {
        i = tmp[l];
        j = tmp[l + 1];
        m = (j - i) >> 1;
        for (h = 0; h <= m; ++h) {
            rv[j - h] = h;
            rv[i + h] = h;
        }
    }
    return rv;
}