class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        思路不够好，看别人的都是几分钟就搞出来了
        """
        if not A:
            return 0
        n = len(A)
        if S == 0:
            r = 0
            i, j = -1, -1
            while j < n:
                i = j + 1
                while i < n:
                    if A[i] == 0:
                        break
                    i += 1
                if i == n:
                    return 0
                j = i + 1
                while j < n:
                    if A[j] == 1:
                        break
                    j += 1
                r += (j - i) * (j - i + 1) // 2
            return r
        r, x, i, j = 0, 0, 0, 0
        while x < S and j < n:
            x += A[j]
            j += 1
        if j == n:
            if x == S:
                return 1
            return 0
        j -= 1
        while j < n:
            a = A.index(1, i)
            b = j
            while b + 1 < n and A[b + 1] == 0:
                b += 1
            r += (a - i + 1) * (b - j + 1)
            # print(i, j, a, b)
            i = a + 1
            j = b + 1
        return r

    def numSubarraysWithSum2(self, A, S):
        '''
          1 0 1 0 1
        0 1 1 2 2 3
        2

          0 1 0 1 0
        0 0 1 1 2 2

          0 0
        0 0 0

        '''
        prefix_sum = [0]
        from collections import Counter
        c = Counter()
        for x in A:
            prefix_sum.append(prefix_sum[-1] + x)
        ans = 0
        for x in prefix_sum:
            ans += c[x - S]
            c[x] += 1
        return ans
