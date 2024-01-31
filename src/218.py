class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        from heapq import heappush, heappop
        kp, h, r, left = [], [(0, float('inf'))], [], -1
        for b in buildings:
            li, ri, hi = b[0], b[1], b[2]
            # print(li, ri, hi)
            while r and r[0][0] < li:
                if r[0][1] == -h[0][0]:
                    kp.append([left, -h[0][0]])
                    left, _ = heappop(r)
                    heappop(h)
                    while h[0][1] <= left:
                        heappop(h)
                else:
                    heappop(r)
            if left != li and hi > -h[0][0]:
                kp.append([left, -h[0][0]])
                left = li
            if hi <= -h[0][0] and r and ri <= r[0][0]:
                continue
            heappush(r, (ri, hi))
            heappush(h, (-hi, ri))
        while r:
            if r[0][1] == -h[0][0]:
                kp.append([left, -h[0][0]])
                left, _ = heappop(r)
                heappop(h)
                while h[0][1] <= left:
                    heappop(h)
            else:
                heappop(r)
        kp.append([left, 0])
        res = [kp[0]]
        for i in range(1, len(kp)):
            if kp[i][1] != res[-1][1]:
                res.append(kp[i])
        return res[1:]
        # 别人10行python搞定。。


s = Solution()
# [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]
# print(s.getSkyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))

# [[1, 2], [2, 3], [4, 0], [6, 2], [7, 0]]
# print(s.getSkyline([[1,3,2],[2,4,3],[6,7,2]]))

# [[1, 2], [2, 0], [4, 2], [5, 0]]
# print(s.getSkyline([[1,2,2],[4,5,2]]))

# [[1, 3], [2, 4], [3, 3], [11, 2], [14, 0]]
# print(s.getSkyline([[1,10,3],[2,3,4],[2,4,2],[5,7,3],[8,11,3],[9,14,2],[11,12,2]]))
