class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type height: List[int]
        :rtype: int
        """
        # does not need dp! use stack!
        if not heights:
            return 0
        heights.append(0)
        area, stack = 0, []
        for i, h in enumerate(heights):
            if stack:
                if h > stack[-1][1]:
                    stack.append((i, h))
                elif h < stack[-1][1]:
                    j, _h = stack.pop()
                    area = max(area, _h * (i - j))
                    while stack and stack[-1][1] > h:
                        j, _h = stack.pop()
                        area = max(area, _h * (i - j))
                    stack.append((j, h))
            elif h:
                stack.append((i, h))
        return area

        # TLE O(n^2)
        if not heights:
            return 0
        n = len(heights)
        minh = [[0] * (n + 2) for _ in xrange(n + 2)]
        for i in xrange(1, n + 1):
            minh[i][i] = heights[i - 1]
        for g in xrange(1, n):
            for i in xrange(1, n - g + 1):
                minh[i][i + g] = min(minh[i][i + g - 1], heights[i + g - 1])
        area = max(minh[i][i + j] * (j + 1) for i in xrange(1, n + 1) for j in xrange(n - i + 1))
        return area

s = Solution()
print s.largestRectangleArea([1, 1])  # 2
print s.largestRectangleArea([1])  # 1
print s.largestRectangleArea([0, 0, 0])  # 0
print s.largestRectangleArea([2, 1, 5, 6, 2, 3])  # 10
print s.largestRectangleArea([2, 1, 3, 4, 2, 3])  # 8
