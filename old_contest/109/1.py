class RecentCounter:

    def __init__(self):
        self.q = []
        self.tt = 0

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        x = max(0, t - 3000)
        self.q.append(t)
        n = len(self.q)
        if not self.q or self.q[-1] < x:
            return 1
        if x == self.q[-1]:
            return 2
        if self.q[self.tt] >= x:
            return n - self.tt
        # binary search
        a = self.tt
        b = n - 1
        # self.q[a] < x < self.q[b]
        mid = (a + b) >> 1
        while a != mid:
            if self.q[mid] < x:
                a = mid
            elif self.q[mid] > x:
                b = mid
            else:
                mid -= 1
                break
            mid = (a + b) >> 1
        self.tt = mid
        return n - mid - 1


obj = RecentCounter()
for i in [1, 100, 3001, 3002, 5000, 6000, 6001, 6002, 6003, 10000]:
    print(i, obj.ping(i))
