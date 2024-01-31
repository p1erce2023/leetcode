class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # count number is easy, but here is a genius idea, O(1) space, called Moore's voting algorithm
        m, count, n = None, 0, len(nums) / 2
        for x in nums:
            if count > n:
                return m
            if not count:
                m = x
                count += 1
            else:
                if m == x:
                    count += 1
                else:
                    count -= 1
        return m


s = Solution()
print(s.majorityElement([1, 1, 2, 3, 2, 2, 2, 4]))
