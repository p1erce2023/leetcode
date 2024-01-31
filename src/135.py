class Solution:
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        # O(n) time 1 pass, O(1) space, k = direction
        i, j, k, n = 0, 0, 1, len(ratings)
        local_max = 1
        if not n:
            return 0
        x = n
        for i in range(1, n):
            if ratings[i - 1] > ratings[i]:
                if k == 1:
                    j = i
                    k = -1
                x += i - j
                if i - j + 2 > local_max:
                    x += 1
            elif ratings[i - 1] < ratings[i]:
                if k == -1:
                    local_max = 1
                    j = i - 1
                    k = 1
                x += i - j
                local_max += 1
            else:
                k = 1
                local_max = 1
                j = i
        return x


s = Solution()
print(s.candy([1, 0, 2]))  # 5
print(s.candy([1, 2, 2]))  # 4
print(s.candy([1, 5, 10, 7, 6, 2, 5, 8, 7, 6, 7]))  # 23
print(s.candy([1, 3, 2, 2, 1]))  # 7
