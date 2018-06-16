#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define int_max_digit_num 10
#define big_int long long
#define mod(a, b) (a % b)
#define int_floordiv(a, b) (a / b)

class Solution {
  public:
    big_int convert(int x) {
        int num_array[int_max_digit_num + 1];
        int digit, max_digit;
        big_int rv = 0;

        for (digit = 0; x != 0; ++digit) {
            num_array[digit] = mod(x, 10);
            x = int_floordiv(x, 10);
        }
        max_digit = digit - 1;

        for (digit = 0; digit <= max_digit; ++digit) {
            rv += num_array[digit];
            if (digit < max_digit)
                rv *= 10;
        }
        return rv;
    }

    int reverse(int x) {
        big_int rv;

        if (x == 0||x==INT_MAX||x==INT_MIN)
            return 0;

        if(mod(x,10)>2 && ((x>1000000000)||(x<-1000000000)))
            return 0;

        if (x > 0) {
            rv = convert(x);
            if (rv > INT_MAX)
                return 0;
            return (int)rv;
        } else {
            rv = convert((~x) + 1);
            if (-rv < INT_MIN)
                return 0;
            return -(int)rv;
        }
    }
};