class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # the algorithm
        n = len(digits)
        i = 0
        while i < n and digits[-1-i] >= 9:
            digits[-1-i] = 0
            i += 1
        if i == n:
            digits.insert(0, 1)
        else:
            digits[-1-i] += 1
        return digits

        # use int
        digit = int(''.join([str(i) for i in digits]))
        return [int(i) for i in str(digit+1)]


s = Solution()
print s.plusOne([1, 9,9])
