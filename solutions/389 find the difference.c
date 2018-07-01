char findTheDifference(char *s, char *t) {
    char rv = 0;
    char c = s[0];
    int i;
    for (i = 0; c != '\0'; c = s[++i]) {
        rv ^= c;
    }
    c = t[0];
    for (i = 0; c != '\0'; c = t[++i]) {
        rv ^= c;
    }
    return rv;
}