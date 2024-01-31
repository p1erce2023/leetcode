class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # 2 dimensional binary search, O(log(m)+log(n))=O(log(mn)), the same with below
        m = len(matrix)
        if not m: return False
        st, ed = 0, m-1
        mid = (st + ed) >> 1
        while st < ed:
            if matrix[mid][0] == target:
                return True
            elif target > matrix[mid][0]:
                st = mid + 1
            else:
                ed = mid - 1
            mid = (st + ed) >> 1
        if target == matrix[st][0]:
            return True
        elif target < matrix[st][0]:
            row = st - 1
        else:
            row = st
        n = len(matrix[0])
        st, ed = 0, n-1
        while st <= ed:
            mid = (st + ed) >> 1
            if matrix[row][mid] == target:
                return True
            elif target > matrix[row][mid]:
                st = mid + 1
            else:
                ed = mid - 1
        return False

        # map binary search to position in matrix, slow? Not exactly, language dependent
        m = len(matrix)
        if not m: return False
        n = len(matrix[0])
        st, ed = 0, m*n-1
        while st <= ed:
            mid = (st + ed) >> 1
            p = matrix[mid/n][mid%n]
            if p == target:
                return True
            elif p < target:
                st = mid + 1
            else:
                ed = mid - 1
        return False

s = Solution()
print s.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,50]], 18)


