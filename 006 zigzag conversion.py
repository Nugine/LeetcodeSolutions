# row>=2

# 0   4   8     12
# 1 3 5 7 9  11 13 15
# 2   6   10    14

# 0        6        12
# 1     5  7     11 13
# 2  4     8  10
# 3        9


# 0   +(row-1+row-1)  +(0+0)
# 1   +(row-2+row-2)  +(1+1)
# 2   +(row-3+row-3)  +(2+2)
# 3   +(row-4+row-4)  +(3+3)
class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        sl = len(s)
        if numRows == 1:
            return s
        return ''.join(self.gen_s(s, numRows, sl))

    @staticmethod
    def gen_s(s, num_rows, sl):
        db_row = 2 * num_rows
        for row in range(num_rows):
            pos = row
            if pos < sl:
                yield s[pos]
            else:
                break
            while True:
                dt = db_row - ((row + 1) << 1)
                if dt:
                    pos += dt
                    if pos < sl:
                        yield s[pos]
                    else:
                        break

                dt = row << 1
                if dt:
                    pos += dt
                    if pos < sl:
                        yield s[pos]
                    else:
                        break
