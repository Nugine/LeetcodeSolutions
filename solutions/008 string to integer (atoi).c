#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define bool int
#define true 1
#define false 0
// #include <stdio.h>
// #define print_int(it) printf("%d\n", it)

#define c2i_case(c)                                                            \
    case c:                                                                    \
        return (int)(c - 48)

int char2int(char c) {
    switch (c) {
        c2i_case('0');
        c2i_case('1');
        c2i_case('2');
        c2i_case('3');
        c2i_case('4');
        c2i_case('5');
        c2i_case('6');
        c2i_case('7');
        c2i_case('8');
        c2i_case('9');
    default:
        return -1;
    }
}

int myAtoi(char *str) {
    bool sign;

    int index = 0;
    char c = str[index];
    bool flag = false;
    int n = -1;
    int tmp = -1;
    // search +-n
    for (; c != '\0' && (!flag); c = str[++index]) {
        switch (c) {
        case '+':
            flag = true;
            sign = true;
            break;
        case '-':
            flag = true;
            sign = false;
            break;
        case ' ':
            break;
        default:
            n = char2int(c);
            if (n != -1) {
                flag = true;
                sign = true;
            }
            else{
                return 0;
            }
        }
    }
    if (!flag)
        return 0; // not find +-n. can not convert

    if (n == -1) {
        if (c == '\0')
            return 0; // +-  is not followed by num
        tmp = char2int(c);
        if (tmp == -1) {
            return 0; // illegal char
        } else {
            n = tmp;
            c = str[++index];
        }
    }

    // c: next char of n
    if (sign) {
        for (int tmp = -1; c != '\0'; c = str[++index]) {
            tmp = char2int(c);
            if (tmp == -1) {
                break; // illegal char
            } else {
                // now try to enlarge n
                if ((n > INT_MAX / 10) || (n == INT_MAX / 10 && tmp > 7))
                    return INT_MAX;

                n *= 10;
                n += tmp;
            }
        }
        return n;
    } else {
        for (int tmp = -1; c != '\0'; c = str[++index]) {
            tmp = char2int(c);
            if (tmp == -1) {
                break; // illegal char
            } else {
                // now try to enlarge n
                if ((n > INT_MAX / 10) || (n == INT_MAX / 10 && tmp > 8))
                    return INT_MIN;

                n *= 10;
                n += tmp;
            }
        }
        return -n;
    }
}

// int main(int argc, char const *argv[]) {
//     char *str = "-9999999999";
//     printf("%d", myAtoi(str));
//     return 0;
// }
