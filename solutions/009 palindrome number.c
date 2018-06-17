// #include <stdbool.h>
// #include <stdio.h>

#include <stdlib.h>

int *digits_of_int(int x) {
    int *rv = (int *)malloc(11 * sizeof(int));
    int n;
    for (n = 0; x != 0; ++n) {
        rv[n + 1] = x % 10;
        x /= 10;
    }
    rv[0] = n;
    return rv;
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    if (!x)
        return true; // x==0

    // assert: x>0
    if (x < 10)
        return true;

    // assert: x>=10
    int *nums = digits_of_int(x);
    int x_len = nums[0];
    int mid = (x_len + 1) >> 1;
    int offset;

    if (x_len & 1) {
        // assert x_len>=3
        for (offset = 1; offset < mid; ++offset) {
            if (nums[mid - offset] != nums[mid + offset])
                return false;
        }
        return true;
    } else {
        int mid_p1 = mid + 1;
        for (offset = 0; offset < mid; ++offset) {
            if (nums[mid - offset] != nums[mid_p1 + offset])
                return false;
        }
        return true;
    }
}

// int main(int argc, char const *argv[]) {
//     int x = 10;
//     printf((isPalindrome(x) ? "true" : "false"));
//     return 0;
// }
