# -*- coding: utf-8 -*-
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        from collections import Counter
        num_set = Counter(nums)
        for idx, n in enumerate(nums):
            if target - n in num_set:
                num_set[n] -= 1
                num_set[target-n] -= 1
                if num_set[n] >= 0 and num_set[target-n] >= 0:
                    return idx+1, nums[idx+1:].index(target - n)+idx+2
                else:
                    num_set[n] += 1
                    num_set[target-n] += 1
        # for idx, num in enumerate(nums):
        #     if target - num in nums[idx+1:]:
        #         return idx+1, nums[idx+1:].index(target - num)+idx+2
        # 时间复杂度O(n^2)，就不行，要用O(n)的

                

s = Solution()
re = s.twoSum([3, 2, 4], 6)
print re

re = s.twoSum([2, 7, 11, 15], 9)
print re

re = s.twoSum([0, 4, 3, 0], 0)
print re