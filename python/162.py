class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a, b = 0, len(nums) - 1
        while a < b:
            mid = (a + b) // 2
            if nums[mid] < nums[mid + 1]:
                a = mid + 1
            else:
                b = mid
        return a

s = Solution()
print(s.findPeakElement([10,9,4,3,2,6,7,9]))
print(s.findPeakElement([1,2,1,3,5,6,4]))
print(s.findPeakElement([2]))
print(s.findPeakElement([2,3]))
print(s.findPeakElement([2,1]))
