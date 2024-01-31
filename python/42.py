class Solution:
    # @param {integer[]} height
    # @return {integer}
    def trap(self, height):
        # script 2: two pointers, interesting method from discussion
        # Keep track of the already safe level and the total water so far.
        # In each step, process and discard the lower one of the leftmost or rightmost elevation.
        L, R = 0, len(height) - 1
        level, water = 0, 0
        while L < R:
            if height[L] < height[R]:
                lower = height[L]
                L += 1
            else:
                lower = height[R]
                R -= 1
            if lower > level:
                level = lower
            water += level - lower
        return water

        # script 1: from left to right. better when stack stores i, not (i, height[i])
        i, n = 0, len(height)
        water = 0
        while i < n and not height[i]:
            i += 1
        if i < n:
            stack = [i]
        i += 1
        while i < n:
            hi = height[i]
            if not hi:
                i += 1
                continue
            if hi < height[stack[-1]]:
                water += hi * (i - stack[-1] - 1)
                stack.append(i)
            elif hi == height[stack[-1]]:
                water += hi * (i - stack[-1] - 1)
                stack[-1] = i
            else:
                calculated_h = 0
                while True:
                    j = stack.pop()
                    hj = height[j]
                    water += (hj - calculated_h) * (i - j - 1)
                    calculated_h = hj
                    if stack:
                        if hi >= height[stack[-1]]:
                            continue
                        else:
                            water += (hi - calculated_h) * (i - stack[-1] - 1)
                            stack.append(i)
                            break
                    else:
                        stack.append(i)
                        break
            i += 1
        return water

s = Solution()
print s.trap([4,2,3])  # 1
print s.trap([0,1,0,2,1,0,1,3,2,1,2,1])  # 6
print s.trap([0,1,0,1,0,1,2,0,3,2,1,2,1,3])  # 10
print s.trap([2,3,2,1,0,2])  # 3


