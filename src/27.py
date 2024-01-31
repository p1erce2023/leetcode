class Solution:
    # @param {integer[]} nums
    # @param {integer} val
    # @return {integer}
    def removeElement(self, nums, val):
        if not nums:
            return 0
        new_length = 0
        i = 0
        l = len(nums) - 1
        while i < l:
            if nums[i] != val:
                i += 1
            else:
                while l and nums[l] == val:
                    l -= 1
                if i < l:
                    nums[i], nums[l] = nums[l], nums[i]
                    i += 1
                    l -= 1
        if nums[i] == val:
            return i
        else:
            return i + 1
        

s = Solution()
print s.removeElement([1, 2, 2, 2, 2, 2], 2)
print s.removeElement([1, 1, 2], 2)
print s.removeElement([1], 0)
print s.removeElement([1, 1, 1], 1)
print s.removeElement([], 2)
print s.removeElement([1,1,1,1,1,1,1, 2, 2, 3, 4, 5], 5)
print s.removeElement([1,1,1,1, 3,1,1,1, 3, 3, 2, 2, 3, 4, 5], 4)
