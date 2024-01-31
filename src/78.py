class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # bit (by instruction)
        nums.sort()
        n = len(nums)
        total = 2**n
        answer = [[] for _ in xrange(total)]  # has 2^n subset, just correspond to range(2^n)
        for i in xrange(n):
            for j in xrange(total):
                if j>>i & 1:
                    answer[j].append(nums[i])
        return answer

        # iterative way
        nums.sort()
        answer = [[]]
        for n in nums:
            s = [a + [n] for a in answer]
            answer.extend(s)
        return answer

        # recursive way is slow
        nums.sort()
        if not nums:
            return []
        elif len(nums) == 1:
            return [[], nums]
        else:
            answer = []
            a = self.subsets(nums[1:])
            answer.extend(a)
            answer.extend([nums[0]] + l for l in a)
            return answer


s = Solution()
print s.subsets([2,3,4])
print s.subsets([1,2,3,4])
