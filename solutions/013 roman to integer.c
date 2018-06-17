// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

#define roman_char_to_int_case(c, i)                                           \
    case c:                                                                    \
        return i;
int roman_char_to_int(char c) {
    switch (c) {
        roman_char_to_int_case('I', 1)
        roman_char_to_int_case('V', 5)
        roman_char_to_int_case('X', 10)
        roman_char_to_int_case('L', 50)
        roman_char_to_int_case('C', 100)
        roman_char_to_int_case('D', 500)
        roman_char_to_int_case('M', 1000)
    }
    return -1;
}
#undef roman_char_to_int_case

#define rti_case(c, c1, c2)                                                    \
    case c:                                                                    \
        if (b == c1 || b == c2) {                                              \
            rv += (n - m);                                                     \
            ++i;                                                               \
            continue;                                                          \
        }                                                                      \
        else{                                                                  \
            rv+=m;                                                             \
        }                                                                      \
        break;
int romanToInt(char *s) {

    int rv = 0;
    char a, b;
    int m, n;
    for (int i = 0; s[i] != '\0'; ++i) {
        a = s[i];
        b = s[i + 1];
        m = roman_char_to_int(a);
        if (b == '\0') {
            rv += m;
            break;
        }
        n = roman_char_to_int(b);
        switch (a) {
            rti_case('I','V','X')
            rti_case('X','L','C')
            rti_case('C','D','M')
            default:
                rv+=m;
        }
    }
    return rv;
}

// int main(int argc, char const *argv[]) {
//     printf("%d",romanToInt("MCMXCIV"));
//     return 0;
// }
