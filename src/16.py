class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def threeSumClosest(self, nums, target):
        if len(nums) < 3:
            return None
        nums.sort()
        i, n = 0, len(nums)
        d, m = 2147483647, 0
        while i < n - 1:
            if i and nums[i] == nums[i-1]:  # avoid duplicate
                i += 1
                continue
            j, k = i + 1, n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return target
                elif s > target:
                    k -= 1
                    while nums[k] == nums[k+1] and j < k:  # avoid duplicate
                        k -= 1
                    if s - target < d:
                        m = s
                        d = s - target
                else:
                    j += 1
                    while nums[j] == nums[j-1] and j < k:  # avoid duplicate
                        j += 1
                    if target - s < d:
                        m = s
                        d = target - s
            i += 1
        return m

s = Solution()
print s.threeSumClosest([-1,2,1,-4], 1)
print s.threeSumClosest([-1,0,1,2,-1,-4], -7)