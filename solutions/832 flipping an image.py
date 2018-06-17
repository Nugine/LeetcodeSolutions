class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i,row in enumerate(A):
            row.reverse()
            A[i]=[x^1 for x in row]
        return A