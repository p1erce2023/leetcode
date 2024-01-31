class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # multiple transactions
        if not prices:
            return 0
        i, n = 1, len(prices)
        while i < n and prices[i] <= prices[i - 1]:
            i += 1
        if i == n:
            return 0
        bought, profit = i - 1, 0
        while i < n:
            if bought != -1 and prices[i] < prices[i - 1]:  # sold @ i
                profit += prices[i - 1] - prices[bought]
                bought = -1
            elif bought == -1 and prices[i] > prices[i - 1]:
                bought = i - 1
            i += 1
        if bought != -1:
            profit += prices[-1] - prices[bought]
        return profit


s = Solution()
print s.maxProfit([1, 2])
print s.maxProfit([3, 2, 6, 5, 0, 3])
print s.maxProfit([7, 3, 1, 5, 3, 6, 4, 1, 2, 5])
print s.maxProfit([7, 6, 4, 3, 1])
