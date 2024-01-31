class Solution:
    def missingNumber(self, nums) -> int:
        s = len(nums)
        for i, x in enumerate(nums):
            s ^= i
            s ^= x
        return s
    

s = Solution()
print(s.missingNumber([3,0,1]))