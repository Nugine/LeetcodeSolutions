class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True
        stack = []
        push = stack.append
        pop = stack.pop
        c_map = {')': '(', ']': '[', '}': '{'}
        for c in s:
            if c in "([{":
                push(c)
            else:
                if not stack:
                    return False
                if stack[-1] != c_map[c]:
                    return False
                else:
                    pop()
        return stack==[]
        


if __name__ == '__main__':
    print(Solution().isValid("[{}]}"))
