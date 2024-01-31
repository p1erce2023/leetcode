class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        # script 2: after reading discuss, 92ms, O(n), using obvious math character
        water = 0
        i, j = 0, len(height) - 1
        while i < j:
            h = min(height[i], height[j]);
            water = max(water, (j - i) * h)
            while height[i] <= h and i < j:
                i += 1
            while height[j] <= h and i < j:
                j -= 1
        return water


        # script 1: accept once, but very slow, 140ms
        if len(height) < 2:
            return 0
        n = len(height)
        points = [(i, height[i]) for i in xrange(n)]
        points.sort(key=lambda item: item[1], reverse=True)
        if points[0][0] < points[1][0]:
            left, right = points[0][0], points[1][0]
        else:
            right, left = points[0][0], points[1][0]
        area = points[1][1] * (right - left)

        for x in points[2:]:
            if x[0] < left:
                area = max(area, x[1] * (right - x[0]))
            elif x[0] > right:
                area = max(area, x[1] * (x[0] - left))
            else:
                area = max(area, x[1] * max(x[0] - left, right - x[0]))

            if x[0] < left:
                left = x[0]
            elif x[0] > right:
                right = x[0]
        return area

s = Solution()
assert s.maxArea([1,1,1,1,1,1]) == 5
assert s.maxArea([1,1,2,1,1,2]) == 6
assert s.maxArea([1,2,3,3,2,1]) == 6
