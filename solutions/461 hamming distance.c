int hammingDistance(int x, int y) {
    int rv = 0;
    x ^= y;
    while (x) {
        x &= x - 1;
        ++rv;
    }
    return rv;
}
