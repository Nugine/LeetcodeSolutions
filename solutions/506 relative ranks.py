class Solution:
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        return [v[0] for v in sorted((('Gold Medal' if i==1 else ('Silver Medal' if i==2 else ('Bronze Medal' if i==3 else str(i))),j)  for i,(j,n) in enumerate(sorted(enumerate(nums),key=lambda x:x[1],reverse=True),start=1)),key=lambda x:x[1])]