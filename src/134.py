class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        y, x, n, start_idx = 0, 0, len(gas), -1
        for i in range(n):
            x += gas[i] - cost[i]
            if x < 0:
                y += x
                x, start_idx = 0, -1
            elif start_idx == -1:
                start_idx = i
        if start_idx != -1 and x + y < 0:
            start_idx = -1
        return start_idx


s = Solution()
print(s.canCompleteCircuit([2], [2]))
print(s.canCompleteCircuit([2, 4], [3, 4]))
print(s.canCompleteCircuit([99, 98, 97, 100], [100, 100, 100, 97]))
