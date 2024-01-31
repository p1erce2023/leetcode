# -*- coding: utf-8 -*-
class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def nextPermutation(self, nums):
        n = len(nums)
        if n <=1:
            return
        def find_bigger(target, st, ed):  # binary search
            while st < ed:
                mid = (st & ed) + ((st ^ ed) >> 1)
                if nums[mid] > target and mid + 1 <= ed and target >= nums[mid + 1]:
                    return mid
                elif nums[mid] <= target:
                    ed = mid - 1
                else:
                    st = mid + 1
            return st

        max = nums[-1]
        for i in xrange(2, n + 1):
            if nums[-i] >= max:
                max = nums[-i]
            else:
                j = find_bigger(nums[-i], n - i + 1, n - 1)
                nums[-i], nums[j] = nums[j], nums[-i]
                nums[n - i + 1:] = nums[n - i + 1:][::-1]
                print nums
                return
                # in general, binary search should be faster than this
                # though this is the popular(easy) way
                # for j in xrange(1, i):
                #     if nums[-j] > nums[-i]:
                        # nums[-i], nums[-j] = nums[-j], nums[-i]
                        # nums[n - i + 1:] = nums[n - i + 1:][::-1]
                        # print nums
                        # return
        nums.reverse()
        print nums
        return


s = Solution()
s.nextPermutation([4,2,0,2,3,2,0])
s.nextPermutation([1,2,3])  #  → 1,3,2
s.nextPermutation([3,2,1])  #  → 1,2,3
s.nextPermutation([1,1,5])  #  → 1,5,1

nums = [1, 2, 3, 4]
for _ in range(25):
    s.nextPermutation(nums)

s.nextPermutation([4,5,5,3,1])
s.nextPermutation([4,5,4,3,2,1])
# 1,2,3,4
# 1,2,4,3
# 1,3,2,4
# 1,3,4,2
# 1,4,2,3
# 1,4,3,2
# 2,1,3,4
# 2,1,4,3
# 2,3,1,4
# 2,3,4,1
# 2,4,1,3
# 2,4,3,1
# 3,1,2,4



# 1,3,4,5,2
# 1,3,5,2,4
# 1,3,5,4,2
# 1,4,2,3,5
# 1,4,2,5,3
# 1,4,5,2,3
# 1,4,5,3,2
# 1,5,2,3,4
# 1,5,2,4,3
# 1,5,3,2,4
# 1,5,3,4,2
# 1,5,4,2,3
# 1,5,4,3,2
# 2,1,3,4,5
# 2,1,3,5,4

# 1,2,1,3
# 1,2,3,1
# 1,3,1,2
# 1,3,2,1
# 2,1,1,3
