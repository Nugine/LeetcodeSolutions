class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        return self.lols_window(s)

    @staticmethod
    def lols_window(s):
        s_len = len(s)
        if not s_len:
            return 0
        elif s_len == 1:
            return 1
        i, max_l = 0, 1
        c2i = {s[0]: 0}
        for j in range(1, s_len):
            c = s[j]
            if i <= c2i.get(c, -1) < j:
                max_l = max(max_l, j - i)
                i = c2i[c] + 1
            else:
                max_l = max(max_l, j - i + 1)
            c2i[c] = j
        return max_l


print(Solution().lengthOfLongestSubstring('tmmzuxt'))
