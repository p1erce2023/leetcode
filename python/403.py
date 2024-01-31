class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        # 的确也有人写的是这个方法，不过没有dfs快
        n = len(stones)
        if n < 2:
            return True
        if n >= 2 and stones[1] - stones[0] != 1:
            return False
        dp = {x: set() for x in stones}
        dp[stones[1]].add(1)
        last = stones[-1]
        for i in range(1, n - 1):
            for j in dp[stones[i]]:
                y = stones[i]+j-1
                if last == y:
                    return True
                if j-1 and y in dp:
                    dp[y].add(j-1)
                for k in range(2):
                    y += 1
                    if last == y:
                        return True
                    if y in dp:
                        dp[y].add(j + k)
        return True if dp[stones[-1]] else False


s = Solution()
print(s.canCross([0,1,3,5,6,8,12,17]))
print(s.canCross([0,1,2,3,4,8,9,11]))
print(s.canCross([0,2]))
