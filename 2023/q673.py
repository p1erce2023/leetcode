from typing import List
from collections import defaultdict

class Solution:
    def findNumberOfLIS(self, A: List[int]) -> int:
        n = len(A)
        dp = [[1,1]] * n
        for i in range(1, n):
            for j in range(0, i):
                if A[i] > A[j]:
                    if dp[j][0]+1 > dp[i][0]:
                        dp[i] = [dp[j][0]+1, dp[j][1]]
                    elif dp[j][0]+1 == dp[i][0]:
                        dp[i][1] += dp[j][1]
        ma, ans = 0, 0
        for v in dp:
            if v[0] > ma:
                ma, ans = v[0], v[1]
            elif v[0] == ma:
                ans += v[1]
        return ans

sol = Solution()
nums = [1,3,5,4,7]
print(sol.findNumberOfLIS(nums))
nums = [2,2,2,2,2]
print(sol.findNumberOfLIS(nums))
nums = [1,2,4,3,5,4,7,2]
print(sol.findNumberOfLIS(nums))