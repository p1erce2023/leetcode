class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        p1, p2 = 0, 1
        s = 1
        n = len(nums)
        while p2 < n:
            if nums[p1] == nums[p2]:
                if s == 1:
                    s = 2
                    p1 += 1
            else:
                p1 += 1
                s = 1
            nums[p1] = nums[p2]
            p2 += 1
        return p1 + 1


s = Solution()
print s.removeDuplicates([1,1,1,2,2,3,3,3,4,4,5,6,6,6,6,6,6,6,6,7])
print s.removeDuplicates([1,1,1,2,2,3])
