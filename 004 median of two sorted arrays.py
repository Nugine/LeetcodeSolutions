class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        return self.fmsa(nums1, nums2)

    @staticmethod
    def find_median(nums, nums_len):
        if nums_len & 1:
            return float(nums[(nums_len + 1) // 2 - 1])
        else:
            return (nums[(nums_len >> 1) - 1] + nums[nums_len >> 1]) / 2.0

    def fmsa(self, nums1, nums2):
        nal1 = len(nums1)
        nal2 = len(nums2)
        if not nal1:
            return self.find_median(nums2, nal2)
        if not nal2:
            return self.find_median(nums1, nal1)

        sl = nal1 + nal2
        if sl & 1:
            return float(self.find_kth((sl >> 1) + 1, nums1, nums2, 0, 0, nal1, nal2))
        else:
            return (self.find_kth((sl >> 1), nums1, nums2, 0, 0, nal1, nal2) +
                    self.find_kth((sl >> 1) + 1, nums1, nums2, 0, 0, nal1, nal2)) / 2.0

    def find_kth(self, k, la, lb, las, lbs, la_size, lb_size):
        while True:
            if las >= la_size:
                return lb[lbs + k - 1]
            if lbs >= lb_size:
                return la[las + k - 1]
            if k == 1:
                return min(la[las], lb[lbs])

            mid = (k + 1) // 2
            a_key = mid - 1
            b_key = k - a_key - 2
            if las + a_key >= la_size:
                a_key = la_size - 1 - las
                b_key = k - a_key - 2
            if lbs + b_key >= lb_size:
                b_key = lb_size - 1 - lbs
                a_key = k - b_key - 2
            if la[las + a_key] < lb[lbs + b_key]:
                k = k - a_key - 1
                las = las + a_key + 1
            else:
                k = k - b_key - 1
                lbs = lbs + b_key + 1

#
# l1 = [1, 3, 7]
# l2 = [8, 9, 10]
# print(Solution().findMedianSortedArrays(l1, l2))
#
# nl = sorted([*l1, *l2])
# print(Solution.find_median(nl, len(nl)))
