class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def firstMissingPositive(self, nums):
        # O(n) time and constant space, did not figure this out by myself
        # Put each number in its right place.
        # For example:
        # When we find 5, then swap it with A[4].
        # At last, the first place where its number is not right, return the place + 1.
        i, n = 0, len(nums)
        while i < n:
            num = nums[i]
            # print i, num
            if 0 < num <= n and nums[num-1] != num:
                nums[i], nums[num-1] = nums[num-1], nums[i]
                # print nums
            else:
                i += 1
        for i, d in enumerate(nums):
            if d != i+1:
                return i + 1
        return n + 1

        # O(n) time and O(n) space
        num_set = set()
        for n in nums:
            num_set.add(n)
        
        while True:
            if i not in num_set:
                return i
            i += 1


s = Solution()
print s.firstMissingPositive([-1,4,2,1,9,10])
print s.firstMissingPositive([1,2,0])
print s.firstMissingPositive([])
print s.firstMissingPositive([1])
print s.firstMissingPositive([3,4,-1,1])