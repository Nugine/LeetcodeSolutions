/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **generate(int numRows, int **columnSizes) {
    int **rv = (int **)malloc(sizeof(int *) * numRows);
    int *cSs = (int *)malloc(sizeof(int) * numRows);
    int i;
    for (i = 0; i < numRows; ++i) {
        cSs[i] = i + 1;
        rv[i] = (int *)malloc(sizeof(int) * cSs[i]);
    }
    *columnSizes = cSs;
    if (numRows == 0) {
        return rv;
    }
    int j, k;
    int *row1, *row2;
    rv[0][0] = 1;
    row1 = rv[0];
    for (j = 1; j < numRows; ++j) {
        row2 = rv[j];
        row2[0] = 1;
        i = cSs[j] - 1;
        row2[i] = 1;
        for (k = 1; k < i; ++k) {
            row2[k] = row1[k - 1] + row1[k];
        }
        row1 = row2;
    }
    return rv;
}