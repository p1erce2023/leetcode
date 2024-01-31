class Solution:
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        # TLE O(n^2)
        n = len(rectangles)
        if n <= 1:
            return True
        corner = [(rectangles[0][0], rectangles[0][1]) for _ in range(4)]
        area_sum = 0
        for rec in rectangles:
            area_sum += (rec[2] - rec[0]) * (rec[3] - rec[1])
            if rec[0] < corner[0][0] or (rec[0] == corner[0][0] and rec[1] < corner[0][1]):
                corner[0] = (rec[0], rec[1])
            if rec[1] < corner[1][1] or (rec[1] == corner[1][1] and rec[0] < corner[1][0]):
                corner[1] = (rec[0], rec[1])
            if rec[2] > corner[2][0] or (rec[2] == corner[2][0] and rec[3] > corner[2][1]):
                corner[2] = (rec[2], rec[3])
            if rec[3] > corner[3][1] or (rec[3] == corner[3][1] and rec[2] > corner[3][0]):
                corner[3] = (rec[2], rec[3])
        if corner[0] != corner[1] or corner[2] != corner[3]:
            return False
        area = (corner[2][0] - corner[0][0]) * (corner[2][1] - corner[0][1])
        if area != area_sum:
            return False
        rectangles.sort()
        for i in range(n):
            for j in range(i + 1, n):  # rec[i] overlay rec[j]
                item1, item2 = rectangles[i], rectangles[j]
                if item1[0] > item2[0]:
                    item1, item2 = item2, item1
                if item2[0] >= item1[2] or item2[1] >= item1[3] or item2[3] <= item1[1]:
                    pass
                else:
                    return False
        return True


s = Solution()
print(s.isRectangleCover([
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]))


print(s.isRectangleCover([
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]))

print(s.isRectangleCover([
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]))

print(s.isRectangleCover([
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]))
