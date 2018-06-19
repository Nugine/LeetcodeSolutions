/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numberOfLines(int *widths, int widthsSize, char *S, int *returnSize) {
    int *rv = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    rv[0] = 0;

    int line_room = 100, wid;
    char c = S[0];
    for (int i = 0; c != '\0'; c = S[++i]) {
        wid = widths[c - 97];
        if (line_room < wid) {
            ++rv[0];
            line_room = 100 - wid;
        } else {
            line_room -= wid;
        }
    }
    rv[1] = 100 - line_room;
    return rv;
}