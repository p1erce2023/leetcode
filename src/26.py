class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        p1, p2, l = 0, 1, len(nums)
        while p2 < l:
            if nums[p1] != nums[p2]:
                p1 += 1
                nums[p1] = nums[p2]
            p2 += 1
        return p1 + 1


s = Solution()
print s.removeDuplicates([1, 1, 2])
print s.removeDuplicates([1])
print s.removeDuplicates([1, 1, 1])
print s.removeDuplicates([])
print s.removeDuplicates([1,1,1,1,1,1,1, 2, 2, 3, 4, 5])
print s.removeDuplicates([1, 2, 2, 2, 2, 2])