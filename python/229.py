class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        a, b = None, None
        ca, cb = 0, 0
        for x in nums:
            if x == a:
                ca += 1
            elif x == b:
                cb += 1
            elif ca == 0:
                a = x
                ca = 1
            elif cb == 0:
                b = x
                cb = 1
            else:
                ca -= 1
                cb -= 1
        c = {a: 0, b: 0}
        for x in nums:
            if x in c:
                c[x] += 1
        return [k for k, v in c.items() if v > len(nums) // 3]


s = Solution()
print(s.majorityElement([1,2,2,3,2,1,1,3]))
print(s.majorityElement([2,2]))
print(s.majorityElement([1,2,2]))
print(s.majorityElement([3,2,3]))
print(s.majorityElement([1,1,1,3,3,2,2,2]))
