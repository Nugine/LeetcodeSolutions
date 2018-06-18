int findComplement(int num) {
    unsigned int t = 1;
    while (t <= num) {
        t <<= 1;
    }
    return t - 1 - num;
}