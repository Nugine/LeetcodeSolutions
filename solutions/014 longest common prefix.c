#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define malloc_array(tp, n) (tp *)malloc((n) * sizeof(tp))

inline char *str_slice(char *str, int st, int ed) {
    int l = ed - st;
    char *rv = malloc_array(char, l + 1);
    memcpy(rv, str, l * sizeof(char));
    rv[l] = '\0';
    return rv;
}

char *longestCommonPrefix(char **strs, int strsSize) {
    if(strsSize == 0){
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }

    bool flag = true;
    int j;
    for (j = 0; flag; ++j) {
        for (int i = 0; i < strsSize - 1; ++i) {
            if (strs[i][j] != strs[i + 1][j]) {
                flag = false;
            }
        }
    }
    --j;
    if (j > 0) {
        return str_slice(strs[0], 0, j);
    } else {
        return "";
    }
}
