// #include <stdbool.h>
bool hasAlternatingBits(int n) {
    int bit=n&1;
    n>>=1;
    while(n){
        if((n&1)!=bit){
            bit^=1;
            n>>=1;
        }
        else{
            return false;
        }
    }
    return true;
}
