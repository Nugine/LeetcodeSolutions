int hammingWeight(uint32_t n) {
    int rv;
    while (n) {
        n &= n - 1;
        ++rv;
    }
    return rv;
}