char *reverseString(char *s) {
    if (s[0] == '\0') {
        return s;
    }
    char tmp;
    int i, offset, a, b;

    for (i = 0; s[i + 1] != '\0'; ++i) {
    }

    if (i & 1) {
        i >>= 1;
        for (offset = 0; offset <= i; ++offset) {
            a = i - offset;
            b = i + 1 + offset;
            tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
        }
    } else {
        i >>= 1;
        for (offset = 1; offset <= i; ++offset) {
            a = i - offset;
            b = i + offset;
            tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
        }
    }
    return s;
}
