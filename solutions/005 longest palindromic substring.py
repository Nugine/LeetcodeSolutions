class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        return self.lp_seed(s)

    @staticmethod
    def lp_seed(s):
        sl = len(s)
        if sl == 0 or sl == 1:
            return s
        elif sl == 2:
            return s if s[0] == s[1] else s[0]
        else:
            # ensure: sl>=3
            max_ss_len = 1
            max_ss_ij = (0, 0)
            for c in range(1, sl - 1):
                i, j = c - 1, c + 1
                while True:
                    if s[i] == s[j]:
                        i -= 1
                        j += 1
                    else:
                        break
                    if i == -1 or j == sl:
                        break
                i, j = i + 1, j - 1
                ss_len = j - i + 1
                if ss_len > max_ss_len:
                    max_ss_len = ss_len
                    max_ss_ij = (i, j)
            for c in range(sl - 1):
                if s[c + 1] == s[c]:
                    i, j = c - 1, c + 2
                    if i >= 0 and j < sl:
                        while True:
                            if s[i] == s[j]:
                                i -= 1
                                j += 1
                            else:
                                break
                            if i == -1 or j == sl:
                                break
                    i, j = i + 1, j - 1
                    ss_len = j - i + 1
                    if ss_len > max_ss_len:
                        max_ss_len = ss_len
                        max_ss_ij = (i, j)
        return s[max_ss_ij[0]:max_ss_ij[1] + 1]


print(Solution().lp_seed('cccbcc'))
