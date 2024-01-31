class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i, j = 0, len(numbers) - 1
        # theoretically below two can use binary search to speed up
        while numbers[i] + numbers[-1] < target:
            i += 1
        while numbers[0] + numbers[j] > target:
            j -= 1
        while 1:
            s = numbers[i] + numbers[j]
            if s == target:
                return [i + 1, j + 1]
            elif s > target:
                j -= 1
            else:
                i += 1


s = Solution()
print(s.twoSum([2, 7, 11, 15], 9))
