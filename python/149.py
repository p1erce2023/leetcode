# Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b


class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        from collections import defaultdict
        n = len(points)
        if not n:
            return 0
        unique_points = defaultdict(int)
        for node in points:
            unique_points[(node.x, node.y)] += 1
        points = list(unique_points.keys())
        m = len(points)
        if m <= 2:
            return n
        k = defaultdict(set)  # y = ax + b
        p = defaultdict(set)  # x = p
        q = defaultdict(set)  # y = q
        for i in range(m):
            for j in range(i + 1, m):
                if points[i][0] == points[j][0]:  # x = p
                    p[points[i][0]].add(points[i])
                    p[points[i][0]].add(points[j])
                elif points[i][1] == points[j][1]:  # y = q
                    q[points[i][1]].add(points[i])
                    q[points[i][1]].add(points[j])
                else:
                    d_y = points[i][1] - points[j][1]
                    d_x = points[i][0] - points[j][0]
                    a1 = d_y / d_x
                    a2 = d_x / d_y  # use a2 to avoid float precision
                    b = points[i][1] - a1 * points[i][0]
                    k[(a1, a2, b)].add(points[i])
                    k[(a1, a2, b)].add(points[j])
        m = 0
        if k:
            m = max(sum(unique_points[vv] for vv in v) for v in k.values())
        if p:
            m = max(m, max(sum(unique_points[vv] for vv in v) for v in p.values()))
        if q:
            m = max(m, max(sum(unique_points[vv] for vv in v) for v in q.values()))
        return m


def from_list(points):
    return [Point(item[0], item[1]) for item in points]


s = Solution()
print(s.maxPoints(from_list([[1,1],[2,2],[3,3]])))  # 3
print(s.maxPoints(from_list([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]])))  # 4
print(s.maxPoints(from_list([[1,1],[1,1],[2,2],[2,2]])))  # 4
print(s.maxPoints(from_list([[1,1],[1,1],[1,1],[2,2],[3,3],[4,4]])))  # 6
print(s.maxPoints(from_list([[1,1],[1,1],[1,1],[2,2],[3,3],[4,4],[1,5],[1,6],[1,7],[1,8]])))
print(s.maxPoints(from_list([[0,0],[94911151,94911150],[94911152,94911151]])))  # float precision
