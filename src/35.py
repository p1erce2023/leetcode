# -*- coding: utf-8 -*-
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def searchInsert(self, nums, target):
        if not nums:
            return 0
        st, ed = 0, len(nums) - 1
        while st < ed:
            mid = (st & ed) + ((st ^ ed) >> 1)  # also use this trick
            # print st, mid, ed
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                st = mid + 1
            else:
                ed = mid - 1
        # print st, ed
        if nums[st] >= target:
            return st
        else:
            return st + 1


s = Solution()
print s.searchInsert([1,3,5,7], 0)  # → 0
print s.searchInsert([1,3,5,7], 1)  # → 0
print s.searchInsert([1,3,5,7], 2)  # → 1
print s.searchInsert([1,3,5,7], 3)  # → 1
print s.searchInsert([1,3,5,7], 4)  # → 2
print s.searchInsert([1,3,5,7], 5)  # → 2
print s.searchInsert([1,3,5,7], 6)  # → 3
print s.searchInsert([1,3,5,7], 7)  # → 3
print s.searchInsert([1,3,5,7], 8)  # → 4

print s.searchInsert([1,3,5,6], 7)  # → 4
print s.searchInsert([1,3,5,6], 5)  # → 2
print s.searchInsert([1,3,5,6], 2)  # → 1
print s.searchInsert([1,3,5,6], 0)  # → 0