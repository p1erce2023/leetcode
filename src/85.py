class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # based on 84. largest rectangle area
        if not matrix:
            return 0
        n, m, area = len(matrix), len(matrix[0]), 0
        heights = [0] * (m + 1)
        for i in xrange(n):
            for j in xrange(m):
                if matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
            # print heights
            stack = []
            for k, h in enumerate(heights):
                if not stack:
                    stack.append(k)
                else:
                    if h >= heights[stack[-1]]:
                        stack.append(k)
                    else:
                        while stack and h < heights[stack[-1]]:
                            x = stack.pop()
                            last = stack[-1] if stack else -1
                            area = max(area, heights[x] * (k - last - 1))
                        stack.append(k)
            # print area
        return area


s = Solution()
matrix = ['0110010101',
          '0010101010',
          '1000010110',
          '0111111010',
          '0011111110',
          '1101011110',
          '0001100010',
          '1101100111',
          '0101101011']
print s.maximalRectangle(matrix)  # 10
matrix = ['10100',
          '10111',
          '11111',
          '10010']
print s.maximalRectangle(matrix)  # 6
matrix = ['101101',
          '111111',
          '011011',
          '111010',
          '011111',
          '110111']
print s.maximalRectangle(matrix)  # 8
matrix = ['10011',
          '11111',
          '11110',
          '01111',
          '10100',
          '11111']
print s.maximalRectangle(matrix)  # 9
matrix = ['10011',
          '11011',
          '11001',
          '01110',
          '10111',
          '11110']
print s.maximalRectangle(matrix)  # 6
