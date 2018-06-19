cache = [str(i) for i in range(101)]
max_n = 100


def set_fb(l, r):
    for i in range(l, r):
        if not i % 15:
            cache[i] = "FizzBuzz"
        elif not i % 3:
            cache[i] = "Fizz"
        elif not i % 5:
            cache[i] = "Buzz"


set_fb(1, 101)


class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        global max_n
        if n > max_n:
            l, r = max_n + 1, n + 1
            cache.extend(str(i) for i in range(l, r))
            set_fb(l, r)
            max_n = n
        return cache[1:max_n+1]
