#include <stdbool.h>
#define ord_U 85
#define ord_D 68
#define ord_L 76
#define ord_R 82

#define jc_case(ord, stat)                                                     \
    if (!(c ^ ord)) {                                                          \
        stat;                                                                  \
        continue;                                                              \
    }

bool judgeCircle(char *moves) {
    int x = 0, y = 0, i = 0;
    char *pc = moves;
    char c;
    for (c = *pc; c != '\0'; c = *(++pc)) {
        jc_case(ord_U, ++y);
        jc_case(ord_D, --y);
        jc_case(ord_L, --x);
        jc_case(ord_R, ++x);
    }
    if ((!x) && (!y)) {
        return true;
    } else {
        return false;
    }
}
