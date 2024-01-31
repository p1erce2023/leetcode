class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # other's total different way of thinking
        if not nums:
            return []
        nums.sort()
        ret = [[]]
        for n in nums:
            new_ret = []
            l = len(ret[-1])
            for seq in ret:
                for i in range(l, -1, -1):
                    if i < l and seq[i] == n:
                        break
                    new_ret.append(seq[:i] + [n] + seq[i:])
            ret = new_ret
        return ret

        # script 2: better
        q = []
        def p(nums, i, n, q):
            if i == n - 1:
                q.append(nums[:])
                return
            swapset = set()
            for j in xrange(i, n):
                if i == j:
                    p(nums, i + 1, n, q)
                    swapset.add(nums[i])
                elif nums[i] == nums[j]:
                    continue
                else:
                    if nums[j] in swapset:
                        continue
                    swapset.add(nums[j])
                    nums[i], nums[j] = nums[j], nums[i]
                    p(nums, i + 1, n, q)
                    nums[i], nums[j] = nums[j], nums[i]
        p(nums, 0, len(nums), q)
        return q

        # script 1: still use set. can not set use?
        q = set()
        nums.sort()
        def p(nums, i, n, q):
            if i == n - 1:
                q.add(tuple(nums[:]))
                return
            for j in xrange(i, n):
                if i == j:
                    p(nums, i + 1, n, q)
                elif nums[i] == nums[j]:
                    continue
                else:
                    if nums[j] in nums[:j]:
                        continue
                    nums[i], nums[j] = nums[j], nums[i]
                    p(nums, i + 1, n, q)
                    nums[i], nums[j] = nums[j], nums[i]
        p(nums, 0, len(nums), q)
        return [list(x) for x in q]

s = Solution()
# r = s.permuteUnique([1,1,1,2,2,3,3,4])
# r = s.permuteUnique([-1, 2, 0, -1, 1, 0, 1])
# print len(r), len(set(tuple(x) for x in r))
# print r
# print r
print s.permuteUnique([1,2,2])
print sorted(s.permuteUnique([2,2,1,1]))
