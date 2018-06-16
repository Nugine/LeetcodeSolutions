class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if not x:
            return 0
        sign = x > 0
        if sign:
            rv = int(''.join(reversed(str(x))))
        else:
            rv = -int(''.join(reversed(str(-x))))
        xmax = (1 << 31) - 1
        xmin = -(1 << 31)
        if rv > xmax or rv < xmin:
            return 0
        return rv
