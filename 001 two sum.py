class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        return self.two_sum_once_hash(nums, target)

    @staticmethod
    def two_sum_traversal(nums, target):
        nums_len = len(nums)
        for i in range(nums_len):
            for j in range(i + 1, nums_len):
                if nums[i] + nums[j] == target:
                    return [i, j]

    @staticmethod
    def two_sum_twice_hash(nums, target):
        table = {n: i for i, n in enumerate(nums)}
        for i, n in enumerate(nums):
            try:
                return [i, table[target - n]]
            except KeyError:
                continue

    @staticmethod
    def two_sum_once_hash(nums, target):
        table = {}
        for i, n in enumerate(nums):
            try:
                return [table[target - n], i]
            except KeyError:
                pass
            table[n] = i
